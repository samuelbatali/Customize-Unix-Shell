#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Split a string at the provided delimeter
// Store each word in a vector of strings
std::vector<std::string> split(const std::string &s, char delim = ' ')
{
    std::stringstream iss(s); // using stringstream to split.
    std::string element;

    std::vector<std::string> result;

    // adding elements into the results vector
    while (getline(iss, element, delim))
        result.push_back(element);

    return result;
}

// Overloading the output operator
// to print vector like a normal data type
template <class T>
std::ostream &operator<<(std::ostream &out, std::vector<T> vec)
{
    out << '{'; // keep values (comma and space separated) in curly braces

    // Input all vector values into output stream with comma and space separation
    for (int i = 0; i < vec.size() - 1; ++i)
        out << vec[i] << ", ";

    // Return output stream with last value and closing curly brace
    return (vec.size() > 0) ? out << vec[vec.size() - 1] << '}' : out << '}';
}

// File processing: Read files and insert read lines to a vector of strings
// Parameters: string vector reference, and a files path
std::vector<std::string> file_getContent(const std::string file_path)
{
    // Open File
    std::ifstream file;
    file.open(file_path);

    std::vector<std::string> file_content;

    // Read each line from files and store in vector
    std::string line;
    if (file)
    { // End at EOF
        while (file)
        { // Read file line by line
            getline(file, line);
            // Store file line strings in a vector
            file_content.push_back(line);
        }
    }
    // File not opened successfully
    else
        file_content.push_back("Error");
    return file_content;

    /*
        Other thoughts:
        1. Maximum length of a string
    */
}