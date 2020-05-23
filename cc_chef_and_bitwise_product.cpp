#include <bits/stdc++.h> 
//#define SIMPLE_LOG

using namespace std;
typedef long long ll;



int main() {

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int T;
    scanf("%d", &T);

    const int MAX_BITS = 48;

    for(int i = 0; i < T; i++) {
        ll X, Y, L, R;
        scanf("%llu %llu %llu %llu", &X, &Y, &L, &R);

        if (L == R) {
            printf("%llu\n", L);
            continue;
        }

        bitset<MAX_BITS> bX(X);
        bitset<MAX_BITS> bY(Y);
        bitset<MAX_BITS> bL(L);
        bitset<MAX_BITS> bR(R);

        int k = 0;
        for(int j = MAX_BITS - 1; j >= 0; j--){
            if( bL[j] != bR[j]){
                k = j;
                break;
            }
        }

        bitset<MAX_BITS> bZ(0);

        #ifndef SIMPLE_LOG
            cout << "bZ 1: " << bZ << " " << bZ.to_ullong() << endl;
        #endif

        for(int j = MAX_BITS; j > k; j--){
            bZ[j] = bR[j];
        }

        #ifndef SIMPLE_LOG
            cout << "bZ 2: " << bZ << " " << bZ.to_ullong() << endl;
        #endif

        vector<ll> z_candidates;
        for(int j = k; j >= 0; j--) {

            if(bR[j] == 0) {
                bZ[j] = 0;
                continue;
            }

            if(bR[j] == 1) {
                bZ[j] = 0;
                for(int l = j-1; l >=0; l--){
                    bZ[l] = 1; //XorY[l];
                }

                #ifndef SIMPLE_LOG
                    cout << "bZ 3: " << bZ << " " << bZ.to_ullong() << endl;
                #endif

                z_candidates.push_back(bZ.to_ullong());
                bZ[j] = 1;
            }

        }

        z_candidates.push_back(bR.to_ullong());
        z_candidates.push_back(bL.to_ullong());

        #ifndef SIMPLE_LOG
            cout << "--- --- ---" << endl;
            for(auto z : z_candidates) {
                cout << "z:    " << bitset<MAX_BITS>(z) << " " << z << endl;
            }
            cout << "--- --- ---" << endl;
        #endif

        sort(z_candidates.begin(), z_candidates.end());

        #ifndef SIMPLE_LOG
            cout << "--- --- ---" << endl;
            for(auto z : z_candidates) {
                cout << "z:    " << bitset<MAX_BITS>(z) << " " << z << endl;
            }
            cout << "--- --- ---" << endl;
        #endif

        ll maxF = numeric_limits<ll>::min();
        ll minZ = *z_candidates.begin();
        for(int j = 0; j < z_candidates.size(); j++) {
            ll Z = z_candidates[j];
            ll F = (X & Z)*(Y & Z);
            if( F > maxF ) {
                maxF = F;
                minZ = Z;
            }
        }


        bitset<MAX_BITS> bminZ(minZ);

        #ifndef SIMPLE_LOG
            cout << "minZ: " << bminZ << " " << bminZ.to_ullong() << endl;
        #endif

        for(int j = k; j >= 0; j--) {

            if(bminZ[j] == 0)
                continue;

            if(bX[j] == 0 && bY[j] == 0){
                bminZ[j] = 0;
            } else {
                continue;
            }

            if (bminZ.to_ullong() < bL.to_ullong()){
                bminZ[j] = 1;
                continue;
            }


        }

        #ifndef SIMPLE_LOG
            cout << "bX:   " << bX << " " << bX.to_ullong() << endl;
            cout << "bY:   " << bY << " " << bY.to_ullong() << endl;
            cout << "bR:   " << bR << " " << bR.to_ullong() << endl;
            cout << "bL:   " << bL << " " << bL.to_ullong() << endl;
            cout << "minZ: " << bminZ << " " << bminZ.to_ullong() << endl;
        #endif

        ll res = bminZ.to_ulong();
        printf("%llu\n", res);


    }
}