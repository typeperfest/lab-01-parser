# CMake generated Testfile for 
# Source directory: /home/perfest/AL_LABS/lab-01-parser-test
# Build directory: /home/perfest/AL_LABS/lab-01-parser-test/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unit_tests "/home/perfest/AL_LABS/lab-01-parser-test/cmake-build-debug/tests")
set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/perfest/AL_LABS/lab-01-parser-test/CMakeLists.txt;52;add_test;/home/perfest/AL_LABS/lab-01-parser-test/CMakeLists.txt;0;")
subdirs("third_party/gtest")
