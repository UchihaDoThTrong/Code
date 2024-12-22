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
#define vi vector<int>
#define vii vector<pair<int, int>>
#define getbit(i, j) ((i >> j) & 1)
#define offbit(i, j) ((1 << j) ^ i)
|#define onbit(i, j) ((1 << j) | i)
const int N = 1e5 + 2;
const ll mod = 1e9 + 7;
const int inf = INT_MAX;
const int base = 31;
const long double EPS = 1e-9;
const long double pi = acos(-1.0);

void inp(){
     
}
void sol(){
     
}
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     inp();
     sol();
     return 0;
}
-------------------------------
// PhuThuyRuntime <3
// A secret makes a woman woman

#include <bits/stdc++.h>
#include <Windows.h>

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
#define el trong << "\n";
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
|#define onbit(i, j) (1 << j) | i
void SET_COLOR(int color){
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
//     1     BLUE
//     2     GREEN
//     3     AQUA
//     4     RED
//     5     PURPLE
//     6     YELLOW
//     7     WHITE
//     8     GRAY
//     9     LIGHT BLUE
//     10 ( A )     LIGHT GREEN
//     11 ( B )     LIGHT AQUA
//     12 ( C )     LIGHT RED
//     13 ( D )     LIGHT PURPLE
//     14 ( E )     LIGHT YELLOW
//     15 ( F )     BRIGHT WHITE
}
const int N = 1e5 + 2;
const ll mod = 1e9 + 7;
const int inf = INT_MAX;
const int base = 31;
const long double EPS = 1e-9;
const long double pi = acos(-1.0);
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
     return l + rd() % (r - l + 1);
}
const string NAME = "";
const int NTEST = 100;
string alphabet = "qwertyuiopasdfghjklzxcvbnm";
string digit = "1234567890";


void inp(){

}
int main(){
     for(int iTest = 1; iTest <= NTEST; iTest++){
          ofstream trong((NAME + ".inp").c_str());
          inp();

          trong.close();
          system((NAME + ".exe").c_str());
          system((NAME + "_trau.exe").c_str());

          if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0){
               SET_COLOR(4);
               cout << "Test " << iTest << " WRONG\n";
               SET_COLOR(7);
               return 0;
          }
          else{
               SET_COLOR(2);
               cout << "Test " << iTest << " CORRECT\n";
               SET_COLOR(7);
          }
     }
     return 0;
}
---------------------------------
const int base = 1000000000;
const int base_digits = 9;
struct bigint {
    vector<int> a; int sign;

    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};
