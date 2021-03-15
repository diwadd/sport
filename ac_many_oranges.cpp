#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, b, w;
    cin >> a >> b >> w;

    int u = floor(1000.0*w/a);
    int l = ceil(1000.0*w/b);

    if(l <= u)
        cout << l << " " << u << "\n";
    else
        cout << "UNSATISFIABLE\n";

}