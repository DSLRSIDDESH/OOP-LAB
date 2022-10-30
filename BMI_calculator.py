from curses.ascii import isalnum
from tkinter import *
def calculate():
    h = height_e.get()
    w = weight_e.get()
    h_,w_ = "",""
    for i in range(len(h)):
        if h[i] != '.':
            h_ += h[i]
    for i in range(len(w)):
        if w[i] != ".":
            w_ += w[i]
    if len(height_e.get()) == 0 or len(weight_e.get()) == 0:
        bmi = "Please Input!"
    elif not h_.isnumeric():
        bmi = "Invalid Input!"
    elif not w_.isnumeric():
        bmi = "Invalid Input!"
    else:
        h = float(height_e.get())
        w = float(weight_e.get())
        if h > 0.0 and w > 0.0:
            bmi = round(w / (h * h),2)
        else:
            bmi = "Invalid Input!"
    bmi_e.delete(0,END)
    bmi_e.insert(0,bmi)

top = Tk()
top.configure(background="light green")
top.title("BMI Calculator")
height_l = Label(top,text = "Height (in Meter)",background="light green")
height_l.grid(row=0,column=0)

height_e = Entry(top)
height_e.grid(row=0,column=1)

weight_l = Label(top,text = "Weight (in Kg)",background="light green")
weight_l.grid(row=1,column=0)

weight_e = Entry(top)
weight_e.grid(row=1,column=1)

bmi_l = Label(top,text = "Your BMI",background="light green")
bmi_l.grid(row=2,column=0)

bmi_e = Entry(top)
bmi_e.grid(row=2,column=1)

calculate_button = Button(top, text=' Calculate ',command= calculate)
calculate_button.grid(row=3, column=1)

top.mainloop()