n = int(input())

d = set()

for i in range(n):

    liseq = input()
    d.add(hash(liseq))

print(len(d))

