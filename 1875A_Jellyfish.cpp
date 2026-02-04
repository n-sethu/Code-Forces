#include <algorithm>
#include <iostream>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <iomanip>
// #include <cmath>
// #include <functional>
#include <queue>
// #include <stack>
// #include <string>
// #include <sstream>
// #include <map>
// #include <numeric>
// #include <set>
// #include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vs = vector<string>;
#define G(x) \
    ll x;    \
    cin >> x;
#define F(i, l, r) for (ll i = l; i < (r); ++i)
#define A(x) (x).begin(), (x).end()
#define N 100010

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vb> vis(1000, vb(1000));

ll solve(ll a, ll b, ll n)
{
  vl v(n);
  ll count=b;
    for (auto &x : v){
      cin >> x;
      if (x < a)
        count += x;
      else
        count+=a-1;
    }
    return count;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        cout << solve(a, b, n) << '\n';
    }
}