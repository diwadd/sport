#include <bits/stdc++.h> 

using namespace std;

template<typename T> void print_vector(vector<T> &vec) {

    int start = 0;
    for(int i = vec.size()-1; i >= 0; i--) {
        if(vec[i] != 0) {
            start = i;
            break;
        }
    }

    for(int i = start; i >= 0; i--) {
        cout << vec[i];
    }
    cout << "\n";
}

void zero_vector(vector<int> &vec) {
    for(auto& v : vec) {
        v = 0;
    }
}

vector<int> multiply_number(vector<int> &n1, vector<int> &n2) {

    vector<int>* longer = nullptr;
    vector<int>* smaller = nullptr;

    if(n1.size() > n2.size()) {
        longer = &n1;
        smaller = &n2;
    } else {
        longer = &n2;
        smaller = &n1;
    }

    int mr = longer->size() + smaller->size();
    vector<int> first_line = vector<int>(mr, 0);
    vector<int> result = vector<int>(mr, 0);

    int shift = 0;
    for(int i = 0; i < smaller->size(); i++) {
        for(int j = 0; j < longer->size(); j++) {

            first_line[j+shift] = (*smaller)[i] * (*longer)[j];

        }
        
        int transfer = 0;
        for(int j = 0; j < mr; j++) {

            int s = result[j] + first_line[j] + transfer;
            int v = (s % 10);
            result[j] = v;
            transfer = s / 10;
        }
        shift++;
    }
    return result;
}


vector<int> convert_int_to_vec_rep(int n) {

    vector<int> number;

    while(n > 0) {
        int v = n % 10;
        number.push_back(v);
        n = n / 10;
    }

    return number;
}

vector<int> factorial(int n, vector<vector<int>> &lookup) {

    if(n <= 1) {
        vector<int> r = {1};
        return r;
    } else if (lookup[n].size() > 0) {
        return lookup[n];
    } else {
        vector<int> front = convert_int_to_vec_rep(n);

        vector<int> back = factorial(n-1, lookup);
        lookup[n-1] = back;
        
        vector<int> res = multiply_number(front, back);

        return res;
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int MAX_FACTORIAL = 100 + 7;
    vector<vector<int>> lookup = vector<vector<int>>(MAX_FACTORIAL, vector<int>());

    vector<int> res = factorial(N, lookup);
    print_vector(res);
}