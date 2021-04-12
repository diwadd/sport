t = int(input())

for _ in range(t):
    n = int(input())

    stores = n // 4
    free_cubes = n % 4

    # Each side will have a 5 and a 6 visable
    # and there will be 4 sides which gives 44
    res = stores * 44

    if free_cubes == 0:
        if stores > 0:
            res += 4*4
    elif free_cubes == 1:
        res += 20
        if stores > 0:
            res += 3*4
    elif free_cubes == 2:
        res += 36
        if stores > 0:
            res += 2*4
    elif free_cubes == 3:
        res += 51
        if stores > 0:
            res += 1*4
    
    print(res)