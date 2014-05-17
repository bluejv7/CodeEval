#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
            // Do something here
        }
    }

    return 0;
}
