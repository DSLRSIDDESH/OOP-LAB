from tkinter import *

top = Tk()
top.configure(background = "#CDFCF6")
top.title("MARKSHEET")

name_l = Label(top,text="Name",background="#CDFCF6")
name_l.grid(row=0,column=0)

name_e = Entry(top,relief="sunken",highlightbackground = "#CDFCF6")
name_e.grid(row=0,column=1)

reg_l = Label(top,text="Reg.No",background="#CDFCF6")
reg_l.grid(row=0,column=3)

reg_e = Entry(top,relief="sunken",highlightbackground = "#CDFCF6")
reg_e.grid(row=0,column=4)

roll_l = Label(top,text="Roll.No",background="#CDFCF6")
roll_l.grid(row=1,column=0)

roll_e = Entry(top,relief="sunken",highlightbackground = "#CDFCF6")
roll_e.grid(row=1,column=1)

srl_l = Label(top,text="Srl.No",background="#CDFCF6")
srl_l.grid(row=2,column=0)

subject_l = Label(top,text="Subject.No",background="#CDFCF6")
subject_l.grid(row=2,column=1)

grade_l = Label(top,text="Grade.No",background="#CDFCF6")
grade_l.grid(row=2,column=2)

sub_credit_l = Label(top,text="Sub Credit",background="#CDFCF6")
sub_credit_l.grid(row=2,column=3)

credit_l = Label(top,text="Credit obtained",background="#CDFCF6")
credit_l.grid(row=2,column=4)

l1_l = Label(top,text="1",background="#CDFCF6")
l1_l.grid(row=3,column=0)

l2_l = Label(top,text="2",background="#CDFCF6")
l2_l.grid(row=4,column=0)

l3_l = Label(top,text="3",background="#CDFCF6")
l3_l.grid(row=5,column=0)

l4_l = Label(top,text="4",background="#CDFCF6")
l4_l.grid(row=6,column=0)

cs201_l = Label(top,text="CS 201",background="#CDFCF6")
cs201_l.grid(row=3,column=1)

cs202_l = Label(top,text="CS 202",background="#CDFCF6")
cs202_l.grid(row=4,column=1)

ma201_l = Label(top,text="MA 201",background="#CDFCF6")
ma201_l.grid(row=5,column=1)

ec201_l = Label(top,text="EC 201",background="#CDFCF6")
ec201_l.grid(row=6,column=1)

grade_1 = Entry(top,relief="sunken",highlightbackground = "#CDFCF6")
grade_1.grid(row=3,column=2)

grade_2 = Entry(top,relief="sunken",highlightbackground = "#CDFCF6")
grade_2.grid(row=4,column=2)

grade_3 = Entry(top,relief="sunken",highlightbackground = "#CDFCF6")
grade_3.grid(row=5,column=2)

grade_4 = Entry(top,relief="sunken",highlightbackground = "#CDFCF6")
grade_4.grid(row=6,column=2)

sub_credit_1_l = Label(top,text="4",background="#CDFCF6")
sub_credit_1_l.grid(row=3,column=3)

sub_credit_2_l = Label(top,text="4",background="#CDFCF6")
sub_credit_2_l.grid(row=4,column=3)

sub_credit_3_l = Label(top,text="3",background="#CDFCF6")
sub_credit_3_l.grid(row=5,column=3)

sub_credit_4_l = Label(top,text="4",background="#CDFCF6")
sub_credit_4_l.grid(row=6,column=3)

total_credit_l = Label(top,text="Total credit",background="#CDFCF6")
total_credit_l.grid(row=7,column=3)
total_credit_2 = Label(top,text="",background="#CDFCF6")
total_credit_2.grid(row=7,column=4)

sgpa_l = Label(top,text="SGPA",background="#CDFCF6")
sgpa_l.grid(row=8,column=3)
sgpa_2 = Label(top,text="",background="#CDFCF6")
sgpa_2.grid(row=8,column=4)

credit_1 = Label(top,text="",background="#CDFCF6")
credit_1.grid(row=3,column=4)

credit_2 = Label(top,text="",background="#CDFCF6")
credit_2.grid(row=4,column=4)

credit_3 = Label(top,text="",background="#CDFCF6")
credit_3.grid(row=5,column=4)

credit_4 = Label(top,text="",background="#CDFCF6")
credit_4.grid(row=6,column=4)

def calculate_cred():
    if len(name_e.get()) == 0:
        sgpa_2.configure(text="Please Enter Name",fg = "#CF0A0A")
        return
    elif len(reg_e.get()) == 0:
        sgpa_2.configure(text="Please Enter Reg.No",fg = "#CF0A0A",font = ("Lucida Console",12))
        return
    elif len(roll_e.get()) == 0:
        sgpa_2.configure(text="Please Enter Roll.No",fg = "#CF0A0A")
        return
    l = [grade_1.get(),grade_2.get(),grade_3.get(),grade_4.get()]
    l1 = []
    d = {'S' : 10, 's' : 10, 'A' : 9, 'a' : 9, 'B' : 8, 'b' : 8, 'C' : 7, 'c' : 7, 'D' : 6, 'd' : 6, 'E' : 5, 'e' : 5, 'U' : 0, 'u' : 0, 'I' : 0, 'i' : 0, 'W' : 0 , 'w' : 0}
    for i in l:
        if len(i) == 0:
            sgpa_2.configure(text="Please Input!",fg = "#CF0A0A",font = ("Lucida Console",12))
            return
        elif i not in d:
            sgpa_2.configure(text="Invalid Input!",fg = "#CF0A0A")
            return
        else:
            l1.append(d[i])

    credit_1.configure(text=l1[0]*4)
    credit_2.configure(text=l1[1]*4)
    credit_3.configure(text=l1[2]*3)
    credit_4.configure(text=l1[3]*4)
    total_credit_2.configure(text=l1[0]*4+l1[1]*4+l1[2]*3+l1[3]*4)
    sgpa_2.configure(text=round((l1[0]*4+l1[1]*4+l1[2]*3+l1[3]*4)/15,2))

submit_button = Button(top,text="submit",command = calculate_cred,background="#5F9DF7",highlightbackground = "#CDFCF6",relief="groove")
submit_button.grid(row=8,column=1)

top.mainloop()