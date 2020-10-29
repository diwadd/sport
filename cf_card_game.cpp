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
        int k1;
        int k2;

        cin >> n;
        cin >> k1;
        cin >> k2;

        vector<int> v1(k1, 0);
        vector<int> v2(k2, 0);

        for(int j = 0; j < k1; j++) {
            int kj;
            cin >> kj;
            v1[j] = kj;
        }

        for(int j = 0; j < k2; j++) {
            int kj;
            cin >> kj;
            v2[j] = kj;
        }

        vector<int>::iterator result_one = max_element(v1.begin(), v1.end());
        vector<int>::iterator result_two = max_element(v2.begin(), v2.end());

        // cout << "result_one: " << *result_one << endl;
        // cout << "result_two: " << *result_two << endl;

        if (*result_one > *result_two)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;


    }


}