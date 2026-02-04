#include <algorithm>
#include <iostream>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <iomanip>
#include <cmath>
// #include <functional>
#include <queue>
// #include <stack>
// #include <string>
// #include <sstream>
// #include <map>
// #include <numeric>
#include <set>
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

ll solve(string &s)
{
    ll coins = 0;
    ll n = s.length();
    ll one = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            one++;
        else
            zero++;
    }
    if (one == n || zero == n)
        return n;
    if (zero == one)
        return 0;
    string acc = "";
    ll j=0;
    for (int i = 0; i < n; i++)
    {
        if (j<n&&s[j] == '1' && zero > 0)
        {
            acc += '0';
            zero--;
            j++;
        } else if (j<n&&s[j] == '1' && zero == 0) {

          coins++;
          }
        else if (j<n&&s[j] == '0' && one > 0)
        {
            acc += '1';
            one--;
            j++;
        }
        else if(j<n&&s[j]=='0' && one==0){
          coins++;
          }
        // cout<<acc<<'\n';
    }

    return coins;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
}