import math
import heapq
import random



if __name__ == "__main__":


    t = int(input())

    for i in range(t):
        s1, s2 = input().split(" ")

        # print(f"{s1}<->{s2}")

        if s1 < s2:
            print(s1)
            continue

        s1 = list(s1)
        s2 = list(s2)

        n = min(len(s1), len(s2))
        smaller = False
        for k in range(n):

            if s1[k] >= s2[k]:
                # print(f"s1[k]: {s1[k]} s2[k]: {s2[k]}")
                for j in range(k+1, len(s1)):
                    # print(f"s1[j]: {s1[j]} s2[k] {s2[k]}")
                    if s1[j] <= s2[k]:
                        # print("Swaping")
                        s1[j], s1[k] = s1[k], s1[j]
                        # print(f"s1: {s1}")
                        if s1 < s2:
                            # print("Condition met")
                            smaller = True
                            break
                        else:
                            s1[j], s1[k] = s1[k], s1[j]
            if smaller == True:
                break

        if smaller == True:
            s1 = "".join(s1)
            print(s1)
        else:
            print("---")