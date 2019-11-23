import math
import time

def fast_mi(s):
    s = list(s)
    s_even = [int(i) for i in s if int(i) % 2 == 0]
    s_odd = [int(i) for i in s if int(i) % 2 != 0]
    #print(f"s_even: {s_even}")
    #print(f"s_odd: {s_odd}")

    s_min = []
    while True:
        if len(s_even) == 0 and len(s_odd) != 0:
            s_min.append(s_odd.pop(0))
            continue
        elif len(s_even) != 0 and len(s_odd) == 0:
            s_min.append(s_even.pop(0))
            continue
        elif len(s_even) != 0 and len(s_odd) != 0:
            if s_even[0] < s_odd[0]:
                s_min.append(s_even.pop(0))
            else:
                s_min.append(s_odd.pop(0))
            continue
        elif len(s_even) == 0 and len(s_odd) == 0:
            break
        else:
            break

    s_min = [str(i) for i in s_min]
    return "".join(s_min)

# Non optimal solution - slow
def mi(s):
    s = list(s)
    s = [int(i) for i in s]
    n = len(s)
    for i in range(n):
        greater_index = math.inf
        for k in range(i-1, -1, -1):
            if s[k] % 2 == s[i] % 2:
                break
            if s[k] > s[i]:
                greater_index = k

        for j in range(i, 0, -1):
            if s[j-1] % 2 != s[j] % 2:
                if (s[j-1] > s[j]) or j > greater_index:
                    t = s[j]
                    s[j] = s[j-1]
                    s[j-1] = t
                else:
                    break
            else:
                break
    s = [str(i) for i in s]
    return "".join(s)

if __name__ == "__main__":
    s = ["0709", "1337", "246432", "04573628", "11749016685127962120", 3*10**5*"2"]
    r = ["0079", "1337", "234642", "04562738", "11406678262209151791", 3*10**5*"2"]

    for i in range(len(s)):
        start = time.time()
        res = fast_mi(s[i])
        end = time.time()
        print("elapsed time: {0}".format(end-start))
        assert res == r[i], "NOK processing {0} expected {1} got {2}".format(s[i],r[i],res)


    # t = input()
    # t = int(t)
    # res = [None for i in range(t)]
    # for i in range(t):
    #     s = input()
    #     res[i] = mi(s)

    # for i in range(t):
    #     print(res[i])