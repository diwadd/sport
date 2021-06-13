n = int(input())
    
a_vec = input().split(" ")
a_vec = [int(a) for a in a_vec]
    
a_vec.sort()
    
is_ok = True
    
for i in range(0, n):
    if a_vec[i] == i+1:
        continue
    else:
        is_ok = False
        break
    
if is_ok == True:
    print("Yes")
else:
    print("No")