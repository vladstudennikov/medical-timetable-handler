#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;
class counter {
public:
    int i = 1;
    void print_menu_main();
};

void counter::print_menu_main() {
    if (i == 1) {
        cout << "===============================================================\n";
        cout.width(40);
        cout << "Doctor's timetable\n";
        cout << "===============================================================\n\n";
        cout << ">>Monday<<\nTuesday\nWednesday\nThursday\nFriday\n";
    }
    else if (i == 2) {
        cout << "===============================================================\n";
        cout.width(40);
        cout << "Doctor's timetable\n";
        cout << "===============================================================\n";
        cout << "Monday\n>>Tuesday<<\nWednesday\nThursday\nFriday\n";
    }
    else if (i == 3) {
        cout << "===============================================================\n";
        cout.width(40);
        cout << "Doctor's timetable\n";
        cout << "===============================================================\n";
        cout << "Monday\nTuesday\n>>Wednesday<<\nThursday\nFriday\n";
    }
    else if (i == 4) {
        cout << "===============================================================\n";
        cout.width(40);
        cout << "Doctor's timetable\n";
        cout << "===============================================================\n";
        cout << "Monday\nTuesday\nWednesday\n>>Thursday<<\nFriday\n";
    }
    else if (i == 5) {
        cout << "===============================================================\n";
        cout.width(40);
        cout << "Doctor's timetable\n";
        cout << "===============================================================\n";
        cout << "Monday\nTuesday\nWednesday\nThursday\n>>Friday<<\n";
    }
}

//array time - time when doctor works
//array_status - is doctor busy at this time or not
class timetable {
    string array_status[21];
public:
    string array_time[21];
    void import_timetable(const char* filename);
    void print_timetable(counter c);
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
void timetable::print_timetable(counter c) {
    cout << "\n===============================================================\n\n";
    cout << "There is a timetable for this day.\nYou can choose the time to change it's status by pressing 'a'\nTo export timetable press 'x'\n";
    cout << "To exit - press 'e'\nTo return back - press 'b'\n\n";
    for (int i = 0; i < 20; i++) 
    {
        if (i == c.i) {
            cout << ">>" << array_time[i] << "\t" << array_status[i] << "<<" << '\n';
        }
        else {
            cout << array_time[i] << '\t' << array_status[i] << '\n';
        }
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

int main() {
    setlocale(LC_ALL, "rus");

    timetable t;
    const char* filename[5] = { "Monday.csv", "Tuesday.csv", "Wednesday.csv", "Thursday.csv", "Friday.csv" };
    string days[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
choose_one: 
    system("cls");
    counter iter;
    iter.print_menu_main();

    while (true) {
        char c = _getch();
        system("cls");
        if (c == 'w') {
            if (iter.i == 0) {
                iter.i = 4;
                iter.print_menu_main();
            }
            else {
                --(iter.i);
                iter.print_menu_main();
            }
        }
        if (c == 's') {
            if (iter.i == 5) {
                iter.i = 1;
                iter.print_menu_main();
            }
            else {
                ++(iter.i);
                iter.print_menu_main();
            }
        }
        if (c == 'a') {
            break;
        }
        if (c != 'a' && c != 'w' && c != 's') {
            iter.print_menu_main();
        }
    }
    int day_number = iter.i - 1;
    iter.i = 0;

    system("cls");
    t.import_timetable(filename[day_number]);
    
    do {
        system("cls");
        cout << "Chosen day:\t" << days[day_number];
        t.print_timetable(iter);
        char c = _getch();

        if (c == 'w') {
            if (iter.i == 0) {
                iter.i = 19;
            }
            else {
                --(iter.i);
            }
        }
        if (c == 's') {
            if (iter.i == 19) {
                iter.i = 0;
            }
            else {
                ++(iter.i);
            }
        }
        if (c == 'a') {
            cout << "\nChanged status for time " << t.array_time[iter.i] << '\n';
            t.change_status_of_time(t.array_time[iter.i]);
            _getch();
        }
        if (c == 'x') {
            t.export_timetable(filename[day_number]);
        }
        if (c == 'e') {
            break;
        }
        if (c == 'b') {
            goto choose_one;
        }
        if (c != 'a' && c != 'w' && c != 's' && c != 'x') {
            continue;
        }
    } while (true);
}

