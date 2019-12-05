#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<cstdio>

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
    // cin >> n >> q;
    scanf("%d%d", &n, &q);

    // vector<int> rv(n, 0);
    // vector<int> cv(n, 0);

    vector<int> r_marks(n+1, 0);
    vector<int> c_marks(n+1, 0);


    int current_mark = 0;
    // cin >> r;
    scanf("%d", &r);
    int prev = r % 2;

    for(int i = 1; i < n; ++i) {
        // cin >> r;
        scanf("%d", &r);
        int p = r % 2;
        if (p == prev){
            r_marks[i+1] = current_mark;
        } else {
            ++current_mark;
            prev = p;
            r_marks[i+1] = current_mark;
        }
    }

    current_mark = 0;
    // cin >> c;
    scanf("%d", &c);
    prev = c % 2;

    for(int i = 1; i < n; ++i) {
        // cin >> c;
        scanf("%d", &c);      
        int p = c % 2;

        if (p == prev){
            c_marks[i+1] = current_mark;
        } else {
            ++current_mark;
            prev = p;
            c_marks[i+1] = current_mark;
        }
    }

    // mark_sectors(rv, r_marks);
    // mark_sectors(cv, c_marks);

    for(int i = 0; i < q; ++i){

        int ra, rb, ca, cb;   
        // cin >> ra >> ca >> rb >> cb;
        scanf("%d %d %d %d", &ra, &ca, &rb, &cb);

        if ((r_marks[ra] == r_marks[rb]) && (c_marks[ca] == c_marks[cb])) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
}