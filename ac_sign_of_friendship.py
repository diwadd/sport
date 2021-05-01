ndh = input().split(" ")
n = int(ndh[0])
d = int(ndh[1])
h = int(ndh[2])


def get_sol(max_hi, max_di, h, d):
    a = (max_hi - h) / (max_di - d)
    b = max_hi - a * max_di
    return a, b


dh_list = [[0,0] for _ in range(n)]
for i in range(n):
    dihi = input().split(" ")

    di = int(dihi[0])
    hi = int(dihi[1])

    dh_list[i][0] = di
    dh_list[i][1] = hi

dh_list.sort(key=lambda x: x[0])

# print(dh_list)

pre_a = h/d
pre_b = 0
min_h = 0
for i in range(n-1, -1, -1):
    di = dh_list[i][0]
    hi = dh_list[i][1]

    if hi < pre_a*di + pre_b:
        continue
    else:
        a, b = get_sol(hi, di, h, d)
        pre_a = a
        pre_b = b
        min_h = pre_b


print(pre_b)