--------------------------
struct BinarySearch {
     int l, r, best;
     BinarySearch(int _l = 0, int _r = 0): l(_l), r(_r), best(_r+1) {}
     int getMid(){
          return (l + r) >> 1;
     }
     bool finished(){
          return l > r;
     }
     void update(bool go_left){
          if (go_left){
               best = getMid();
               r = getMid() - 1;
          }
          else l = getMid() + 1;
     }
} state[N];
--------------------------
struct Trie{
     struct Node{
          Node* child[2];
          int cnt;
          Node(){
               child[0] = child[1] = NULL;
               cnt = 0;
          }
     };
     int cur;
     Node* root;
     Trie() : cur(0){
          root = new Node();
     };
     void add(int val){
          Node *p = root;
          foi(i, 31, 0){
               int k = getbit(val, i);
               if(p -> child[k] == 0) p -> child[k] = new Node();
               p = p -> child[k];
               p -> cnt++;
          }
     }
     int count(int val){
          Node *p = root;
          foi(i, 31, 0){
               int k = getbit(val,i);
               if(p -> child[k] == 0 ||| p -> child[k] -> cnt == 0) return 0;
               p = p -> child[k];
          }
          return p -> cnt;
     }
     bool findnum(int val){
          return count(val) > 0;
     }
     void del(int num, int val){
          Node *p = root;
          foi(i, 31, 0){
               int k = getbit(num, i);
               if(p -> child[k] == NULL) return;
               p = p -> child[k];
               p -> cnt -= val;
          }
     }
     int getkth(int k){
          Node *p = root;
          int res = 0;
          foi(i, 31, 0){
               if(p -> child[0] && p -> child[0] -> cnt >= k) p = p -> child[0];
               else if(p -> child[1] && p -> child[1] -> cnt){
                    res += 1 << i;
                    if(p -> child[0]) k -= p-> child[0] -> cnt;
                    p = p -> child[1];
               }
               else return res;
          }
          return res;
     }
     int getsum(int num){
          if(num <= 0) return 0;
          int res = 0;
          Node *p = root;
          int i;
          foi(i, 31, 0){
               int k = getbit(num, i);
               if(k){
                    if(p -> child[0]) res += p -> child[0] -> cnt;
                    if(p -> child[1] && p -> child[1] -> cnt) p = p -> child[1];
                    else return res;
               }
               else if(k == 0 && p -> child[0] && p -> child[0] -> cnt ) p = p -> child[0];
               else return res;
          }
          return res + p -> cnt;
     }
} trie;
-----------------------
struct CentroidDecomposition {
     vi adj[N], clrlist;
     int subsize[N], h[N], dppart[N], pa[N], treesize;
     bool visited[N];
     void init(int n) {
          for(int i = 1 ; i <= n ; ++i) adj[i].clear();
     }
     void addEdge(int u, int v) {
          adj[u].emplace_back(v); adj[v].emplace_back(u);
     }
     void dfs(int u, int par){
          if(par == -1) clrlist.clear();
          subsize[u] = 1; clrlist.pb(u);
          for(auto v : adj[u]){
               if(visited[v] ||| v == par) continue;
               dfs(v, u);
               subsize[u] += subsize[v];
          }
          if(par == -1) treesize = subsize[u];
     }
     int centroid(int u, int par){
          for(auto v : adj[u]){
               if(visited[v] || v == par) continue;
               if(subsize[v] * 2 > treesize) return centroid(v, u);
          }
          return u;
     }
     int parts = 0;
     void fill(int u, int p, int cent){
          if(p == cent){
               dppart[u] = parts;
               parts++;
          }
          else if(p != -1) dppart[u] = dppart[p];
          for(auto v : adj[u]){
               if(v == p || visited[v]) continue;

               h[v] = h[u] + 1;
               fill(v, u, cent);

          }
     }
     ll solve(int cent){
          for(auto it : clrlist) h[it] = 0;
          parts = 0;
          fill(cent, -1, cent); parts--;
          dppart[cent] = -1;

          for(auto u : clrlist){
               if(u == cent) continue;

          }
          ll ans = 0;
          for(auto u : clrlist){
               int ht = h[u];
               int pt = dppart[u];
               if(u == cent){

               }
               else{

               }
          }
          return ans;
     }
     ll compsolve(int u = 1, int p = 0){
          dfs(u, -1);
          int cent = centroid(u, -1);
          ll ans = solve(cent);
          pa[cent] = p;
          visited[cent] = true;
          for(auto v : adj[cent]){
               if(!visited[v]) ans += compsolve(v, cent);
          }
          return ans;
     }
     void modify(int u) {
          for(int v = u ; v != 0 ; v = pa[v]);
     }
     ll query(int u) {
          ll mn = inf;
          for(int v = u ; v != 0 ; v = pa[v]);
          return mn;
     }
} cen;
---------------------------
struct Line{
    long long a, b;
    long long cal(long long x) const{return a*x + b;}
};
deque <Line> q;
double slope(Line x, Line y) {
     return (long double) (y.b - x.b) / (long double) (x.a - y.a);
}
bool comp(Line l1, Line l2, Line l3) {
     return slope(l1, l2) <= slope(l2, l3); // change <= to >= if you wanna get minimum
}
void add(Line L){
     while (q.size() >= 2 && !comp(q.end()[-2], q.end()[-1], L))
          q.pop_back();
     q.push_back(L);
}
long long query(long long x){
     while (q.size() >= 2 && q[0].cal(x) <= q[1].cal(x)) q.pop_front(); // change <= to >= if you wanna get minimum
     return q[0].cal(x);
}
-----------------------------
pair<vector<point>, vector<point>> convexHull(vector<point> p, int n) {
     // Sắp xếp các điểm theo tọa độ x, nếu bằng nhau sắp xếp theo y
     sort(p.begin(), p.end(), [](const point &A, const point &B) {
          if (A.fi != B.fi) return A.fi < B.fi;
          return A.se < B.se;
     });

     // Tập bao lồi
     vector<point> hull, unused;
     hull.push_back(p[0]);

     // Dựng bao trên
     for (int i = 1; i < n; ++i) {
          while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p[i])) {
               unused.eb(hull.back());
               hull.pop_back();
          }
          hull.push_back(p[i]);
     }

     // Tiếp tục dựng bao dưới
     for (int i = n - 2; i >= 0; --i) {
          while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p[i])) {
               unused.eb(hull.back());
               hull.pop_back();
          }
          hull.push_back(p[i]);
     }

     // Xoá đỉểm đầu được lặp lại ở cuối
     if (n > 1) hull.pop_back();

     return {hull, unused};
}
--------------------------------
ll dp[8008][808];
int P[8008][808];
long long cost(int i, int j) {
    if (i > j) return 0;
    return (f[j] - f[i - 1]) * (j - i + 1);
}
void solve(int id, int L, int R, int optL, int optR) {
    if (L > R) return;
    int mid = (L + R) / 2;
    dp[mid][id] = 0x3f3f3f3f3f3f3f3f;
    for (int i = optL; i <= optR; ++i) {
        long long new_cost = dp[i][id - 1] + cost(i + 1, mid);
        if (dp[mid][id] > new_cost) {
            dp[mid][id] = new_cost;
            P[mid][id] = i;
        }
    }
    solve(id, L, mid - 1, optL, P[mid][id]);
    solve(id, mid + 1, R, P[mid][id], optR);
}
----------------------------
struct dsu{
     int par[2 * N], sz[2 * N];
     void makeset(int u){
          par[u] = u;
          sz[u] = 1;
     }
     int findset(int u){
          return u == par[u] ? u : par[u] = findset(par[u]);
     }
     void joinset(int u, int v){
          u = findset(u);
          v = findset(v);
          if(u == v) return;
          if(sz[u] < sz[v]) swap(u, v);
          par[v] = u;
          sz[u] += sz[v];
     }
};
----------------------------
struct dsu{
     struct zata{
          int x, y, xSize, ySize;
     };
     stack<zata> st;
     int par[2 * N], sz[2 * N];
     void makeset(int u){
          par[u] = u;
          sz[u] = 1;
     }
     int findset(int u){
          return u == par[u] ? u : findset(par[u]);
     }
     void joinset(int u, int v){
          u = findset(u);
          v = findset(v);
          if(u == v) return;
          if(sz[u] < sz[v]) swap(u, v);
          st.push({u, v, sz[u], sz[v]});
          par[v] = u;
          sz[u] += sz[v];
     }
     void rollback(int SZ){
          while((int)st.size() > SZ){
               zata top = st.top();
               st.pop();
               par[top.x] = top.x;
               par[top.y] = top.y;
               sz[top.x] = top.xSize;
               sz[top.y] = top.ySize;
          }
     }

} dsu;
---------------------------
struct Fenwick {
     ll nodes[N];

