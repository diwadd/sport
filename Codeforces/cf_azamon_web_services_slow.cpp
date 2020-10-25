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

        int n = min(vs1.size(), vs2.size());
        bool smaller = false;
        for(int k = 0; k < n; k++) {

            if (vs1[k] >= vs2[k]) {

                for(int j = k+1; j < vs1.size(); j++){

                    if(vs1[j] <= vs2[k]){
                        int temp = vs1[j];
                        vs1[j] = vs1[k];
                        vs1[k] = temp;
                        if(lexicographical_compare(vs1.begin(), vs1.end(), vs2.begin(), vs2.end()) == true){
                            smaller = true;
                            break;
                        } else {
                            int temp = vs1[j];
                            vs1[j] = vs1[k];
                            vs1[k] = temp;
                        }


                    }

                }
            }
            if (smaller == true)
                break;
        }

        if(smaller){
            string res(vs1.begin(), vs1.end());
            cout << res << endl;
        } else {
            cout << "---"  << endl;
        }

    }


}