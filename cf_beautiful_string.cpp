#include <iostream>
#include <string>
#include<cstdio>

using namespace std;

bool make_string_beautiful(string &s){

    int n = s.length();
    if (s[0] == '?' && n == 1) {
        s[0] = 'a';
        return true;
    } else if (s[0] != '?' && n == 1) {
        return true;
    }

    for(int i = 1; i < n; i++)
        if ((s[i] == s[i-1]) && (s[i] != '?') && (s[i-1] != '?'))
            return false;

    int start = -1;
    int stop = -1;
    for(int i = 0; i < n; ++i){

        if (s[i] == '?' && start == -1) {
            start = i;
            continue;
        }  

        if (s[i] != '?' && start != -1)
            stop = i;
        else if (s[i] == '?' && start != -1 && i == n-1)
            stop = i;

        if (start != -1 && stop != -1){
            for (int j = start; j < stop; ++j) {
                if (j != 0)
                    s[j] = 'a' + (s[j - 1] % 3);
                else
                    s[j] = 'a';
            }

            if (s[stop] == '?')
                s[stop] = 'a' + (s[stop-1] % 3);

            if (s[stop] == s[stop - 1])
                s[stop-1] = 'a' + (s[stop] % 3);
            start = -1;
            stop = -1;
        } 

    }

    if (start != -1 && stop == -1) {
        s[n-1] = 'a' + (s[n-2] % 3);
    }

    return true;
}





int main() {

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        bool is_beautiful = make_string_beautiful(s);

        if (is_beautiful == true) {
            cout << s << endl;
        } else {
            cout << "-1" << endl;
        }
    }

}