// WikiFunctionTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("GD.txt");

    ofstream out("out.txt");

    string line;

    if (file.is_open() && out.is_open()) {
        while (getline(file, line)) {
            auto pos = line.find_first_of(',');

            auto col0 = line.substr(0, pos);

            auto col1 = line.substr(pos + 1);

            pos = col1.find('(');

            auto funcName = col1.substr(0, pos);

            auto params = col1.substr(pos);

            auto s = "|-\n|" + col0 + "\n" + "|[[#" + funcName + "|" + funcName + "]]" + params + "\n";

            out << s;
        }
        
        file.close();

        out.close();
    } else {
        cout << "Unable to open file.";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
