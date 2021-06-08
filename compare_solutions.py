import string
import random
import subprocess

# Template with specific example (Code Chef Smallest KMP, SKMP problem) for comparing two solutions.

def execute_solution(cmd, input_string):

    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
    encoded_input_string = input_string.encode('utf-8')
    solution_output, _ = p.communicate(encoded_input_string)

    return solution_output


def get_whlrud():

    max_string_length = 6
    while True:
        w = random.randint(1, max_string_length)
        h = random.randint(1, max_string_length)

        l = random.randint(1, w)
        r = random.randint(1, w)

        u = random.randint(1, h)
        d = random.randint(1, h)

        if 1 <= l and l <= r and r <= w and 1 <= u and u <= d and d <= h and l != 1 and u != 1 and r != w and d != w:
            return w, h, l, u, r, d



def prepare_input():

    # Needs to be adjusted for each considered problem.
    # Should output the input for the solution.
    w, h, l, u, r, d = get_whlrud()

    return f"1\n{w} {h} {l} {u} {r} {d}\n"


def compare_two_solutions(cmd_one, cmd_two, same_input):

    output_one = execute_solution(cmd_one, same_input)
    output_two = execute_solution(cmd_two, same_input)

    if output_one != output_two:
        print(f"Mismatch found for:\n{same_input}\n")
        print(f"Expected: {output_two}")
        print(f"Got:      {output_one}")


if __name__ == "__main__":
    cmd_one = "./gks_2020_round_b_wandering_robot.py"
    cmd_two = "./ttt"

    n = 100000
    for i in range(n):

        same_input = prepare_input()
        # if i % 1000 == 0:
        print(f"We are at: {i}")
            # print(f"Checking: {same_input}") 

        compare_two_solutions(cmd_one, cmd_two, same_input)

