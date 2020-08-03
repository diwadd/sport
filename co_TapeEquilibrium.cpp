#include <vector>
#include <limits>

using namespace std;

int solution(vector<int> &A) {
    
    int total = 0;
    for(unsigned int i = 0; i < A.size(); i++) {
        total += A[i];
    }
    
    int left = 0;
    int right = total;
    int min_d = numeric_limits<int>::max();
    
    for(unsigned int i = 1; i < A.size(); i++) {
        
        left = left + A[i-1];
        right = right - A[i-1];
        int d = abs(left - right);
        // cout << "d: " << d << endl;
        if(d < min_d)
            min_d = d; 
    }
    return min_d;
}