import math

def new_mp(p):
    
    n = len(p)
    possible_moves = [1 for i in range(n)]
    for i in range(n):
        for j in range(n):
            if p[j] == i:
                for k in range(j, 0, -1):
                    if p[k-1] < p[k]:
                        break

                    if possible_moves[k-1] == 1:
                        t = p[k]
                        p[k] = p[k-1]
                        p[k-1] = t
                        possible_moves[k-1] = 0
    return p



if __name__ == "__main__":
    q = input()
    q = int(q)
    res = [None for i in range(q)]
    for i in range(q):
        n = input()
        p = input()
        p = [int(i) for i in p.split(" ")]
        res[i] = new_mp(p)

    # print("Printing the resutls: ")
    for i in range(q):
        s = str(res[i]).replace(", ", " ").replace("[","").replace("]","")
        print(s)