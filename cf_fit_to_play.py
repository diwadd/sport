t = int(input())

for _ in range(t):
    n = int(input())
    numbers = input().split(" ")
    numbers = [int(nb) for nb in numbers]
    
    max_ele = [0 for _ in range(n)]
    min_ele = [0 for _ in range(n)]
    
    current_max = numbers[n-1]
    for i in range(n-1, -1, -1):
        current_max = max(current_max, numbers[i])
        max_ele[i] = current_max
    
    current_min = numbers[0]
    for i in range(n):
        current_min = min(current_min, numbers[i])
        min_ele[i] = current_min

    max_dif = [max_ele[i] - min_ele[i] for i in range(n)]
    res = max(max_dif)
    if res == 0:
        print("UNFIT")
    else:
        print(res)
