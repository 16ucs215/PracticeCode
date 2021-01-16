#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
ll a[44];

int main() {
    ll n, x;
    cin>>n>>x;
    vector<int> v1, v2, s1, s2, us2;
    for(int i=0;i<n;i++) {
        cin>>a[i];

        if(i>=n/2) {
            v2.pb(a[i]);
        } else {
            v1.pb(a[i]);
        }
    }
    int p = n/2;
    int q = n - p;
    map<int, int> f1, f2, mark;
    for(int i=0;i<(1LL<<p);i++) {
        ll ans = 0;
        for(int j=0;j<p;j++) {
            if(i & (1LL<<j)) {
                ans += a[j];
            } else {
            }
        }
        f1[ans]++;
        s1.pb(ans);
    }
    ll sz = v2.size();
    for(int i=0;i<(1LL<<sz);i++) {
        ll ans = 0;
        for(int j=0;j<sz;j++) {
            if(i & (1LL<<j)) {
                ans += v2[j];
            }
        }
        f2[ans]++;
        s2.pb(ans);
    }

    for(int i=0;i<s2.size();i++) {
        if(!mark[s2[i]]) {
            mark[s2[i]] = 1;
            us2.pb(s2[i]);
        }
    }
    sort(us2.begin(), us2.end());

    ll fin = 0;
    for(int i=0;i<s1.size();i++) {
        ll req = x - s1[i];
        fin = fin + f2[req];
    }
    cout<<fin<<endl;
}

