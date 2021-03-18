import math

def left_right(pa, pb, pc):

    xa = pa[0]
    ya = pa[1]

    xb = pb[0]
    yb = pb[1]

    xc = pc[0]
    yc = pc[1]

    return (xb - xa) * (yc - ya) - (xc - xa) * (yb - ya)


def graham_hull(h_vec):

    points = [[i, h_vec[i]] for i in range(len(h_vec))]
    # points = points[::-1]

    # print(points)

    # stack = [[0,0], [len(h_vec)+1, 0]]
    stack = [points[0], points[-1]]

    for i in range(len(points)-2, -1, -1):
        # print(f"--> {stack}")
        p1 = stack[-1]
        p2 = stack[-2]

        if len(stack) == 2 or left_right(p2, p1, points[i]) > 0:
            stack.append(points[i])
        else:
            stack.pop()
            stack.append(points[i])

    stack = stack[1:]
    stack = stack[::-1]
    stack = [s[0] for s in stack]

    return stack




t = int(input())

for _ in range(t):

    n = int(input())
    h_vec = input().split(" ")
    h_vec = [int(h) for h in h_vec]

    # hull = [0]
    # index = 0
    # while index < n-1:

    #     x1 = index
    #     y1 = h_vec[index]

    #     max_alpha = -math.inf
    #     max_index = None
    #     for j in range(index+1, n):

    #         x2 = j
    #         y2 = h_vec[j]

    #         alpha = None
    #         if y1 == y2:
    #             alpha = 90
    #         elif y1 > y2:
    #             alpha = 90 - 180*math.atan((y1 - y2) / (x2 - x1)) / math.pi
    #         elif y1 < y2:
    #             alpha = 90 + 180*math.atan((y2 - y1) / (x2 - x1)) / math.pi

    #         if max_alpha <= alpha:
    #             max_alpha = alpha
    #             max_index = j

    #         # print(f"alpha: {alpha} j: {j}")
    #     # print(f"max_alpha: {max_alpha} max_index: {max_index}")

    #     index = max_index
    #     hull.append(max_index)

    # print(hull)

    hull = graham_hull(h_vec)

    # print(hull)

    diff = 0

    for i in range(1, len(hull)):
        delta = hull[i] - hull[i-1]
        if diff < delta:
            diff = delta

    print(diff)


