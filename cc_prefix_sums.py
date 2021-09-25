t = int(input())

for _ in range(t):

    n = int(input())

    s = n * (n + 1) // 2

    if s % 2 != 0:
        print("NO")
        continue

    vec = [i for i in range(1, n+1)]

    array_one = []
    array_two = []

    for i in range(0, n // 2):
        if i % 2 == 0:
            array_one.append(i+1)
        else:
            array_two.append(i+1)
    
    for i in range(n // 2, n):
        if i % 2 == 0:
            array_two.append(i+1)
        else:
            array_one.append(i+1)

    array_one = [str(ao) for ao in array_one]
    array_two = [str(at) for at in array_two]

    print("YES")
    print(" ".join(array_one))
    print(" ".join(array_two))

