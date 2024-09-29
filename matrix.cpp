// PhuThuyRuntime <3
// A secret makes a woman woman

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define fo(i, l, r) for(int i = l; i <= r; i++)
#define foi(i, l, r) for(int i = l; i >= r; i--)
#define elif else if
#define el cout << "\n";
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define fi first
#define se second
#define in(x) freopen(x, "r", stdin)
#define out(x) freopen(x, "w", stdout)
#define ll long long
#define ull unsigned long long
#define pob pop_back
#define bs binary_search
#define vi vector<int>
#define vii vector<pair<int, int>>
#define getbit(i, j) (i >> j) & 1
#define offbit(i, j) (1 << j) ^ i
#define onbit(i, j) (1 << j) | i
const int N = 1e5 + 2;
const ll mod = 1e9 + 7;
const int inf = INT_MAX;
const int base = 31;
const long double EPS = 1e-9;
const long double pi = acos(-1.0);
unordered_map<int, int> m; // if multiply queries, no need to recompute inverse :)
ll Pow(ll a, ll b, ll m){
     if(b == 0) return 1;
     ll tmp = Pow(a, b / 2, m);
     tmp = (tmp * tmp) % m;
     if(b % 2) tmp = (tmp * a) % m;
     return tmp;
}
int rv(int x) {
     if (m.count(x)) return m[x];
     return m[x] = Pow(x, mod - 2, mod);
}

