#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

#include "functions/CPPFunctions.hpp"
extern "C"
{
#include "functions/CFunctions.h"
#include "processes/UnixProcess.h"
}

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::vector;

int main(int argc, char const *argv[])
{

    // This is a set of commands that are unique to this shell
    // If a user enter a command out of this set, we will create a child process
    // to execute the command in the main Unix Shell
    unordered_set<string> commands = {"read", "set"};
    char *user = get_user();
    char *dirr = get_cdir();

    string dir = "";
    if (dirr != NULL)
    {
        vector<string> dirs = split_string(string(dirr), '/');
        delete[] dirr;
        string dir = dirs[dirs.size() - 1];
    }

    string input;
    cout << '<' << user << '>' << "dir::" << dir << ':';
    while (getline(cin, input) && (input != "quit" && input != "exit"))
    { // Keep the shell running until you type quit or exit

        // Tokenize the input string
        vector<string> tokens = split_string(input);
        if (!tokens.empty())
        {
            // Run commands Unique to this shell
            if (commands.find(tokens[0]) != commands.end())
            {
                if (tokens[0] == "read")
                {
                    // read commands from a file
                }
            }
            // For other commands (Fork a new process ane execute the command in the Unix shell)
            else
            {
                char **commnds = create_cString_array(tokens);
                // print_cString_array(commnds);
                process_unix_commands(commnds, 1);
                // Make sure to always free allocated memory
                delete_cString_array(commnds, tokens.size());
            }
        }
        cout << '<' << user << '>' << "dir::" << dir << ':';
    }
    return 0;
}
