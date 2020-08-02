#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;

template<typename T> void print_vector(vector<T> &vec) {

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template<typename T> void print_matrix(vector<vector<T>> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        cout << i << ": ";
        print_vector(mat[i]);
    }
}

bool dfs(int &node, 
         int &parent,
         vector<int> &p,
         vector<int> &h,
         vector<vector<int>> &tree_node_connections,
         vector<int> &a,
         vector<int> &g){

    // cout << "Working on " << node << "\n";

    a[node] = p[node];
    int n_good_mood_visitors = 0;
    for(int i = 0; i < tree_node_connections[node].size(); i++) {
        int child = tree_node_connections[node][i];

        // cout << "Processing child " << child << "\n";

        if(child == parent) {
            continue;
        }

        int res = dfs(child, node, p, h, tree_node_connections, a, g);
        // cout << "Got result " << res << " for child " << child <<  "\n";

        if(res == false)
            return false;

        n_good_mood_visitors += g[child];
        a[node] += a[child];
    }


    // cout << "Back in dfs for node " << node << "\n";
    if((a[node] + h[node]) % 2 != 0) {
        // cout << "Did not meet conditon: a[node] + h[node]) == 2\n";
        return false;
    }

    g[node] = (a[node] + h[node])/2;
    if(g[node] < 0 || g[node] > a[node]) {
        // cout << "Did not meet conditon: g[node] >= 0 && g[node] <= a[node]\n";
        return false;
    }

    if(n_good_mood_visitors > g[node]) {
        // cout << "Did not meet condition: n_good_mood_visitors <= g[node]\n";
        return false;
    }

    return true;
}


int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 1; t <= T; t++) {
 
        lli N, M;
        cin >> N >> M;

        vector<int> p(N+1, 0);
        vector<int> h(N+1, 0);

        vector<vector<int>> tree_node_connections(N + 1, vector<int>());

        for(int i = 1; i < N+1; i++) {
            cin >> p[i];
        }

        for(int i = 1; i < N+1; i++) {
            cin >> h[i];
        }

        for(int i = 1; i <= N-1; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            tree_node_connections[n1].push_back(n2);
            tree_node_connections[n2].push_back(n1);
        }


        // print_matrix(tree_node_connections);

        int root = 1;
        int parent = 0;
        vector<int> a(N+1, 0); // Number of people that visited the city.
        vector<int> g(N+1, 0); // Number of people that visited the city with good mood.

        int res = dfs(root, parent, p, h, tree_node_connections, a, g);

        if(res == true) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}