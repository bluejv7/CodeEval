#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swap_case(string);

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
            swap_case(lineBuffer);
        }
    }

    return 0;
}

void swap_case(string s)
{
    // Go through all the letters in the string
    for (unsigned i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] += 'A' - 'a';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] -= 'A' - 'a';
        }
    }
    cout << s << endl;
}
