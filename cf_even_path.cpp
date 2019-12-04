#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


void inline mark_sectors(vector<int> &v, vector<int> &marks){

    int current_mark = 0;
    int prev = v[0] % 2;

    for(int i = 1; i < v.size(); ++i){

        int p = v[i] % 2;

        if (p == prev){
            marks[i+1] = current_mark;
        } else {
            current_mark++;
            prev = p;
            marks[i+1] = current_mark;
        }
    }

}

void print_vector(vector<int> &v){

    for(auto a : v) {
        cout << a << " ";
    }
    cout << endl;
}

void string_to_vector(string &s, vector<int> &v){

    int m;
    stringstream st_sr(s);

    for (int i = 0; i < v.size(); i++) {
        st_sr >> m;
        v[i] = m;
    }
}


int main() {


    int r, c, n, q;
    cin >> n >> q;

    vector<int> rv(n, 0);
    vector<int> cv(n, 0);

    for(int i = 0; i < n; ++i) {
        cin >> r;
        rv[i] = r;
    }

    for(int i = 0; i < n; ++i) {
        cin >> c;
        cv[i] = c;
    }

    vector<int> r_marks(n+1, 0);
    vector<int> c_marks(n+1, 0);

    mark_sectors(rv, r_marks);
    mark_sectors(cv, c_marks);

    for(int i = 0; i < q; ++i){

        int ra, rb, ca, cb;
        cin >> ra >> ca >> rb >> cb;

        if ((r_marks[ra] == r_marks[rb]) && (c_marks[ca] == c_marks[cb])) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

}