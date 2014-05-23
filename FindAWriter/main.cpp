#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<string> split(char, string);
void find_a_writer(string);

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
            find_a_writer(lineBuffer);
        }
    }

    return 0;
}

void find_a_writer(string line)
{
    vector<string> args = split('|', line);
    string enc_text = args[0];
    string key_text = args[1];
    if (key_text[0] == ' ')
    {
        key_text = key_text.substr(1);
    }
    vector<string> keys = split(' ', key_text);
    for (size_t i = 0; i < keys.size(); i++)
    {
        cout << enc_text[atoi(keys[i].c_str())-1];
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
