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


template<typename T = int> class Vertex {

    public:
        T m_key;
        Vertex* m_parent;
        unsigned int m_rank; 

    Vertex() {
        m_key = T(); 
        m_parent = nullptr; 
        m_rank = 0; 
    }
    
    Vertex(T key) { 
        m_key = key; 
        m_parent = nullptr; 
        m_rank = 0;
    }

    friend bool operator==(const Vertex& lhs, const Vertex& rhs) {
        return lhs.m_key == rhs.m_key;
    }

    friend bool operator!=(const Vertex& lhs, const Vertex& rhs) {
        return !(lhs.m_key == rhs.m_key);
    }

    friend ostream& operator<<(ostream& os, const Vertex<T>& v)
    {
        os << v.m_key;
        return os;
    }

};

class Edge {

    public:
        int m_u;
        int m_v;

        Edge() {
            m_u = 0;
            m_v = 0;
        }

        Edge(int u, int v) {
            m_u = u;
            m_v = v;
        }
};

template<typename T = int> class DisjointSetForest {
    public:
        T m_parent;
        T m_rank;

        DisjointSetForest() {
            m_parent = T();
            m_rank = T();
        }

        DisjointSetForest(T parent, T rank) {
            m_parent = parent;
            m_rank = rank;
        }

    friend bool operator==(const DisjointSetForest& lhs, const DisjointSetForest& rhs) {
        return lhs.m_parent == rhs.m_parent;
    }

    friend bool operator!=(const DisjointSetForest& lhs, const DisjointSetForest& rhs) {
        return !(lhs.m_parent == rhs.m_parent);
    }
};

template<typename T> class Graph {
    public:
        vector<T> &m_vertex_list;
        vector<Edge> &m_edge_list;

    Graph() {}

    Graph(vector<T> &vertex_list, vector<Edge> &edge_list) : 
        m_vertex_list(vertex_list), m_edge_list(edge_list) {}

    void print() {
        for(int i = 0; i < m_vertex_list.size(); i++) {
            cout << m_vertex_list[i];
            for(int j = 0; j < m_edge_list.size(); j++) {
                int u = m_edge_list[j].m_u;
                int v = m_edge_list[j].m_v;
                if(u == m_vertex_list[i].m_key) {
                    cout << " -> " << v;
                } else if (v == m_vertex_list[i].m_key) {
                    cout << " -> " << u;
                }

            }
            cout << "\n";
        }

    }

};

template<typename T> void make_set(Vertex<T> &v) {
    v.m_parent = &v;
    v.m_rank = 0;
}

template<typename T> void link(Vertex<T>& x, Vertex<T>& y) {

    if(x.m_rank > y.m_rank) {
        y.m_parent = &x;
    } else {
        x.m_parent = &y;
        if(x.m_rank == y.m_rank) {
            y.m_rank++;
        }
    }
}

template<typename T> Vertex<T>& find_set(Vertex<T> &x) {
    if (&x != x.m_parent) {
        find_set(*x.m_parent);
    }
    return *x.m_parent;
}

template<typename T> void union_func(Vertex<T> &x, Vertex<T> &y) {
    link<T>(find_set<T>(x), find_set<T>(y));
}

template<typename T> void connected_components(Graph<Vertex<T>> &g) {

    for(int i = 0; i < g.m_vertex_list.size(); i++) {
        make_set(g.m_vertex_list[i]);
    }

    for(int i = 0; i < g.m_edge_list.size(); i++) {
        Edge &e = g.m_edge_list[i];
        if(find_set(g.m_vertex_list[e.m_u]) != find_set(g.m_vertex_list[e.m_v])) {
            union_func(g.m_vertex_list[e.m_u], g.m_vertex_list[e.m_v]);
        }
    }

}

