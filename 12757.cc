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
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
#define FOR1(a, A) for (ll a = 0; a < A; ++a)
#define FOR2(a, b, A, B)       \
    for (ll a = 0; a < A; ++a) \
        for (ll b = 0; b < B; ++b)

cll N = 1e5, M = 1e5, K = 1e5;
ll n, m, limit;
vpll db;

pll &find(ll k)
{
    ll st = 0, en = db.size() - 1, mid, _k, _st = st, _en = en;
    while (st <= en)
    {
        mid = (st + en) / 2;
        if (db[mid].first < k)
        {
            st = mid + 1, _st = mid;
        }
        else
        {
            en = mid - 1, _en = mid;
        }
    }
    // cout << _st << " " << _en << "\n";
    if (db[_st].first > k || db[_en].first < k)
    {
        return db[0];
    }
    else if (k - db[_st].first > limit && db[_en].first - k > limit)
    {
        return db[0];
    }

    if (k - db[_st].first < db[_en].first - k)
    {
        return db[_st];
    }
    else if (k - db[_st].first > db[_en].first - k)
    {
        return db[_en];
    }
    else
    {
        return db[0];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    db.emplace_back(make_pair(-1, -1));
    db.emplace_back(make_pair(1e9 + 1, -1));

    cin >> n >> m >> limit;
    for (ll k, v, i = 0; i < n; ++i)
    {
        cin >> k >> v;
        db.emplace_back(make_pair(k, v));
    }
    sort(db.begin(), db.end());

    for (ll cmd, k, v, left, right, i = 0; i < m; ++i)
    {
        cin >> cmd >> k;
        if (cmd == 1)
        {
            cin >> v;
            db.emplace_back(make_pair(k, v));
            sort(db.begin(), db.end());
            // cout << "---------\n";
            // for (auto &p : db)
            // {
            //     cout << p.first << " " << p.second << "\n";
            // }
            // cout << "---------\n";
        }
        if (cmd == 2)
        {
            cin >> v;
            auto &p = find(k);
            if (p.first != -1)
            {
                p.second = v;
            }
        }
        if (cmd == 3)
        {
            auto &p = find(k);
            if (p.first != -1)
            {
                cout << p.second << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}