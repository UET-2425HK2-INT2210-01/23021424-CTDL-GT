#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

class StudentManager {
private:
    unordered_map<int, pair<string, string>> students;

public:
    void insert(int ID, string Name, string Class) {
		students[ID] = make_pair(Name, Class);
    }

    void remove(int ID) {
        students.erase(ID);
    }

    void infor(int ID) {
        if (students.find(ID) != students.end()) {
            cout << students[ID].first << "," << students[ID].second << endl;
        } else {
            cout << "NA,NA" << endl;
        }
    }
};

int main() {
    StudentManager manager;
    string input;

    while (getline(cin, input)) {
        if (input.empty()) break;

        stringstream ss(input);
        string command, args;
        getline(ss, command, '(');
        getline(ss, args, ')');

        stringstream argStream(args);
        string part;
        int ID;
        string Name, Class;

        if (command == "Insert") {
            getline(argStream, part, ',');
            ID = stoi(part);
            getline(argStream, Name, ',');
            getline(argStream, Class, ',');
            manager.insert(ID, Name, Class);
        } 
        else if (command == "Delete") {
            getline(argStream, part, ',');
            ID = stoi(part);
            manager.remove(ID);
        } 
        else if (command == "Infor") {
            getline(argStream, part, ',');
            ID = stoi(part);
            manager.infor(ID);
        }
    }

    return 0;
}
