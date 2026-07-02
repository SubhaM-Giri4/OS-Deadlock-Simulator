import tkinter as tk
import subprocess
from graph import show_graph

def run_banker():
    subprocess.run(["banker.exe"])

    with open("output.txt","r") as f:
        data=f.read()

    output.delete("1.0",tk.END)
    output.insert(tk.END,data)

root=tk.Tk()
root.title("Deadlock Detection Simulator")
root.geometry("700x500")

tk.Label(root,text="Deadlock Detection & Prevention System",
         font=("Arial",16,"bold")).pack(pady=10)

tk.Button(root,text="Run Banker's Algorithm",
          command=run_banker).pack(pady=10)

tk.Button(root,text="Show Wait-For Graph",
          command=show_graph).pack(pady=10)

output=tk.Text(root,height=15,width=70)
output.pack(pady=20)

root.mainloop()
