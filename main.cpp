// author: jamikdev
#include <bits/extc++.h>
using namespace std;
const long long AURA = 1e18;
using ull = uint64_t;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
 
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...) 42
#endif
// hashing
ull SEED = chrono::steady_clock::now().time_since_epoch().count();
ull splitmix64(ull x) {
    x += SEED + 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}
 
ull hash_vector(const vector<ll>& v) {
    ull h = 0;
 
    for (ll x : v) {
        h ^= splitmix64((ull)x);
    }
 
    return h;
}
 

//xaxaxaxaxaxa im shit
void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (auto& d : a) cin >> d;
    for (auto& d : b) cin >> d;

    ll zeros = 0;   
    int best = 0;
    map<pll, int> mp;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            if (b[i] == 0) ++zeros;
            continue;               
        }
        ll num = -b[i];
        ll den = a[i];
        ll g = __gcd(llabs(num), llabs(den));  
        num /= g;
        den /= g;
        if (den < 0) {         
            num = -num;
            den = -den;
        }
        best = max(best, ++mp[{num, den}]);
    }

    cout << best + zeros << endl;
}
// Good guy with good problems :) XDDD
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef jamikdev
#endif
    int T = 1;
    //cin >> T;
    while (T--){
        solve();
    }
    
    return 0;
}
/*
If U are reading this stage of my code 

pls do not g00n :) bcs this code is so hot)
*/
