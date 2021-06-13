import math
import random
    
abc = input().split(" ")
    
a = int(abc[0])
b = int(abc[1])
c = int(abc[2])
    
def g_sign(a, b, c):
    if a == b or (abs(a) == abs(b) and c % 2 == 0):
        return 0
    elif a < 0 and b < 0:
        if c % 2 == 0:
            if a < b:
                return 1
            elif a > b:
                return -1
            else:
                return 0
        else:
            if a < b:
                return -1
            elif a > b:
                return 1
            else:
                return 0
    elif a > 0 and b > 0:
        if a < b:
            return -1
        else:
            return 1
    elif a == 0 and b != 0:
        if c % 2 != 0 and b < 0:
            return 1
        else:
            return -1
    elif a != 0 and b == 0:
        if c % 2 != 0 and a < 0:
            return -1
        else:
            return 1
    elif a < 0 and b > 0:
        if c % 2 == 0 and abs(a) > abs(b):
            return 1
        else:
            return -1
    elif a > 0 and b < 0:
        if c % 2 == 0 and abs(a) < abs(b):
            return -1
        else:
            return 1
    
def g_sign_ex(a, b, c):
    if math.pow(a, c) < math.pow(b, c):
        return -1
    elif math.pow(a, c) > math.pow(b, c):
        return 1
    else:
        return 0
    
r = g_sign(a, b, c)
    
if r == 1:
    print(">")
elif r == -1:
    print("<")
else:
    print("=")