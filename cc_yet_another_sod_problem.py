t = int(input())

def get_sum_of_digits(n):

    d = []
    while n // 10 > 0:

        d.append(n % 10)
        n = n // 10
    
    d.append(n)
    return sum(d)


for _ in range(t):

    lr = input().split(" ")
    l = int(lr[0])
    r = int(lr[1])

    start = None
    for i in range(l, r+1):
        if get_sum_of_digits(i) % 3 == 0:
            start = i           
            break
    
    if start is None:
        print(0)
    else:
        delta = r - start
        print( (delta // 3) + 1 )