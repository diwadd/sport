import math
import bisect

MAX_D = int(math.sqrt(2)*(100000 + 7))
seq = [float(math.ceil((n*n)/2.0)) for n in range(MAX_D)]

t = int(input())

for g in range(1, t+1):

    dk = input().split(" ")
    d = float(dk[0])
    k = float(dk[1])

    if d == k:
        print("Ashish")
        continue

    ratio = (d*d)/(k*k)

    left = 1
    right = len(seq) - 1
    marker = None
    while left <= right:
        middle = math.floor((left + right)/2)
        if seq[middle] == ratio:
            marker = middle
            break
        elif(seq[middle] < ratio):
            marker = middle            
            left = middle + 1
        elif (seq[middle] > ratio):
            right = middle - 1

    if(marker % 2 == 0):
        print("Utkarsh")
    else:
        print("Ashish")
