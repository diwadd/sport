#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ulli;

bool sort_by_second(const pair<int, int> &p1, const pair<int, int> &p2) 
{ 
    return p1.second < p2.second; 
} 

int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){

        int n, m;
        cin >> n >> m;
        vector<int> f_vec(n, 0);
        vector<int> p_vec(n, 0);

        for(int j = 0; j < n; j++){
            cin >> f_vec[j];
        }

        for(int j = 0; j < n; j++){
            cin >> p_vec[j];
        }

        map<int, int> pfr;

        for(int j = 0; j < n; j++){
            int f = f_vec[j];
            int p = p_vec[j];
            if(pfr.find(f) != pfr.end()) {
                pfr[f] = pfr[f] + p; 
            } else {
                pfr[f] = p;
            }
        }

        map<int, int>::iterator it;
        int min_ele = numeric_limits<int>::max();
        for(it = pfr.begin(); it != pfr.end(); it++){
            if(it->second < min_ele){
                min_ele = it->second;
            }
        }

        cout << min_ele << endl;

    }

}