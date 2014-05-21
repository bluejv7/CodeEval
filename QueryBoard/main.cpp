#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int board[256][256];
void query_board(string);
vector<string> split(char, string);
void print_board();

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
            query_board(lineBuffer);
        }
    }

    return 0;
}

void query_board(string line)
{
    vector<string> query = split(' ', line);
    if (query.empty()) return;

    if (query[0] == "SetRow")
    {
        size_t row = atoi(query[1].c_str());
        unsigned value = atoi(query[2].c_str());

        for (size_t i = 0; i < 256; i++)
        {
            board[row][i] = value;
        }
    }
    else if (query[0] == "SetCol")
    {
        size_t col = atoi(query[1].c_str());
        unsigned value = atoi(query[2].c_str());

        for (size_t i = 0; i < 256; i++)
        {
            board[i][col] = value;
        }
    }
    else if (query[0] == "QueryRow")
    {
        size_t row = atoi(query[1].c_str());
        unsigned value = 0;

        for (size_t i = 0; i < 256; i++)
        {
            value += board[row][i];
        }
        cout << value << endl;
    }
    else if (query[0] == "QueryCol")
    {
        size_t col = atoi(query[1].c_str());
        unsigned value = 0;

        for (size_t i = 0; i < 256; i++)
        {
            value += board[i][col];
        }
        cout << value << endl;
    }
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

void print_board()
{
    for (size_t i = 0; i < 256; i++)
    {
        for (size_t j = 0; j < 256; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
