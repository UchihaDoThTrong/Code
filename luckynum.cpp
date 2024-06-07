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
int t, x, n;
char a[10 * N];
int cnt[10 * N];
void inp(){
     cin >> x >> n;
     fo(i, 1, n){
          cin >> a[i];
          cnt[i] = cnt[i - 1] + (a[i] != '0');
     }
}
int get(int l, int r){
     return cnt[r] - cnt[l - 1];
}
void sol(){
     int zeros = 0;
     while(x % 10 == 0){
          zeros++;
          x /= 10;
     }
     int twos = 0, fives = 0;
     int num2 = 1, num5 = 1;
     while(x % 2 == 0){
          twos++;
          num2 *= 2;
          x /= 2;
     }
     while(x % 5 == 0){
          fives++;
          num5 *= 5;
          x /= 5;
     }
     ll ans = 0;
     fo(i, 1, n){
          if(a[i] == '0') ans++;
          if(i <= zeros) continue;
          if(zeros >= 1 && get(i - zeros + 1, i)) continue;
          int cur = 0;
          if(i - zeros - twos + 1 >= 1 && twos >= 1){
               fo(j, i - zeros - twos + 1, i - zeros) cur = cur * 10 + a[j] - '0';
               if(cur % num2 == 0) ans += cnt[i - zeros - twos + 1];
          }
          if(i - zeros - fives + 1 >= 1 && fives >= 1){
               fo(j, i - zeros - fives + 1, i - zeros) cur = cur * 10 + a[j] - '0';
               if(cur % num5 == 0) ans += cnt[i - zeros - fives + 1];
          }
          if(twos == 0 && fives == 0) ans += cnt[i - zeros];
//          cout << ans, el
     }
     cout << ans, el
}
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin >> t;
     while(t--){
          inp();
          sol();
     }
     return 0;
}