template<typename T> bool same_component(Vertex<T> &u, Vertex<T> &v) {

    if(find_set(u) == find_set(v)) {
        return true;
    } else {
        return false;
    }

}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N, K;
        cin >> N >> K;

        int MAX_NUMBER_OF_VERTICES = N + 1;
        vector<Vertex<int>> vertex_list(MAX_NUMBER_OF_VERTICES, Vertex<int>(-1));
        vector<int> abc = {0, 0, 0};

        vector<int> type = {-1, -1, -1};

        int res = 0;
        for(int k = 0; k < K; k++) {
            
            int d, x, y;
            cin >> d >> x >> y;

            if(x > N || y > N) {
                // cout << "k: " << k << " is false.\n";
                res++;
                continue;
            }

            x--;
            y--;

            if (vertex_list[x].m_parent == nullptr) {
                make_set(vertex_list[x]);
            }

            if (vertex_list[y].m_parent == nullptr) {
                make_set(vertex_list[y]);
            }

            if(d == 1) {

                int kx = find_set(vertex_list[x]).m_key;
                int ky = find_set(vertex_list[y]).m_key;

                if(kx == -1 && ky == -1) {
                    if(abc[0] == 0) {
                        vertex_list[x].m_key = 0;
                        vertex_list[y].m_key = 0;
                        union_func(vertex_list[x], vertex_list[y]);
                        abc[0] = 1;
                        type[0] = x;
                    } else if(abc[1] == 0) {
                        vertex_list[x].m_key = 1;
                        vertex_list[y].m_key = 1;
                        union_func(vertex_list[x], vertex_list[y]);
                        abc[1] = 1;
                        type[1] = x;
                    } else if(abc[2] == 0) {
                        vertex_list[x].m_key = 2;
                        vertex_list[y].m_key = 2;
                        union_func(vertex_list[x], vertex_list[y]);
                        abc[2] = 1;
                        type[2] = x; 
                    } else {
                        vertex_list[x].m_key = 0;
                        vertex_list[y].m_key = 0;
                        union_func(vertex_list[type[0]], vertex_list[x]);
                        union_func(vertex_list[type[0]], vertex_list[y]);
                    }
                } else if(kx != -1 && ky == -1) {
                    vertex_list[x].m_key = vertex_list[y].m_key;
                    union_func(vertex_list[x], vertex_list[y]);
                } else if(kx == -1 && ky != -1) {
                    vertex_list[y].m_key = vertex_list[x].m_key;
                    union_func(vertex_list[x], vertex_list[y]);  
                } else if(kx != -1 && ky != -1) {

                    if(kx == ky) {
                        continue;
                    } else {
                        res++;
                        // cout << "k: " << k << " is false.\n";
                    }

                }


            } else if (d == 2) {

                int kx = find_set(vertex_list[x]).m_key;
                int ky = find_set(vertex_list[y]).m_key;

                if(kx == -1 && ky == -1) {

                    vertex_list[x].m_key = 0;
                    vertex_list[y].m_key = 1;
                    if(type[0] == -1)
                        type[0] = x;
                    if(type[1] == -1)
                        type[1] = y;

                } else if(kx != -1 && ky == -1) {

                    int nt = (vertex_list[x].m_key + 1) % (2 + 1);
                    vertex_list[y].m_key = nt;

                    if(type[nt] == -1) {
                        type[nt] = y;
                    } else {
                        union_func(vertex_list[type[nt]], vertex_list[y]);
                    }


                } else if(kx == -1 && ky != -1) {


                    int nt = (vertex_list[y].m_key - 1) % (2 + 1);
                    vertex_list[x].m_key = nt;

                    if(type[nt] == -1) {
                        type[nt] = x;
                    } else {
                        union_func(vertex_list[type[nt]], vertex_list[x]);
                    }


                } else if(kx != -1 && ky != -1) {

                    int k1 = vertex_list[x].m_key;
                    int k2 = vertex_list[y].m_key;

                    if ( (k1 == 0 && k2 == 1) || (k1 == 1 && k2 == 2) || (k1 == 2 && k2 == 0)) {
                        continue;
                    } else {
                        res++;
                        // cout << "k: " << k << " is false.\n";
                    }
                }
                


            }

        }


        cout << res << "\n";

    }


}