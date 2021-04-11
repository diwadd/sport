import glob
import os

cwd = os.getcwd()
files = glob.glob(cwd + "/*")

valid_extensions = [".cpp", ".go", ".py", ".kt"]
invalid_prefixes = ["at_", "cf_", "tc_", "cc_", "co_", "gks_", "gcj_"]
d = set()
for i in range(len(files)):

    s = files[i]
    problem_name, extension = os.path.splitext(s)

    is_ok = False
    for ipn in invalid_prefixes:
        if ipn in problem_name:
            is_ok = True
            break

    if is_ok == False:
        continue

    if extension in valid_extensions:
        d.add(problem_name)

print(f"Number of problems: {len(d)}")

