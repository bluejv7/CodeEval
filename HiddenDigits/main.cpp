#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void hidden_digits(string);

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
            hidden_digits(lineBuffer);
        }
    }

    return 0;
}

void hidden_digits(string line)
{
    bool found_digit = false;

    for (unsigned i = 0; i < line.size(); i++)
    {
        if (line[i] >= 'a' && line[i] <= 'j')
        {
            unsigned digit = line[i] - 'a';
            cout << digit;
            found_digit = true;
        }
        else if (line[i] >= '0' && line[i] <= '9')
        {
            cout << line[i];
            found_digit = true;
        }
    }
    if (!found_digit)
    {
        cout << "NONE";
    }
    cout << endl;
}
