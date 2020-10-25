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
        string s1;
        cin >> s1;

        string s2;
        cin >> s2;

        vector<char> vs1(s1.begin(), s1.end());
        vector<char> vs2(s2.begin(), s2.end());

        if(lexicographical_compare(vs1.begin(), vs1.end(), vs2.begin(), vs2.end()) == true) {
            cout << s1 << endl;
            continue;
        }

        vector<char> vs1_smallest(s1.begin(), s1.end());
        sort(vs1_smallest.begin(), vs1_smallest.end());

        int mismatch_index = -1;
        for(int j = 0; j < vs1.size(); j++) {
            // cout << "vs1[j]: " << vs1[j] << " vs1_smallest[j]: " << vs1_smallest[j] << endl;
            if(vs1[j] != vs1_smallest[j]) {
                // cout << "mismatch_index: " << j << endl;
                mismatch_index = j;
                break;
            }
        }

        if(mismatch_index == -1) {
            cout << "---" << endl;
            continue;
        }

        for(int j = vs1.size()-1; j >= mismatch_index+1; j--) {
            if(vs1[j] == vs1_smallest[mismatch_index]) {
                int temp = vs1[j];
                vs1[j] = vs1[mismatch_index];
                vs1[mismatch_index] = temp;
                break;
            }
        }

        if(lexicographical_compare(vs1.begin(), vs1.end(), vs2.begin(), vs2.end())==true) {
            string res(vs1.begin(), vs1.end());
            cout << res << endl;
        } else {
            cout << "---" << endl;
        }
    }
}