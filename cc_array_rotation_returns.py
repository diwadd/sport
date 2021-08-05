#!/usr/bin/python3

import math

t = int(input())

def make_move(vec, n):
    if n == 0:
        return vec
    else:
        return vec[n:] + vec[:n]

for _ in range(t):

    n = int(input())
    a_vec = input().split(" ")
    b_vec = input().split(" ")

    a_vec = [int(a) for a in a_vec]
    b_vec = [int(b) for b in b_vec]

    if n == 1:
        print( (a_vec[0] + b_vec[0]) % n )
        continue

    a0 = a_vec[0]

    c_zero_min = math.inf
    index_zero_min = None
    for i in range(n):
        c0 = (a0 + b_vec[i]) % n

        if c0 < c_zero_min:
            c_zero_min = c0
            index_zero_min = i

    c_one_min = math.inf
    index_one_min = None
    for i in range(n):
        if i == index_zero_min:
            continue

        c0 = (a0 + b_vec[i]) % n

        if c0 < c_one_min:
            c_one_min = c0
            index_one_min = i

    b_zero = make_move(b_vec, index_zero_min)
    b_one = make_move(b_vec, index_one_min)

    c_zero = [(a_vec[i] + b_zero[i]) % n for i in range(n)]
    c_one = [(a_vec[i] + b_one[i]) % n for i in range(n)]

    smaller = c_zero
    for i in range(n):
        if c_zero[i] == c_one[i]:
            continue
        elif c_zero[i] < c_one[i]:
            smaller = c_zero
            break
        elif c_zero[i] > c_one[i]:
            smaller = c_one
            break

    smaller = [str(s) for s in smaller]
    print(" ".join(smaller))