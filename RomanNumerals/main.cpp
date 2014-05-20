#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void roman_numerals(string);

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
            roman_numerals(lineBuffer);
        }
    }

    return 0;
}

void roman_numerals(string line)
{
    int number = atoi(line.c_str());

    // IVXLCDM -> 1, 5, 10, 50, 100, 500, 1000
    char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int numeral_vals[] = {1, 5, 10, 50, 100, 500, 1000};

    for (int i = sizeof(numerals) - 1; i >= 0; i--)
    {
        int num_numerals = number / numeral_vals[i];

        // special case for 4, 40, 400; sc 9, 90, 900; regular case
        if (i % 2 == 0 && numeral_vals[i] * 4 <= number && numerals[i] != 'M')
        {
            cout << numerals[i] << numerals[i+1];
            number -= numeral_vals[i+1] - numeral_vals[i];
        }
        else if (i % 2 == 1 && numeral_vals[i] + numeral_vals[i-1]*4 <= number)
        {
            cout << numerals[i-1] << numerals[i+1];
            number -= numeral_vals[i+1] - numeral_vals[i-1];
        }
        else
        {
            for (int j = 0; j < num_numerals; j++) cout << numerals[i];
            number -= num_numerals * numeral_vals[i];
        }
    }
    cout << endl;
}
