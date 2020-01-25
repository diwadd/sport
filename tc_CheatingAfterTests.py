import math

class CheatingAfterTests:
    def cheat(self, sc):
        n = len(sc)
        sum = 0
        m = 256 # greater then the largest possible number in sc
        g = 256 # greater then the largest possible number in sc
        for i in range(n):
            sum = sum + sc[i]
            if sc[i] >= 10:
                if sc[i] < m:
                    m = sc[i]
            if sc[i] < g:
                g = sc[i]

        new_sum_m = 0

        d = math.floor(m/10.0)
        s = round(10.0*(m/10.0 - math.floor(m/10.0)))
        if d < 9:
            new_sum_m = sum + 90 + s - m
        else:
            new_sum_m = sum + 99 - m

        new_sum_g = sum + 9 - g
        return max(new_sum_g, new_sum_m)