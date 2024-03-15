cmake_minimum_required(VERSION 3.25)
project(rational)

set(CMAKE_CXX_STANDARD 23)

add_executable(rational main.cpp rational/rational.cpp rational/rational.h "operators/multiplication/multiplication.cpp" "operators/multiplication/multiplication.h" operators/addition/addition.cpp operators/addition/addition.h operators/division/division.cpp operators/division/division.h operators/subtraction/subtraction.cpp operators/subtraction/subtraction.h operators/logical/logic.cpp operators/logical/logic.h operators/assignment/assign.cpp operators/assignment/assign.h "operators/in n out/in n out.h" "operators/in n out/in n out.cpp" "operators/incriment n decriment/incriment n decriment.h" "operators/incriment n decriment/incriment n decriment.cpp" operators/factorial/factorial.h operators/factorial/factorial.cpp operators/factorial/factorial.cpp operators/factorial/factorial.h vector/vector.cpp vector/vector.h)
