number = input()

digits = len(number)

res = 0
for d in range(1, digits):

    if d % 2 != 0:
        continue
    delta = (10 ** (d//2) - 1) - (10 ** ((d//2) - 1) - 1)
    res += delta


if digits % 2 == 0:
    m = digits//2
    half1 = number[0:m]
    half2 = number[m:]

    max_number = None
    if int(half1) <= int(half2):
        max_number = int(half1)
    else:
        max_number = int(half1) - 1

    min_number = int(str(10**(m-1)))

    if m > 1 != 0:
        res += (max_number - min_number) + 1
    else:
        res += max_number

print(res)


