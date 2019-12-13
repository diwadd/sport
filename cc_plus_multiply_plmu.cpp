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
        scanf("%d", &n);
        
        int as = 0;
        int zs = 0;
        for(int j = 0; j < n; j++){

            int a;
            scanf("%d", &a);
            if(a==0)
                zs++;
            else if(a == 2)
                as++;

        }
    
        int res = 0;
        for(int k = as - 1; k >= 1; k--){
            res = res + k;
        }

        for(int k = zs - 1; k >= 1; k--){
            res = res + k;
        }

        printf("%d\n", res);
    
    }
 
}