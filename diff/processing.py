import matplotlib.pyplot as plt
import numpy as np

import sys

sys.path.append("../")
import csvreader
import graphs

data = csvreader.readData("13.csv")

fig, ax = graphs.basePlot()

plt.title("L = 1, N = 3")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
k, b, dk, db = graphs.lsqm(np.log(data[2:, 0]), np.log(data[2:, 1]))
ax.plot([np.log(data[2, 0]), np.log(data[-1, 0])], [k * np.log(data[2, 0]) + b, k * np.log(data[-1, 0]) + b])

print(f"k = {k:.2f}")

plt.show()


data = csvreader.readData("14.csv")

fig, ax = graphs.basePlot()

plt.title("L = 1, N = 4")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
k, b, dk, db = graphs.lsqm(np.log(data[1:, 0]), np.log(data[1:, 1]))
ax.plot([np.log(data[1, 0]), np.log(data[-1, 0])], [k * np.log(data[1, 0]) + b, k * np.log(data[-1, 0]) + b])

print(f"k = {k:.2f}")

plt.show()


data = csvreader.readData("15.csv")

fig, ax = graphs.basePlot()

plt.title("L = 1, N = 5")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
k, b, dk, db = graphs.lsqm(np.log(data[1:, 0]), np.log(data[1:, 1]))
ax.plot([np.log(data[1, 0]), np.log(data[-1, 0])], [k * np.log(data[1, 0]) + b, k * np.log(data[-1, 0]) + b])

print(f"k = {k:.2f}")

plt.show()


data = csvreader.readData("23.csv")

fig, ax = graphs.basePlot()

plt.title("L = 2, N = 3")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
k, b, dk, db = graphs.lsqm(np.log(data[2:, 0]), np.log(data[2:, 1]))
ax.plot([np.log(data[2, 0]), np.log(data[-1, 0])], [k * np.log(data[2, 0]) + b, k * np.log(data[-1, 0]) + b])

print(f"k = {k:.2f}")

plt.show()


data = csvreader.readData("24.csv")

fig, ax = graphs.basePlot()

plt.title("L = 2, N = 4")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
k, b, dk, db = graphs.lsqm(np.log(data[1:, 0]), np.log(data[1:, 1]))
ax.plot([np.log(data[1, 0]), np.log(data[-1, 0])], [k * np.log(data[1, 0]) + b, k * np.log(data[-1, 0]) + b])

print(f"k = {k:.2f}")

plt.show()


data = csvreader.readData("25.csv")

fig, ax = graphs.basePlot()

plt.title("L = 2, N = 5")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
k, b, dk, db = graphs.lsqm(np.log(data[1:, 0]), np.log(data[1:, 1]))
ax.plot([np.log(data[1, 0]), np.log(data[-1, 0])], [k * np.log(data[1, 0]) + b, k * np.log(data[-1, 0]) + b])

print(f"k = {k:.2f}")

plt.show()

