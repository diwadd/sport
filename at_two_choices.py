nm = input().split(" ")
n = int(nm[0])

even = 0
odd = 0

for _ in range(n):

    si = input()
    ones = 0
    for s in si:
        if s == "1":
            ones += 1

    if ones % 2 == 0:
        even += 1
    else:
        odd += 1
    
print(even*odd)