// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_


#include <iostream>
#include <vector>
#include "student.h"

std::vector<Student> PARSER(const std::string& fileName);
void PRINTER(const std::vector<Student>& students);

#endif // INCLUDE_HEADER_HPP_
