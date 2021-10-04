t = int(input())

for _ in range(t):

    nh = input().split(" ")
    n = int(nh[0])
    h = int(nh[1])

    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    a_vec.sort(reverse=True)

    a = a_vec[0]
    b = a_vec[1]

    # print(f"a: {a} b: {b}")

    m = h // (a + b)

    if m * a + m * b >= h:
        print(2 * m)
    else:
        d = h % (a + b)
        if d <= max(a, b):
            print(2 * m + 1)
        else:
            print(2 * m + 2)