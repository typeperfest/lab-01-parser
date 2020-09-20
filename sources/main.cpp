//
// Created by perfest on 18.09.2020.
//
#include "parser_printer.hpp"
#include <fstream>

#define DEBUG

// int argc, char* argv[]

int main()
{

#ifndef DEBUG
  if (argc > 2)
  {
    std::cout << "Too many arguments" << std::endl;
    exit(0);
  }
  if (argc == 1)
  {
    std::cout << "You need to enter a name of file" << std::endl;
    exit(0);
  }
    std::string fileName(argv[1]);
#endif

  std::vector<Student> students;

#ifdef DEBUG
  std::string fileName = "file.txt";
#endif

  students = PARSER(fileName);
  PRINTER(students);

  return 0;
}
