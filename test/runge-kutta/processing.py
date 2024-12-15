import matplotlib.pyplot as plt
import numpy as np

import sys

sys.path.append("../../")
import csvreader
import graphs

p1 = csvreader.readData("p1.csv", titlesize = 0)
fix, ax = graphs.basePlot()

plt.title("equation 1")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(p1[:, 0]), np.log(p1[:, 1]), '.')

k, b, dk, db = graphs.lsqm(np.log(p1[:17, 0]), np.log(p1[:17, 1]))
ax.plot([np.log(p1[0, 0]), np.log(p1[16, 0])], [k * np.log(p1[0, 0]) + b, k * np.log(p1[16, 0]) + b])
print(f"k1 = {k}")

plt.show()

p2 = csvreader.readData("p2.csv", titlesize = 0)
fix, ax = graphs.basePlot()

plt.title("equation 2")
plt.xlabel("ln(h)")
plt.ylabel("ln(err)")

ax.plot(np.log(p2[:, 0]), np.log(p2[:, 1]), '.')

k, b, dk, db = graphs.lsqm(np.log(p2[-15:, 0]), np.log(p2[-15:, 1]))
ax.plot([np.log(p2[-1, 0]), np.log(p2[-15, 0])], [k * np.log(p2[-1, 0]) + b, k * np.log(p2[-15, 0]) + b])
print(f"k2 = {k}")

plt.show()

