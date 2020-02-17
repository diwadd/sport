import math

if __name__ == "__main__":
    t = int(input())

    for i in range(t):

        n = int(input())
        a = input().split(" ")
        b = input().split(" ")

        a = [int(ai) for ai in a]
        b = [int(bi) for bi in b]

        a.sort()
        b.sort()

        s = 0
        for j in range(n):
            s = s + min(a[j], b[j])
        
        print(s)