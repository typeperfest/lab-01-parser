// Copyright 2018 Your Name <your_email>

#include "parser_printer.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include <nlohmann/json.hpp>


std::vector<Student> PARSER(const std::string& fileName)
{
  std::ifstream file(fileName);
  if(!file)
  {
    std::cout << "There is no such file with that name"
              << std::endl;
    throw std::runtime_error("file isn't exist");
  }

  using json = nlohmann::json;

  json data;
  file >> data;

  std::vector<Student> students;
  for (const auto& student : data.at("items")) {
    Student currentStudent;
    currentStudent.Name = student.at("name");
    currentStudent.Group = student.at("group");
    currentStudent.Avg = student.at("Avg");
    currentStudent.Debt = student.at("debt");

    
    // student.at("name").get_to(currentStudent.Name);
    // student.at("group").get_to(currentStudent.Group);
    // student.at("avg").get_to(currentStudent.Avg);
    // student.at("debt").get_to(currentStudent.Debt);
    students.push_back(currentStudent);
  }
  return students;
}

std::ostream& operator << (std::ostream& out, const std::any& object)
{
  if (object.type() == typeid(std::string))
  {
    out << std::any_cast<std::string>(object);
  }
  else if (object.type() == typeid(int))
  {
    out << std::any_cast<int>(object);
  }
  else if (object.type() == typeid(float))
  {
    out << std::any_cast<float>(object);
  }
  else if (object.type() == typeid(std::vector<std::string>))
  {
    std::vector<std::string> str_vec = std::any_cast<std::vector<std::string>>(object);
    for (auto& iter : str_vec)
    {
      out << iter << ' ';
    }
  }
  else
  {
    std::bad_cast ex;
    throw ex;
  }
  return out;
}

void PRINTER(const std::vector<Student>& students)
{
  // FIRST STRING
  std::cout << '|';
  std::cout <<  std::setfill(' ') << "name" << std::setw(15);
  std::cout << '|';
  std::cout <<  std::setfill(' ') << "group" << std::setw(8);
  std::cout << '|';
  std::cout <<  std::setfill(' ') << "avg" << std::setw(6);
  std::cout << '|';
  std::cout <<  std::setfill(' ') << "debt" << std::setw(15);
  std::cout << '|';
  std::cout << std::endl;

  // SECOND STRING
  std::cout << '|';
  std::cout <<  std::setfill('-') << std::setw(15);
  std::cout << '|';
  std::cout <<  std::setfill('-') << std::setw(8);
  std::cout << '|';
  std::cout <<  std::setfill('-') << std::setw(6);
  std::cout << '|';
  std::cout <<  std::setfill('-') << std::setw(15);
  std::cout << '|';
  std::cout << std::endl;

  // LAST STRINGS
  for(const auto& student : students)
  {
    // deteminedType<std::string> det_name(std::any_cast<std::string>(student.Name));
    // deteminedType<std::vector<std::string>> det_debt(std::any_cast<std::vector<std::string>>(student.Debt);
    // Здесь же проверить на все возможные типы, и просто перегрузить вывод для detType
    // после этого выводить detType
    // Можно ли проще?


    // TOP STRING
    std::cout << '|' << std::setfill(' ') << student.Name
              << std::setw(15) << '|';
    std::cout << std::setfill(' ') << student.Group
              << std::setw(8) << '|';
    std::cout << std::setfill(' ') << student.Avg
              << std::setw(6) << '|';
    int totalDebtSize = 0;
    for (const auto& debt : student.Debt) totalDebtSize += static_cast<int>(debt.size()) + 1;
    totalDebtSize--;

    if (totalDebtSize > 15)
    {
      std::cout << std::setfill(' ') << std::setw(15)
                << student.Debt.size() << " items" << '|';
    }
    else
    {
      std::string debtString;
      for (const auto& debt : student.Debt)
      {
        debtString += debt;
      }
      std::cout << std::setfill(' ') << debtString << std::setw(15)
      << '|';
    }
    std::cout << std::endl;

    // BOTTOM STRING
    std::cout << '|';
    std::cout <<  std::setfill('-') << std::setw(15);
    std::cout << '|';
    std::cout <<  std::setfill('-') << std::setw(8);
    std::cout << '|';
    std::cout <<  std::setfill('-') << std::setw(6);
    std::cout << '|';
    std::cout <<  std::setfill('-') << std::setw(15);
    std::cout << '|';
    std::cout << std::endl;

  }
}


