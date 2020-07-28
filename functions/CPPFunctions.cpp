//
// Created by Samuel Batali
//
#include <iostream>
#include <vector>
#include <sstream>

#include "CPPFunctions.hpp"

std::vector<std::string> split_string(const std::string &s, char delim)
{
    // Split a string at the provided delimeter
    // Store each word in a vector of strings

    std::stringstream iss(s); // using stringstream to split.
    std::string element;

    std::vector<std::string> result;

    // adding elements into the results vector
    while (getline(iss, element, delim))
        result.push_back(element);

    return result;
}

std::vector<std::vector<std::string>> read_csv(std::string filename)
{
    // Given a filename of a CSV file
    // Read each line of the CSV file and store the results in a vector
    // containing vector of strings representing values of each column
    // The first line of the return vector<vector<string>> contains the column header names

    std::vector<std::vector<std::string>> data;
    return data;
}

void write_csv(
    std::vector<std::vector<std::string>> &data,
    std::string filename,
    std::size_t headers_row)
{
    // Given some data (vector of vector strings container values of each column in a row)
    // Write the data for each column into a CSV file with the name provided in the second argument
    // By default: first row contain the CSV columns header name
    // If not, supply the row with header names in the third argument
}

std::vector<std::pair<std::string, int>> search_csv_file(
    std::string filename,
    std::vector<std::string> &keywords)
{
    // Given a CSV file and a vector containing keywords
    // Search the CSV file to find all the occurances of each keyword
    // Return a vector of pairs
    // where each pair is a keyword and the number of occurances of the keyword in the CSV file)

    std::vector<std::pair<std::string, int>> result;
    return result;
}

char **create_cString_array(std::vector<std::string> &vec)
{
    // Converts a vector string to C string array (char**)
    char **arr = new char *[vec.size()];
    for (size_t i = 0; i < vec.size(); ++i)
    {
        arr[i] = new char[vec[i].size() + 1];
        strcpy(arr[i], vec[i].c_str());
    }
    return arr;
}

void delete_cString_array(char **arr, size_t length)
{
    // Delete memory for char**
    for (size_t i = 0; i < length; ++i)
    {
        // std::cout << arr[i] << ' ';
        delete[] arr[i];
    }
    // std::cout << '\n';
    delete[] arr;
}