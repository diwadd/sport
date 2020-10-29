#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
 
using namespace std;
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    for(int i = 0; i < t; i++){
 
        int n;
        cin >> n;
 
 
        int max_element = -1;
        int index = -1;
        vector<int> a(n, 0);
        for(int j = 0; j < n; j++) {
            int aj;
            cin >> aj;
            a[j] = aj;
        }
 
        int index_one = 0;
        for(int j = 0; j < n; j++) {
            // cout << "a[j]: " << a[j] << endl;
            // cout << "j: " << j << endl;
            if(a[j] >= j) {
                index_one = j;
                continue;
            } else {
                break;
            }
        }
 
        int index_two = n - 1;
        for(int j = n - 1; j >= 0; j--) {
            if(a[j] >= n - 1- j) {
                index_two = j;
                continue;
            } else {
                break;
            }
        }
 
 
        // cout << "index_one: " << index_one << endl;
        // cout << "index_two: " << index_two << endl;
        if(index_one >= index_two){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}