#pylint:skip-file

import tkinter as tk
import os
import sys

def main():
    root = tk.Tk()
    root.minsize(300, 500)
    label = tk.Label(root, text="Coverage Status")
    label.pack()
    btn = tk.Button(root, text="Quit", command=root.destroy)
    btn.pack()
    root.mainloop()

if __name__ == "__main__":
    main()