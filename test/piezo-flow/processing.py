import matplotlib.pyplot as plt
import numpy as np

import sys
sys.path.append("../../")
import csvreader

h = 1
plt.ion()
x = np.arange(0, 501, h)

data = csvreader.readData("vals.csv", titlesize = 0)
fig, ax = plt.subplots()

for t in range(240):
	ax.plot(x, data[t, :])
	ax.plot(0, np.max(data))
	ax.plot(0, np.min(data))
	plt.pause(0.02)
	ax.clear()
plt.close()
