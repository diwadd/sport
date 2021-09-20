t = int(input())

for _ in range(t):

    n = int(input())
    vec = input().split(" ")
    vec = [int(v) for v in vec]

    ne = 0
    no = 0
    for v in vec:
        if v % 2 == 0:
            ne += 1
        else:
            no += 1
    
    if no == 0 or ne == 0:
        print(-1)
    else:
        output = []
        for v in vec:
            if v % 2 == 0:
                output.append(v)
        
        for v in vec:
            if v % 2 != 0:
                output.append(v)
        
        output = [str(o) for o in output]
        print(" ".join(output))
