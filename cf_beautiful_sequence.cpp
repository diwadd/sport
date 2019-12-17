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
 
    int a;
    int b;
    int c;
    int d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    int n = a + b + c + d;
    for(int i = 0; i < 4; i++) {

        map<int, int> abcd_mapping;
        abcd_mapping[0] = a;
        abcd_mapping[1] = b;
        abcd_mapping[2] = c;
        abcd_mapping[3] = d;

        if (abcd_mapping[i] == 0)
            continue;

        vector<int> bs;
        bs.push_back(i);
        int previous = i;
        abcd_mapping[i]--;

        for(int j = 0; j < n - 1; j++) {

            if ( abcd_mapping[previous + 1] > 0 ) {
                bs.push_back(previous + 1);
                abcd_mapping[previous + 1]--;
                previous = previous + 1;
                continue;
            }
            if ( abcd_mapping[previous - 1] > 0 ) {
                bs.push_back(previous - 1);
                abcd_mapping[previous - 1]--;
                previous = previous - 1;
                continue;
            }
            break;
        }

        if (bs.size() == n) {
            cout << "YES" << endl;
            for(int i = 0; i < bs.size(); i++) {
                cout << bs[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

}