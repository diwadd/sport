#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

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

    int d = 0;
    for(int i = 0; i < peaks_location.size(); i++) {
        
        if(peaks_type[i] == -1)
            continue;
        
        int first_peak = a_vec[peaks_location[i]];

        int min_delta = numeric_limits<int>::max();
        for(int j = i + 1; j < peaks_location.size(); j++) {
            
            int second_peak = a_vec[peaks_location[j]];
            if(peaks_type[j] == 1 && second_peak >= first_peak) {

                int delta = min(first_peak, second_peak) - min_delta;
                if (delta > d) {
                    d = delta;
                }

                i = j - 1;
                break;
            } else if(peaks_type[j] == -1) {
                if(second_peak < min_delta) {
                    min_delta = second_peak;
                }
            } else if(j == peaks_location.size() - 1) {
                i = j - 1;
                break;
            }
        }
    }

    for(int i = peaks_location.size()-1; i >= 0; i--) {
        
        if(peaks_type[i] == -1)
            continue;
        
        int first_peak = a_vec[peaks_location[i]];

        int min_delta = numeric_limits<int>::max();
        for(int j = i - 1; j >= 0; j--) {
            
            int second_peak = a_vec[peaks_location[j]];
            if(peaks_type[j] == 1 && second_peak >= first_peak) {
                
                int delta = min(first_peak, second_peak) - min_delta;
                if (delta > d) {
                    d = delta;
                }

                i = j + 1;
                break;
            }  else if(peaks_type[j] == -1) {
                if(second_peak < min_delta) {
                    min_delta = second_peak;
                }
            } else if(j == 0) {
                i = j + 1;
                break;
            }

        }
    }

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