import re

s = input()

max_length = 0
for m in re.finditer(r"(ZONe)+", s):
    n = len(m.group())
    max_length += n//4

print(max_length)
