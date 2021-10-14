import math

t = int(input())

INFINITE_TUPLE = (-math.inf, -math.inf)

def find_digits(d, o, number):

    o_index = None
    for i in range(len(number)-1, -1 ,-1):
        if number[i] == o:
            o_index = i
            break

    if o_index is None:
        return INFINITE_TUPLE

    d_index = None
    for i in range(o_index-1, -1 ,-1):
        if number[i] == d:
            d_index = i
            break

    if d_index is None:
        return INFINITE_TUPLE
    else:
        return (d_index, o_index)


for _ in range(t):

    s = input()


    d00, o00 = find_digits("0", "0", s)
    d25, o25 = find_digits("2", "5", s)
    d50, o50 = find_digits("5", "0", s)
    d75, o75 = find_digits("7", "5", s)

    # print(f"d00: {d00} d25 {d25} d50: {d50} d75: {d75}")

    m = max(d00, d25, d50, d75)

    print(len(s) - m - 1 - 1)
        
