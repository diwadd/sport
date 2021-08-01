t = int(input())

for _ in range(t):

    p = int(input())

    if p % 2 != 0:
        print(f"2 {p-1}")
    else:
        print(f"2 {p//2}")