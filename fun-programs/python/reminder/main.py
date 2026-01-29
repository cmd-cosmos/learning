#pylint:skip-file

import tkinter as tk
import os
import sys

def main():
    root = tk.Tk()
    root.minsize(300, 500)
    root.configure(background="black")

    label = tk.Label(root, text="Coverage Status", fg="white", bg="black", border=1.0, height=3, font=("Times New Roman", 18, "bold"))
    label.pack()
    btn = tk.Button(root, text="Quit", command=root.destroy, background="black", foreground="white", width=10, borderwidth=2.0, highlightcolor="white", font=("Times New Roman",10,"bold"))
    btn.pack(side=tk.BOTTOM, pady=20)
    root.mainloop()

if __name__ == "__main__":
    main()