     void reset() {
          memset(nodes, 0, sizeof nodes);
     }

     void update(int k, int val) {
          for(; k < N; k += k&-k) nodes[k] += val;
     }

     void rangeUpdate(int l, int r, int val) {
          update(l, val);
          update(r+1, -val);
     }

     ll getSum(int k) {
          ll ans = 0;
          for(; k > 0; k -= k&-k) ans += nodes[k];
          return ans;
     }
} FT;
----------------------------
struct fenwick {
    ll c[2 * N], d[2 * N];
    void update(int pos, ll val) {
        for(int i = pos; i <= n; i += i & -i) {
            c[i] += val;
            d[i] += (pos - 1) * val;
        }
    }
    void update(int l, int r, ll val) {
        update(l, val);
        update(r + 1, -val);
    }
    ll query(int a) {
        ll ans = 0;
        for(int i = a;i;i-=i&-i) {
            ans += a * c[i] - d[i];
        }
        return ans;
    }
    ll query(int a, int b) {
        return query(b) - query(a - 1);
    }
} bit;
------------------------
ll bit[2002][2002];
void update(int u, int v, ll x){
     for(int i = u; i <= n; i += i & -i){
          for(int j = v; j <= m; j += j & -j) bit[i][j] += x;
     }
}
ll query(int u, int v){
     ll sum = 0;
     for(int i = u; i > 0; i -= i & -i){
          for(int j = v; j > 0; j -= j & -j) sum += bit[i][j];
     }
     return sum;
}
ll query(int i, int j, int u, int v){
     return query(u, v) - query(u, j - 1) - query(i - 1, v) + query(i - 1, j - 1);
}
--------------------------
int BIT[4][N][M];
void add(int u, int v, int x){
    for(int i = u; i <= n; i += i&(-i)){
        for(int j = v; j <= m; j += j&(-j)){
            BIT[0][i][j] += x;
            BIT[1][i][j] += u * x;
            BIT[2][i][j] += v * x;
            BIT[3][i][j] += u * v * x;
        }
    }
}
void rectAdd(int a, int b, int u, int v, int x){
    add(a, b, x);
    add(a, v + 1, -x);
    add(u + 1, b, -x);
    add(u + 1, v + 1, x);
}
int query(int u, int v){
    int a[4] = {0, 0, 0, 0};
    for(int ty = 0; ty < 4; ty++){
        for(int i = u; i > 0; i -= i&(-i)){
            for(int j = v; j > 0; j -= j&(-j)){
                a[ty] += BIT[ty][i][j];
            }
        }
    }
    return a[0]*(u + 1)*(v + 1) - a[1]*(v + 1) - a[2]*(u + 1) + a[3];
}
-------------------------------
struct vecto{
     ll fi, se;
};
struct point{
     ll fi, se;
     vecto operator - (point a){
          return {fi - a.fi, se - a.se};
     }
};
ll cross(vecto a, vecto b){
     return a.fi * b.se - a.se * b.fi;
}
ll dot(vecto a, vecto b){
     return a.fi * b.fi + a.se * b.se;
}
long double len(vecto a){
     return (long double)sqrt(a.fi * a.fi + a.se * a.se);
}
long double angle(vecto a, vecto b){
     return acos(dot(a, b) / len(a) / len(b)) * 180 / pi;
}
bool check(point a, pair<point, point> bc){
     point b = bc.fi, c = bc.se;
     return angle(a - b, c - b) < 90 && angle(a - c, b - c) < 90;
}
ll area(point a, point b, point c){
     return abs(cross(b - a, c - a));
}
bool ccw(point a, point b, point c){
     return cross(b - a, c - a) > 0;
}
------------------------------
ll Pow[N], h[N], rh[N];
ll gethash(int l, int r){
     return (h[r] - h[l - 1] * Pow[r - l + 1] + mod * mod) % mod;
}
ll getrhash(int l, int r){
     return (rh[n - l + 1] - rh[n - r] * Pow[r - l + 1] + mod * mod) % mod;
}
bool check(int l, int r){
     return gethash(l, r) == getrhash(l, r);
}
void sol(){
     Pow[0] = 1;
     fo(i, 1, n){
          Pow[i] = (Pow[i - 1] * base) % mod;
          h[i] = (h[i - 1] * base + s[i] - 'a' + 1) % mod;
     }
     foi(i, n, 1){
          rh[n - i + 1] = (rh[n - i] * base + s[i] - 'a' + 1) % mod;
     }

}
-----------------------------
int sz[2 * N], par[2 * N];
void dfs(int u, int fa){
     sz[u] = 1;
     for(auto v : adj[u]){
          if(v == fa) continue;
          dfs(v, u);
          par[v] = u;
          sz[u] += sz[v];
     }
}
int curChain = 1, chainHead[2 * N], chainId[2 * N];
int curPos = 0, pos[2 * N], rep[2 * N];
void hld(int u, int fa){
     if(!chainHead[curChain]) chainHead[curChain] = u;
     chainId[u] = curChain;
     curPos++;
     pos[u] = curPos;
     rep[curPos] = u;
     int nxt = 0;
     for(auto v : adj[u]){
          if(v == fa) continue;
          if(nxt == 0 || sz[nxt] < sz[v]) nxt = v;
     }
     if(nxt) hld(nxt, u);
     for(auto v : adj[u]){
          if(v == fa || v == nxt) continue;
          curChain++;
          hld(v, u);
     }
}
int findlca(int u, int v){
     while(chainId[u] != chainId[v]){
          if(chainId[u] > chainId[v]){
               u = par[chainHead[chainId[u]]];
          }
          else{
               v = par[chainHead[chainId[v]]];
          }
     }
     if(pos[u] < pos[v]) return u;
     return v;
}
----------------------------------
struct fenwick {
    ll c[2 * N], d[2 * N];
    void update(int pos, ll val) {
        for(int i = pos; i <= n; i += i & -i) {
            c[i] += val;
            d[i] += (pos - 1) * val;
        }
    }
    void update(int l, int r, ll val) {
        update(l, val);
        update(r + 1, -val);
    }
    ll query(int a) {
        ll ans = 0;
        for(int i = a;i;i-=i&-i) {
            ans += a * c[i] - d[i];
        }
        return ans;
    }
    ll query(int a, int b) {
        return query(b) - query(a - 1);
    }
} bit;
struct HLD {
     fenwick fen;
     int hson[2 * N], tin[2 * N], rep[2 * N], dep[2 * N], siz[2 * N], fa[2 * N], top[2 * N], tot, tout[2 * N];
     void dfs1(int u = 1, int f = 0) {
          dep[u] = dep[f] + 1;
          fa[u] = f;
          siz[u] = 1;
          for(int v : adj[u]) {
               if(v == f) continue;
               dfs1(v, u);
               siz[u] += siz[v];
               if(siz[v] >= siz[hson[u]]) hson[u] = v;
          }
     }
     void dfs2(int u = 1, int f = 0, int tp = 1) {
          tin[u] = ++tot;
          rep[tot] = u;
          top[u] = tp;
          if(hson[u] == 0){
               tout[u] = tot;
               return;
          }
          dfs2(hson[u], u, tp);
          for(int v : adj[u]) {
               if(v == f ||| v == hson[u]) continue;
               dfs2(v, u, v);
          }
          tout[u] = tot;
     }
     void update(int u, int v, ll val) {
          while(top[u] != top[v]) {
               if(dep[top[u]] < dep[top[v]]) swap(u, v);
               fen.update(tin[top[u]], tin[u], val);
               u = fa[top[u]];
          }
          fen.update(min(tin[u], tin[v]), max(tin[u], tin[v]), val);
     }
     ll query(int u, int v) {
          ll ans = 0;
          while(top[u] != top[v]) {
               if(dep[top[u]] < dep[top[v]]) swap(u, v);
               ans += fen.query(tin[top[u]], tin[u]);
               u = fa[top[u]];
          }
          ans += fen.query(min(tin[u], tin[v]), max(tin[u], tin[v]));
          return ans;
     }
     void update(int u, ll val){
          fen.update(tin[u], tout[u], val);
     }
     ll query(int u){
          return fen.query(tin[u], tout[u]);
     }
} hld;
----------------------------
unordered_map<ll, ll> m; // if multiply queries, no need to recompute inverse :)
ll Pow(ll a, ll b, ll m){
     if(b == 0) return 1;
     ll tmp = Pow(a, b / 2, m);
     tmp = (tmp * tmp) % m;
     if(b % 2) tmp = (tmp * a) % m;
     return tmp;
}
ll rv(ll x) {
     if (m.count(x)) return m[x];
     return m[x] = Pow(x, mod - 2, mod);
}

