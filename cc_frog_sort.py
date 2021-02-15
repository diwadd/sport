import math

t = int(input())


def make_current_state(world):

    current_state = []
    for w in world:
        for i in range(len(w)):
            current_state.append(w[i])
    return current_state

def is_world_single_state(world):

    for w in world:
        if len(w) > 1:
            return False

    return True


for _ in range(t):
    n = int(input())
    w_vec = input().split(" ")
    l_vec = input().split(" ")

    w_vec = [int(w) for w in w_vec]
    l_vec = [int(l) for l in l_vec]

    l_mapping = [0 for _ in range(n+1)]
    for i in range(n):
        l_mapping[w_vec[i]] = l_vec[i]

    MAX_POS = 50
    world = [[] for _ in range(MAX_POS)]

    for i in range(n):
        world[i] = [w_vec[i]]

    current_state = [w for w in w_vec]
    is_single_state = is_world_single_state(world)

    MAX_W = n+1
    res = 0
    while sorted(current_state) != current_state or is_single_state != True:

        for w in range(2, MAX_W):
            w_index = None
            for i in range(MAX_POS):
                if len(world[i]) > 0:
                    for k in range(len(world[i])):
                        if world[i][k] == w:
                            w_index = i
                            break

            pre_w_index = None
            for i in range(MAX_POS):
                if len(world[i]) > 0:
                    for k in range(len(world[i])):

                        if world[i][k] == w - 1:
                            pre_w_index = i
                            break

            if pre_w_index < w_index:

                is_single_state = is_world_single_state(world) 
                current_state = make_current_state(world)

                if sorted(current_state) != current_state or is_single_state != True:
                    continue
                else:
                    break
            elif pre_w_index > w_index:
                multi = math.ceil((pre_w_index - w_index)/l_mapping[w])
                new_index = w_index + multi*l_mapping[w]

                world[new_index].append(w)
                world[w_index].remove(w)
                res += multi
            elif pre_w_index == w_index:
                new_index = w_index + l_mapping[w]
                world[new_index].append(w)
                world[w_index].remove(w)
                res += 1

            is_single_state = is_world_single_state(world)

    print(res)

