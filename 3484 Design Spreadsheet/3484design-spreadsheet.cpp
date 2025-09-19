class Spreadsheet {
private:
    unordered_map<string,int> mp;
public:
    Spreadsheet(int rows) {
        // maybe store rows if needed, but not strictly necessary with hash approach
    }

    void setCell(string cell, int value) {
        mp[cell] = value;
    }

    void resetCell(string cell) {
        mp.erase(cell);
    }

    int getValue(string formula) {
        // formula is like "=X+Y"
        string s = formula.substr(1);  // remove '='
        int plusPos = s.find('+');
        string left = s.substr(0, plusPos);
        string right = s.substr(plusPos + 1);

        return getOperandValue(left) + getOperandValue(right);
    }

    int getOperandValue(const string &t) {
        if (isdigit(t[0])) {
            return stoi(t);
        } else {
            // it's a cell
            if (mp.find(t) != mp.end()) return mp[t];
            else return 0;
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */