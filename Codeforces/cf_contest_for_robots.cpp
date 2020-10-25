#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;

    vector<int> r(n, 0);
    vector<int> b(n, 0);
    for(int i = 0; i < n; i++)
        cin >> r[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    int N = 0;
    int M = 0;
    int P = 0;
    int Q = 0;
    for(int i = 0; i < n; i++) {
        if (r[i] == 0 && b[i] == 1)
            N++;
        else if ((r[i] == 1 && b[i] == 1))
            M++;
        else if ((r[i] == 1 && b[i] == 0))
            P++;
        else if ((r[i] == 0 && b[i] == 0))
            Q++;
    }

    if (n == 1) {
        if (N > 0)
            cout << "-1" << endl;
        else if (P > 0)
            cout << "1" << endl;
        else if (M > 0)
            cout << "-1" << endl;
        else if (Q > 0)
            cout << "-1" << endl;
    } else if (Q == n) {
        cout << "-1" << endl;
    } else if (M == n) {
        cout << "-1" << endl;
    } else if (P == 0) {
        cout << "-1" << endl;
    } else if (N >= P) {
        int r = N/P + 1;
        cout << r << endl;
    } else if (N < P) {
        cout << "1" << endl;      
    }
}