#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
typedef unsigned long long int ulli;


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;    
    for(int i = 0; i < t; i++) {


        int n;
        cin >> n;

        ulli s = 0;
        ulli x = 0;
        for(int j = 0; j < n; j++){
            ulli aj;
            cin >> aj;
            s = s + aj;
            x = x ^ aj;
        }

        cout << "2" << endl;
        cout << x << " " << s + x << endl;
    }
}