import math

def binary_search(a, x):
    left = 0
    right = len(a)
    n_less = 0
    n_greater = 0
    while left < right:
        middle = (left + right) // 2

        if a[middle] <= x:
            left = middle + 1
            if x != middle:
                n_less += 1
        else:
            right = middle
            n_greater += 1
    if left > 0 and a[left - 1] == x:
        return True, n_less, n_greater
    else:
        return False, n_less, n_greater

def combination(n, k):

    if k > n:
        return 0
    else:
        return math.factorial(n)//(math.factorial(k)*math.factorial(n-k))

nxpos = input().split(" ")

n = int(nxpos[0])
x = int(nxpos[1])
pos = int(nxpos[2])

n_smaller_numbers = x - 1
n_bigger_numbers = n - x

a = [i for i in range(n)]
_, n_less, n_greater = binary_search(a, pos)

c1 = combination(n_smaller_numbers, n_less) * math.factorial(n_less)
c2 = combination(n_bigger_numbers, n_greater) * math.factorial(n_greater)
res = c1 * c2 * math.factorial(n - n_less - n_greater - 1)
print(res % (1000000000 + 7))





