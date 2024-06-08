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
int m, n;
vi g[N], f[N];
void inp(){
     cin >> m >> n;
     fo(i, 1, n){
          int u, v; cin >> u >> v;
          g[u].emplace_back(i);
          f[v].emplace_back(i);
     }
}
int port[N];
void sol(){
     stack<int> st;
     foi(i, m, 1) st.push(i);
     fo(i, 0, 100000){
          for(auto it : f[i]){
               st.push(port[it]);
          }
          for(auto it : g[i]){
               if(st.empty()){
                    continue;
               }
               port[it] = st.top();
               st.pop();
          }
     }
     vi res;
     fo(i, 1, n) if(port[i]) res.emplace_back(port[i]);
     cout << (int)res.size(), el
     fo(i, 1, n) cout << port[i] << ' ';
}
int main(){
     in("seaports.inp");
     out("seaports.out");
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     inp();
     sol();
     return 0;
}
