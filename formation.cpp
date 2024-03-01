// PhuThuyRuntime ❤
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
#define onbit(i, j) (1 << j)  i
const int N = 1e5 + 2;
const ll mod = 1e9 + 7;
const int inf = INT_MAX;
const int base = 31;
const long double EPS = 1e-9;
const long double pi = acos(-1.0);
int n, m, k, a[2002][2002];
void inp(){
     cin >> n >> m >> k;
     fo(i, 1, n){
          fo(j, 1, m) cin >> a[i][j];
     }
}
int f[4004][4004];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int get(int i, int j, int u, int v, int f[][4004]){
     if(i > u || j > v) return 0;
     return f[u][v] - f[i - 1][v] - f[u][j - 1] + f[i - 1][j - 1];
}
int get(int i, int j, int dis){
     int ii = i + j - 1, jj = i - j + m;
     return get(max(1, ii - dis), max(1, jj - dis), min(n + m, ii + dis), min(n + m, jj + dis), f);
}
int val[4][2002][2002];
int sum[4][4004][4004];
int pref[4][4004][4004];
int cnt[4][4004][4004];
int precnt[4004][4004];
void full(){
     fo(i, 1, n){
          fo(j, 1, m){
               f[i + j - 1][i - j + m] = a[i][j];
          }
     }
     fo(i, 1, n + m){
          fo(j, 1, n + m){
               val[0][i][j] = a[i][j] * (i + j);
               val[1][i][j] = a[i][j] * ((n + 1 - i) + j);
               val[2][i][j] = a[i][j] * ((n + 1 - i) + (m + 1 - j));
               val[3][i][j] = a[i][j] * (i + (m + 1 - j));
               fo(id, 0, 3){
                    sum[id][i][j] = sum[id][i - 1][j] + sum[id][i][j - 1] - sum[id][i - 1][j - 1] + val[id][i][j];
               }
               precnt[i][j] = precnt[i - 1][j] + precnt[i][j - 1] - precnt[i - 1][j - 1] + a[i][j];
          }
     }
     fo(i, 1, n + m){
          fo(j, 1, n + m){
               f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
          }
     }
     fo(i, 1, n + m){
          fo(j, 1, n + m){
               pref[0][i][j] = val[0][i][j] + pref[0][i - 1][j] + pref[0][i - 1][j + 1];
               if(i >= 2) pref[0][i][j] -= pref[0][i - 2][j + 1];
               pref[1][i][j] = val[1][i][j] + pref[1][i][j - 1] + pref[1][i - 1][j - 1];
               if(j >= 2) pref[1][i][j] -= pref[1][i - 1][j - 2];
               cnt[0][i][j] = (val[0][i][j] > 0) + cnt[0][i - 1][j] + cnt[0][i - 1][j + 1];
               if(i >= 2) cnt[0][i][j] -= cnt[0][i - 2][j + 1];
               cnt[1][i][j] = (val[1][i][j] > 0) + cnt[1][i][j - 1] + cnt[1][i - 1][j - 1];
               if(j >= 2) cnt[1][i][j] -= cnt[1][i - 1][j - 2];
          }
     }
     foi(i, n + m, 1){
          foi(j, n + m, 1){
               pref[2][i][j] = (i >= m && j >= n ? val[2][i - m][j - n] : 0) + pref[2][i + 1][j - 1] + pref[2][i + 1][j] - pref[2][i + 2][j - 1];
               pref[3][i][j] = (i >= m && j >= n ? val[3][i - m][j - n] : 0) + pref[3][i][j + 1] + pref[3][i + 1][j + 1] - pref[3][i + 1][j + 2];
               cnt[2][i][j] = (i >= m && j >= n ? (val[2][i - m][j - n] > 0) : 0) + cnt[2][i + 1][j - 1] + cnt[2][i + 1][j] - cnt[2][i + 2][j - 1];
               cnt[3][i][j] = (i >= m && j >= n ? (val[3][i - m][j - n] > 0) : 0) + cnt[3][i][j + 1] + cnt[3][i + 1][j + 1] - cnt[3][i + 1][j + 2];
          }
     }
     ll totalans = 0;
     fo(i, 1, 1){
          fo(j, m, m){
               int pre = m + n - 2;
               while(pre-- >= 0){
//                    cout << pre << " : " << get(i, j, pre), el
                    if(get(i, j, pre) < k) break;
               }
               int val = get(i, j, pre);
               pre++;
               ll ans = (k - val) * pre;
               cout << pre << ' ';
               if(pre <= 1){
//                    cout << ans << ' ';
                    totalans += ans;
                    continue;
               }
               else{
                    pre--;

                    // x - i + y - j <= pre
                    ans += pref[0][i + pre][j] - pref[0][i][j + pre] - get(1, j, i, j + pre - 1, sum[0]);
//                    cout << pref[0][i + pre][j] << ' ' << pref[0][i][j + pre] << ' ' << get(1, j, i, j + pre - 1, sum[0]), el
                    ans -= (i + j) * (cnt[0][i + pre][j] - cnt[0][i][j + pre] - get(1, j, i, j + pre - 1, precnt));
//                    cout << ans, el

                    // i - x + y - j <= pre
                    ans += pref[1][i][j + pre] - pref[1][max(i - 1, i - pre - 1)][j] - get(max(i - 1, i - pre - 1) + 1, 1, i, j, sum[1]);
//                    cout << pref[1][i][j + pre] << ' ' << pref[1][max(i, i - pre - 1)][j] << ' ' << get(max(i, i - pre - 1) + 1, 1, i, j, sum[1]), el
                    ans -= (n + 1 - i + j) * (cnt[1][i][j + pre] - cnt[1][max(i - 1, i - pre - 1)][j] - get(max(i - 1, i - pre - 1) + 1, 1, i, j, precnt));
//                    cout << ans, el

                    // i - x + j - y <= pre
                    ans += pref[2][max(0, i - pre + m)][j + n] - pref[2][i + m][max(0, j - pre + n)] - get(i, max(0, j - pre + 1), n, j, sum[2]);
//                    cout << pref[2][max(0, i - pre + m)][j + n] << ' ' << pref[2][j >= pre ? i + m : i - (pre - j) + m][max(0, j - pre + n)] << ' ' << get(j >= pre ? i : i - (pre - j), max(0, j - pre) + 1, n, j, sum[2]), el
                    ans -= (n + 1 - i + m + 1 - j) * (cnt[2][max(0, i - pre + m)][j + n] - cnt[2][i + m][max(0, j - pre + n)] - get(i, max(0, j - pre + 1), n, j, precnt));
//                    cout << ans, el

                    // x - i + j - y <= pre
                    ans += pref[3][i + m][j - pre + n] - pref[3][min(i + pre, n + 1) + m][i + pre > n ? j - (i + pre - n) + 1 + n : j + n] - get(i, i + pre > n ? j - (i + pre - n) + 1 : j, min(i + pre, n + 1) - 1, m, sum[3]);
//                    cout << pref[3][i + m][j - pre + n] << ' ' << pref[3][min(i + pre, n + 1) + m][i + pre > n ? j - (i + pre - n) + n : j + n] << ' ' << get(i, i + pre > n ? j - (i + pre - n) + 1 : j, min(i + pre, n + 1) - 1, m, sum[3]), el
                    ans -= (i + m + 1 - j) * (cnt[3][i + m][j - pre + n] - cnt[3][min(i + pre, n + 1) + m][i + pre > n ? j - (i + pre - n) + 1 + n : j + n] - get(i, i + pre > n ? j - (i + pre - n) + 1: j, min(i + pre, n + 1) - 1, m, precnt));
//                    cout << ans, el
               }
               totalans += ans;
               cout << ans << ' ';
          }
          el
     }
     cout << totalans;
}
char ch[4004][4004];
void test(){
     fo(i, 1, n){
          fo(j, 1, m){
               ch[i + j - 1][i - j + m] = char(a[i][j] + '0');
          }
     }
     fo(i, 1, n + m){
          fo(j, 1, n + m){
               cout << ch[i][j] << ' ';
          }
          el
     }
//     memset(ch, ' ', sizeof(ch));
//     fo(i, 1, n){
//          fo(j, 1, m){
//               if(i <= 2 && j >= 3 && j - i <= 2) ch[i + j - 1][i - j + m] = char(a[i][j] + '0');
//          }
//     }
//     fo(i, 1, n + m){
//          fo(j, 1, n + m) cout << ch[i][j] << ' ';
//          el
//     }
}
void sol(){
//     test();
     full();
}
int main(){
//     in("formation.inp");
//     out("formation.out");
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     inp();
     sol();
     return 0;
}
/*
3 4 6
0 0 1 1
0 1 0 1
0 1 1 0
*/
