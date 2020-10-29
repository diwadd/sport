import math


t = int(input())

MAX_RANGE = 64

a_vec = [1 for _ in range(MAX_RANGE)]

for i in range(2, MAX_RANGE):
    a_vec[i] = 2*a_vec[i-1] + 2**(2*(i-1))

a_sum = [a_vec[i] for i in range(MAX_RANGE)]

for i in range(2, MAX_RANGE):
    a_sum[i] = a_sum[i] + a_sum[i-1]

# print(a_vec)
# print(a_sum)

for _ in range(t):

    x = int(input())


    for i in range(1, MAX_RANGE):
        if a_sum[i] == x:
            print(i)
            break
        elif a_sum[i] > x:
            print(i-1)
            break
