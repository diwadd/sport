#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<cstdio>
 
using namespace std;
 
int main() {
 
    int t;
    scanf("%d", &t);
 
    for(int i = 0; i < t; i++){
        int n;
        int p;
        scanf("%d", &n);
        vector<int> pv(n, 0);
        for(int j = 0; j < n; j++){
            scanf("%d", &p);
            pv[j] = p;
        } 
 
        int max_medals = int(n/2);
        int no_medals = pv[max_medals];
        int g = 1;
        int s = 0;
        int b = 0;
 
        int min_g = pv[0];
        int min_s = -1;
 
        for(int j = 1; j < max_medals; j++){
            if(pv[j] == min_g){
                g++;
                continue;
            }
 
            if(pv[j] < min_g && s == 0){
                s++;
                min_s = pv[j];
                continue;
            }
 
            if(pv[j] < min_s && s > 0 && g >= s) {
                s++;
                min_s = pv[j];
                continue;
            }
 
            if(pv[j] == min_s ) {
                s++;
                continue;
            }
 
            if(pv[j] <= pv[j-1] && pv[j] > no_medals){
                // printf("pv[j] %d no_medals: %d\n", pv[j], no_medals);
                b++;
            }
 
        }
 
        if(g > 0 && s > 0 && b > 0 && g < s && g < b)
            printf("%d %d %d\n", g, s, b);
        else
            printf("0 0 0\n");
 
 
    }
 
}