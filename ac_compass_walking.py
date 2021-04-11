import math

rxy = input().split(" ")

r = int(rxy[0])
x = int(rxy[1])
y = int(rxy[2])

d = math.sqrt(x*x + y*y)

# print(f"d: {d}")

m = math.floor(d / r)

# print(f"m: {m}")

if abs(r * m - d) < 10**(-30):
# if r * m == d:
    print(m)
elif r > d:
    print(2)
else:
    print(m+1)

