#include <bits/stdc++.h> 

using namespace std;

int main() {

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int t;
    scanf("%d",&t);


    for(int i = 0; i < t; i++) {
        int r, c;
        scanf("%d %d", &r, &c);

        vector<pair<int,int>> route;
        route.reserve(20);
        if (r == c){
            route.push_back(make_pair(1, 1));
        } else {
            int s = (r + c)/2;
            route.push_back(make_pair(s, s));
            route.push_back(make_pair(1, 1));
        }

        // Chess board positions along the path
        // of the bishop.
        route.push_back(make_pair(2,2));
        route.push_back(make_pair(1,3));
        route.push_back(make_pair(3,1));
        route.push_back(make_pair(8,6));
        route.push_back(make_pair(6,8));
        route.push_back(make_pair(2,4));
        route.push_back(make_pair(5,1));
        route.push_back(make_pair(8,4));
        route.push_back(make_pair(4,8));
        route.push_back(make_pair(2,6));
        route.push_back(make_pair(1,5));
        route.push_back(make_pair(2,6));
        route.push_back(make_pair(7,1));
        route.push_back(make_pair(8,2));
        route.push_back(make_pair(2,8));
        route.push_back(make_pair(1,7));
        route.push_back(make_pair(4,4));
        route.push_back(make_pair(8,8));

        int n = route.size();
        printf("%d\n", n);
        for(int i = 0; i < n; i++){
            printf("%d %d\n", route[i].first, route[i].second);
        }
    }

}