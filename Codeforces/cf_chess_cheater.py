import math

t = int(input())


for _ in range(t):
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])

    s = input()

    n_winning_steaks = 0
    n_wins = 0
    n_losses = 0
    losing_streaks = []
    for i in range(n):
        if s[i] == "W":
            n_wins += 1
            if i == 0 or s[i-1] == "L":
                n_winning_steaks += 1
        if s[i] == "L":
            n_losses += 1
            if i == 0 or s[i-1] == "W":
                losing_streaks.append(0)
            losing_streaks[-1] += 1

    # print(f"{n_wins} - {n_losses} - {n_winning_steaks}")
    # print(f"losing_streaks: {losing_streaks}")

    if k >= n_losses:
        print(2*n-1)
        continue

    if n_wins == 0:
        if k == 0:
            print(0)
        else:
            print(2*k-1)
        continue

    if s[0] == "L":
        losing_streaks[0] = math.inf
    if s[-1] == "L":
        losing_streaks[-1] = math.inf

    losing_streaks.sort()
    # print(f"losing_streaks: {losing_streaks}")

    n_wins += k
    for i in range(len(losing_streaks)):
        ls = losing_streaks[i]
        if ls > k:
            break
        k -= ls
        n_winning_steaks -= 1
    
    print(f"{2*n_wins - n_winning_steaks}")