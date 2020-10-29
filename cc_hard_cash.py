import math

if __name__ == "__main__":

    t = int(input())

    for i in range(t):

        nk = input().split(" ")
        n = int(nk[0])
        k = int(nk[1])

        a = input().split(" ")
        a = [int(j) for j in a]

        s = sum(a)
        d = s // k
        
        # print(f"s: {s}")
        # print(f"d: {d}")
        print(s - d*k)