// Copyright 2018 Your Name <your_email>

#include "parser_printer.hpp"

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>

std::vector<Student> PARSER(const std::string& fileName)
{
  namespace fs = std::filesystem;
  if(!fs::exists(fs::status(fileName)))
  {
    std::cout << "There is no such file with that name"
              << std::endl;
    throw std::runtime_error("file isn't exist");
  }

  using json = nlohmann::json;
  std::ifstream file(fileName);
  json data;
  file >> data;

  std::vector<Student> students;
  for (const auto& student : data.at("items")) {
    Student currentStudent;
    student.at("name").get_to(currentStudent.Name);
    student.at("group").get_to(currentStudent.Group);
    student.at("avg").get_to(currentStudent.Avg);
    student.at("debt").get_to(currentStudent.Debt);
    students.push_back(currentStudent);
  }
  return students;
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


