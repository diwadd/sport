import math

if __name__ == "__main__":

    # it = find_intersection([[2, 10], [0, 8], [-2, 4], [-3, -12]])
    # print(it)

    q = int(input())

    for i in range(q):

        nm = input().split(" ")
        n = int(nm[0])
        m = int(nm[1])

        # print(f"n: {n} m: {m}")
        current_temp_low = m
        current_temp_high = m       
        c = [[0, 0, 0] for j in range(n)]
        d = {}

        prev_time = 0
        no_intersection = True
        for j in range(n):
            tlh = input().split(" ")

            t = int(tlh[0])
            l = int(tlh[1])
            h = int(tlh[2])

            if t != prev_time:
                current_temp_low = current_temp_low - t + prev_time
                current_temp_high = current_temp_high + t - prev_time
                prev_time = t

            # print(f"1-h: {h} l: {l} current_temp_low: {current_temp_low} current_temp_high: {current_temp_high}")
            if h < current_temp_low or l > current_temp_high:
                no_intersection = False

            current_temp_low = max(current_temp_low, l)
            current_temp_high = min(current_temp_high, h)
            # print(f"2-h: {h} l: {l} current_temp_low: {current_temp_low} current_temp_high: {current_temp_high}")

        if no_intersection == True:
            print("YES")
        else:
            print("NO")

        #intersection = find_intersection 