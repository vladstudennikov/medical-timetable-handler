import tkinter as tk

class timetable:

    array_time = []
    array_status = []
    chosen_day = None

    def import_timetable(self, name):
        file = open(name, "r")
        for line in file:
            self.array_time.append(line[:line.find(';'):])
            self.array_status.append(line[line.find(';')+1:line.find('\n'):])
        file.close()
        print("Imported", name)
        self.chosen_day = name

        for x in range(20):
            label_time[x]["text"] = self.array_time[x]

        for x in range(20):
            label_status[x]["text"] = self.array_status[x]

    def print_timetable(self):
        for x in range(20):
            label_time[x]["text"] = self.array_time[x]

        for x in range(20):
            label_status[x]["text"] = self.array_status[x]


    def change_status_of_time(self, change):
        for i in self.array_time:
            if i == change:
                k = self.array_time.index(i)
                if self.array_status[k] == "yes":
                    self.array_status[k] = "no"
                else:
                    self.array_status[k] = "yes"

        self.print_timetable()

    def export_timetable(self, name):
        file = open(name, "w")
        for line in self.array_time:
            a = line + ';' + self.array_status[self.array_time.index(line)] + '\n'
            file.write(a)
        file.close()

        print("Exported ", name)

t = timetable()

window = tk.Tk()
window.title("Medical timetable")
window.resizable(width=False, height=False)

#Форма для кнопок выбора дня и расписания
frm_main = tk.Frame(
    relief=tk.SUNKEN,
    borderwidth=2,
    height = 600,
    width = 600
)
frm_main.pack(fill = tk.X)

#Рамка для кнопок выбора дня
frm_main_one = tk.Frame(
    master = frm_main,
    width = 200,
)
frm_main_one.grid(column = 0, row = 0, sticky = "ns", padx = 10, pady = 10)

#Рамка для выбора времени
frm_main_two = tk.Frame(
    relief=tk.SUNKEN,
    borderwidth=2,
    master = frm_main,
    background = "#FFFFFF",
    width = 300,
    height = 600
)
frm_main_two.grid(column = 1, row = 0, sticky = "ns", padx = 10, pady = 10)

#время из массива
label_time = []
for i in range(20):
    label_time.append(tk.Label(
        master = frm_main_two,
        background = "#FFFFFF",
        width = 25
    ))
    label_time[i].grid(row = i, column = 0)

#статусы из массива
label_status = []
for i in range(20):
    label_status.append(tk.Label(
        master = frm_main_two,
        background = "#FFFFFF",
        width = 25
    ))
    label_status[i].grid(row = i, column = 1)

btn_change0 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[0])
).grid(row = 0, column = 2)

btn_change1 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[1])
).grid(row = 1, column = 2)

btn_change2 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[2])
).grid(row = 2, column = 2)

btn_change3 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[3])
).grid(row = 3, column = 2)

btn_change4 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[4])
).grid(row = 4, column = 2)

btn_change5 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[5])
).grid(row = 5, column = 2)

btn_change6 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[6])
).grid(row = 6, column = 2)

btn_change7 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[7])
).grid(row = 7, column = 2)

btn_change8 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[8])
).grid(row = 8, column = 2)

btn_change9 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[9])
).grid(row = 9, column = 2)

btn_change10 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[10])
).grid(row = 10, column = 2)

btn_change11 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[11])
).grid(row = 11, column = 2)

btn_change12 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[12])
).grid(row = 12, column = 2)

btn_change13 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[13])
).grid(row = 13, column = 2)

btn_change14 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[14])
).grid(row = 14, column = 2)

btn_change15 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[15])
).grid(row = 15, column = 2)

btn_change16 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[16])
).grid(row = 16, column = 2)

btn_change17 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[17])
).grid(row = 17, column = 2)

btn_change18 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[18])
).grid(row = 18, column = 2)

btn_change19 = tk.Button(
    master = frm_main_two,
    width = 5,
    text="\N{RIGHTWARDS BLACK ARROW}",
    command = lambda: t.change_status_of_time(t.array_time[19])
).grid(row = 19, column = 2)

#Текст выбора дня
text_main = tk.Label(
    master = frm_main_one,
    font = "2",
    text = "Выберите день:"
)
text_main.grid(column = 0, row = 0)

nmae = ""
#Кнопки дней
btn_mon = tk.Button(
    master = frm_main_one,
    text = "Понедельник",
    height = 2,
    width = 30,
    background = "#DCDCDC",
    command = lambda: t.import_timetable("Monday.csv")
).grid(column = 0, row = 1)

btn_tue = tk.Button(
    master = frm_main_one,
    text = "Вторник",
    height = 2,
    width = 30,
    background = "#DCDCDC",
    command = lambda: t.import_timetable("Tuesday.csv")
).grid(column = 0, row = 2)

btn_wen = tk.Button(
    master = frm_main_one,
    text = "Среда",
    height = 2,
    width = 30,
    background = "#DCDCDC",
    command = lambda: t.import_timetable("Wednesday.csv")
).grid(column = 0, row = 3)

btn_thr = tk.Button(
    master = frm_main_one,
    text = "Четверг",
    height = 2,
    width = 30,
    background = "#DCDCDC",
    command = lambda: t.import_timetable("Thursday.csv")
).grid(column = 0, row = 4)

btn_frd = tk.Button(
    master = frm_main_one,
    text = "Пятница",
    height = 2,
    width = 30,
    background = "#DCDCDC",
    command = lambda: t.import_timetable("Friday.csv")
).grid(column = 0, row = 5)

#Форма для организационных кнопок - выход экспорт и т.д.
frm_buttons = tk.Frame(
    relief=tk.SUNKEN,
    borderwidth=2,
    height = 100,
    width = 400
)
frm_buttons.pack(fill = tk.X, pady = 15)

btn_export = tk.Button(
    text = "Экспортировать",
    master = frm_buttons,
    command = lambda: t.export_timetable(t.chosen_day)
    
).pack(side = tk.RIGHT, padx = 20, pady = 15)

window.mainloop()

