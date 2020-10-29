#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


int get_product(vector<int> &v) {

    // This is to slow :-(

    int p = 1;
    for(int i = 0; i < v.size(); i++) {
        p = p * v[i];
    }

    return p;
}


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ulli K;
    cin >> K;

    vector<int> freq = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    ulli p = 1;
    while(true) {

        bool bc = false;
        for(int n = 0; n < freq.size(); n++) {

            if(p >= K) {
                // cout << "Exiting loop..." << "\n";
                bc = true;
                break;
            }

            p = (p / freq[n]) * (freq[n] + 1);
            freq[n]++;

        }

        if(bc == true)
            break;
    }


    // print_vector(freq);

    vector<char> letters = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
    string res = "";
    for(int n = 0; n < freq.size(); n++) {

        string cf_part(freq[n], letters[n]);
        res = res + cf_part;
    }

    cout << res;
}