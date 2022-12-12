#ifndef RELATIONALTABLE_H
#define RELATIONALTABLE_H

#include <string>
#include <vector> 
#include <functional>

using namespace std;

class RelationalTable {
public:
    RelationalTable(double loadThreshold = 0.5);
    RelationalTable(const string[], int, double loadThreshold = 0.5);
    void addRow(const string[], int);
    vector<string> removeRow(const string&);
    void setValue(const string&, const string&, const string&);
    string getValue(const string&, const string&);
    void addField(const string&);
    void removeField(const string&);
    int getSize();
private:
    vector<string> fieldNames;
    vector<pair<string, vector<string>>> rows;
    int capacity;
    const double loadThreshold;
};
#include "RelationalTable.cpp.h"
#endif