ll interpolate(ll x, ll k, bool bf = false) {
     if(x == 0) return 0;
     if (k == 0) return x;
     // find 1^k + 2^k + ... + x^k
     // (k+1) degree polynomial -> (k+2) points
     if (x <= k + 1 | bf) {
          ll s = 0;
          for (ll i = 1; i <= x; i ++) {
               s = (s + Pow(i, k, mod)) % mod;
          }
          return s;
     }
     vector<ll> pre(k + 2), suf(k + 2), inv(k + 2);
     inv[0] = 1;
     pre[0] = x;
     suf[k + 1] = x - (k + 1);
     for (ll i = 1; i <= k; i ++) pre[i] = pre[i - 1] * (x - i) % mod; //numerator prefix product
     for (ll i = k; i >= 1; i --) suf[i] = suf[i + 1] * (x - i) % mod; //numerator suffix product
     for (ll i = 1; i <= k + 1; i ++) inv[i] = inv[i - 1] * rv(i) % mod; // denominator factorial
     ll ans = 0;
     ll yi = 0; // 0^k +~ i^k
     ll num, denom;
     for (ll i = 0; i <= k + 1; i ++) {
          yi = (yi + Pow(i, k, mod)) % mod; // interpolate point: (i, yi)

          if (i == 0) num = suf[1];
          else if (i == k + 1) num = pre[k];
          else num = pre[i - 1] * suf[i + 1] % mod; // numerator

          denom = inv[i] * inv[k + 1 - i] % mod; // denominator

          if ((i + k) & 1) ans += (1LL * yi * num % mod) * denom % mod; // (-1)^(i-deg) however deg is k+1 here so :)
          else ans -= (1LL * yi * num % mod) * denom % mod;

          ans = (ans % mod + mod) % mod;
     }
     return ans;
}
-------------------------------
void dfs(int u, int fa){
     sz[u] = 1;
     for(auto v : adj[u]){
          if(v == fa) continue;
          h[v] = h[u] + 1;
          dfs(v, u);
          sz[u] += sz[v];
          up[v][0] = u;
     }
}
int goup(int u, int dis){
     for(int i = 0; (1 << i) <= dis; i++){
          if(getbit(dis, i)) u = up[u][i];
     }
     return u;
}
int findlca(int u, int v){
     if(h[u] < h[v]) swap(u, v);
     u = goup(u, h[u] - h[v]);
     if(u == v) return u;
     foi(i, __lg(h[u]), 0){
          if(up[u][i] != up[v][i]){
               u = up[u][i];
               v = up[v][i];
          }
     }
     return up[u][0];
}
------------------------------
struct Line {
     mutable ll k, m, p;
     bool operator<(const Line& o) const { return k < o.k; }
     bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
     // (for doubles, use inf = 1/.0, div(a,b) = a/b)
     static const ll inf = LLONG_MAX;
     ll div(ll a, ll b) { // floored division
          return a / b - ((a ^ b) < 0 && a % b); }
     bool isect(iterator x, iterator y) {
          if (y == end()) return x->p = inf, 0;
          if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
          else x->p = div(y->m - x->m, x->k - y->k);
          return x->p >= y->p;
     }
     void add(ll k, ll m) {
          auto z = insert({k, m, 0}), y = z++, x = y;
          while (isect(y, z)) z = erase(z);
          if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
          while ((y = x) != begin() && (--x)->p >= y->p)
               isect(x, erase(y));
     }
     ll query(ll x) {
          assert(!empty());
          auto l = *lower_bound(x);
          return l.k * x + l.m;
     }
};
----------------------------
int dd[N], ghepx[N], ghepy[N];
bool dfs(int u, int root){
     if(dd[u] == root) return 0;
     dd[u] = root;
     for(auto v : adj[u]){
          if(ghepx[v] == 0 ||| dfs(ghepx[v], root)){
               ghepy[u] = v;
               ghepx[v] = u;
               return 1;
          }
     }
     return 0;
}
----------------------
struct matrix{
     ll val[101][101] = {};
     inline void Init()
     {
          for (int i = 0; i < M; i ++)
               val[i][i] = 1;
     }
     matrix operator * (const matrix &b) const
     {
          matrix c;
          for (int k = 0; k < M; k ++)
               for (int i = 0; i < M; i ++)
                    for (int j = 0; j < M; j ++)
                         c.val[i][j] = (1LL * val[i][k] * b.val[k][j] + c.val[i][j]) % mod;
          return c;
     }
     matrix operator ^ (int y) const
     {
          matrix r, x = *this;
          for (r.Init(); y; y >>= 1, x = x * x)
               if (y & 1)
                    r = r * x;
          return r;
     }
};
-----------------------
struct Edge {
     int a, b, cap, flow;
};

