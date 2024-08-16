import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data_cpp=pd.read_csv("time data - C++.csv")
data_python=pd.read_csv("time data - Python.csv")

print(data_python.head())
# create a line chart where x axis is N and y axis has time, and add legend for Meat time Real time User time System time
# plt.plot(data_python['N'], data_python['Real time'], label='Real time')
# plt.plot(data_python['N'], data_python['User time'], label='User time')
# plt.plot(data_python['N'], data_python['System time'], label='System time')
# plt.plot(data_python['N'], data_python['Meat time'], label='Meat time')

# on the x point, create a horizontal line and remove existing labels and add new labels
# plt.axvline(x=1024, color='r', linestyle='--')
# plt.xticks(data_python['N'])
# for i in range(len(data_python['N'])):
#     plt.plot(data_python['N'][i], data_python['Real time'][i], 'ro')
#     plt.plot(data_python['N'][i], data_python['User time'][i], 'ro')
#     plt.plot(data_python['N'][i], data_python['System time'][i], 'ro')
#     plt.plot(data_python['N'][i], data_python['Meat time'][i], 'ro')

# Compare meal time of C++ and Python
plt.plot(data_python['N'], data_python['System time'], label='Python Meat time')
plt.plot(data_python['N'], data_cpp['System time'], label='C++ Meat time')
# plt.title('Comparison of Meat time of C++ and Python')
plt.xticks(data_python['N'])



plt.xlabel('N')
plt.ylabel('Time (ms)')
plt.legend()
plt.show()

