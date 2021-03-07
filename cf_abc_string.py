t = int(input())


def check_string(abc):

    stack = []

    stack.append(abc[0])
    for i in range(1, len(abc)):
        if len(stack) == 0:
            stack.append(abc[i])
            continue
        elif stack[-1] == '(' and abc[i] == ')':
            stack.pop()
            continue
        else:
            stack.append(abc[i])
            continue
    
    if len(stack) == 0:
        return True
    else:
        return False

for _ in range(t):

    abc = input()

    f = abc[0]

    if f == 'A':
        rem = ['B','C']
    elif f == 'B':
        rem = ['A','C']
    elif f == 'C':
        rem = ['A','B']

    left = 0

    brackets = [['(','('],[')',')'],['(',')'],[')','(']]
    is_ok = False
    for b in brackets:

        new_abc = abc.replace(rem[0], b[0])
        new_abc = new_abc.replace(rem[1], b[1])
        new_abc = new_abc.replace(f, '(')

        is_ok = check_string(new_abc)

        if is_ok == True:
            break

    if is_ok == True:
        print("YES")
    else:
        print("NO")