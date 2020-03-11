import math


if __name__ == "__main__":

    t = int(input())

    for i in range(t):
        nm = input().split(" ")
        n = int(nm[0])
        m = int(nm[0])

        x_points = input().split(" ")
        y_points = input().split(" ")

        x_points = [int(x) for x in x_points]
        y_points = [int(y) for y in y_points]

        x_points.sort()
        y_points.sort()

        # print(x_points)
        # print(y_points)

        x_positive = [x for x in x_points if x >= 0]
        x_negative = [x for x in x_points if x < 0]

        y_positive = [y for y in y_points if y >= 0]
        y_negative = [y for y in y_points if y < 0]

        res = 0

        if x_positive[0] == 0 and y_positive[0] != 0:
            
            q_ne = 0
            q_se = 0
            q_nw = 0
            q_sw = 0

            if len(x_positive) > 0:
                q_ne = (len(x_positive)-1)*len(y_positive)
                q_se = (len(x_positive)-1)*len(y_negative)

            if len(x_negative) > 0:
                q_nw = (len(x_negative))*len(y_positive)
                q_sw = (len(x_negative))*len(y_negative)

            # print(f"1 q_ne: {q_ne} q_se: {q_se} q_nw: {q_nw} q_sw: {q_sw}")
            res = res + q_ne + q_se + q_nw + q_sw
        elif x_positive[0] != 0 and y_positive[0] == 0:

            q_ne = 0
            q_se = 0
            q_nw = 0
            q_sw = 0

            if len(x_positive) > 0:
                q_ne = len(x_positive)*(len(y_positive)-1)
                q_se = len(x_positive)*(len(y_negative))

            if len(x_negative) > 0:
                q_nw = len(x_negative)*(len(y_positive)-1)
                q_sw = len(x_negative)*(len(y_negative))

            # print(f"2 q_ne: {q_ne} q_se: {q_se} q_nw: {q_nw} q_sw: {q_sw}")
            res = res + q_ne + q_se + q_nw + q_sw
        elif x_positive[0] == 0 and y_positive[0] == 0:

            q_ne = 0
            q_se = 0
            q_nw = 0
            q_sw = 0

            if len(x_positive) > 0:
                q_ne = (len(x_positive)-1)*(len(y_positive)-1)
                q_se = (len(x_positive)-1)*(len(y_negative)-1)

            if len(x_negative) > 0:
                q_nw = (len(x_negative)-1)*(len(y_positive)-1)
                q_sw = (len(x_negative)-1)*(len(y_negative)-1)

            # print(f"3 q_ne: {q_ne} q_se: {q_se} q_nw: {q_nw} q_sw: {q_sw}")
            res = res + q_ne + q_se + q_nw + q_sw

        # print(f"x_positive: {x_positive}")
        # print(f"x_negative: {x_negative}")

        # print(f"y_positive: {y_positive}")
        # print(f"y_negative: {y_negative}")

        x_set = set()
        y_set = set()

        for j in range(len(x_points)):
            if x_points[j] == 0:
                continue
            x_set.add(x_points[j])

        for j in range(len(y_points)):
            if y_points[j] == 0:
                continue
            y_set.add(y_points[j])

        # print(f"x_set: {x_set}")
        # print(f"y_set: {y_set}")

        for j in range(len(x_negative)):

            x2 = x_negative[j]
            # print(f"--- x2: {x2} ---")
            for k in range(len(x_positive)):
                x1 = x_positive[k]
                # print(f"x1: {x1}")
                y3 = math.sqrt(-x2*x1)

                # print(f"y3: {y3}")

                is_zero = round(y3 - int(y3), 14) < math.pow(10, -14)
                # print(f"is_zero: {is_zero}")
                if is_zero == False:
                    continue
                
                if int(y3) in y_set:
                    # print("adding to res")
                    res += 1

                if -int(y3) in y_set:
                    # print("adding to res")
                    res += 1

        for j in range(len(y_negative)):

            y2 = y_negative[j]
            # print(f"y2: {y2}")
            for k in range(len(y_positive)):
                y1 = y_positive[k]
                # print(f"y1: {y1}")
                x3 = math.sqrt(-y2*y1)

                # print(f"x3: {x3}")

                is_zero = round(x3 - int(x3), 14) < math.pow(10, -14)
                # print(f"is_zero: {is_zero}")
                if is_zero == False:
                    continue
                
                if int(x3) in x_set:
                    # print("adding to res")
                    res += 1

                if -int(x3) in x_set:
                    # print("adding to res")
                    res += 1

        print(f"{res}")