// RelationalTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "RelationalTable.h"
int main()
{
    string example[] = { "ExampleStudent","Testing"};
    string secondExample[] = { "Student","NextTest","ExampleValue"};
    string secondValues[] = { "ExampleStudent","NextTest","ExampleValue" };
    string test = "Test";
    string value = "TestValue";
    try {
RelationalTable r1 = RelationalTable();
    cout << "Created table." << endl;
    cout << "Table size is: "<<r1.getSize()<<endl;
    r1.addField("Student");
    r1.addField("Name");
    cout << "Added fields to table" << endl;
    r1.addRow(example,example->size());
    cout << "Added row to table" << endl;
    cout << r1.getValue(example[0], "Name") << endl;
    cout << r1.getValue(example[0], "Student") << endl;
    r1.setValue(example[0], test, value);
    cout << r1.getValue(example[0], test) << endl;
    RelationalTable r2 = RelationalTable(secondExample,3);
    cout << "Table size is: " << r2.getSize() << endl;
    r2.addRow(secondExample, secondExample->size());
    cout << r2.getValue(secondValues[0], "NextTest") << endl;
    }
    catch (...) {
        cout << "An error occurred" << endl;
    }
    return 0;
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
