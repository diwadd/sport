import math

t = int(input())

for _ in range(t):

    n = int(input())
    s = input()

    front_scan_range = 4
    back_scan_range = 4
    looking_for = ["2","0","2","0"]
    
    found_at_front = []
    found_at_back = []
    index = None
    n_found = 0
    for i in range(front_scan_range):
        if s[i] == looking_for[i]:
            found_at_front.append(s[i])
            n_found += 1
        else:
            index = i
            break

    # print(found_at_front)
    if len(found_at_front) == front_scan_range:
        print(f"YES")
        continue

    for i in range(n-(front_scan_range-n_found), n):
        # print(f"i: {i} index: {index}")
        if s[i] == looking_for[index]:
            found_at_front.append(s[i])
            index += 1
        else:
            break

    # print(found_at_front)
    if ''.join(found_at_front) == "2020":
        print(f"YES")
    else:
        print(f"NO")