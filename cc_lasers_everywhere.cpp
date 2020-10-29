#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void left_just(string &s, int n, char c = ' ') {
    while(s.length() < n) {
        s = c + s;
    }
}

template<typename T> void print_vector(vector<T> &vec) {

    int n = vec.size();
    for(int i = 0; i < n; i++) {
        if(i == n - 1)
            cout << vec[i];
        else
            cout << vec[i] << " ";
    }
    cout << "\n";
}

template<typename T> void print_matrix(vector<vector<T>> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        print_vector(mat[i]);
    }
}


class Event {
    public:
        Event() {y = 0; t = 0; i = 0;}
        Event(int iy, int it, int ii) {y = iy; t = it; i = ii;}
        int y;
        int t;
        int i;
};


int fenwick_sum(int index, vector<int> &fenwick_bit) {
    int res = 0;
    while(index > 0) {
        res += fenwick_bit[index];
        index -= (index & (-index));
    }
    return res;
}

void fenwick_update(int index, int value, vector<int> &fenwick_bit) {
    while(index < fenwick_bit.size()) {
        fenwick_bit[index] += value;
        index += (index & (-index));
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N, Q;
        cin >> N >> Q;

        vector<int> a_vec(N, 0);
        const int N_ROWS = 3;
        vector<vector<int>> q_vec(Q, vector<int>(N_ROWS, 0));

        for(int n = 0; n < N; n++) {
            cin >> a_vec[n];
        }

        for(int q = 0; q < Q; q++) {
            int x1, x2, y;
            cin >> x1 >> x2 >> y;
            q_vec[q][0] = x1;
            q_vec[q][1] = x2;
            q_vec[q][2] = y;
        }


        vector<Event> events;
        events.reserve(2*(N-1) + Q);
        for(int n = 0; n < N - 1; n++) {
            Event e_low = Event(min(a_vec[n], a_vec[n+1]), 1, n);
            Event e_high = Event(max(a_vec[n], a_vec[n+1]), 3, n);
        
            events.push_back(e_low);
            events.push_back(e_high);
        }

        for(int q = 0; q < Q; q++) {
            Event e_lazer = Event(q_vec[q][2], 2, q);
            events.push_back(e_lazer);
        }

        auto func = [](Event &e1, Event &e2){
            if(e1.y < e2.y) { 
                return true;
            } else if(e1.y == e2.y) {
                if(e1.t <= e2.t) {
                    return true;
                } else {
                    return false;
                }
            }
            return false;
        };
        sort(events.begin(), events.end(), func);

        // for(const auto & e : events) {
        //     cout << "e: " << e.y << " " << e.t << " " << e.i << "\n";
        // }

        vector<int> fenwick_bit(N, 0);
        vector<int> res(Q, 0);
        for(int i = 0; i < events.size(); i++) {
            if(events[i].t == 1) {
                fenwick_update(events[i].i+1, 1, fenwick_bit);
            } else if(events[i].t == 2) {
                res[events[i].i] = fenwick_sum(q_vec[events[i].i][1]-1, fenwick_bit) - fenwick_sum(q_vec[events[i].i][0]-1, fenwick_bit);
                // cout << "fenwick_sum(q_vec[events[i].i][1]-1, fenwick_bit): " << fenwick_sum(q_vec[events[i].i][1]-1, fenwick_bit) << "\n";
            } else if(events[i].t == 3) {
                fenwick_update(events[i].i+1, -1, fenwick_bit);
            }
        }

        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << "\n";
        }



    }

}