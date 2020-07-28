//
// Created by Samuel Batali
//

#ifndef CPPFunctions_h
#define CPPFunctions_h

// Splits a string into words tokens
std::vector<std::string> split_string(const std::string &s, char delim = ' ');

// Read data from a csv file
std::vector<std::vector<std::string>> read_csv(std::string filename);

// Write data into a csv file
void write_csv(
    std::vector<std::vector<std::string>> &data,
    std::string filename,
    std::size_t headers_row = 0);

// Search some keywords from a csv file
std::vector<std::pair<std::string, int>> search_csv_file(
    std::string filename,
    std::vector<std::string> &keywords);

// Converts a vector string to C string array (char**)
char **create_cString_array(std::vector<std::string> &vec);
// Delete memory for char**
void delete_cString_array(char **arr, size_t length);

#endif