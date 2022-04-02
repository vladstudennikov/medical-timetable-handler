# medical-timetable-handler
Simple C++ project for proccesing CSV files (tables) with medical schedule. 
Program can import data to the program, output it on a screen and change timetable if necessary.

All CSV files contain the doctor's timetable for all working days of the week.
If at this exact time doctor does not have any work - status for this time will be "no", else the status would be "yes".

To manipulate with menu use 2 keys - 'w' - to go up, 's' - do go down.
CPP file exports the timetable for chosen day to the special class of the program. 
This class contains 2 arrays - with time and statuses for each time.

When you choose time, the program will output the timetable fot this day on a screen.
Then, if you choose exact time by pressing 'a' - you can change its status.
To go back for choosing day - press 'b'.
To export timetable to the CSV file - press 'x' after choosing day and time.
To exit the program - press 'e'.

Notes:
- You can change CSV files, but without adding new fields to it.
- The program will work only on Windows OS.

Things to change in future:
- Add more functions
- Add the ability to change the number of fields in CSV file
- Make the history of changes
- Add simple GUI
