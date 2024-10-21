import matplotlib.pyplot as plt
import numpy as np

import sys

sys.path.append("../")
import csvreader
import graphs

data = csvreader.readData("1.csv")

fig, ax = graphs.basePlot()

plt.title("N = 1")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
k, b, dk, db = graphs.lsqm(np.log(data[0:, 0]), np.log(data[0:, 1]))
ax.plot([np.log(data[0, 0]), np.log(data[-1, 0])], [k * np.log(data[0, 0]) + b, k * np.log(data[-1, 0]) + b])

print(f"k = {k:.2f}")

plt.show()


data = csvreader.readData("4.csv")

fig, ax = graphs.basePlot()

plt.title("N = 4")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(data[:, 0]), np.log(data[:, 1]), '.')
# k, b, dk, db = graphs.lsqm(np.log(data[0:, 0]), np.log(data[0:, 1]))
# ax.plot([np.log(data[0, 0]), np.log(data[-1, 0])], [k * np.log(data[0, 0]) + b, k * np.log(data[-1, 0]) + b])

# print(f"k = {k:.2f}")

plt.show()