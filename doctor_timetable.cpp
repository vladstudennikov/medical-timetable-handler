#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//array time - time when doctor works
//array_status - is doctor busy at this time or not
class timetable {
    string array_time[21];
    string array_status[21];
public:
    void import_timetable(const char* filename);
    void print_timetable();
    void change_status(string stime);
    void export_timetable(const char* filename);
};

//import data from the CSV file into two arrays of the class
void timetable::import_timetable(const char* filename) {
    ifstream file;
    file.open(filename);
    if (!file.is_open())    cout << "File is NOT opened";
    string time_part, status;
    int i = 0;
    while (file.good()) {
        getline(file, time_part, ';');
        getline(file, status, '\n');

        array_time[i] = time_part;
        array_status[i] = status;
        i++;
    }
    file.close();
}

//outputting info from the class - before timetable should be imported to the program
void timetable::print_timetable() {
    cout << '\n';
    for (int i = 0; i < 20; i++) 
    {
        cout << array_time[i];
        cout.width(10);    cout.setf(ios::right);
        cout << array_status[i] << endl;
    }
}

void timetable::change_status(string stime) {
    for (int i = 0; i < 20; i++) {
        if (array_time[i] == stime) {
            cout << "Status for this time:\t" << array_status[i];
            if (array_status[i] == "yes") {
                array_status[i] = "no";
            }
            else {
                array_status[i] = "yes";
            }
            break;
        }
    }
}

void timetable::export_timetable(const char* filename) {
    ofstream file(filename);
    for (int i = 0; i < 20; i++) {
        file << array_time[i] << ';' << array_status[i] << '\n';
    }
    file.close();
}

int main() {
    setlocale(LC_ALL, "rus");

    timetable t;
    const char* filename = "Test_file.csv";
    t.import_timetable(filename);
    t.print_timetable();
    t.change_status("17:30 - 18:00");
    t.export_timetable(filename);
    t.print_timetable();
}

