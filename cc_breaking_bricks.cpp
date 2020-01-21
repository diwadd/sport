#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;
 
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
 
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {

        int s;
        int w1;
        int w2;
        int w3;

        cin >> s >> w1 >> w2 >> w3;

        if (s >= w1 + w2 + w3) {
            cout << "1" << endl;
        } else if (s >= w1 + w2) {
            cout << "2" << endl;
        } else if (s >= w1) {

            if(s >= w2 + w3) {
                cout << "2" << endl;
            } else {
                cout << "3" << endl;
            }
        }
    }
}