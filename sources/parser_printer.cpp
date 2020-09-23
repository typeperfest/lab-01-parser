// Copyright 2018 Your Name <your_email>

#include "parser_printer.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <nlohmann/json.hpp>
#include <string>


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
    //NAME
    currentStudent.Name = student.at("name");
    //END_NAME

    //GROUP
    if (student.at("group").is_string())
    {
      currentStudent.Group = static_cast<std::string>(student.at("group"));
    }
    else if(student.at("group").is_number_integer())
    {
      currentStudent.Group = static_cast<int>(student.at("group"));
    }
    //END_GROUP

    // AVG
    if (student.at("avg").is_string()) {
      std::size_t offset = 0;
      std::string avgScoreRead = student.at("avg");
      currentStudent.Avg = std::stod(avgScoreRead, &offset);
    }
    else if (student.at("avg").is_number_integer())
    {
      currentStudent.Avg = static_cast<float>(student.at("avg"));
    }
    else if (student.at("avg").is_number_float())
    {
      currentStudent.Avg = student.at("avg");
    }
    // END_AVG

    // DEBT
    if(student.at("debt").is_string())
    {
      currentStudent.Debt = static_cast<std::string>(student.at("debt"));
    }
    else if (student.at("debt").is_array())
    {
      currentStudent.Debt =
          static_cast<std::vector<std::string>>(student.at("debt"));
    }
    else if (student.at("debt").is_null())
    {
      bool Flag = false;
      currentStudent.Debt = Flag;
    }
    // END_DEBT

    // student.at("name").get_to(currentStudent.Name);
    // student.at("group").get_to(currentStudent.Group);
    // student.at("avg").get_to(currentStudent.Avg);
    // student.at("debt").get_to(currentStudent.Debt);
    students.push_back(currentStudent);
  }
  return students;
}

std::string print_any(const std::any& object)
{
  std::string out_str;
  if (object.type() == typeid(std::string))
  {
    out_str = std::any_cast<std::string>(object);
  }
  else if (object.type() == typeid(int))
  {
    out_str = std::any_cast<int>(object);
  }
  else if (object.type() == typeid(float))
  {
    out_str = std::any_cast<float>(object);
  }
  else if (object.type() == typeid(std::vector<std::string>))
  {
    std::vector<std::string> str_vec = std::any_cast<std::vector<std::string>>(object);
    int size = str_vec.size();
    if (size > 1)
    {
      out_str = std::to_string(size) + " items";
    }
    else if (size == 1)
    {
      out_str = str_vec[0];
    }
  }
  else if (object.type() == typeid(bool))
  {
    out_str = "null";
  }
  else
  {
    std::bad_cast ex;
    throw ex;
  }
  return out_str;
}

void PRINTER(const std::vector<Student>& students)
{
  // FIRST STRING
  std::cout << '|';
  std::cout <<  std::setfill(' ') << " name" << std::setw(11);
  std::cout << '|';
  std::cout <<  std::setfill(' ') << " group" << std::setw(3);
  std::cout << '|';
  std::cout <<  std::setfill(' ') << " avg" << std::setw(3);
  std::cout << '|';
  std::cout <<  std::setfill(' ') << " debt" << std::setw(11);
  std::cout << '|';
  std::cout << std::endl;

  // SECOND STRING
  std::cout << '|';
  std::cout <<  std::setfill('-') << std::setw(16);
  std::cout << '|';
  std::cout <<  std::setfill('-') << std::setw(9);
  std::cout << '|';
  std::cout <<  std::setfill('-') << std::setw(7);
  std::cout << '|';
  std::cout <<  std::setfill('-') << std::setw(16);
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
    std::cout << '|' << ' ' << std::setfill(' ') << std::left << std::setw(14) << student.Name
              << '|' << ' ';
    std::cout << std::setfill(' ') << std::setw(7) << print_any(student.Group)
              << '|' << ' ';
    std::cout << std::setfill(' ') << std::setw(5) << student.Avg
              << '|' << ' ';
    std::cout << std::setfill(' ') << std::setw(14) << print_any(student.Debt)
              << '|';
    std::cout << std::endl;

    // BOTTOM STRING
    std::cout << '|';
    std::cout <<  std::setfill('-') << std::right << std::setw(16);
    std::cout << '|';
    std::cout <<  std::setfill('-') << std::setw(9);
    std::cout << '|';
    std::cout <<  std::setfill('-') << std::setw(7);
    std::cout << '|';
    std::cout <<  std::setfill('-') << std::setw(16);
    std::cout << '|';
    std::cout << std::endl;

  }
}


