import math

def make_bs(s_list):

    n = len(s_list)
    res = n
    n_odd_strings = 0
    n_even_bad_strings = 0
    for i in range(n):
        s = s_list[i]
        m = len(s)
        if m % 2 == 1:
            n_odd_strings += 1
        else:
            n_zeros = s.count("0")
            n_ones = s.count("1")
            if n_zeros % 2 == 1 or n_ones % 2 == 1:
                n_even_bad_strings += 1

    if n_odd_strings == 0 and n_even_bad_strings % 2 == 1:
        res -= 1

    return res


if __name__ == "__main__":
    i_mode = True

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