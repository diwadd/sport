#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        string s;
        cin >> s;
 
        vector<char> qc;
        vector<char> qb;
        qc.reserve(s.size());
        qb.reserve(s.size());
 
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(qc.empty() == true && s[i] == '(' && s[i] == ')') {
                qc.push_back(s[i]);
                continue;
            }
 
            if(qb.empty() == true && s[i] == '[' && s[i] == ']') {
                qb.push_back(s[i]);
                continue;
            }
 
            if(qc.back() == '(' && s[i] == ')') {
                res++;
                qc.pop_back();
            } else if (qb.back() == '[' && s[i] == ']') {
                res++;
                qb.pop_back();    
            } else if (s[i] == ']' || s[i] == ')') {
                continue;
            } else if (s[i] == '[') {
                qb.push_back(s[i]);
            } else if (s[i] == '(') {
                qc.push_back(s[i]);
            }
 
        }
 
        cout << res << "\n";
    }
}