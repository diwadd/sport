import math

if __name__ == "__main__":

    t = int(input())

    for i in range(t):

        n_p = input().split(" ")
        n = int(n_p[0])
        p = int(n_p[1])

        d = input().split(" ")
        d = [int(j) for j in d]

        s = 0
        q = p
        r = [0 for j in range(n)]
        rip_off = False
        for j in range(n-1, -1, -1):
        
            # print(f"d[j] {d[j]} s: {s} q: {q} (q // d[j]): {(q // d[j])} r: {r}")
            if q % d[j] != 0:
                # print("!=")
                div = (q // d[j])
                s = s + d[j]*div
                r[j] = div
                q = q - d[j]*div
            else:
                # print("==")
                div = (q // d[j])
                s = s + d[j]*(div-1)
                r[j] = (div-1)
                q = q - d[j]*(div-1)

            # print(f"d[j] {d[j]} s: {s} q: {q} (q // d[j]): {(q // d[j])} r: {r}")
            if s + d[j] > p:
                r[j] = r[j] + 1
                rip_off = True
                break

        if rip_off == False:
            print("NO")
        else:
            st = "YES"
            for j in range(n):
                st = st + f" {r[j]}"
            print(st)