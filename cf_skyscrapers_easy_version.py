import math

if __name__ == "__main__":


    n = int(input())
    mi = input().split()
    mi = [int(m) for m in mi]

    l = [0 for i in range(n)]
    r = [0 for i in range(n)]

    right_to_left = [-1 for i in range(n)]
    left_to_right = [-1 for i in range(n)]

    stack = [0]
    for i in range(1, n, 1):
        while len(stack) != 0 and mi[stack[-1]] > mi[i]:
            left_to_right[stack.pop()] = i
        stack.append(i)

    stack = [n-1]
    for i in range(n-2, -1, -1):
        while len(stack) != 0 and mi[stack[-1]] > mi[i]:
            right_to_left[stack.pop()] = i
        stack.append(i)

    l[0] = mi[0]
    for i in range(1, n, 1):
        if mi[i - 1] <= mi[i]:
            l[i] = l[i - 1] + mi[i]
        else:
            li = right_to_left[i]
            if li == -1:
                l[i] = mi[i] * (i + 1)
            else:
                l[i] = l[li] + mi[i] * (i - li)

    r[n-1] = mi[n-1]
    for i in range(n - 2, -1, -1):
        if mi[i + 1] <= mi[i]:
            r[i] = r[i + 1] + mi[i]
        else:
            ri = left_to_right[i]
            if ri == -1:
                r[i] = mi[i] * (n - i)
            else:
                r[i] = r[ri] + mi[i] * (ri - i)

    # print(f"l: {l}")
    # print(f"r: {r}")

    peak = 0
    for i in range(n):
        if l[peak] + r[peak] - mi[peak] < l[i] + r[i] - mi[i]:
            peak = i

    # print(f"peak: {peak}")
    for i in range(peak, 0, -1):
        if mi[i-1] > mi[i]:
            mi[i-1] = mi[i]

    for i in range(peak, n-1, 1):
        if mi[i+1] > mi[i]:
            mi[i+1] = mi[i]
    
    for i in range(n):
        print(mi[i],end=" ")
    print()