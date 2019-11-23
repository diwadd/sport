import math

def make_bs(s_list):

    t_zeros = 0
    t_ones = 0
    n = len(s_list)
    n_zeros_in_strings = [0 for i in range(n)]
    n_ones_in_strings = [0 for i in range(n)]
    for i in range(n):
        s = s_list[i]
        m = len(s)
        for j in range(m):
            if s[j] == "0":
                n_zeros_in_strings[i] = n_zeros_in_strings[i] + 1
                t_zeros = t_zeros + 1
            if s[j] == "1":
                n_ones_in_strings[i] = n_ones_in_strings[i] + 1
                t_ones = t_ones + 1
    
    n_even_zero_strings = 0
    n_odd_zero_strings = 0
    n_even_one_strings = 0
    n_odd_one_strings = 0

    res = 0
    for i in range(n):
        s = s_list[i]
        m = len(s)
        print(f"m: {m} s: {s} t_zeros: {t_zeros} t_ones: {t_ones} n_odd_zero_strings: {n_odd_zero_strings} n_odd_one_strings: {n_odd_one_strings}")
        if m <= t_zeros:
            t_zeros = t_zeros - m
            if m % 2 == 0:
                n_even_zero_strings = n_even_zero_strings + 1
            else:
                n_odd_zero_strings = n_odd_zero_strings + 1
            res = res + 1
            continue
        if m <= t_ones:
            t_ones = t_ones - m
            if m % 2 == 0:
                n_even_one_strings = n_even_one_strings + 1
            else:
                n_odd_one_strings = n_odd_one_strings + 1
            res = res + 1
            continue

        if m <= t_zeros + t_ones:
            if t_zeros > t_ones:
                t_ones = t_ones - (m - t_zeros)
                t_zeros = 0
                res = res + 1
            elif t_ones > t_zeros:
                t_zeros = t_zeros - (m - t_ones)
                t_ones = 0
                res = res + 1

    return res


if __name__ == "__main__":
    i_mode = False

    if i_mode:
        q = input()
        q = int(q)

        res = [None for k in range(q)]
        for i in range(q):
            n = input()
            n = int(n)
            s_list = [None for k in range(n)]
            for j in range(n):
                s = input()
                s_list[j] = s
            res[i] = make_bs(s_list)

        for i in range(q):
            print(res[i])
    else:
        s_list = ["00", "01"]
        s_list = ["1110","100110","010101"]
        print(make_bs(s_list))