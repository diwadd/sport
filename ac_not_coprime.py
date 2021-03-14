import math

n = int(input())
    
x_vec = input().split(" ")
x_vec = [int(x) for x in x_vec]
    
    
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]
found_primes = []
non_primes = []

for x in x_vec:

    if x in primes:
        found_primes.append(x)
    else:
        non_primes.append(x)

# print(found_primes)
# print(non_primes)

if len(non_primes) == 0:
    res = 1
    for fp in found_primes:
        res *= fp
    print(res)
else:
    non_res = None
    MAX_COMPOSIT = 220
    for i in range(2, MAX_COMPOSIT + 1):
        
        is_ok = True
        for np in non_primes:
            if math.gcd(np, i) == 1:
                is_ok = False
                break;     

        if is_ok == True:
            non_res = i
            break
    # print(f"non_res: {non_res}")
    for fp in found_primes:
        if non_res % fp == 0:
            continue
        else:
            non_res *= fp
    print(non_res)


    