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
int n, m;
int a[22][N];
void inp(){
     cin >> n >> m;
     fo(i, 1, n){
          fo(j, 1, m){
               char ch; cin >> ch;
               a[i][j] = ch - '0';
          }
     }
}
int dp[22][1 << 20];
int MASK[N];
void sol(){
     fo(j, 1, m){
          fo(i, 1, n){
               MASK[j] |= a[i][j] << (i - 1);
          }
          dp[0][MASK[j]]++;
     }
     fo(i, 1, n){
          fo(mask, 0, (1 << n) - 1){
               if(i >= 2) dp[i][mask] = (i - 2 - n) * dp[i - 2][mask];
               fo(j, 0, n - 1){
                    dp[i][mask] += dp[i - 1][mask ^ (1 << j)];
               }
               dp[i][mask] /= k;
          }
     }
}
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     inp();
     sol();
     return 0;
}

