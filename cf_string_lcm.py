    import math
     
    def lcm(a, b):
        return abs(a * b) // math.gcd(a, b)
     
    tn = int(input())
     
    for _ in range(tn):
     
        s = input()
        t = input()
     
        sn = len(s)
        st = len(t)
     
        st_lcm = lcm(sn, st)
        # print(f"lcm: {st_lcm} {(st_lcm // st)} {(st_lcm // sn)}")
        s_p = (st_lcm // sn) * s
        t_p = (st_lcm // st) * t
        # print(f"--> {s_p} {t_p}")
        if(s_p == t_p):
            print(s_p)
        else:
            print(-1)