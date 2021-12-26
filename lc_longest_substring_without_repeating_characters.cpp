#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int start = 0;
        int stop = 0;
        int n = s.size();
        int longest_substring = 0;

        set<char> us;
        
        while(stop != n and start != n) {

            if(us.find(s[stop]) == us.end()) {
                us.insert(s[stop]);
                stop++;
                longest_substring = max(longest_substring, stop - start);
            } else {
                
                while(s[start] != s[stop]) {
                    us.erase(s[start]);
                    start++;
                }
                us.erase(s[stop]);
                start++;
            }
        }
        return longest_substring;
    }
};