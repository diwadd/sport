#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;


void print_matrix(vector<int> &matrix, int &n, int &m) {

    for(int j = 0; j < n; j++) {
        for(int k = 0; k < m; k++) {
            cout << matrix[j*m + k] << " ";

        }
        cout << endl;
    }
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
 
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {

        int n, m;
        cin >> n >> m;

        vector<int> matrix(n*m, 0);

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
            
                int mij;
                cin >> mij;

                matrix[j*m + k] = mij;

            }
        }

        int res = n*m;
        //print_matrix(matrix, n, m);

        int shorter_side = min(n, m);
        for(int j = 3; j <= shorter_side; j = j + 2) {

            int offset = int(j/2);
            //cout << "offset: " << offset << endl;

            for(int k = offset; k <= n - offset - 1; k++) {
                for(int l = offset; l <= m - offset -1 ; l++) {

                    //cout << "j: " << j << " k: " << k << " l: " << l << endl;


                    // Check if row sub sequence is a palindrome

                    bool is_rp = true;
                    //cout << "Checking row sub sequence" << endl;
                    for(int c = 1; c <= offset; c++) {
                        int right = l + c;
                        int left = l - c;

                        //cout << matrix[k*m + left] << " " << matrix[k*m + right] << " ";


                        if(matrix[k*m + right] != matrix[k*m + left]){
                            is_rp = false;
                            break;
                        }
                    }
                    //cout << endl;

                    if(is_rp == false)
                        continue;

                    bool is_cp = true;
                    //cout << "Checking column sub sequence" << endl;
                    for(int c = 1; c <= offset; c++) {
                        int down = k + c;
                        int top = k - c;

                        //cout << matrix[down*m + l] << " " << matrix[top*m + l] << " ";

                        if(matrix[down*m + l] != matrix[top*m + l]) {
                            is_cp = false;
                            break;
                        }

                    }
                    //cout << endl;

                    if(is_cp == false)
                        continue;

                    res = res + 1;
                }
            }
        } // 3, 5, 7, 9,... loop


    cout << res << endl;
    } // testcase loop
}