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

cll N = 50, M = 50, MAX = 3000, G = 1, directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, INF = 1e9;
ll n, m, s0, s1, f0, f1, mat[N][M] = {{}}, near[N][M] = {{}};
pll minDist[N][M];

bool isValidCord(ll i, ll l)
{
    return i >= 0 && i < n && l >= 0 && l < m;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 0; i < n; ++i)
    {
        cin.ignore();
        for (ll l = 0; l < m; ++l)
        {
            char c;
            cin >> c;
            if (c == 'g')
            {
                mat[i][l] = G;
            }
            else if (c == 'F')
            {
                f0 = i, f1 = l;
            }
            else if (c == 'S')
            {
                s0 = i, s1 = l;
            }
            minDist[i][l] = {INF, INF};
        }
    }

    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < m; ++l)
        {
            for (auto &d : directions)
            {
                ll _i = i + d[0], _l = l + d[1];
                if (isValidCord(_i, _l) && !mat[_i][_l])
                {
                    near[_i][_l] |= mat[i][l];
                }
            }
        }
    }
    near[f0][f1] = near[s0][s1] = 0;

    priority_queue<pair<pll, pll>, vector<pair<pll, pll>>, greater<pair<pll, pll>>> pq;
    minDist[s0][s1] = {0, 0};
    pq.push(make_pair(make_pair(0, 0), make_pair(s0, s1)));
    while (!pq.empty())
    {
        pll w = pq.top().first;
        ll i = pq.top().second.first, l = pq.top().second.second;

        pq.pop();
        if (w > minDist[i][l])
        {
            continue;
        }

        w.first += mat[i][l], w.second += near[i][l];
        for (auto &d : directions)
        {
            ll _i = i + d[0], _l = l + d[1];
            if (isValidCord(_i, _l) && w < minDist[_i][_l])
            {
                minDist[_i][_l] = w;
                pq.push(make_pair(w, make_pair(_i, _l)));
            }
        }
    }

    cout << minDist[f0][f1].first << " " << minDist[f0][f1].second << "\n";

    return 0;
}