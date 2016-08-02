cmake_minimum_required(VERSION 3.2)

project(DynamicTextSearch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    TextSearch.cpp TextSearch.h
    naive.cpp naive.h
    KnuthMorrisPratt.cpp KnuthMorrisPratt.h)

add_executable(DynamicTextSearch ${SOURCE_FILES})

#add_subdirectory( googletest )

#find_package(GTest REQUIRED)
#INCLUDE_DIRECTORIES(googletest/googletest/include)
#TARGET_LINK_LIBRARIES(GoogleTest lib)


include(ExternalProject)
ExternalProject_Add(gtest
        URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        INSTALL_COMMAND ""
        )
ExternalProject_Get_Property(gtest source_dir binary_dir)

################
# Define a test
add_executable(textsearch_test tests.cpp)

######################################
# Configure the test to use GoogleTest
add_dependencies(textsearch_test gtest)
include_directories(${source_dir}/include)
target_link_libraries(textsearch_test ${binary_dir}/libgtest.a)
target_link_libraries(textsearch_test ${binary_dir}/libgtest_main.a)

##################################
# Just make the test runnable with
#   $ make test
enable_testing()
add_test(NAME   textsearch_test
        COMMAND textsearch_test)