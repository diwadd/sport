#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
 
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
 
        string s;
        cin >> s;
 
        bool number_is_ok = false;
        for(int j = n-1; j >= 0; j--){
            if(s[j] == '0' || s[j] == '2' || s[j] == '4' || s[j] == '6' || s[j] == '8'){
                s[j] = 'x';           
            } else {
                number_is_ok = true;
                break;
            }
        }
 
        if(number_is_ok == false){
            cout << "-1" << endl;
            continue;
        }
 
        //cout << "s: " << s << endl;
 
        int sum = 0;
        int last = -1;
        for(int j = n-1; j >= 0; j--){
            if(s[j] != 'x') {
                sum = sum + (int)s[j] - (int)'0';
                if(sum % 2 == 0){
                    last = j;
                    break;
                }
            }
        }
 
        //cout << "sum: " << sum << endl;
        if(last == -1){
            cout << "-1" << endl;
            continue; 
        }
 
        for(int j = last; j <= n-1; j++){
            if(s[j] != 'x') {
                cout << s[j];
            }
        }
        cout << endl;
    }
}