#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<cstdio>
 
using namespace std;
 
int main() {
 

    int t;
    int n_problems = 11;
    int n_scorable_problems = 8;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {

        int n;
        scanf("%d", &n);
        vector<int> sub(n_problems+1, 0);
        for(int j = 0; j < n; j++) {

            int p, s;
            scanf("%d %d", &p, &s);

            if(sub[p] < s)
                sub[p] = s;
        }

        int score = 0;
        for(int p = 1; p < n_scorable_problems+1; p++){
            score += sub[p];
        }

        printf("%d\n", score);

    }

 
}