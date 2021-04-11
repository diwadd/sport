n_dec = input()

def check_pal(pal_can):
    n = len(pal_can)
    for i in range(0, n//2):
        if(pal_can[i] != pal_can[n-i-1]):
            return False
    
    return True

n = len(n_dec)
is_pal = check_pal(n_dec)

if is_pal == True:
    print("Yes")
elif n_dec[n-1] != "0":
    print("No")
else:
    index = None
    for i in range(n-1, -1, -1):
        if n_dec[i] != "0":
            index = i
            break

    cut_dec = n_dec[0:index+1]

    # print(cut_dec)

    is_pal = check_pal(cut_dec)
    if is_pal == True:
        print("Yes")
    else:
        print("No")
