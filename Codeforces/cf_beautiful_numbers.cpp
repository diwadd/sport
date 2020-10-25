#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        vector<int> p(n, 0);
        for(int j = 0; j < n; j++) {
            int el;
            scanf("%d", &el);
            p[j] = el;

        }


        int left = 0;
        int right = n-1;
        int d = right - left + 1;
        string s(n,'0');

        for(int j = n; j > 0; j--) {
 
            // printf("j: %d d: %d left: %d right: %d p[left]: %d p[right]: %d\n", j, d, left, right, p[left], p[right]);
            while ((p[left] > j || p[right] > j) && d > j) {

                if (p[left] > j) {
                    left = left + 1;
                    d = right - left + 1;
                    continue;
                } else if (p[right] > j) {
                    right = right - 1;
                    d = right - left + 1;
                    continue;
                }

            }

            if (p[left] <= j && p[right] <= j && d == j) {
                // printf("setting s[%d] to 1\n", j-1);
                s[j-1] = '1';
            } else if (p[left] <= j &&  p[right] <= j && d > j) {
                continue;
            }



        }

        cout << s << endl;

    }


}