#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//array time - time when doctor works
//array_status - is doctor busy at this time or not
class timetable {
    string array_time[21];
    string array_status[21];
public:
    void import_timetable(const char* filename);
    void print_timetable();
    void change_status_of_time(string stime);
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

void timetable::change_status_of_time(string stime) {
    for (int i = 0; i < 20; i++) {
        if (array_time[i] == stime) {
            cout << "Status for this time:\t" << array_status[i];
            if (array_status[i] == "yes") {
                array_status[i] = "no";
            }
            else {
                array_status[i] = "yes";
            }
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

void print_main_menu() {
    cout << "===============================================================";
    cout << "\n\t\t\tDoctor's timetable\n";
    cout << "===============================================================\n";
    cout << "\n\t\t\tChoose the day:\n\n";
    cout << "1 - Monday\n2 - Tuesday\n3 - Wednesday\n4 - Thursday\n5 - Friday\n\n";
}

void print_day_menu() {
    cout << "\n\n===============================================================\n\n";
    cout << "1 - Print timetable\n2 - Change status for the time\n3 - Export timetable\n4 - Goto main menu\n\n";
}

int main() {
    setlocale(LC_ALL, "rus");

    timetable t;
    const char* filename[5] = { "Monday.csv", "Tuesday.csv", "Wednesday.csv", "Thursday.csv", "Friday.csv" };
    string days[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
choose_one: print_main_menu();
    int function;
    cin >> function;
    if (function < 6) {
        t.import_timetable(filename[function - 1]);
    }
    else {
        cout << "\nChoose another time\n\n";
        goto choose_one;
    }
    cout << "\nChosen day:\t" << days[function - 1];
    do {
        print_day_menu();
        int function_day = 0;
        cin >> function_day;
        if (function_day == 1) {
            t.print_timetable();
        }
        if (function_day == 2) {
            string time_change;
            cout << "\n\nChoose the time to change:\n\n";
            getline(cin, time_change);
            getline(cin, time_change);
            t.change_status_of_time(time_change);
        }
        if (function_day == 3) {
            cout << "\n\nExporting timetable...\n\n";
            t.export_timetable(filename[function - 1]);
        }
        if (function_day == 4) {
            goto choose_one;
        }
    } while (1);
}

