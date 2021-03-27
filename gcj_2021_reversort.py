tests = int(input())

for t in range(tests):

    n = int(input())
    vec = input().split(" ")
    vec = [int(v) for v in vec]

    res = 0
    for i in range(n):

        min_v = vec[i]
        index = i
        for j in range(index, n):
            if vec[j] < min_v:
                index = j
                min_v = vec[j]

        # print(f"index: {i} {index}")
        # print(list(reversed(vec[i:index+1])))
        vec[i:index+1] = list(reversed(vec[i:index+1]))
        # print(vec)
        # print(f"cost: {index-i+1}")
        res += index-i+1

    print(f"Case #{t+1}: {res - 1}")