struct MaxFlow {
     int n, s, t;
     vector<int> d, ptr, q;
     vector< Edge > e;
     vector< vector<int> > g;

     MaxFlow(int _n) : n(_n), d(_n), ptr(_n), q(_n), g(_n) {
          e.clear();
          for (int i = 0; i < n; i++) {
               g[i].clear();
               ptr[i] = 0;
          }
     }

     void addEdge(int a, int b, int cap) {
          Edge e1 = { a, b, cap, 0 };
          Edge e2 = { b, a, 0, 0 };
          g[a].push_back( (int) e.size() );
          e.push_back(e1);
          g[b].push_back( (int) e.size() );
          e.push_back(e2);
     }
     int getMaxFlow(int _s, int _t) {
          s = _s; t = _t;
          int flow = 0;
          for (;;) {
               if (!bfs()) break;
               std::fill(ptr.begin(), ptr.end(), 0);
               while (int pushed = dfs(s, INF))
                    flow += pushed;
          }
          return flow;
     }

private:
     bool bfs() {
          int qh = 0, qt = 0;
          q[qt++] = s;
          std::fill(d.begin(), d.end(), -1);
          d[s] = 0;

          while (qh < qt && d[t] == -1) {
               int v = q[qh++];
               for (int i = 0; i < (int) g[v].size(); i++) {
                    int id = g[v][i], to = e[id].b;
                    if (d[to] == -1 && e[id].flow < e[id].cap) {
                         q[qt++] = to;
                         d[to] = d[v] + 1;
                    }
               }
          }
          return d[t] != -1;
     }

