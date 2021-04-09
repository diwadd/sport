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

int left_right(int xa, int ya, int xb, int yb, int xc, int yc) {
    return (xb - xa) * (yc - ya) - (xc - xa) * (yb - ya);
}

// int depth(vector<int> &a_vec) {

//     int N = a_vec.size();

//     if(N <= 2)
//         return 0;

//     vector<pair<int, int>> points(N, pair<int,int>());

//     for(int i = 0; i < N; i++) {
//         points[i] = make_pair(i, a_vec[i]);
//     }

//     vector<pair<int,int>> stack;
//     stack.reserve(N);

//     stack.push_back(points[N-1]);
//     stack.push_back(points[N-2]);

//     for(int i = N - 3; i >= 0; i--) {

//         while(true) {

//             int M = stack.size();
//             pair<int, int> pb = stack[M - 1];
//             pair<int, int> pa = stack[M - 2];

//             // cout << "pa: " << pa.first << " " << pa.second << endl;
//             // cout << "pb: " << pb.first << " " << pb.second << endl;

//             int xa = pa.first;
//             int ya = pa.second;

//             int xb = pb.first;
//             int yb = pb.second;

//             int xc = points[i].first;
//             int yc = points[i].second;

//             int t = left_right(xa, ya, xb, yb, xc, yc);

//             // cout << "xc: " << xc << " yc: " << yc << " t: " << t << endl;

//             if(M > 2 && t <= 0) {
//                 stack.pop_back();
//             } else {
//                 break;
//             }

//         }
//         stack.push_back(points[i]);

//         // if(t) {
//         // }
//     }

//     for (int i = 0; i < stack.size(); i++) {
//         // cout << stack[i].first << " " << stack[i].second << endl;
//     }

//     return 0;
// }

void squeeze_input(vector<int> &non_squeezed_input, vector<int> &input) {

    input.clear();
    input.reserve(non_squeezed_input.size());

    input.push_back(non_squeezed_input[0]);

    for(int i = 1; i < non_squeezed_input.size(); i++) {

        if(non_squeezed_input[i] != non_squeezed_input[i-1]){
            input.push_back(non_squeezed_input[i]);
        }

    }
}

int deep(vector<int> &non_squeezed_input) {

    vector<int> input;
    squeeze_input(non_squeezed_input, input);

    if(input.size() <= 2)
        return 0;

    vector<int> a_vec(input.size() + 2, 0);
    for(int i = 0; i < input.size(); i++) {
        a_vec[i+1] = input[i];
    }
    // print_vector(a_vec);

    vector<int> peaks_location;
    vector<int> peaks_type;
    peaks_location.reserve(input.size());
    peaks_type.reserve(input.size());

    for(int i = 1; i < a_vec.size()-1; i++) {
        if(a_vec[i-1] < a_vec[i] && a_vec[i] > a_vec[i+1]) {
            peaks_location.push_back(i);
            peaks_type.push_back(1);
        } else if(a_vec[i-1] > a_vec[i] && a_vec[i] < a_vec[i+1]) {
            peaks_location.push_back(i);
            peaks_type.push_back(-1);
        }
    }

    // print_vector(peaks_location);
    // print_vector(peaks_type);

    int d = 0;
    for(int i = 0; i < peaks_location.size(); i++) {
        
        // cout << "i: " << i << " peaks_location[i]: " << peaks_location[i] << endl;
        if(peaks_type[i] == -1)
            continue;
        
        int first_peak = a_vec[peaks_location[i]];


        for(int j = i + 1; j < peaks_location.size(); j++) {
            
            // cout << "j: " << j << " peaks_location[j]: " << peaks_location[j] << endl;
            int second_peak = a_vec[peaks_location[j]];
            int min_peak = min(first_peak, second_peak);
            if(peaks_type[j] == 1 && second_peak >= first_peak) {

                // cout << "will loop from " << peaks_location[j] << " to " << peaks_location[i] << endl;
                // cout << "first peak: " << first_peak << " second_peak: " << second_peak << endl;
                for(int k = j; k >= i; k--) {
                    if(peaks_type[k] == -1) {
                        int delta = min_peak - a_vec[peaks_location[k]];
                        // cout << "k: " << k << " minimum: " << a_vec[peaks_location[k]] << " delta: " << delta << endl;
                        if (delta > d) {
                            d = delta;
                        }
                    }
                }

                i = j - 1;
                // cout << "new i set to: " << i << endl;
                break;
            }   
        }
        // cout << "closing i: " << i << endl;
    }

    // cout << " --- --- --- --- " << endl;

    for(int i = peaks_location.size()-1; i >= 0; i--) {
        
        // cout << "i: " << i << " peaks_location[i]: " << peaks_location[i] << endl;
        if(peaks_type[i] == -1)
            continue;
        
        int first_peak = a_vec[peaks_location[i]];


        for(int j = i - 1; j >= 0; j--) {
            
            // cout << "j: " << j << " peaks_location[j]: " << peaks_location[j] << endl;
            int second_peak = a_vec[peaks_location[j]];
            int min_peak = min(first_peak, second_peak);
            if(peaks_type[j] == 1 && second_peak >= first_peak) {
                
                // cout << "will loop from " << peaks_location[j] << " (j: " << j << ") to " << peaks_location[i] << "(i: " << i<< ")" << endl;
                // cout << "first peak: " << first_peak << " second_peak: " << second_peak << endl;
                for(int k = i; k >= j; k--) {
                    if(peaks_type[k] == -1) {
                        int delta = min_peak - a_vec[peaks_location[k]];
                        // cout << "k: " << k << " minimum: " << a_vec[peaks_location[k]] << " delta: " << delta << endl;
                        if (delta > d) {
                            d = delta;
                        }
                    }
                }

                i = j + 1;
                // cout << "new i set to: " << i << endl;
                break;
            }   
        }
        // cout << "closing i: " << i << endl;
    }

    // cout << "d: " << d << endl;
    return d;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // vector<int> input = {6, 8, 7, 6, 4, 3, 4, 5, 7, 6, 5, 4, 3, 2, 1, 3, 6, 12, 3, 1};
    // vector<int> input = {1,2,3,4,5,6,7,8,9};
    // vector<int> input = { 4, 7, 6, 5, 4, 2, 1, 5, 3, 2, 12, 9, 8, 5, 16, 14, 3, 2, 3, 6, 9, 12, 1 };
    // vector<int> input = {1, 3, 2, 1, 2, 1, 5, 3, 3, 4, 2};

    vector<int> input = {4, 7, 7, 7, 7, 6, 5, 4, 2, 1, 1, 1, 5, 3, 2, 12, 12, 12, 9, 8, 5, 16, 14, 3, 2, 3, 6, 9, 12, 1};

    // vector<int> input = {};

    int d = deep(input);
    cout << d << endl;

}