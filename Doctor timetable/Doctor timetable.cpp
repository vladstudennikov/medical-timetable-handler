#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void output_timetable() {
    ifstream file("Test_file.csv");
    string time_part, status;
    while (file.good()) {
        getline(file, time_part, ';');
        getline(file, status, '\n');

        cout << time_part;
        cout.setf(ios::right);    cout.width(20);
        cout << status << endl;
    }

    cout << '\n';
    file.close();
}

void output_freetime() {
    ifstream file("Test_file.csv");
    string time_part, status;
    cout << "\nFree times:\n\n";
    while (file.good()) {
        getline(file, time_part, ';');
        getline(file, status, '\n');

        if (status == "no") {
            cout << time_part << '\n';
        }
        else {
            continue;
        }
    }

    cout << '\n';
    file.close();
}

void choose_time() {
    ifstream file("Test_file.csv");
    string time_part, status;
    cout << "\nChoose the time\n";
    string searched_time;
    cin >> searched_time;
    while (file.good()) {
        getline(file, time_part, ';');
        getline(file, status, '\n');

        if (time_part == searched_time) {
            cout << status;
        }
        else {
            continue;
        }
    }

    cout << '\n';
    file.close();
}

int main(){
    setlocale(LC_ALL, "rus");

choosing: 
    int action;
    string time_part, status;
    cout << "1 - output all doctor's timetable\n2 - output doctor's freetime\n3 - choose the time part\n\n";
    cin >> action;
    if (action == 1) {
        output_timetable();
        goto choosing;
    }
    else if (action == 2) {
        output_freetime();
        goto choosing;
    }
    else if (action == 3) {
        choose_time();
        goto choosing;
    }
    else {
        cout << "Choose the number 1 - 3\n";
        goto choosing;
    }

    ofstream a;
    a.open("Test_file.csv");
    if (a.is_open())  cout << "File is opened";
    if (!a.is_open())   cout << "File is not opened";
}

