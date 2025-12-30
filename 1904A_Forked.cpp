#include <algorithm>
#include <iostream>
#include <iterator>
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
#include <set>
#include <unordered_set>
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
// #define G(x) \
//     ll x;    \
//     cin >> x;
// #define F(i, l, r) for (ll i = l; i < (r); ++i)
// #define A(x) (x).begin(), (x).end()
// #define N 100010

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
vector<vb> vis(1000, vb(1000));

bool canAttack(ll a, ll b, ll x, ll y, ll qx, ll qy) {
  ll m1 = abs(x - qx), m2 = abs(y - qy);
  return (m1==a && m2==b) || (m1==b && m2 == a);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    int dx[4] = {1, -1, -1, 1};
    int dy[4] = {-1, -1, 1, 1};

    while (t--)
    {
        pair<ll, ll> move, k, q;
        cin >> move.first >> move.second >> k.first >> k.second >> q.first >> q.second;

        set<pair<ll, ll>> king, queen;

        for (int i = 0; i < 4; i++)
        {
            king.insert({k.first + dx[i] * move.first,
                         k.second + dy[i] * move.second});
            king.insert({k.first + dx[i] * move.second,
                         k.second + dy[i] * move.first});
        }

        for (int i = 0; i < 4; i++)
        {
            queen.insert({q.first + dx[i] * move.first,
                          q.second + dy[i] * move.second});
            queen.insert({q.first + dx[i] * move.second,
                          q.second + dy[i] * move.first});
        }

        ll count = 0;
        for (const auto &s : king)
        {
            if (queen.contains(s))
            {
                count++;
            }
        }

        cout << count << "\n";
    }
}