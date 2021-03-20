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

    stack = [points[0], points[-1]]

    for i in range(len(points)-2, -1, -1):

        while len(stack) > 2 and left_right(stack[-2], stack[-1], points[i]) <= 0:
            stack.pop()
        stack.append(points[i])

    if stack[-1] == stack[0]:
        stack = stack[0:-1]

    stack.sort(key=lambda x: x[0])
    stack = [s[0] for s in stack]

    return stack


def jarvis_march(h_vec):

    n = len(h_vec)

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

        index = max_index
        hull.append(max_index)

    return hull


t = int(input())

for _ in range(t):

    n = int(input())
    h_vec = input().split(" ")
    h_vec = [int(h) for h in h_vec]

    hull = graham_hull(h_vec)

    diff = 0

    for i in range(1, len(hull)):
        delta = hull[i] - hull[i-1]
        if diff < delta:
            diff = delta

    print(diff)


