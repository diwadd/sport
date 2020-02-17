#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
typedef unsigned long long int ulli;


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;    
    for(int i = 0; i < t; i++) {

        int m1, y1, m2, y2;
        cin >> m1 >> y1 >> m2 >> y2;

        if (m1 > 2)
            y1 = y1 + 1;
        if (m2 < 2)
            y2 = y2 - 1;

        int counter = 0;
        // We calcualte directly when the sample is small
        if (y2 - y1 < 1001) {
            for(int y = y1; y <= y2; ++y) {


                int a = y - 1;
                // This is the Gauss formula for the day of the week.
                int wd = (6 + 1 + 32 + 5*(a%4) + 4*(a%100) + 6*(a%400) ) % 7;
                if (wd == 6) {
                    ++counter;
                }
                int is_leap = ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
                if (is_leap == false && wd == 0) {
                    ++counter;
                }
            }
            cout << counter << endl;
            continue;
        }

        vector<int> pattern = {0, 0, 0};
        int y_mark = -1;
        int prev = -1;
        for(int y = y1; y <= y2; ++y) {


            int a = y - 1;
            // This is the Gauss formula for the day of the week.
            int wd = (6 + 1 + 32 + 5*(a%4) + 4*(a%100) + 6*(a%400) ) % 7;

            bool update_pattern = false;
            if (wd == 6) {
                update_pattern = true;
                ++counter;
            }
            int is_leap = ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
            if (is_leap == false && wd == 0) {
                update_pattern = true;
                ++counter;
            }

            int diff = 0;
            if (update_pattern == true) {
                if (prev == -1) {
                    prev = y;
                } else {
                    int diff = y - prev;
                    rotate(pattern.begin(), pattern.begin()+1, pattern.end());
                    pattern[2] = diff;

                    //cout << "y: " << y << " --- diff: " << diff << endl;
                }
                prev = y;

                //cout << "Pattern: " << pattern[0] << " " << pattern[1] << " " << pattern[2] << endl;

                if(pattern[0] == 1 && pattern[1] == 6 && pattern[2] == 5) {
                    //cout << "Pattern found" << endl;
                    y_mark = y;
                    break;
                }
            }

        }

        // 400 is the period of a leap year
        // 101 is the number of different Febuary months
        // that fulfill the solution condition.
        int freq = (y2 - y_mark) / 400;
        counter = counter + freq*101;

        int new_y1 = y_mark + freq*400 + 1;

        for(int y = new_y1; y <= y2; ++y) {


            int a = y - 1;
            // This is the Gauss formula for the day of the week.
            int wd = (6 + 1 + 32 + 5*(a%4) + 4*(a%100) + 6*(a%400) ) % 7;
            if (wd == 6) {
                ++counter;
            }
            int is_leap = ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
            if (is_leap == false && wd == 0) {
                ++counter;
            }
        }

        cout << counter  << endl;


    }
}