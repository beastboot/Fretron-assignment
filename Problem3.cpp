import matplotlib.pyplot as plt

# Coordinates for each flight
flight1 = [(1, 1), (2, 2), (3, 3)]
flight2 = [(1, 1), (2, 4), (3, 2)]
flight3 = [(1, 1), (4, 2), (3, 4)]

# Separate x and y coordinates for each flight
f1_x, f1_y = zip(*flight1)
f2_x, f2_y = zip(*flight2)
f3_x, f3_y = zip(*flight3)

# Plotting the flight paths
plt.figure(figsize=(8, 8))
plt.plot(f1_x, f1_y, 'o-', label='Flight 1', color='orange')
plt.plot(f2_x, f2_y, 'o-', label='Flight 2', color='yellow')
plt.plot(f3_x, f3_y, 'o-', label='Flight 3', color='red')

# Highlighting start and end points
plt.scatter(f1_x[0], f1_y[0], color='green', s=100, label='Start Point (Flight 1)', edgecolor='black')
plt.scatter(f1_x[-1], f1_y[-1], color='red', s=100, label='End Point (Flight 1)', edgecolor='black')
plt.scatter(f2_x[0], f2_y[0], color='green', s=100, label='Start Point (Flight 2)', edgecolor='black')
plt.scatter(f2_x[-1], f2_y[-1], color='red', s=100, label='End Point (Flight 2)', edgecolor='black')
plt.scatter(f3_x[0], f3_y[0], color='green', s=100, label='Start Point (Flight 3)', edgecolor='black')
plt.scatter(f3_x[-1], f3_y[-1], color='red', s=100, label='End Point (Flight 3)', edgecolor='black')


plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')
plt.title('Flight Paths')
plt.legend()


plt.grid(True)


plt.show()
