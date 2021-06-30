
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void left_just(string &s, int n, char c = ' ') {
    while(s.length() < n) {
        s = c + s;
    }
}

template<typename T> void print_vector(vector<T> &vec) {

    int n = vec.size();
    for(int i = 0; i < n; i++) {
        if(i == n - 1)
            cout << vec[i];
        else
            cout << vec[i] << " ";
    }
    cout << "\n";
}

template<typename T> void print_matrix(vector<vector<T>> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        print_vector(mat[i]);
    }
}

struct Triple {
    Triple() {}
    Triple(int pa, int pb, int pc): a(pa), b(pb), c(pc) {}
    int a;
    int b;
    int c;
};

void apply_operation(vector<int>& a_vec, Triple &t) {
    int a = t.a;
    int b = t.b;
    int c = t.c;

    a_vec[c] = a_vec[a] ^ a_vec[b];
}

bool make_even(vector<int> & a_vec, vector<Triple>& res) {

    int N = a_vec.size();

    int first = -1;
    int second = -1;

    // for(int parity = 0; parity <= 1; parity++) {


    //     for(int i = 0; i < N; i = i + 2) {
    //         if(a_vec[i] % 2 == parity) {
    //             first = i;
    //             break;
    //         }
    //     }

    //     for(int i = 0; i < N; i = i + 2) {
    //         if(a_vec[i] % 2 == parity && i != first && a_vec[i] != a_vec[first]) {
    //             second = i;
    //             break;
    //         }
    //     }

    //     cout << "even: " << first << " " << second << endl;
    //     if(first != -1 && second != -1) {
    //         break;
    //     } else {
    //         first = -1;
    //         second = -1;
    //     }

    // }

    first = 0;
    for(int i = 2; i < N; i = i + 2) {
        if(a_vec[i] != a_vec[first]) {
            second = i;
            break;
        }
    }

    if(first != -1 && second != -1) {

        cout << N << "\n";

        for(int i = 1; i < N; i = i + 2) {
            cout << first+1 << " " << second+1 << " " << i+1 << endl;
            // res.push_back(Triple(first+1, second+1, i+1));
        }

        for(int i = 0; i < N; i = i + 2) {
            cout << "2 4 " << i+1 << endl;
            // res.push_back(Triple(2, 4, i+1));
        }
        return true;
    } else {
        return false;
    }
}


bool make_odd(vector<int> & a_vec, vector<Triple>& res) {

    int N = a_vec.size();

    int first = -1;
    int second = -1;


    // for(int parity = 0; parity <= 1; parity++) {


    //     for(int i = 1; i < N; i = i + 2) {
    //         if(a_vec[i] % 2 == parity) {
    //             first = i;
    //             break;
    //         }
    //     }

    //     for(int i = 1; i < N; i = i + 2) {
    //         if(a_vec[i] % 2 == parity && i != first && a_vec[i] != a_vec[first]) {
    //             second = i;
    //             break;
    //         }
    //     }

    //     cout << "odd: " << first << " " << second << endl;
    //     if(first != -1 && second != -1) {
    //         break;
    //     } else {
    //         first = -1;
    //         second = -1;
    //     }

    // }

    first = 1;
    for(int i = 3; i < N; i = i + 2) {
        if(a_vec[i] != a_vec[first]) {
            second = i;
            break;
        }
    }


    if(first != -1 && second != -1) {

        cout << N << "\n";

        for(int i = 0; i < N; i = i + 2) {
            cout << first+1 << " " << second+1 << " " << i+1 << endl;
            // res.push_back(Triple(first+1, second+1, i+1));
        }

        for(int i = 1; i < N; i = i + 2) {
            cout << "1 3 " << i+1 << endl;
            // res.push_back(Triple(1, 3, i+1));
        }
        return true;
    } else {
        return false;
    }
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N;
        cin >> N;

        vector<int> a_vec(N, 0);
        for(auto &a : a_vec) {
            cin >> a;
        }

        // print_vector(a_vec);

        if(N == 1) {
            cout << "0\n";
        } else if(N == 2) {
            if(a_vec[0] == a_vec[1]) {
                cout << "-1\n";
            } else {
                cout << "0\n";
            }
        } else if(N == 3) {

            if(a_vec[0] == 0 && a_vec[1] == 0 && a_vec[2] == 0) {
                cout << "-1\n";
                continue;
            }
            
            if(a_vec[0] == a_vec[2] && a_vec[0] != a_vec[1]) {
                cout << "0\n";
                continue;
            }


            vector<Triple> triples = {Triple(0, 1, 2),
                                      Triple(1, 2, 0),
                                      Triple(0, 2, 1)};
            bool is_ok = false;
            Triple op;
            for(auto & trip : triples) {
                vector<int> v = a_vec;
                apply_operation(v, trip);

                // cout << " --- --- --- \n";
                // print_vector(v);

                if(v[0] == v[2] && v[0] != v[1]) {
                    is_ok = true;
                    op = trip;
                    break;
                }
            }

            if(is_ok == false) {
                cout << "-1\n";
            } else {
                cout << "1\n";
                cout << op.a+1 << " " << op.b+1 << " " << op.c+1 << "\n";
            }
        } else {

            bool is_zero = true;
            for(auto & a : a_vec) {
                if(a != 0) {
                    is_zero = false;
                    break;
                }
            }

            if(is_zero == true) {
                cout << "-1\n";
                continue;
            }

            bool is_same_value = true;
            int p = a_vec[0];

            for(int i = 1; i < N; i++) {
                if(a_vec[i] != p) {
                    is_same_value = false;
                    break;
                }
                p = a_vec[i];
            }

            if(is_same_value == true) {

                if(N % 2  == 0)
                    cout << N/2 << "\n";
                else
                    cout << N/2+1 << "\n";

                for(int i = 1; i < N; i = i + 2) {
                    cout << "1 3 " << i+1 << "\n";
                }

            } else {

                vector<Triple> res;

                if(make_even(a_vec, res) == false) {
                    make_odd(a_vec, res);
                }


                // vector<int> sol = a_vec;

                // for(int i = 0; i < res.size(); i++) {

                //     int a = res[i].a-1;
                //     int b = res[i].b-1;
                //     int c = res[i].c-1;

                //     sol[c] = sol[a] ^ sol[b];
                // }

                // cout << "res.size(): " << res.size() << " --- --- ---\n";
                // print_vector(sol);

            }

        }



    }


}