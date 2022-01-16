#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n = seats.size();
        vector<pair<int, int>> markers(n, pair<int,int>(0, 0));
        
        markers[n-1].second = n-1;
        
        for(int i = 1; i < n; i++) {
            if(seats[i] == 1) {
                markers[i].first = i;
            } else {
                markers[i].first = markers[i-1].first;
            }
        }
        
        for(int i = n-2; i >= 0; i--) {
            if(seats[i] == 1) {
                markers[i].second = i;
            } else {
                markers[i].second = markers[i+1].second;
            }
        }
        
        int res = -1;
        for(int i = 0; i < n; i++) {
            
            if(seats[i] == 1)
                continue;
            
            int d1 = i - markers[i].first;
            int d2 = markers[i].second - i;
            res = max( res, min(d1,d2));
        }
        
        if(seats[0] == 0) {
            int d2 = markers[0].second - 0;
            res = max(res, d2);
        }

        if(seats[n-1] == 0) {
            int d1 = n-1 - markers[n-1].first;
            res = max(res, d1);
        }
        
        return res;
        
    }
};