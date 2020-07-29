#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

const int N_LETTERS = 26;
int N_LEAFS = 1000000;

class Leaf {
    public:
        Leaf *next[N_LETTERS];
        int freqs[N_LETTERS];

        Leaf() {
            for(int i = 0; i < N_LETTERS; i++) {
                next[i] = nullptr;
                freqs[i] = 0;
            }
        }
};

void print_tree(Leaf *root) {

    for(int i = 0; i < N_LETTERS; i++) {
        cout << char('A' + char(i)) << ": " << root->freqs[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < N_LETTERS; i++) {
        if(root->next[i] != nullptr) {
            print_tree(root->next[i]);
        }
    }

}

void count_value(Leaf *root, int &value, int &K) {

    for(int i = 0; i < N_LETTERS; i++) {
        if(root->next[i] != nullptr) {
            value = value + floor(root->freqs[i] / K);
            count_value(root->next[i], value, K);
        }
    }

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {

        int N, K;
        cin >> N >> K;

        Leaf root;
        Leaf *current = &root;
        vector<Leaf> leafs_vec;
        leafs_vec.reserve(N_LEAFS);

        for(int i = 0; i < N; i++) {

            string s;
            cin >> s;

            for(int j = 0; j < s.length(); j++) {

                int c = s[j] - 'A';

                current->freqs[c]++;
                if(current->next[c] == nullptr) {
                    current->next[c] = new Leaf();
                }
                current = current->next[c];
            }
            current = &root;
        }

        // print_tree(&root);

        int value = 0;
        count_value(&root, value, K);

        cout << "Case #" << t << ": " << value << "\n";
    }
}