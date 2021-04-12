t = int(input())

for _ in range(t):

    k1k2k3v = input().split(" ")
    k1 = float(k1k2k3v[0])
    k2 = float(k1k2k3v[1])
    k3 = float(k1k2k3v[2])
    v = float(k1k2k3v[3])

    time = round(100.0/(k1*k2*k3*v), 2)
    # print(f"speed: {time}")
    if time < 9.58:
        print("YES")
    else:
        print("NO")