     int dfs (int v, int flow) {
          if (!flow) return 0;
          if (v == t) return flow;
          for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
               int id = g[v][ptr[v]],
                    to = e[id].b;
               if (d[to] != d[v] + 1) continue;
               int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
               if (pushed) {
                    e[id].flow += pushed;
                    e[id^1].flow -= pushed;
                    return pushed;
               }
          }
          return 0;
     }
};
-----------------------------
vector<int> path;
struct edge{
    int x, y, cap, flow;
    ll cost;
};
struct MaxFlowMinCost{
     int n, S, T;
     vector<vector<int>> a;
     vector<int> done, prev;
     vector<ll> dist, pot;
     vector<edge> e;
     MaxFlowMinCost() {}
     MaxFlowMinCost(int _n, int _S, int _T){
          n = _n; S = _S; T = _T;
          a = vector < vector <int> >(n + 1);
          dist = vector <ll>(n + 1);
          prev = vector <int>(n + 1);
          done = vector <int>(n + 1);
          pot = vector <ll>(n + 1, 0);
     }
     void addEdge(int x, int y, int _cap, ll _cost){
          edge e1 = {x, y, _cap, 0, _cost};
          edge e2 = {y, x, 0, 0, -_cost};
          a[x].push_back(e.size()); e.push_back(e1);
          a[y].push_back(e.size()); e.push_back(e2);
     }
     pil dijkstra(){
          int flow = 0;
          ll cost = 0;
          for (int i = 1; i <= n; i++) done[i] = 0, dist[i] = 0x3f3f3f3f3f3f3f3f;
          priority_queue < pli > q;
          dist[S] = 0; prev[S] = -1;
          q.push(make_pair(0, S));
          while (!q.empty()){
               int x = q.top().second; q.pop();
               if (done[x]) continue;
               done[x] = 1;
               for (int i = 0; i < int(a[x].size()); i++){
                    int id = a[x][i], y = e[id].y;
                    if (e[id].flow < e[id].cap){
                         ll D = dist[x] + e[id].cost + pot[x] - pot[y];
                         if (!done[y] && D < dist[y]){
                              dist[y] = D; prev[y] = id;
                              q.push(make_pair(-dist[y], y));
                         }
                    }
               }
          }
          for(int i = 1; i <= n; i++) pot[i] += dist[i];
          if(done[T]){
               flow = 0x3f3f3f3f3f3f3f3f;
               for (int id = prev[T]; id >= 0; id = prev[e[id].x])
                    flow = min(flow, e[id].cap - e[id].flow);
               for (int id = prev[T]; id >= 0; id = prev[e[id].x]) {
                    cost += e[id].cost * flow;
                    e[id].flow += flow;
                    e[id ^ 1].flow -= flow;
               }
          }
          return make_pair(flow, cost);
     }
     pil minCostMaxFlow(int k){
          int totalFlow = 0;
          ll totalCost = 0;
          while(k--){
               pil u = dijkstra();
               if (!done[T]) break;
               totalFlow += u.first; totalCost += u.second;
          }
          return make_pair(totalFlow, totalCost);
     }
     void trace(int x){
          if(x == T){
               // print the path

               return;
          }
          path.push_back(x);
          for (int i = 0; i < int(a[x].size()); i++)
          {
               int id = a[x][i];
               if (e[id].flow > 0)
               {
                    if (e[id].y < T) e[id].flow = 0;
                    trace(e[id].y);
                    return;
               }
          }
     }
};
-----------------------------
template <typename T1, typename T2> bool minimize(T1 &a, T2 b){ if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b){ if (a < b) { a = b; return true; } return false; }
------------------------------
priority_queue<int, vector<int>, greater<int>> Big, OweBig;
priority_queue<int> Small, OweSmall;
int sizBig, sizSmall;
void Paid(){
    while(!OweBig.empty() && OweBig.top() == Big.top()){
        OweBig.pop();
        Big.pop();
    }
    while(!OweSmall.empty() && OweSmall.top() == Small.top()){
        OweSmall.pop();
        Small.pop();
    }
}
void Balance(){
    // cân bằng Small và Big
    if(sizSmall > sizBig + 1){
        Big.push(Small.top()); sizBig++;
        Small.pop(); sizSmall--;
    }
    else if(sizSmall < sizBig){
        Small.push(Big.top()); sizSmall++;
        Big.pop(); sizBig--;
    }
    Paid();
}
void add(int x){
    if(Small.empty()){ // Small rỗng
        Small.push(x); sizSmall++;
    }
    else{
        int median = Small.top(); // trung vị hiện tại là phần tử lớn nhất của small
        if(x > median){
            Big.push(x); sizBig++;
        }
        else{
            Small.push(x); sizSmall++;
        }
    }
    Balance();
}
void rev(int x){
    if(x == Small.top()){ // nếu x là trung vị
        Small.pop(); sizSmall--;
    }
    else if(x < Small.top()){ // ghi nợ của Small
        OweSmall.push(x);
        sizSmall--;
    }
    else if(x == Big.top()){ // nếu x là phần tử sau trung vị
        Big.pop();
        sizBig--;
    }
    else if(x > Big.top()){ // ghi nợ của Big
        OweBig.push(x);
        sizBig--;
    }
    Paid();
    Balance();
}
--------------------------
struct Node {
     ll val;
     Node *l, *r;

