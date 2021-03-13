import math

MAX_MASK = 12

n = int(input())

def get_mask():

    mask = [0 for _ in range(MAX_MASK)]
    value = [0 for _ in range(MAX_MASK)]
    p = 3
    mask[0] = 10**p - 1
    value[0] = 10**p - 1
    for i in range(1, MAX_MASK):
        p = p + 3
        mask[i] = (10**p - 1) - value[i-1]
        value[i] = 10**p - 1

    return mask, value

mask, value = get_mask()

# print(mask)
# print(value)

index = None
for i in range(0, MAX_MASK):
    # print(f"n: {n} value[{i}]: {value[i]}")
    if n <= value[i]:
        index = i
        break

# print(f"Index: {index}")

res = (n - value[index - 1])*index
index -= 1
while index > 0:
    # print(f"--> index: {index}")
    res += mask[index]*index
    index -= 1


print(res)






