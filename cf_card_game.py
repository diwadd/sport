t = int(input())

for _ in range(t):
    
    n, x = input().split(" ")
    n = int(n)
    x = int(x)
    
    number_of_even = 0
    number_of_odd = 0

    if n % 2 == 0:
        number_of_odd = n // 2
        number_of_even = n // 2
    else:
        number_of_even = n // 2
        number_of_odd = n // 2 + 1
    
    if x % 2 == 0:
        print(f"{number_of_even - 1}")
    else:
        print(f"{number_of_odd - 1}")
