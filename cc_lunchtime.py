t = int(input())

for _ in range(t):

    n = int(input())
    h_vec = input().split(" ")

    h_vec = [int(h) for h in h_vec]

    stack = []
    next_equal_left = [0 for _ in range(n)]
    next_equal_right = [0 for _ in range(n)]

    for i in range(n):
        while len(stack) > 0:
            index = stack[-1]
            if h_vec[index] >= h_vec[i]:
                break
            stack.pop()
        
        if len(stack) > 0:
            next_equal_left[i] = stack[-1]
        else:
            next_equal_left[i] = -1
        stack.append(i)

    stack = []
    for i in range(n-1, -1, -1):
        while len(stack) > 0:
            index = stack[-1]
            if h_vec[index] >= h_vec[i]:
                break
            stack.pop()
        
        if len(stack) > 0:
            next_equal_right[i] = stack[-1]
        else:
            next_equal_right[i] = -1
        stack.append(i)

    left_result = [0 for _ in range(n)]
    right_result = [0 for _ in range(n)]

    for i in range(n):
        if next_equal_left[i] == -1 or h_vec[i] != h_vec[next_equal_left[i]]:
            continue
        else:
            left_result[i] = left_result[next_equal_left[i]] + 1

    for i in range(n-1, -1 ,-1):
        if next_equal_right[i] == -1 or h_vec[i] != h_vec[next_equal_right[i]]:
            continue
        else:
            right_result[i] = right_result[next_equal_right[i]] + 1

    res = [0 for _ in range(n)]
    for i in range(n):
        res[i] = left_result[i] + right_result[i]

    res = [str(r) for r in res]
    res = " ".join(res)
    print(res)



