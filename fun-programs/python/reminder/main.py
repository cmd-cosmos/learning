#pylint:skip-file
#type:ignore

import tkinter as tk
from tkinter import *
import os

def main():
    root = tk.Tk()
    root.title("Coverage Status 🚀")
    root.minsize(300, 500)
    root.configure(background="black")

    label = tk.Label(root, text="Coverage Status", fg="white", bg="black", border=1.0, height=3, font=("Times New Roman", 18, "bold"))
    label.pack()

    btn = tk.Button(root, text="Quit", command=root.destroy, background="black", foreground="white", width=10, borderwidth=2.0, highlightcolor="white", font=("Times New Roman",10,"bold"))
    btn.pack(side=tk.BOTTOM, pady=20)

    cb1_var = IntVar()
    cb2_var = IntVar()
    cb3_var = IntVar()
    cb4_var = IntVar()
    
    cb1 = tk.Checkbutton(root, height=3, width=100, onvalue=1, offvalue=0, variable=cb1_var, background="black", foreground="white" , text="Digital Electronics")
    cb2 = tk.Checkbutton(root, height=3, width=100, onvalue=1, offvalue=0, variable=cb2_var, background="black", foreground="white" , text="Computer Architecture")
    cb3 = tk.Checkbutton(root, height=3, width=100, onvalue=1, offvalue=0, variable=cb3_var, background="black", foreground="white" , text="Operating Systems")
    cb4 = tk.Checkbutton(root, height=3, width=100, onvalue=1, offvalue=0, variable=cb4_var, background="black", foreground="white" , text="Networking")

    cb1.pack()
    cb2.pack()
    cb3.pack()
    cb4.pack()

    root.mainloop()

if __name__ == "__main__":
    main()