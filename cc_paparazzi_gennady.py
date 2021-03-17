import math

t = int(input())

for _ in range(t):

    n = int(input())
    h_vec = input().split(" ")
    h_vec = [int(h) for h in h_vec]

    hull = [0]
    index = 0
    while index < n-1:

        x1 = index
        y1 = h_vec[index]

        max_alpha = -math.inf
        max_index = None
        for j in range(index+1, n):

            x2 = j
            y2 = h_vec[j]

            alpha = None
            if y1 == y2:
                alpha = 90
            elif y1 > y2:
                alpha = 90 - 180*math.atan((y1 - y2) / (x2 - x1)) / math.pi
            elif y1 < y2:
                alpha = 90 + 180*math.atan((y2 - y1) / (x2 - x1)) / math.pi

            if max_alpha <= alpha:
                max_alpha = alpha
                max_index = j

            # print(f"alpha: {alpha} j: {j}")
        # print(f"max_alpha: {max_alpha} max_index: {max_index}")

        index = max_index
        hull.append(max_index)

        # print(hull)
    diff = 0

    for i in range(1, len(hull)):
        delta = hull[i] - hull[i-1]
        if diff < delta:
            diff = delta

    print(diff)


