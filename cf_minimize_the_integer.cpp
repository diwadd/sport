#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <chrono>

using namespace std;

template<typename T> void print_container(T& c) {
    for(int i = 0; i < c.size(); i++)
        cout << c[i] << endl;
}


string mi(string s){

    int n = s.length();

    vector<int> s_min;
    deque<int> even;
    deque<int> odd;

    for(int i = 0; i < n; i++){
        int e = int(s[i] - '0');
        if (e % 2 == 0)
            even.push_back(e);
        else
            odd.push_back(e);
    }

    string ns = "";
    while(true) {
        if (even.empty() == true && odd.empty() == false) {
            ns += to_string(odd.front());
            odd.pop_front();
        } else if (even.empty() == false && odd.empty() == true) {
            ns += to_string(even.front());
            even.pop_front();
        } else if (even.empty() == true && odd.empty() == true) {
            break;
        } else if (even.empty() == false && odd.empty() == false) {
            int e = even.front();
            int o = odd.front();
            if (e < o) {
                ns += to_string(e);
                even.pop_front();
            } else {
                ns += to_string(o);
                odd.pop_front();
            }
        }

    }

    return ns;
}

int main(){

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string a;
        cin >> a;
        string r = mi(a);
        cout << r << endl;
    }

    // string s(3*100000, '2');
    
    // auto start = std::chrono::system_clock::now();
    // string r = mi(s);
    // auto end = std::chrono::system_clock::now();
    // std::chrono::duration<double> elapsed_seconds = end-start;

    // cout << "elapsed_seconds: " << elapsed_seconds.count() << endl;

    return 0;

}