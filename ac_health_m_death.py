mh = input().split(" ")

m = int(mh[0])
h = int(mh[1])

if h % m == 0:
    print("Yes")
else:
    print("No")