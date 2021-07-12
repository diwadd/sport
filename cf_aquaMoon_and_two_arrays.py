t = int(input())

for _ in range(t):

    n = int(input())
    a_vec = input().split(" ")
    b_vec = input().split(" ")

    a_vec = [int(a) for a in a_vec]
    b_vec = [int(b) for b in b_vec]

    if sum(a_vec) != sum(b_vec):
        print("-1")
        continue

    operations = []
    for i in range(n):
        if a_vec[i] > b_vec[i]:
            for j in range(n):
                if a_vec[i] == b_vec[i]:
                    break
                elif a_vec[j] < b_vec[j]:

                    op = [i + 1, j + 1]
                    while True:
                        a_vec[i] -= 1
                        a_vec[j] += 1

                        operations.append(op)
                        if a_vec[i] == b_vec[i] or a_vec[j] == b_vec[j]:
                            break
        elif a_vec[i] < b_vec[i]:
            for j in range(n):
                if a_vec[i] == b_vec[i]:
                    break
                elif a_vec[j] > b_vec[j]:

                    op = [j + 1, i + 1]
                    while True:
                        a_vec[i] += 1
                        a_vec[j] -= 1

                        operations.append(op)
                        if a_vec[i] == b_vec[i] or a_vec[j] == b_vec[j]:
                            break
    is_ok = True
    for i in range(n):
        if a_vec[i] != b_vec[i]:
            is_ok = False
            break

    if is_ok == False:
        print("-1")
    else:
        m = len(operations)
        print(f"{m}")

        for j in range(m):
            print(f"{operations[j][0]} {operations[j][1]}")
