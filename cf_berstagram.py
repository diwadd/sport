import math

def high_low_position(n, m, a):
    post_position = {}
    position_post = {}
    post_max_pos = [i for i in range(0, n+1)]
    post_min_pos = [i for i in range(0, n+1)]
    for i in range(1, n+1):
        post_position[i] = i
        position_post[i] = i

    #print(f"Post positions: {sorted(post_position.items())}")
    #print(f"Position post: {sorted(position_post.items())}")

    n_a = len(a)
    for i in range(n_a):
        post_like = a[i]

        current_position = post_position[post_like]
        if current_position == 1:
            continue
        new_position = current_position - 1
        degradate_post = position_post[new_position]

        post_position[post_like] = new_position
        post_position[degradate_post] = current_position

        position_post[new_position] = post_like
        position_post[current_position] = degradate_post

        if new_position < post_max_pos[post_like]:
            post_max_pos[post_like] = new_position
        if new_position > post_min_pos[post_like]:
            post_min_pos[post_like] = new_position

        if current_position < post_max_pos[degradate_post]:
            post_max_pos[degradate_post] = current_position
        if current_position > post_min_pos[degradate_post]:
            post_min_pos[degradate_post] = current_position


        #print(f"Post positions: {sorted(post_position.items())}")
        #print(f"Position post: {sorted(position_post.items())}")
    return post_max_pos, post_min_pos



if __name__ == "__main__":
    nm = input()
    n, m = [int(i) for i in nm.split(" ")]
    a = input()
    a = [int(i) for i in a.split(" ")]
    
    post_max_pos, post_min_pos = high_low_position(n, m, a)
    for i in range(1, n+1):
        print(f"{post_max_pos[i]} {post_min_pos[i]}")