int interpolate(int x, int k, bool bf = false) {
     if(x == 0) return 0;
     if (k == 0) return x;
     // find 1^k + 2^k + ... + x^k
     // (k+1) degree polynomial -> (k+2) points
     if (x <= k + 1 | bf) {
          int s = 0;
          for (int i = 1; i <= x; i ++) {
               s = (s + Pow(i, k, mod)) % mod;
          }
          return s;
     }
     vector<int> pre(k + 2), suf(k + 2), inv(k + 2);
     inv[0] = 1;
     pre[0] = x;
     suf[k + 1] = x - (k + 1);
     for (int i = 1; i <= k; i ++) pre[i] = pre[i - 1] * (x - i) % mod; //numerator prefix product
     for (int i = k; i >= 1; i --) suf[i] = suf[i + 1] * (x - i) % mod; //numerator suffix product
     for (int i = 1; i <= k + 1; i ++) inv[i] = inv[i - 1] * rv(i) % mod; // denominator factorial
     int ans = 0;
     int yi = 0; // 0^k +~ i^k
     int num, denom;
     for (int i = 0; i <= k + 1; i ++) {
          yi = (yi + Pow(i, k, mod)) % mod; // interpolate point: (i, yi)

          if (i == 0) num = suf[1];
          else if (i == k + 1) num = pre[k];
          else num = pre[i - 1] * suf[i + 1] % mod; // numerator

          denom = inv[i] * inv[k + 1 - i] % mod; // denominator

          if ((i + k) & 1) ans += (yi * num % mod) * denom % mod; // (-1)^(i-deg) however deg is k+1 here so :)
          else ans -= (yi * num % mod) * denom % mod;

          ans = (ans % mod + mod) % mod;
     }
     return ans;
}
int t, n, k, ALPHA, BETA;
ll u, v, x, y;
ll powalpha, powbeta;
void inp(){
     cin >> n >> k >> ALPHA >> BETA >> u >> v >> x >> y;
}
ll get(int l, int r, int k){
     return (interpolate(r, k) - interpolate(l - 1, k) + mod) % mod;
}
ll geta(int i, int ii, int j, int jj){
     return get(i, ii, ALPHA) * get(j, jj, BETA) % mod;
}
ll getb(int i, int ii, int j, int jj){
     return get(i, ii, BETA) * get(j, jj, ALPHA) % mod;
}
int val(int u){
     return (u - 1) % n + 1;
}
void sol(){
     int hangu = (u - 1) / n + 1;
     int hangx = (x - 1) / n + 1;
     int cotv = (v - 1) / n + 1;
     int coty = (y - 1) / n + 1;
     int cnthang = hangx - hangu - 1;
     int cntcot = coty - cotv - 1;
     powalpha = interpolate(n, ALPHA);
     powbeta = interpolate(n, BETA);
     ll source = powalpha * powbeta % mod;
     ll ans = 0;
     if(cnthang > 0 && cntcot > 0){
          ll cnt = (1LL * cnthang * cntcot) % mod;
          ans = (cnt * source) % mod;
     }
     if((hangu + cotv) % 2 == 0){
          if(hangu == hangx){
               if(cotv == coty) ans = (ans + get(val(u), val(x), ALPHA) * get(val(v), val(y), BETA)) % mod;
               else{
                    ans = (ans + get(val(u), val(x), ALPHA) * get(val(v), n, BETA)) % mod;
                    if(cntcot & 1){
                         ans = (ans + get(val(u), val(x), ALPHA) * get(1, val(y), BETA)) % mod;
                         int cntb = cntcot / 2 + 1;
                         int cnta = cntcot / 2;
                         ans = (ans + cntb * getb(val(u), val(x))) % mod;
                         ans = (ans + cnta * geta(val(u), val(x))) % mod;
                    }
                    else{
                         ans = (ans + get(val(u), val(x), BETA) * get(1, val(y), ALPHA)) % mod;
                         int cnta = cntb = cntcot / 2;
                         ans = (ans + cntb * getb(val(u), val(x))) % mod;
                         ans = (ans + cnta * geta(val(u), val(x))) % mod;
                    }
               }
          }
          else{
               if(cotv == coty){
                    ans = (ans + get(val(u), n, ALPHA) * get(val(v), val(y), BETA)) % mod;
                    if(cnthang & 1){
                         ans = (ans + get(1, val(x), ALPHA) * get(val(v), val(y), BETA)) % mod;
                         int cntb = cnthang / 2 + 1;
                         int cnta = cnthang / 2;
                         ans = (ans + cntb * geta(val(v), val(y))) % mod;
                         ans = (ans + cnta * getb(val(v), val(y))) % mod;
                    }
                    else{
                         ans = (ans + get(1, val(x), BETA) * get(val(v), val(y), ALPHA)) % mod;
                         int cnta = cntb = cnthang / 2;
                         ans = (ans + cnta * getb(val(v), val(y))) % mod;
                         ans = (ans + cntb * geta(val(v), val(y))) % mod;
                    }
               }
               else{
                    ans = (ans + get(val(u), n, ALPHA) * get(val(v), n, BETA)) % mod;
                    if(cntcot & 1){
                         ans = (ans + get(val(u), n, ALPHA) * get(1, val(y), BETA)) % mod;
                         int cntb = cntcot / 2 + 1;
                         int cnta = cntcot / 2;
                         ans = (ans + cntb * getb(val(u), n)) % mod;
                         ans = (ans + cnta * geta(val(u), n)) % mod;
                    }
                    else{
                         ans = (ans + get(val(u), n, BETA) * get(1, val(y), ALPHA)) % mod;
                         int cntb = cntcot / 2;
                         int cnta = cntcot / 2;
                         ans = (ans + cntb * getb(val(v), val(y))) % mod;
                         ans = (ans + cnta * geta(val(v), val(y))) % mod;
                    }
                    if(cnthang & 1){
                         ans = (ans + get(1, val(x), ALPHA) * get(val(v), n, BETA)) % mod;
                         int cntb = cnthang / 2 + 1;
                         int cnta = cnthang / 2;
                         ans = (ans + cntb * getb(1, n, val(v), n)) % mod;
                         ans = (ans + cnta * geta(1, n, val(v), n)) % mod;
                    }
                    else{
                         ans = (ans + get(1, val(x), BETA) * get(val(v), n, ALPHA)) % mod;
                         int cntb = cnthang / 2;
                         int cnta = cnthang / 2;
                         ans = (ans + cntb * getb(1, n, val(v), n)) % mod;
                         ans = (ans + cnta * geta(1, n, val(v), n)) % mod;
                    }
               }
          }
     }

}
int main(){
//     in("matrix.inp");
//     out("matrix.out");
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin >> t;
     while(t--){
          inp();
          sol();
     }
     return 0;
}
