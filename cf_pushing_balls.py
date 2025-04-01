t = int(input())


for _ in range(t):

    n, m = [int(a) for a in input().split(" ")]

    grid = []
    for _ in range(n):
        row = [int(aij) for aij in str(input())]
        grid.append(row)

    marks = [[0 for _ in range(m)] for _ in range(n)]

    # rows
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                marks[i][j] = 1
                continue
            else:
                break
    
    #cols
    for j in range(m):
        for i in range(n):
            if grid[i][j] == 1:
                marks[i][j] = 1
                continue
            else:
                break

    number_of_balls = 0
    number_of_marks = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                number_of_balls += 1
            if marks[i][j] == 1:
                number_of_marks += 1
    
    if number_of_balls == number_of_marks:
        print("YES")
    else:
        print("NO")
    

