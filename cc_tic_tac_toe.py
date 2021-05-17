#!/usr/bin/env python3

t = int(input())

def get_n_cols(tictactoe, player):

    n = len(tictactoe)
    n_cols = 0
    for i in range(n):
        os = 0
        for j in range(n):
            if tictactoe[j][i] == player:
                os +=1
        if os == n:
            n_cols += 1
        
    return n_cols


def get_n_rows(tictactoe, player):

    n = len(tictactoe)
    n_rows = 0
    for i in range(n):
        os = 0
        for j in range(n):
            if tictactoe[i][j] == player:
                os +=1

        if os == n:
            n_rows += 1
        
    return n_rows

def get_diagonal(tictacto):

    n = len(tictactoe)
    s = set()
    n_d = 0
    for i in range(n):
        for j in range(n):
            if i == j:
                s.add(tictacto[i][j])

    p = None
    res = "_" in s
    if len(s) == 1 and res == False:
        n_d += 1
        if s.pop() == "O":
            p = 0
        else:
            p = 1
    
    s = set()
    sub = [2, 0, -2]
    for i in range(n):
        s.add(tictacto[i][i + sub[i]])

    res = "_" in s
    if len(s) == 1 and res == False:
        n_d += 1
        if s.pop() == "O":
            p = 0
        else:
            p = 1
    
    return n_d, p


for _ in range(t):

    tictactoe = []
    N_LINES = 3

    for _ in range(N_LINES):
        line = input()
        tictactoe.append(line)

    n = len(tictactoe)

    n_o = 0
    n_x = 0

    for i in range(n):
        for j in range(n):
            if tictactoe[i][j] == "O":
                n_o += 1
            elif tictactoe[i][j] == 'X':
                n_x += 1

    if abs(n_o - n_x) > 1 or n_x < n_o:
        print(3)
        continue

    n_cols_o = get_n_cols(tictactoe, "O")
    n_cols_x = get_n_cols(tictactoe, "X")
    n_rows_o = get_n_rows(tictactoe, "O")
    n_rows_x = get_n_rows(tictactoe, "X")
    n_diag_o, p = get_diagonal(tictactoe)

    o_won = n_cols_o == 1 or n_rows_o == 1 or (p == 0 and n_diag_o != 0)
    x_won = n_cols_x == 1 or n_rows_x == 1 or (p == 1 and n_diag_o != 0)

    both_players_won = o_won and x_won
    player_won = o_won or x_won

    if both_players_won == True:
        print(3)
    elif o_won == True and n_o < n_x:
        print(3)
    elif x_won == True and n_o == n_x:
        print(3)
    elif player_won == False and n_o + n_x < 9:
        print(2)
    elif player_won == False and n_o + n_x == 9:
        print(1)
    elif player_won == True:
        print(1)