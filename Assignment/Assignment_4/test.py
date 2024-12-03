data = [[3, "apple"], [1, "banana"], [2, "cherry"]]

# Using sorted (returns a new sorted list)
sorted_data = sorted(data, key=lambda x: x[0])
print("Sorted list:", sorted_data)

# Using list.sort (sorts in place)
data.sort(key=lambda x: x[0])
print("Sorted in place:", data)

for item in data :
    if(item[0]%2==0) :
      print(item)