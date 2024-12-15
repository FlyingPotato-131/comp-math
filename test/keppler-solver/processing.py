import matplotlib.pyplot as plt
import numpy as np

import sys

sys.path.append("../../")
import csvreader
import graphs

e01 = csvreader.readData("e0.1.csv", titlesize = 0)
fig, ax = graphs.basePlot()

plt.title("e = 0.1")
plt.xlabel("i")
plt.ylabel("log(err)")

ax.plot(np.log(e01) / np.log(10), '.')
plt.show()

e02 = csvreader.readData("e0.2.csv", titlesize = 0)
fig, ax = graphs.basePlot()

plt.title("e = 0.2")
plt.xlabel("i")
plt.ylabel("log(err)")

ax.plot(np.log(e02) / np.log(10), '.')
plt.show()

e05 = csvreader.readData("e0.5.csv", titlesize = 0)
fig, ax = graphs.basePlot()

plt.title("e = 0.5")
plt.xlabel("i")
plt.ylabel("log(err)")

ax.plot(np.log(e05) / np.log(10), '.')
plt.show()

e08 = csvreader.readData("e0.8.csv", titlesize = 0)
fig, ax = graphs.basePlot()

plt.title("e = 0.8")
plt.xlabel("i")
plt.ylabel("log(err)")

ax.plot(np.log(e08) / np.log(10), '.')
plt.show()
