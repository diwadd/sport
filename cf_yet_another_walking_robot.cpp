#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <map>
#include <utility>
#include <limits>

using namespace std;
typedef unsigned long long int ulli;
 
int main() {
 
    const int n_bits = 32;
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    for(int i = 0; i < t; i++){
 
        int n;
        cin >> n;

        string s;
        cin >> s;

        int px = 0;
        int py = 0;
        map<pair<int, int>, int> visited;
        int r = -1;
        int l = -1;
        int len = numeric_limits<int>::max();
        visited[make_pair(0,0)] = 0;
        for(int j = 0; j < s.length(); j++){
            if( s[j] == 'L')
                 px = px - 1;
            if( s[j] == 'R')
                 px = px + 1;
            if( s[j] == 'U')
                 py = py + 1;
            if( s[j] == 'D')
                 py = py - 1;
            
            if(visited.find(make_pair(px,py)) == visited.end() ) {
                // not found
                visited[make_pair(px,py)] = j+1;
            } else {
                int d = j + 1 - visited[make_pair(px,py)];
                if (d < len) {
                    len = d;
                    r = visited[make_pair(px,py)];
                    l = j;
                }
                visited[make_pair(px,py)] = j+1;
            }


        }

        if(r == -1)
            cout << "-1" << endl;
        else
            cout << r + 1 << " " << l + 1 << endl;


    }
 
 
}