     Node(ll x) : val(x), l(nullptr), r(nullptr) {}
     Node(Node *ll, Node *rr) {
          l = ll, r = rr;
          val = 0;
          if (l) val += l->val;
          if (r) val += r->val;
     }
     Node(Node *cp) : val(cp->val), l(cp->l), r(cp->r) {}
};

int n, cnt = 1;
ll a[200001];
Node *roots[200001];

Node *build(int l = 1, int r = n) {
     if (l == r) return new Node(a[l]);
     int mid = (l + r) / 2;
     return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(Node *node, int val, int pos, int l = 1, int r = n) {
     if (l == r) return new Node(val);
     int mid = (l + r) / 2;
     if (pos > mid)
          return new Node(node->l, update(node->r, val, pos, mid + 1, r));
     else return new Node(update(node->l, val, pos, l, mid), node->r);
}

ll query(Node *node, int a, int b, int l = 1, int r = n) {
     if (l > b || r < a) return 0;
     if (l >= a && r <= b) return node->val;
     int mid = (l + r) / 2;
     return query(node->l, a, b, l, mid) + query(node->r, a, b, mid + 1, r);
}
---------------------------------
ll phi(ll n){
     ll res = n;
     for(int i = 2; 1LL * i * i <= n; i++){
          if(n % i == 0){
               while(n % i == 0) n /= i;
               res -= res / i;
          }
     }
     if(n != 1) res -= res / n;
     return res;
}
-------------------------------
ll Pow(ll a, ll b, ll m){
     if(b == 0) return 1;
     ll tmp = Pow(a, b / 2, m);
     tmp = (tmp * tmp) % m;
     if(b % 2) tmp = (tmp * a) % m;
     return tmp;
}
-----------------------------
int dp[2 * N];
void calculateDP(int u, int fa){
     dp[u] = a[u];
     for(auto v : adj[u]){
          if(v == fa) continue;
          calculateDP(v, u);
          dp[u] += max(0, dp[v]);
     }
}
void move(int u, int v){
     dp[u] -= max(0, dp[v]);
     dp[v] += max(0, dp[u]);
}
void dfs(int u, int fa){
     int fixDPnow = dp[u], fixDPv;
     for(auto v : adj[u]){
          if(v == fa) continue;
          fixDPv = dp[v];
          move(u, v); //it will move the root from nw to v and updates dp
          dfs(v, u);
          //following two lines will move the root to nw and update dp
          dp[v] = fixDPv;
          dp[u] = fixDPnow;
     }
}
void sol(){
     int root = 1;
     calculateDP(root, root); //it will calculate the DP when the root is root
     dfs(root, root); //this will move the root to all the vertices
}
-----------------------------
// f(i, j) = (i + j, m - 1 - i + j)
-----------------------------
|struct Node{#include<bits/stdc++.h>
using namespace std;

const int N = 505, LG = 10;

int st[N][N][LG][LG];
int a[N][N], lg2[N];

int yo(int x1, int y1, int x2, int y2) {
  x2++;
  y2++;
  int a = lg2[x2 - x1], b = lg2[y2 - y1];
  return max(
         max(st[x1][y1][a][b], st[x2 - (1 << a)][y1][a][b]),
         max(st[x1][y2 - (1 << b)][a][b], st[x2 - (1 << a)][y2 - (1 << b)][a][b])
       );
}

void build(int n, int m) { // 0 indexed
  for (int i = 2; i < N; i++) lg2[i] = lg2[i >> 1] + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      st[i][j][0][0] = a[i][j];
    }
  }
  for (int a = 0; a < LG; a++) {
    for (int b = 0; b < LG; b++) {
      if (a + b == 0) continue;
      for (int i = 0; i + (1 << a) <= n; i++) {
        for (int j = 0; j + (1 << b) <= m; j++) {
          if (!a) {
            st[i][j][a][b] = max(st[i][j][a][b - 1], st[i][j + (1 << (b - 1))][a][b - 1]);
          } else {
            st[i][j][a][b] = max(st[i][j][a - 1][b], st[i + (1 << (a - 1))][j][a - 1][b]);
          }
        }
      }
    }
  }
}

