#include <bits/stdc++.h>

using namespace std;



int main() {

    const int N_MAX = 1000000 + 4;
    const int N_NUMBERS = 2;
    vector<vector<int>> res(N_MAX/2, vector<int>());
    for(int i = 0; i < N_MAX; i++) {
        res.reserve(N_NUMBERS);
    }
    
    res[0].push_back(1);
    res[0].push_back(2);
    res[0].push_back(3);
    int page = 4;
    for(int i = 1; i < N_MAX/2; i++) {
        res[i].push_back(page);
        page++;
        res[i].push_back(page);
        page++;
    }

    // for(int i = 0; i < res.size(); i++) {
    //     for(int j = 0; j < res[i].size(); j++) {
    //         printf("%d ", res[i][j]);
    //     }
    //     printf("\n");
    // }

    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {

        int N;
        scanf("%d", &N);

        if(N == 1){
            printf("1\n1 1\n");
            continue;
        }

        int days = N/2;
        printf("%d\n", days);

        for(int i = 0; i < N_MAX; i++) {
            
            if(res[i][0] > N) {
                break;
            }

            int m = 0;
            string s = "";
            for(int j = 0; j < res[i].size(); j++) {
                if(res[i][j] <= N) {
                    //printf("%d ", res[i][j]);
                    s = s + to_string(res[i][j]) + " ";
                    m++;
                } else {
                    break;
                }
            }

            s.pop_back();
            s = to_string(m) + " " + s + "\n";
            printf("%s", s.c_str());
        }
    }
}