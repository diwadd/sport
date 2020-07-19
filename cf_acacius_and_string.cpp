#include <bits/stdc++.h> 
 
using namespace std;
typedef unsigned long long int ulli;
 
void fill_z(string &s) {
 
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '?') {
            s[i] = 'z';
        }
    }
}

int count_abacaba(string &s){
 
    int n = s.length();
    string target = "abacaba";
    int m = target.length();
 
    int first_letter = 0;
    int n_ok = 0;
    int n_occurrence = 0;
    while(true) {
 
        int last_letter = min(first_letter + m, n);
        int t_index = 0;
        for(int i = first_letter; i < last_letter; i++) {

            if(s[i] == target[t_index]) {
                n_ok++;
            } else {
                n_ok = 0;
                break;
            }
            t_index++;
        }
 
        first_letter++;
        if(n_ok == m) {
            n_occurrence++;
            n_ok = 0;
        } else {
            n_ok = 0;
        }
        if(first_letter >= n) {
            break;
        }
 
    }
    return n_occurrence;
}

int count_and_fill_abacaba(string &s_original){
 
    int n = s_original.length();
    string target = "abacaba";
    int m = target.length();
 
    int first_letter = 0;
    int n_ok = 0;
    int n_occ = 0;
    while(true) {
 
        int last_letter = min(first_letter + m, n);
 
        string s = s_original;
        int t_index = 0;
        for(int i = first_letter; i < last_letter; i++) {

            if(s[i] == target[t_index]) {
                n_ok++;
            } else if (s[i] == '?') {
                n_ok++;
                s[i] = target[t_index];
            } else {
                n_ok = 0;
                break;
            }
            t_index++;
        }
 
        first_letter++;
        if(n_ok == m) {
            n_ok = 0;
        }

        n_occ = count_abacaba(s);
        if(n_occ == 1) {
            s_original = s;
            break;
        }
        
        if(first_letter >= n) {
            break;
        }
 
    }
    return n_occ;
} 
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int n;
        cin >> n;
 
        string s;
        cin >> s;
 
 
        int no = count_abacaba(s);
        if(no == 1) {
            fill_z(s);
            cout << "YES\n" << s << "\n";
            continue;
        } else if (no > 1) {
            cout << "NO\n";
            continue;   
        }
 
        no = count_and_fill_abacaba(s);
        if(no == 0 || no > 1) {
            cout << "NO\n";
            continue;
        }

        fill_z(s);
        cout << "YES\n" << s << "\n";

 
 
    }
}