"""
Tutorial Tracker Software

- Create a checklist to keep track of tutorials.
- Organize which tutorials to watch with utmost priority.

"""

import tkinter as tk
window = tk.Tk()
window.resizable(True, True)
window.title("Tutorial Tracker")
window.configure(bg="black")
window.geometry("400x320")
title = tk.Label(text="Tutorial Checklist", 
                 foreground="white",
                 background="black")
title.pack()

label2 = tk.Label(window, 
                  bg="blue",
                    fg="white",
                      text="Incomplete",
                      )
label2.place(relx=0.5,
             rely=0.5,
             anchor="center")

def check_logic():
    if (tut1.get() == True):
        label2.config(text="Completed {}".format(course1))
    else:
        label2.config(text="Incomplete...")

tut1 = tk.BooleanVar()
tut2 = tk.BooleanVar()

course1 = "Linear Algebra for ML/DL"
btn1 = tk.Checkbutton(master=window,
                      text=course1,
                      variable=tut1,
                      onvalue=True,
                      offvalue=False,
                      command=check_logic)

btn1.place(relx=0.5,
           rely=0.2,
           anchor="center")


window.mainloop()


