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
