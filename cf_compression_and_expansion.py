t = int(input())

for _ in range(t):

    n = int(input())

    stack = []
    for i in range(n):
        ai = int(input())
        if ai == 1:
            stack.append(ai)
        else:
            while ai - stack[-1] != 1:
                stack.pop()
            stack[-1] += 1
        ps = [str(s) for s in stack]
        print(".".join(ps))
