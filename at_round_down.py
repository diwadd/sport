import math

x = input()

res = ""

for i in range(len(x)):
    if x[i] == ".":
        break
    res += x[i]

print(res)