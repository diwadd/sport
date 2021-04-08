from difflib import SequenceMatcher

t = int(input())


for _ in range(t):

    a = input()
    b = input()

    match = SequenceMatcher(None, a, b).find_longest_match(0, len(a), 0, len(b))
    lcs = a[match.a : match.a + match.size]

    if len(lcs) == 0:
        print(f"{len(a) + len(b)}")
    else:
        print(f"{len(a) + len(b) - 2 * len(lcs)}")