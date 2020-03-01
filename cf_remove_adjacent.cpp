#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<char> q;
    for(int i = 0; i < s.length(); i++)
        q.insert(s[i]);

    int counter = 0;
    for(auto it = q.rbegin(); it != q.rend(); it++) {
        bool found = true;
        //cout << "--- " << s << " it: " << *it << endl;
        while (found == true) {
            
            found = false;
            for(int i = 1; i < s.length()-1; i++){
                //cout << "s[i]: " << s[i] << " *it: " << *it << endl; 
                if (s[i] != *it)
                    continue;

                if (s[i] - s[i-1] == 1  || s[i] - s[i+1] == 1 ) {
                    s.erase(s.begin() + i);
                    counter++;
                    found = true;
                    break;
                }   
            }

            if (s.length() == 1)
                break;

            //cout << "s[s.length()-1]: " << s[s.length()-1] << " *it: " << *it << endl; 
            if (s[s.length()-1] != *it) {
                // pass
            } else {
                if (s[s.length()-1] - s[s.length()-2] == 1){
                    s.erase(s.begin() + s.length()-1);
                    counter++;
                    found = true;
                }
            }

            if (s.length() == 1)
                break;

            //cout << "s[0]: " << s[0] << " *it: " << *it << endl; 
            if (s[0] != *it) {
                // pass
            } else {
                if (s[0] - s[1] == 1){
                    s.erase(s.begin());
                    counter++;
                    found = true;
                }
            }

        }

    }
    cout << counter << endl;

}