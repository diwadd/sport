#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;    
    for(int i = 0; i < t; i++) {
        long long x;
        cin >> x;

        string s;
        cin >> s;
        

        long long index = 0;
        long long st = s.length();
        while(s.length() < x) {
            long long n = s[index] - '0';
            string suffix = s.substr(index+1);
            for(long long i = 1; i <= n-1; i++) {
                // cout << "i = " << i << " " << suffix << endl;
                s = s + suffix;
            }

            // cout << "n: " << n << " s[index]:" << s[index] << " index: " << index << endl << s << endl;
            index++;
        }
        long long res = s.length();

        // cout << "index: " << index << endl;
        index = 0;
        while(index < x) {
            long long n = s[index] - '0';
 
            long long suffix_length = st - index - 1;
            // cout << "n: " << n << " s[index]:" << s[index] << " index: " << index << " suffix_length: " << suffix_length << endl;
            for(long long i = 1; i <= n-1; i++) {
                // cout << "i = " << i << endl;
                st = st + suffix_length;
            }

            index++;
            // cout << "st: " << st << endl;

        }
        cout << st % (1000000000+7) << endl;
    }


}