import string
import random
import subprocess

# Template with specific example (Code Chef Smallest KMP, SKMP problem) for comparing two solutions.

def execute_solution(cmd, input_string):

    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
    encoded_input_string = input_string.encode('utf-8')
    solution_output, _ = p.communicate(encoded_input_string)

    return solution_output


def prepare_input():

    # Needs to be adjusted for each considered problem.
    # Should output the input for the solution.

    base = 'abcdefghijklmnopqrstuvwxyz'
    max_string_length = 1000
    ns = random.randint(1, max_string_length)
    np = random.randint(1, ns)

    s = []
    p = []
    for i in range(ns):
        c = random.choice(base)
        s.append(c)
        p.append(c)

    random.shuffle(p)

    s = ''.join(s)
    p = ''.join(p[0:np])

    return f"1\n{s}\n{p}\n"


def compare_two_solutions(cmd_one, cmd_two, same_input):

    output_one = execute_solution(cmd_one, same_input)
    output_two = execute_solution(cmd_two, same_input)

    if output_one != output_two:
        print(f"Mismatch found for:\n{same_input}\n")
        print(f"Expected: {output_two}")
        print(f"Got:      {output_one}")


if __name__ == "__main__":
    cmd_one = "./cc_smallest_kmp_xe"
    cmd_two = "./temp"

    n = 100000
    for i in range(n):

        same_input = prepare_input()
        # if i % 1000 == 0:
        print(f"We are at: {i}")
            # print(f"Checking: {same_input}") 

        compare_two_solutions(cmd_one, cmd_two, same_input)

