#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef queue<ll> qll;
typedef queue<pll> qpll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;
typedef vector<ll> vll;
typedef pair<pll, ll> ppll;

cll MAX_M = 5 * 1e5;
ll n, m, isVisted[MAX_M] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<ppll> v(m);
    for (ll i = 0; i < m; ++i)
    {
        cin >> v[i].first.first >> v[i].first.second;
        if (v[i].first.second < v[i].first.first)
        {
            v[i].first.second += n;
        }
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end(), [](const ppll &a, const ppll &b)
         {
             if (a.first.first == b.first.first)
             {
                 return a.first.second > b.first.second; // first.first가 같으면 first.second가 클수록
             }
             return a.first.first < b.first.first; // first.first가 작을수록
         });
    deque<ppll> d(v.begin(), v.end());
    queue<ppll, deque<ppll>> q(d);

    while (!q.empty())
    {
        static ll prev = 0;
        ll st = q.front().first.first, en = q.front().first.second,
           idx = q.front().second;
        if (st >= 2 * n)
        {
            break;
        }
        q.pop();
        if (en > prev)
        {
            prev = en;
            q.push(make_pair(make_pair(st + n, en + n), idx));
        }
    }

    vll result;
    while (!q.empty())
    {
        result.push_back(q.front().second);
        q.pop();
    }
    sort(result.begin(), result.end());
    for (auto &r : result)
    {
        cout << r << " ";
    }

    return 0;
}