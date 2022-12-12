// RelataionalTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "RelationalTable.h"
int main()
{
    cout << (0^2) << endl;
    string example[] = { "ExampleStudent","Testing"};
    string secondExample[] = { "Student","NextTest","Value"};
    string secondValues[] = { "ExampleStudent","ExampleTest","ExampleValue" };
    string test = "Test";
    string value = "TestValue";
    try {
    RelationalTable r1 = RelationalTable();
    cout << "Created table." << endl;
    cout << "Table size is: "<<r1.getSize()<<endl;
    r1.addField("Student");
    r1.addField("Name");
    cout << "Added fields to table" << endl;
    r1.addRow(example,2);
    cout << "Added row to table" << endl;
    cout << r1.getValue(example[0], test) << endl;
    r1.setValue(example[0], test, value);
    cout << r1.getValue(example[0], test) << endl;
    RelationalTable r2 = RelationalTable(secondExample,3);
    cout << "Table size is: " << r2.getSize() << endl;
    r2.addRow(secondValues,3);
    cout << r2.getValue(secondValues[0], "NextTest") << endl;
    }
    catch (invalid_argument err) {
        cout << err.what() << endl;
    }
    
}
