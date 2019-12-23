#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;    
    for(int i = 0; i < t; i++) {
        int x;
        cin >> x;

        string s;
        cin >> s;
        
        int index = 1;
        while(index < x) {
            int n = s[index] - '0';
            for(int i = 0; i < n; i++)
                s = s + s.substr(index);
            index++;
            cout << s << endl;
        }


    }


}