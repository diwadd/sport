import math
import random

class VP:
    def __init__(self, dv):
        self.d = dv[0]
        self.v = dv[1]


def get_result_fast(d1, v1, d2, v2, p):

    d = sorted([(d1, v1),(d2, v2)])

    plant_1 = VP(d[0])
    plant_2 = VP(d[1])

    n = math.ceil(p / plant_1.v)

    if(plant_1.d + n <= plant_2.d):
        print(plant_1.d + n - 1)
        # return plant_1.d + n - 1
    else:
        m = math.ceil( (p - abs(plant_1.d - plant_2.d)*plant_1.v)/(plant_1.v + plant_2.v) )
        print(plant_2.d + m - 1)
        # return plant_2.d + m - 1


def get_result_slow(d1, v1, d2, v2, p):

    s = 0
    d = 1
    while True:
        if d1 <= d:
            # print(f"-> d: {d} d1: {d1} d2: {d2} s: {s} p: {p}")
            s += v1
        if d2 <= d:
            # print(f"<- d: {d} d1: {d1} d2: {d2} s: {s} p: {p}")
            s += v2

        if s >= p:
            # print(f"d: {d} d1: {d1} d2: {d2} s: {s} p: {p}")
            return d

        d += 1

v1d1v2d2p = input().split(" ")
d1 = int(v1d1v2d2p[0])
v1 = int(v1d1v2d2p[1])
d2 = int(v1d1v2d2p[2])
v2 = int(v1d1v2d2p[3])
p = int(v1d1v2d2p[4])

get_result_fast(d1, v1, d2, v2, p)

