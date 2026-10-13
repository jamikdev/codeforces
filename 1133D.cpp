// author: jamikdev
#include <bits/extc++.h>
using namespace std;
using ull = uint64_t;
using ll = long long;

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
    for (ll x : v) h ^= splitmix64((ull)x);
    return h;
}

vector<bool> isPrime(51, true); 
vector<int> primes;               

vector<ll> kopaytmalar;
vector<ll> kopaytmalar_manfiy;
vector<vector<ll>> dd;
vector<vector<ll>> qq;
ll manfiylar = 0;
ll musbat = 0;
int x;
vector<ll> oddPrimes(ll v) {
    vector<ll> res;
    for (int p : primes) {
        int cnt = 0;
        while (v % p == 0) {
            v /= p;
            cnt++;
        }
        if (cnt & 1) res.push_back(p);
    }
    if (v > 1) res.push_back(v);  
    return res;
}

void addtosum() {
    for (int i = 0; i < musbat; ++i) dd[i] = oddPrimes(kopaytmalar[i]);
}

void addtosum2() {
    for (int i = 0; i < manfiylar; ++i) qq[i] = oddPrimes(kopaytmalar_manfiy[i]);
}

void solve() {
    cin >> x;

    vector<ll> a(x);
    vector<ll> b(x);
    ll sum = 0;
    ll sum2 = 0;
    for (auto& d : a) cin >> d;
    for (auto& d : b) cin >> d;
    for (int i = 0; i < x; ++i) {
        if (a[i] * b[i] > 0) {
            kopaytmalar.push_back(a[i] * b[i]);
            ++musbat;
        } else if (a[i] * b[i] < 0) {
            kopaytmalar_manfiy.push_back(abs(a[i] * b[i]));
            ++manfiylar;
        } else {
            if (a[i] == 0 && b[i] == 0) {
                ++sum;
                ++sum2;
            } else if (b[i] == 0 && a[i] != 0) {
                if (a[i] > 0) {
                    kopaytmalar.push_back(a[i]);
                    musbat++;
                } else {
                    kopaytmalar_manfiy.push_back(abs(a[i]));
                    manfiylar++;
                }
            }
        }
    }

    dd.assign(musbat, {});
    qq.assign(manfiylar, {});
    addtosum();
    addtosum2();

    map<ull, int> mp;
    map<ull, int> mpsec;

    for (int i = 0; i < musbat; ++i) mp[hash_vector(dd[i])]++;
    for (int i = 0; i < manfiylar; ++i) mpsec[hash_vector(qq[i])]++;

    ll cnt = 0;
    ll cnt1 = 0;
    for (int i = 0; i < musbat; ++i) {
        auto it = mp.find(hash_vector(dd[i]));
        if (it != mp.end()) cnt += it->second;
    }
    for (int i = 0; i < manfiylar; ++i) {
        auto it = mpsec.find(hash_vector(qq[i]));
        if (it != mpsec.end()) cnt1 += it->second;
    }
    sum += cnt;
    sum2 += cnt1;

    cout << max(sum, sum2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    int n = 50;

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes.push_back(i);

    // cin >> T;
    while (T--) {
        kopaytmalar.clear();
        kopaytmalar_manfiy.clear();
        solve();
    }
    return 0;
}
