import matplotlib.pyplot as plt
import numpy as np
from math import pi
import os
import sys

if not len(sys.argv) >= 2:
    for f in os.listdir():
        if f.endswith(".csv"):
            File = f
            print(f"Nutze {f}")
    if not File:
        print("Konnte keine .csv Datei finden.")
        exit()
else:
    File = sys.argv[1]

try:
    values = np.genfromtxt(File, delimiter=";")[1:,2]
except IOError:
    print(f"Konnte {File} nicht finden.")
    exit()

values += values[:1]
N = len(values)

angles = [n / float(N) * 2 * pi for n in range(N)]

fig = plt.figure(figsize=(8, 8))
ax = fig.add_subplot(111, polar=True)
ax.set_facecolor("black")

plt.xticks(size=8)
plt.yticks(size=8, color="grey")

ax.plot(angles, values, linewidth=1, linestyle="solid", color="grey")
ax.fill(angles, values, "white")

fig.savefig(File+".png", dpi=300)
plt.show()
