import math

def pwc(a, b, n, S):
    needed_a_coins = S // n
    delta = S - n*min(needed_a_coins, a)
    if delta == 0:
        return "YES"
    else:
        if delta <= b:
            return "YES"
        else:
            return "NO"


if __name__ == "__main__":
    q = input()
    q = int(q)
    res = [None for i in range(q)]
    for i in range(q):
        line  = input()
        a, b, n, S = [int(i) for i in line.split(" ")]
        res[i] = pwc(a, b, n, S)
    
    for  i in range(q):
        print(res[i])