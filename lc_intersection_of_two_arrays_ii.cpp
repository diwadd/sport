#include <set>
#include <map>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s1(nums1.begin(), nums1.end());

        std::map<int, int> m1 = {};
        std::map<int, int> m2 = {};
        for(auto e : nums1)
        {
            auto it = m1.find(e);
            if(it == m1.end())
            {
                m1[e] = 1;
            }
            else
            {
                it->second += 1;
            }
        }
        for(auto e : nums2)
        {
            auto it = m2.find(e);
            if(it == m2.end())
            {
                m2[e] = 1;
            }
            else
            {
                it->second += 1;
            }
        }

        vector<int> res = {};
        for(auto e : s1)
        {
            auto it1 = m1.find(e);
            auto it2 = m2.find(e);
            if(it1 == m1.end() or it2 == m2.end())
            {
                continue;
            }

            auto n = std::min(it1->second, it2->second);

            for(int i = 0; i < n; i++)
            {
                res.push_back(e);
            }
        }
        return res;
    }
};
