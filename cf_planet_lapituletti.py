t = int(input())

def check_time(hs, mt):
    for h in hs:
        hi = int(h)
        if hi == 3 or hi == 4 or hi == 6 or hi == 7 or hi == 9:
            return False

    for m in mt:
        mi = int(m)
        if mi == 3 or mi == 4 or mi == 6 or mi == 7 or mi == 9:
            return False

    return True

def is_valid(hss, mts, h, m):


    hss_mro = ""
    for hh in hss:
        if hh == "2":
            hss_mro = "5" + hss_mro
        elif hh == "5":
            hss_mro = "2" + hss_mro
        else:
            hss_mro = hh + hss_mro

    mts_mro = ""
    for mm in mts:
        if mm == "2":
            mts_mro = "5" + mts_mro
        elif mm == "5":
            mts_mro = "2" + mts_mro
        else:
            mts_mro = mm + mts_mro


    # print(f"is valid: {hss_mro}:{mts_mro}")

    hss_mro = int(hss_mro)
    mts_mro = int(mts_mro)

    if mts_mro < h and hss_mro < m:
        return True
    else:
        return False


for _ in range(t):

    hm = input().split(" ")
    h = int(hm[0])
    m = int(hm[1])

    hhmm = input()

    h1 = int(hhmm[0])
    h2 = int(hhmm[1])
    m1 = int(hhmm[3])
    m2 = int(hhmm[4])

    hs = int(hhmm[0:2])
    mt = int(hhmm[3:])

    mts = None
    hss = None
    if len(str(mt)) == 1:
        mts = "0" + str(mt)
    else:
        mts = str(mt)

    if len(str(hs)) == 1:
        hss = "0" + str(hs)
    else:
        hss = str(hs)

    is_ok = check_time(hss, mts)
    if is_ok == True:
        if is_valid(hss, mts, h, m) == True:
            print(f"{hss}:{mts}")
            continue

    while True:
        mt += 1
        if mt >= m:
            mt = 0
            hs += 1
            if hs >= h:
                hs = 0
        
        mts = None
        hss = None
        if len(str(mt)) == 1:
            mts = "0" + str(mt)
        else:
            mts = str(mt)

        if len(str(hs)) == 1:
            hss = "0" + str(hs)
        else:
            hss = str(hs)

        # print(f"-> {hss}:{mts}")

        is_ok = check_time(hss, mts)
        if is_ok == True:
            # print(f"is_ok: {is_ok}")
            iv = is_valid(hss, mts, h, m)
            # print(f"iv: {iv}")
            if iv == True:
                print(f"{hss}:{mts}")
                break