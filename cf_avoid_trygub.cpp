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
     
            int N;
            cin >> N;
     
            string s;
            cin >> s;
     
            sort(s.begin(), s.end());
            cout << s << "\n";
        }
    }