#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<string> split(char, string);
void swap_elements(string);

int main(int argc, char** argv)
{
    ifstream file;
    file.open(argv[1]);
    while (!file.eof()) 
    {
        string lineBuffer;
        getline(file, lineBuffer);
        if (lineBuffer.length() == 0)
        {
            continue; //ignore all empty lines
        }
        else 
        {
            swap_elements(lineBuffer);
        }
    }

    return 0;
}

void swap_elements(string line)
{
    vector<string> args = split(' ', line);
    vector<int> numbers;
    size_t colon_index = 0;

    // Put all the elements into a vector
    for (size_t i = 0; i < args.size(); i++)
    {
        if (args[i] == ":")
        {
            colon_index = i;
            break;
        }
        numbers.push_back(atoi(args[i].c_str()));
    }

    // swap elements
    for (size_t i = colon_index + 1; i < args.size(); i++)
    {
        string current_arg = args[i];
        // if there is a comma at the end, parse it out
        if (current_arg[current_arg.size()-1] == ',')
        {
            current_arg = current_arg.substr(0, current_arg.size()-1);
        }
        
        vector<string> swap = split('-', args[i]);
        size_t first_index = atoi(swap[0].c_str());
        size_t second_index = atoi(swap[1].c_str());
        int temp_value = numbers[first_index];
        numbers[first_index] = numbers[second_index];
        numbers[second_index] = temp_value;
    }

    // Now print!  =)
    for (size_t i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

vector<string> split(char delim, string s)
{
    vector<string> result;
    size_t start_index = 0;

    // Set start_index after leading delims
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == delim)
        {
            start_index = i+1;
        }
        else
        {
            break;
        }
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        // skip ending delim; otherwise if matching delim/end of string, add to result
        if (s[i] == delim && i == s.size() - 1)
        {
        }
        else if (s[i] == delim)
        {
            unsigned substr_size = i - start_index;
            result.push_back(s.substr(start_index, substr_size));
            start_index = i + 1;
        }
        else if (i == s.size() - 1)
        {
            result.push_back(s.substr(start_index));
        }
    }

    return result;
}
