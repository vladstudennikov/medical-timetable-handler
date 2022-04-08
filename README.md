# medical-timetable-handler
All CSV files contain the doctor's timetable for all working days of the week.
In both apps you can import timetable to the program, and it will output the timetable on a screen.
On a screen will be times and statuses for all of them.
If at this exact time doctor does not have any work - status for this time will be "no", else the status would be "yes".

How to work with cpp app:
Press 'a' - you to change status of time.
To go back for choosing day - press 'b'.
To export timetable to the CSV file - press 'x' after choosing day and time.
To exit the program - press 'e'.

Python app has the same functionality as cpp app, but it has UI that was made with TKinter.
You can choose day to import timetable for it to the program.
Then, using arrows, you can change statuses for all times.
By pressing "Export" you can save your changes.

Notes:
- You can change CSV files, but without adding new fields to it.
- The cpp program will work only on Windows OS.

Things to change in future:
- Add more functions
- Make the history of changes
- Add database