string s[N];
int l[N][N], u[N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!j) l[i][j] = 1;
      else l[i][j] = 1 + (s[i][j - 1] <= s[i][j] ? l[i][j - 1] : 0);
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (!i) u[i][j] = 1;
      else u[i][j] = 1 + (s[i - 1][j] <= s[i][j] ? u[i - 1][j] : 0);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int nw = 1, mnx = u[i][j], mny = l[i][j];
      for (int len = 1; len <= min(i, j); len++) {
        mnx = min(mnx, u[i][j - len]);
        mny = min(mny, l[i - len][j]);
        if (min(mnx, mny) >= len + 1) nw++;
        else break;
      }
      a[i][j] = nw;
    }
  }
  build(n, m);
  int q;
  cin >> q;
     while (q--) {
          int x1, y1, x2, y2;
          cin >> x1 >> y1 >> x2 >> y2;
          x1--, y1--;
          x2--;
          y2--;
          int l = 1, r = min(x2 - x1 + 1, y2 - y1 + 1), ans = 0;
          while (l <= r) {
               int mid = l + r >> 1;
               if (yo(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid) ans = mid, l = mid + 1;
               else r = mid - 1;
          }
     cout << ans << '\n';
     }
     return 0;
}
-----------------------
struct Trie{
     struct Node{
          Node* child[26];
          int exist, cnt, hei;
          Node(){
               fo(i, 0, 25) child[i] = NULL;
               exist = cnt = hei = 0;
          }
     };
     int cur;
     Node* root;
     Trie() : cur(0){
          root = new Node();
     };
     void add(string s, ll &ans){
          Node* p = root;
          for(auto f : s){
               int c = f - 'A';
               if(p->child[c] == NULL) p->child[c] = new Node();
               p->child[c]->hei = p->hei + 1;
               p = p->child[c];
               p->cnt++;
               ans = max(ans, 1LL * p->cnt * p->hei);
          }
          p->exist++;
     }
     void del(string s){
          Node* p = root;
          for(auto f : s){
               int c = f - 'A';
               p = p->child[c];
               p->cnt--;
          }
          p->exist--;
     }
} trie;
------------------------------
struct CentroidDecomposition {
     vii adj[N];
     vi clrlist;
     int subsize[N], h[N], dppart[N], pa[N], treesize;
     bool visited[N];
     void init(int n) {
          for(int i = 1 ; i <= n ; ++i) adj[i].clear();
     }
     void addEdge(int u, int v, int w) {
          adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
     }
     void dfs(int u, int par){
          if(par == -1) clrlist.clear();
          subsize[u] = 1; clrlist.pb(u);
          for(auto it : adj[u]){
               int v = it.fi, w = it.se;
               if(visited[v] || v == par) continue;
               dfs(v, u);
               subsize[u] += subsize[v];
          }
          if(par == -1) treesize = subsize[u];
     }
     int centroid(int u, int par){
          for(auto it : adj[u]){
               int v = it.fi, w = it.se;
               if(visited[v] || v == par) continue;
               if(subsize[v] * 2 > treesize) return centroid(v, u);
          }
          return u;
     }
     int parts = 0;
     void fill(int u, int p, int cent){
          if(p == cent){
               dppart[u] = parts;
               parts++;
          }
          else if(p != -1) dppart[u] = dppart[p];
          for(auto it : adj[u]){
               int v = it.fi, w = it.se;
               if(v == p || visited[v]) continue;

               h[v] = h[u] + 1;
               fill(v, u, cent);

          }
     }
     ll solve(int cent){
          for(auto it : clrlist) h[it] = 0;
          parts = 0;
          fill(cent, -1, cent); parts--;
          dppart[cent] = -1;

          for(auto u : clrlist){
               if(u == cent) continue;

          }
          ll ans = 0;
          for(auto u : clrlist){
               int ht = h[u];
               int pt = dppart[u];
               if(u == cent){

               }
               else{

               }
          }
          return ans;
     }
     ll compsolve(int u = 1, int p = 0){
          dfs(u, -1);
          int cent = centroid(u, -1);
          ll ans = solve(cent);
          pa[cent] = p;
          visited[cent] = true;
          for(auto it : adj[cent]){
               int v = it.fi, w = it.se;
               if(!visited[v]) ans += compsolve(v, cent);
          }
          return ans;
     }
     void modify(int u) {
          for(int v = u ; v != 0 ; v = pa[v]);
     }
     ll query(int u) {
          ll mn = inf;
          for(int v = u ; v != 0 ; v = pa[v]);
          return mn;
     }
} cen;
----------------------------
vector<int> z_algo(const string &s) {
    int n(s.size());
    vector<int> z(n);

    int l(0), r(0);
    for (int i=1; i<n; i++) {
        if (i > r) {
            l = r = i;
            while (r<n && s[r-l]==s[r]) r += 1;
            z[i] = r - l;
            r -= 1;
        } else if (z[i-l] < r-i+1) {
            z[i] = z[i-l];
        } else {
            l = i;
            while (r<n && s[r-l]==s[r]) r += 1;
            z[i] = r - l;
            r -= 1;
        }
    }

    return z;
}
--------------------------

          int fi;
          Node operator + (const Node &other) const{
               Node res;
               res.fi = fi + other.fi;
               return res;
          }
     };
     int a[N];
     struct SegmentTree{
          Node st[4 * N];
          void build(int id, int l, int r){
               if(l == r){
                    st[id] = {a[l]};
                    return;
               }
               int m = l + r >> 1;
               build(id << 1, l, m);
               build(id << 1 | 1, m + 1, r);
               st[id] = st[id << 1] + st[id << 1 | 1];
          }
          void update(int id, int l, int r, int u, int val){
               if(l > u || r < u) return;
               if(l == r){
                    st[id].fi += val;
                    return;
               }
               int m = l + r >> 1;
               update(id << 1, l, m, u, val);
               update(id << 1 | 1, m + 1, r, u, val);
               st[id] = st[id << 1] + st[id << 1 | 1];
          }
          Node get(int id, int l, int r, int u, int v){
               if(l > v || r < u) return {0};
               if(u <= l && r <= v) return st[id];
               int m = l + r >> 1;
               return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
          }
     };
--------------------------------
