#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
        if(i != vec.size()-1)
            cout << vec[i] << " ";
        else
            cout << vec[i];
    }
    cout << "\n";
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int n, x, y;
        cin >> n >> x >> y;

        int MAX_DISTANCE = 50;
        int minimal_i = 0;
        for(int i = 1; i <= MAX_DISTANCE; i++){
            int index = 0;
            int t_x = x;
            
            while(index < n - 1) {
                t_x += i;
                index++;
                if(index == n || t_x >= y)
                    break;
            }

            if(t_x != y)
                continue;
        
            minimal_i = i;
            break;
        }

        vector<int> res;
        res.reserve(n);

        for(int i = x; i <= y; i += minimal_i) {
            res.push_back(i);
        }

        int t_x = x - minimal_i;
        while(t_x > 0 && res.size() < n) {
            res.push_back(t_x);
            t_x -= minimal_i;
        }

        int t_y = y + minimal_i;
        while(res.size() < n) {
            res.push_back(t_y);
            t_y += minimal_i;
        }

        print_vector(res);

    }
}