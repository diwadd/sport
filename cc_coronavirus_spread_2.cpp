#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;

struct TA {
    double d;
    int i; 
    int j;
    TA(double dx = 0.0, int ix = 0, int jx=0): d(dx), i(ix), j(jx) {}
    friend ostream& operator<<(ostream& os, const TA& ta);
};

ostream& operator<<(ostream& os, const TA& ta)
{
    os << "d: " <<  ta.d << " i: " << ta.i << " j: " << ta.j;
    return os;
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;

        vector<int> v_vec(N, 0);
        for(int i = 0; i < N; i++)
            cin >> v_vec[i];


        vector<vector<int>> t_vec(N, vector<int>(N, 0));
        vector<TA> time_athletes;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {

                if(i == j){
                    t_vec[i][j] = 1;
                    continue;
                }

                int v_i = v_vec[i];
                int v_j = v_vec[j];

                if((v_i == 0 && v_j == 0) || (v_i == v_j)) {
                    t_vec[i][j] = 0;
                    continue;
                }

                double d = ((double(i)+1.0) - (double(j)+1.0)) / (double(v_j) - double(v_i));
                t_vec[i][j] = ceil(d);

                if(d > 0 && i > j) {
                    time_athletes.push_back(TA(d, i+1, j+1));
                }

                t_vec[i][j] = max(0, t_vec[i][j]);
                t_vec[i][j] = min(1, t_vec[i][j]);
            }
        }


        auto comp = [](const TA &ta1, const TA &ta2){ return ta1.d < ta2.d; };
        sort(time_athletes.begin(), time_athletes.end(), comp);

        int res_min = numeric_limits<int>::max();
        int res_max = numeric_limits<int>::min();
        for(int n = 1; n <= N; n++) {
            set<int> run;
            run.insert(n);
            for(int m = 0; m < time_athletes.size(); m++) {
                
                int i = time_athletes[m].i;
                int j = time_athletes[m].j;

                if (run.find(i) != run.end() || run.find(j) != run.end()) {
                    run.insert(i);
                    run.insert(j);
                }
            }

            res_min = min(res_min, int(run.size()));
            res_max = max(res_max, int(run.size()));
        }

        cout << res_min << " " << res_max << "\n";

    }
}