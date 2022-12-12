RelationalTable::RelationalTable(double loadThreshold) : loadThreshold(loadThreshold) {
    capacity = 8;
    rows.resize(capacity);
}

RelationalTable::RelationalTable(const string attNames[], int size, double loadThreshold) : loadThreshold(loadThreshold) {
    capacity = 8;
    rows.resize(capacity);
    for (int i = 0; i < size; i++){
        fieldNames.push_back(attNames[i]);
        for(int j = 0; j < capacity; j++)
            rows[j].second.push_back("\0");
    }
    
}

void RelationalTable::addRow(const string values[], int size) {
    unsigned int myHash = hash<string>{}(values[0]) & (capacity - 1);
    int val_iterator = 0;
    if (getSize() + 1 >= capacity * loadThreshold) {
        vector<pair<string, vector<string>>> swap = rows;
        rows.clear();
        capacity *= 2;
        rows.resize(capacity);
        for (auto i = swap.begin(); i != swap.end(); i++) {
            if (!(i->second.empty() || i->second[0] == "\0") ) {
                string* current_row = new string[size];
                for (auto j = i->second.begin(); j != i->second.end(); j++, val_iterator++) {
                    current_row[val_iterator] = *j;
                }
                val_iterator = 0;
                //addRow(current_row, size); Seems to be causing the error
                delete[] current_row;
            }
        }
    }

    if (rows[myHash].first == values[0] && !(rows[myHash].second.empty() || rows[myHash].second[0] == "\0"))
        return;

    int quad_collider = 0;
    bool hashing = true;
    unsigned int newHash = myHash;
    while (hashing) {
        newHash = (newHash + quad_collider*quad_collider) % capacity;
        
        if (rows[newHash].second.empty() || rows[newHash].second[0] == "\0") {
            rows[newHash].first = values[0];            
            for (val_iterator = 0; val_iterator < size; val_iterator++) {
                rows[newHash].second[val_iterator] = values[val_iterator];
            }
                
            hashing = false;
        }

        quad_collider++;
    }
}

vector<string> RelationalTable::removeRow(const string& pkValue) {
    vector<string> output;
    for (auto i = rows.begin(); i != rows.end(); i++) {
        if (i->first == pkValue) {
            output = i->second;
            i->second.clear();
        }
    }
    return output;
}

void RelationalTable::setValue(const string& pkValue, const string& fieldName, const string& fieldValue) {
    unsigned int newHash = hash<string>{}(pkValue) & (capacity - 1);
    bool hashing = true;
    int quad_collider = 0;
    /*
    invalid_argument noKeyErr("Key does not exist");
    if (rows.empty())
        throw noKeyErr;*/
    while (hashing) {
        newHash = (newHash + quad_collider*quad_collider) % capacity;

        if (rows[newHash].first == pkValue) {            
            auto j = fieldNames.begin();

            for (auto i = rows[newHash].second.begin(); i != rows[newHash].second.end(); i++, j++)
                if (*j == fieldName)
                    *i = fieldValue;
            hashing = false;
        }
        quad_collider++;
    }
    return;
}

string RelationalTable::getValue(const string& pkValue, const string& fieldName) {
    unsigned int newHash = hash<string>{}(pkValue) & (capacity - 1);
    bool hashing = true;
    int quad_collider = 0;
    string output;
    /*
    invalid_argument emptyKeyErr("No values found");
    if (rows.empty())
        throw emptyKeyErr;*/
    while (hashing) {
        newHash = (newHash + quad_collider*quad_collider) % capacity;

        if (rows[newHash].first == pkValue) {
            auto j = fieldNames.begin();
            for (auto i = rows[newHash].second.begin(); i != rows[newHash].second.end(); i++, j++) {
                if (*j == fieldName)
                    output = *i;
            }
                
            hashing = false;
        }
        quad_collider++;
    }
    return output;
}

void RelationalTable::addField(const string& fieldName) {
    /*
    invalid_argument err("Field name already exists.");
    for (auto i = fieldNames.begin(); i != fieldNames.end(); i++)
        if (*i == fieldName)
            throw(err);*/
    fieldNames.push_back(fieldName);
    for (auto i = rows.begin(); i != rows.end(); i++)
        i->second.push_back("\0");
}

void RelationalTable::removeField(const string& fieldName) {
    /*
    invalid_argument err("Field name already exists.");*/
    bool exists = false;
    int count = 0;
    for (auto i = fieldNames.begin(); i != fieldNames.end(); i++, count++) {
        if (*i == fieldName) {
            exists = true;
            fieldNames.erase(i);
        }
    }/*
    if (!exists)
        throw(err);*/
    fieldNames.push_back(fieldName);
    for (auto i = rows.begin(); i != rows.end(); i++) {
        auto j = i->second.begin() + count;
        i->second.erase(j);
    }
}

int RelationalTable::getSize() {
    int sum = 0;
    for (auto i = rows.begin(); i != rows.end(); i++) {
        if (!(i->second.empty() || i->second[0] == "\0"))
            sum++;
    }
    return sum;
}
