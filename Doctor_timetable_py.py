class timetable:

    array_time = []
    array_status = []

    def import_timetable(self, name):
        file = open(name, "r")
        for line in file:
            self.array_time.append(line[:line.find(';'):])
            self.array_status.append(line[line.find(';')+1:line.find('\n'):])
        file.close()

    def print_timetable(self):
        for x in range(len(self.array_time)):
            print(self.array_time[x], ' ', self.array_status[x])

    def change_status_of_time(self, change):
        for i in self.array_time:
            if i == change:
                k = self.array_time.index(i)
                if self.array_status[k] == "yes":
                    self.array_status[k] = "no"
                else:
                    self.array_status[k] = "yes"

    def export_timetable(self, name):
        file = open(name, "w")
        for line in self.array_time:
            a = line + ';' + self.array_status[self.array_time.index(line)] + '\n'
            file.write(a)
        file.close()


def import_timetable(time, status, name):
    file = open(name, "r")
    for line in file:
        time.append(line[:line.find(';'):])
        status.append(line[line.find(';')+1:line.find('\n'):])
    file.close()

def print_timetable(time, status):
    for x in range(len(time)):
        print(status[x])

def change_status_of_time(time, status, change):
    for i in time:
        if i == change:
            if status[time.index(i)] == "yes":
                status[time.index(i)] = "no"
            else:
                status[time.index(i)] = "yes"

def export_timetable(time, status, name):
    file = open(name, "w")
    for line in time:
        a = line + ';' + status[time.index(line)] + '\n'
        file.write(a)
    file.close()

files = ["Monday.csv", "Tuesday.csv", "Wednesday.csv", "Thursday.csv", "Friday.csv"]
t = timetable()
t.import_timetable(files[0])
t.print_timetable()
t.change_status_of_time("8:00 - 8:30")
print('\n')
t.print_timetable()
t.export_timetable(files[0])
