import glob
import os

cwd = os.getcwd()
files = glob.glob(cwd + "\\*")

valid_extensions = [".cpp", ".go", ".py"]
invalid_problem_names = ["cf_custom", "compare_solutions", "check_number_of_problems"]
d = set()
for i in range(len(files)):

    s = files[i]
    problem_name, extension = os.path.splitext(s)

    is_ok = True
    for ipn in invalid_problem_names:
        if ipn in problem_name:
            is_ok = False
            break

    if is_ok == False:
        continue

    if extension in valid_extensions:
        d.add(problem_name)

print(f"Number of problems: {len(d)}")

