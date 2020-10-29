#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;    
    for(int i = 0; i < t; i++) {
        unsigned long long x;
        cin >> x;

        string ss;
        cin >> ss;
        

        vector<char> s(ss.begin(), ss.end());

        unsigned long long index = 0;
        unsigned long long st = s.size() % MOD7;
        while(s.size() < x) {
            unsigned long long n = s[index] - '0';
            vector<char> substr(s.begin() + index + 1, s.end()); // s.substr(index+1);
            for(unsigned long long i = 1; i <= n-1; i++) {
                s.insert(s.end(), substr.begin(), substr.end());
            }

            index++;
        }

        index = 0;
        while(index < x) {
            unsigned long long n = s[index] - '0';
 
            unsigned long long suffix_length = st - index - 1;
            for(unsigned long long i = 1; i <= n-1; i++) {
                st = st + suffix_length % MOD7;
            }

            index++;

        }
        cout << st % MOD7 << endl;
    }


}