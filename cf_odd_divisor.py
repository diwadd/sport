t = int(input())

for _ in range(t):

    x = int(input())

    while x % 2 == 0:
        x = x / 2

    if x == 1:
        print("NO")
    elif x % 2 != 0:
        print("YES")