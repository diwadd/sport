#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

void print_map(map<int, int> m) {

    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << "\n";
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int N;
    cin >> N;

    const int MAX_NUMBERS = 100000;
    // vector<int> freq(MAX_NUMBERS + 1, 0);
    map<int, int> freq;

    for(int n = 0; n < N; n++) {
        int a;
        cin >> a;
        freq[a]++;
    }

    set<int> fours;
    set<int> twos;

    for(auto it = freq.begin(); it != freq.end(); it++) {
        int f = it->second;

        if(f >= 4) {
            fours.insert(it->first);
        }

        if(f >= 2 && f < 4){
            twos.insert(it->first);
        }
    }


    int Q;
    cin >> Q;

    for(int q = 0; q < Q; q++) {

        char c;
        cin >> c;
        int x;
        cin >> x;

        // cout << "x : " << x << endl;
        if(c == '+') {
            if(freq[x] + 1 == 4) {
                auto it = twos.find(x);
                twos.erase(it);
                fours.insert(x);
                freq[x]++;
            } else if (freq[x] + 1 == 2) {
                twos.insert(x);
                freq[x]++;
            } else {
                freq[x]++;
            }
        } else {
            if(freq[x] - 1 == 3) {
                auto it = fours.find(x);
                fours.erase(it);
                twos.insert(x);
                freq[x]--;
            } else if (freq[x] - 1 == 1) {
                auto it = twos.find(x);
                twos.erase(it);
                freq[x]--;
            } else {
                if(freq[x] > 0)
                    freq[x]--;
            }
        }

        // print_map(freq);

        int n_fours = 0;
        int n_twos = 0;
        for(auto it = fours.begin(); it != fours.end(); it++) {
            int x = *it;
            int f = freq[x];

            while(true) {

                if(f - 4 >= 0){
                    f -= 4;
                    n_fours++;
                }

                if(n_fours >= 2 || f < 4)
                    break;
            }

            if(n_fours == 2) {
                break;
            }

            while(true) {
                if(f - 2 >= 0){
                    f -= 2;
                    n_twos++;
                }

                if(n_twos >= 2 || f < 2)
                    break;
            }

            if(n_twos == 2) {
                break;
            }
        }

        if(n_fours == 2 || (n_fours == 1 && n_twos == 2)) {
            cout << "YES\n";
        } else if (n_fours == 0) {
            cout << "NO\n";  
        } else if(n_twos == 0 && twos.size() >= 2) {
            cout << "YES\n";
        } else if (n_twos == 1 && twos.size() >= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";  
        }



    }

}