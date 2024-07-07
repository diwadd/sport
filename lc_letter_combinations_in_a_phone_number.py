def digit_to_letters(digit):
    if digit == "2":
        return ["a", "b", "c"]
    if digit == "3":
        return ["d", "e", "f"]
    if digit == "4":
        return ["g", "h", "i"]
    if digit == "5":
        return ["j", "k", "l"]
    if digit == "6":
        return ["m", "n", "o"]
    if digit == "7":
        return ["p", "q", "r", "s"]
    if digit == "8":
        return ["t", "u", "v"]
    if digit == "9":
        return ["w", "x", "y", "z"]

def append_letters(letters, new_letters):

    new_stems = []
    for stem in letters:
        for new_stem in new_letters:
            new_stems.append(stem + new_stem)

    return new_stems

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []

        letters = digit_to_letters(digits[0])

        for i in range(1, len(digits)):
            new_letters = digit_to_letters(digits[i])
            letters = append_letters(letters, new_letters)

        return letters
