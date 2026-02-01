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
#include <map>
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

string solve(ll n, ll k, string s)
{
    ll newLen = n - k;
    if (k == n - 1)
        return "YES";
    map<char, ll> freq;
    vb evO(26);
    bool total = false;
    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
        evO[s[i] - 97] = true ? freq[s[i]] % 2 == 0 : false;
    }
    if (newLen % 2 == 0)
    {
        for (auto i : freq)
        {
            if (i.second % 2 == 1 && k > 0)
            {
                k--;
                i.second--;
            }
            else if (i.second % 2 == 1 && k <= 0)
                return "NO";
        }
        if (k % 2 == 0)
            return "YES";
        else
            return "NO";
    }
    bool flag = false;
    for (auto i : freq)
    {
        if (i.second % 2 == 1 && !flag)
        {
            flag = true;
        }
        else if (i.second % 2 == 1 && flag)
        {
            if (k > 0)
            {
                k--;
                i.second--;
            }
            else
                return "NO";
        }
    }
    if (!flag && k % 2 == 1)
        return "YES";
    else if (!flag && k % 2 == 0)
        return "NO";
    if (k % 2 == 0)
        return "YES";
    return "NO";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        string s;
        cin >> n >> k >> s;
        cout << solve(n, k, s);
        cout << "\n";
    }
}
