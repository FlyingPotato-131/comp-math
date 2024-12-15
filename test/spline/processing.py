import matplotlib.pyplot as plt
import numpy as np

import sys

sys.path.append("../")
import csvreader
import graphs

data = csvreader.readData("natural.csv")

fig, ax = graphs.basePlot()

plt.title("natural spline")
plt.xlabel("ln(N)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
k, b, dk, db = graphs.lsqm(np.log(data[:, 0]), np.log(data[:, 1]))
ax.plot([np.log(data[0, 0]), np.log(data[-1, 0])], [k * np.log(data[0, 0]) + b, k * np.log(data[-1, 0]) + b])

print(f"k = {k:.2f}")

plt.show()


data = csvreader.readData("unnatural.csv")

fig, ax = graphs.basePlot()

plt.title("spline with set second derivative at endpoints")
plt.xlabel("ln(N)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
k, b, dk, db = graphs.lsqm(np.log(data[:, 0]), np.log(data[:, 1]))
ax.plot([np.log(data[0, 0]), np.log(data[-1, 0])], [k * np.log(data[0, 0]) + b, k * np.log(data[-1, 0]) + b])

print(f"k = {k:.2f}")

plt.show()
