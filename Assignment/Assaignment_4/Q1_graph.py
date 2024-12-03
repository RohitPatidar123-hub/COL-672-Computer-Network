import csv
import matplotlib.pyplot as plt

loss = [0.0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0]

data = []

timeWithRecovery=[]
timeWithoutRecovery=[]

with open("reliability_delay.csv") as file:
    csvObj = csv.reader(file, delimiter=",")
    lineNo = 0
    for line in csvObj:
        data.append(line)

# Check if data was loaded correctly
if len(data) < 2:  # Less than 2 lines (header + data)
    print("Error: CSV file is empty or does not contain enough data.")
else:
    print(data[1]) 
for i in range(1,len(data), 5):
    value = 0
    for j in range(i,i+5):
        value += float(data[j][4])
    avgValue = value/5
    if(data[i][2] == "True"):
        timeWithRecovery.append(avgValue)
    elif(data[i][2] == "False"):
        timeWithoutRecovery.append(avgValue)
        


# print(data)
print(timeWithRecovery)
print(timeWithoutRecovery)

plt.plot(loss,timeWithRecovery, marker = 'd', color = 'g', label = "With FastRecovery")
plt.plot(loss,timeWithoutRecovery, marker = 'd', color = 'y', label = "Without FastRecovery")

plt.xlabel("Loss --->")
plt.ylabel("File Transmission Time")
plt.legend()

plt.show()
plt.savefig("p1_lossPlot.png")