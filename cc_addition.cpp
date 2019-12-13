#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>

using namespace std;

int bit_addition(int &a, int &b) {

    std::bitset<8> ab(a);
    std::bitset<8> bb(b);
    cout << ab << endl; 
    cout << bb << endl; 

    int index = 0;
    while(b>0){
        // cout << "index: " << index << endl;
        int u = a ^ b;
        int v = a & b;
        a = u;
        b = v * 2;
        std::bitset<8> ub(u);
        std::bitset<8> vb(v);
        std::bitset<8> ab(a);
        std::bitset<8> bb(b);

        cout << "u: " << ub << endl;    
        cout << "v: " << vb << endl; 
        cout << "a: " << ab << endl; 
        cout << "b: " << bb << endl; 
        index++;
    }
    return index;
}


int main() {
 



    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        //string as;
        //string bs;

        int as;
        int bs;
        cin >> as;
        cin >> bs;
        //int a = stoi(as, nullptr, 2);
        //int b = stoi(bs, nullptr, 2);

        int res = bit_addition(a, b);
        printf("%d\n", res);
    }

}