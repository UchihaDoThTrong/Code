// PhuThuyRuntime <3
// A secret makes a woman woman

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
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
int m, n, a[N], b[10 * N];
vi adj[20 * N];
void inp(){
     cin >> m >> n;
     fo(i, 1, m) cin >> a[i];
     fo(i, 1, n){
          cin >> b[i];
          adj[b[i] + 1000000].emplace_back(i);
     }
}
int dp[1001][1001];
int par[1001][1001];
void sol(){
     memset(dp, 0x3f, sizeof(dp));
     fo(i, 0, m) dp[i][0] = 0;
     int ans = 0;
     fo(i, 1, m){
          fo(j, 1, n){
               dp[i][j] = dp[i - 1][j];
               if(dp[i - 1][j - 1] <= m){
                    int id = lower_bound(adj[a[i] + 1000000].begin(), adj[a[i] + 1000000].end(), dp[i - 1][j - 1]) - adj[a[i] + 1000000].begin();
                    if(id != (int)adj[a[i] + 1000000].size()){
                         dp[i][j] = min(dp[i][j], adj[a[i] + 1000000][id]);
                         if(dp[i][j] == adj[a[i] + 1000000][id]){
                              par[i][j] = 1;
                         }
                    }
               }
//               cout << dp[i][j] << ' ';
               if(i == n && dp[i][j] <= m) ans = j;
          }
//          el
     }
     cout << ans, el
     int u = m, v = ans;
     vi res;
     while(v){
          if(par[u][v]) res.emplace_back(a[u]);
          v -= par[u][v];
          u--;
     }
     foi(i, (int)res.size() - 1, 0) cout << res[i] << ' ';
}
int main(){
     in("lcs.inp");
     out("lcs.out");
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     inp();
     sol();
     return 0;
}
