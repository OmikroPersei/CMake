# CMake generated Testfile for 
# Source directory: /home/aleksandre.novikov/Desktop/CPP
# Build directory: /home/aleksandre.novikov/Desktop/CPP/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[Test:2]=] "/home/aleksandre.novikov/Desktop/CPP/build/YETI" "2")
set_tests_properties([=[Test:2]=] PROPERTIES  PASS_REGULAR_EXPRESSION "True" _BACKTRACE_TRIPLES "/home/aleksandre.novikov/Desktop/CPP/CMakeLists.txt;27;add_test;/home/aleksandre.novikov/Desktop/CPP/CMakeLists.txt;36;make_test;/home/aleksandre.novikov/Desktop/CPP/CMakeLists.txt;0;")
add_test([=[Test:3]=] "/home/aleksandre.novikov/Desktop/CPP/build/YETI" "3")
set_tests_properties([=[Test:3]=] PROPERTIES  PASS_REGULAR_EXPRESSION "True" _BACKTRACE_TRIPLES "/home/aleksandre.novikov/Desktop/CPP/CMakeLists.txt;27;add_test;/home/aleksandre.novikov/Desktop/CPP/CMakeLists.txt;37;make_test;/home/aleksandre.novikov/Desktop/CPP/CMakeLists.txt;0;")
subdirs("config")
