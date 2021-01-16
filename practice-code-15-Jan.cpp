// Problen => Given N weights. N <= 1000 and w[i] <= 1e6. Given W<=1e6. Check if creating W is possible
//Use of bitset in C++

#include <bits/stdc++.h>
using namespace std;
int n, W;

bitset<1000000> can;
int wt[100005];
int main() {
    cin>>n>>W;
    for(int i=0;i<n;i++) {
        cin>>wt[i];
    }
    can[0] = 1;

    for(int i=0;i<n;i++) {

        can = can | (can << wt[i]);

    }
    cout<<can[W]<<endl;
}