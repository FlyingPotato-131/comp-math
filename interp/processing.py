import matplotlib.pyplot as plt
import numpy as np

import sys

sys.path.append("../")
import csvreader
import graphs

data = csvreader.readData("ne3.csv")

fig, ax = graphs.basePlot()

plt.title("Newton, equidistant knots, N = 3")
plt.xlabel("l")
plt.ylabel("err")

ax.plot(data[:, 0], data[:, 1], '.')

plt.show()


data = csvreader.readData("ne4.csv")

fig, ax = graphs.basePlot()

plt.title("Newton, equidistant knots, N = 4")
plt.xlabel("l")
plt.ylabel("err")

ax.plot(data[:, 0], data[:, 1], '.')

plt.show()


data = csvreader.readData("ne5.csv")

fig, ax = graphs.basePlot()

plt.title("Newton, equidistant knots, N = 5")
plt.xlabel("l")
plt.ylabel("err")

ax.plot(data[:, 0], data[:, 1], '.')

plt.show()


data = csvreader.readData("nc3.csv")

fig, ax = graphs.basePlot()

plt.title("Newton, Chebyshev knots, N = 3")
plt.xlabel("l")
plt.ylabel("err")

ax.plot(data[:, 0], data[:, 1], '.')

plt.show()


data = csvreader.readData("nc4.csv")

fig, ax = graphs.basePlot()

plt.title("Newton, Chebyshev knots, N = 4")
plt.xlabel("l")
plt.ylabel("err")

ax.plot(data[:, 0], data[:, 1], '.')

plt.show()


data = csvreader.readData("nc5.csv")

fig, ax = graphs.basePlot()

plt.title("Newton, Chebyshev knots, N = 5")
plt.xlabel("l")
plt.ylabel("err")

ax.plot(data[:, 0], data[:, 1], '.')

plt.show()


data = csvreader.readData("ee3.csv")

fig, ax = graphs.basePlot()

plt.title("Hermite, equidistant knots, N = 3")
plt.xlabel("l")
plt.ylabel("err")

ax.plot(data[:, 0], data[:, 1], '.')

plt.show()


data = csvreader.readData("ee4.csv")

fig, ax = graphs.basePlot()

plt.title("Hermite, equidistant knots, N = 4")
plt.xlabel("l")
plt.ylabel("err")

ax.plot(data[:, 0], data[:, 1], '.')

plt.show()


data = csvreader.readData("ee5.csv")

fig, ax = graphs.basePlot()

plt.title("Hermite, equidistant knots, N = 5")
plt.xlabel("l")
plt.ylabel("err")

ax.plot(data[:, 0], data[:, 1], '.')

plt.show()
