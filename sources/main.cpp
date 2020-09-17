//
// Created by perfest on 18.09.2020.
//
#include "parser_printer.hpp"

int main(int argc, char* argv[])
{
  if (argc > 2)
  {
    std::cout << "Too many arguments" << std::endl;
    return 1;
  }
  if (argc == 1)
  {
    std::cout << "You need to enter a name of file" << std::endl;
    return 2;
  }
  std::vector<Student> students;
  students = PARSER(argv[1]);

  PRINTER(students);

  return 0;
}
