#include <string>
#include <vector>
#include <functional>
using namespace std;

class RelationalTable{
	vector<string> fieldNames;
	vector<pair<string, vector<string>>> rows;
	int capacity;
	const double loadThreshold;

	RelationalTable(double loadThreshold = 0.5);
	RelationalTable(const string attNames[], int size, double loadThreshold = 0.5);
	void addRow(const string values[], int size);
	vector<string> removeRow(const string& pkValue);
	void setValue(const string& pkValue, const string& fieldName, const string& fieldValue);
	string getValue(const string& pkVallue, const string& fieldName);
	void addField(const string& fieldName);
	void removeField(const string& fieldName);
	int getSize();
}

RelationalTable::RelationalTable(double loadThreshold = 0.5) {
	capacity = 4;
}
RelationalTable::RelationalTable(string attNames[], int size, double loadThreshold = 0.5) {
	for (int i = 0; i < size; i++) {
		fieldNames[i] = attNames[i];
		rows[i].first = hash<string>()(attNames[i]);
	}
	capacity = 4;
}
void RelationalTable::addRow(const string values[], int size) {
	if (rows.size() != size) {
		throw exception();
	}
	vector<string> temp;
	for (int i = 1; i < size; i++)
		temp.push_back(values[i]);

	rows.push_back(make_pair(hash<string>()(values[0]),temp))
	// Need to update loadthreshold here
	if (loadThreshold > 0.5)
		capacity = capacity * 2;
	
}
int RelationalTable::getSize() {
	return rows.size();
}
void RelationalTable::addField(const string& fieldname) {
	for (it = fieldNames.begin(); it != fieldNames.end(); it++) {
		if (hash<string>()(*it) == hash<string>()(fieldname))
			throw exception()
	}
	for (it = rows.begin(); it != rows.end(); it++) {
		*it.push_back(make_pair(hash<string>()(fieldname),""))
	}
}
void RelationalTable::setValue(const string& pkValue, const string& fieldName, const string& fieldValue) {

}
