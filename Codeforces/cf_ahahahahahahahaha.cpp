#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
        if(i != vec.size()-1)
            cout << vec[i] << " ";
        else
            cout << vec[i];
    }
    cout << "\n";
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
 
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
 
        }
 
        vector<int> marks(N, 0);
        for(int i = 0; i < N; i++) {
            if(a_vec[i] == 1) {
                bool found = false;
                for(int j = i + 1; j < N; j++){
                    if(a_vec[j] == 1) {
                        if((j - i) % 2 != 0) {
                            i = j;
                        } else {
                            // cout << "Marking " << j - 1 << "\n";
                            i = j;
                            marks[j - 1] = 1;
                        }
                        found = true;
                        break;
                    }
                }
 
                if(found == false) {
                    marks[i]= 1;
                }
            }
        }
 
        // print_vector(a_vec);
        // print_vector(marks);
        
        int k = 0;
        for(int i = 0; i < N; i++)
            if(marks[i] == 0)
                k++;
        cout << k << "\n";
 
        int index = 0;
        for(int i = 0; i < N; i++) {
 
            if(marks[i] == 0) {
                index++;
                if(index != k)
                    cout << a_vec[i] << " ";
                else
                    cout << a_vec[i] << "\n";
            }
        }
    }
}