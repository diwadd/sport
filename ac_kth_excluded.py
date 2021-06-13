import bisect

nq = input().split(" ")

n = int(nq[0])
q = int(nq[1])

a_vec = input().split(" ")
a_vec = [int(a) for a in a_vec]

ranges_list = []

if a_vec[0] != 1:
    ranges_list.append([0, a_vec[0]])

for i in range(1, len(a_vec)):
    if a_vec[i] - a_vec[i-1] == 1:
        continue
    else:
        ranges_list.append([a_vec[i-1], a_vec[i]])

if a_vec[-1] != 10*18:
    ranges_list.append([a_vec[-1], 10**19])
 
numbers = [0 for _ in range(len(ranges_list))]
 
for i in range(len(ranges_list)):
    numbers[i] = ranges_list[i][1] - ranges_list[i][0] - 1
 
prefix_sum = [0 for _ in range(len(numbers))]
 
prefix_sum[0] = numbers[0]
for i in range(1, len(numbers)):
    prefix_sum[i] = prefix_sum[i-1] + numbers[i]

for _ in range(q):
    k = int(input())
 
    pos = bisect.bisect_left(prefix_sum, k)

    res = None
    if pos == len(ranges_list) - 1:
        if pos - 1 >= 0:
            res = ranges_list[pos][0] + k - prefix_sum[pos-1]
        else:
            res = ranges_list[pos][0] + k
    elif pos == 0:
        res = ranges_list[pos][0] + k
    else:
        if pos - 1 >= 0:
            res = ranges_list[pos][0] + k - prefix_sum[pos-1]
        else:
            res = ranges_list[pos][0] + k
 
    print(f"{res}")