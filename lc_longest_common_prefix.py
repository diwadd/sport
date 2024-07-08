import math

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:

        shortest_word = None
        shortest_word_size = math.inf

        for word in strs:
            if word == "":
                return ""

            if len(word) < shortest_word_size:
                shortest_word_size = len(word)
                shortest_word = word

        print(shortest_word)

        common_prefix_index = -1
        for i in range(0, len(shortest_word)):
            letter = word[i]
            all_words_agree = True
            for word in strs:
                if word[i] == letter:
                    continue
                else:
                    all_words_agree = False
            if all_words_agree == True:
                common_prefix_index = i
            else:
                break
        
        if common_prefix_index == -1:
            return ""
        else:
            return shortest_word[0:common_prefix_index+1]
