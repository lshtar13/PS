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

cll N = 1000, W = 10000, INF = 1e7;
ll n, w, stations[N][2] = {{}};
double m;
vector<vector<double>> mat(N, vector<double>(N, INF));
vector<double> dist(N, INF);

double _dist(ll i, ll l)
{
    double a = abs(stations[i][0] - stations[l][0]), b = abs(stations[i][1] - stations[l][1]);
    return sqrt(pow(a, 2) + pow(b, 2));
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> w >> m;
    for (ll i = 0; i < n; ++i)
    {
        cin >> stations[i][0] >> stations[i][1];
        mat[i][i] = 0;
    }

    for (ll a, b, i = 0; i < w; ++i)
    {
        cin >> a >> b;
        --a, --b;
        mat[a][b] = mat[b][a] = 0;
    }

    for (ll i = 0; i < n; ++i)
    {
        for (ll l = i + 1; l < n; ++l)
        {
            double d;
            if (mat[i][l] && mat[l][i] && (d = _dist(i, l)) <= m)
            {
                mat[i][l] = mat[l][i] = d;
            }
        }
    }

    typedef pair<ll, double> plld;
    priority_queue<plld, vector<plld>, greater<plld>> pq;
    dist[0] = 0;
    pq.push(make_pair(0, 0));
    while (!pq.empty())
    {
        ll node = pq.top().first;
        double distance = pq.top().second;
        pq.pop();
        if (dist[node] != distance)
        {
            continue;
        }

        for (ll i = 0; i < n; ++i)
        {
            if (i == node)
            {
                continue;
            }
            double _distance = distance + mat[node][i];
            if (_distance < dist[i])
            {
                dist[i] = _distance;
                pq.push(make_pair(i, _distance));
            }
        }
    }

    ll result = dist[n - 1] * 1000;
    cout << result << "\n";

    return 0;
}