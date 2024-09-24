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
ll n, w, stations[N][2] = {{}}, parents[N] = {};
double m;
vector<vll> childs(N);
vector<vector<double>> mat(N, vector<double>(N, -INF));

ll _parent(ll a)
{
    if (parents[a] == a)
    {
        return a;
    }
    return parents[a] = _parent(parents[a]);
}

void merge(ll a, ll b)
{
    childs[a].insert(childs[a].end(), childs[parents[b]].begin(), childs[parents[b]].end());
    parents[b] = _parent(a);
}

double _dist(ll i, ll l)
{
    double a = abs(mat[i][0] - mat[l][0]), b = abs(mat[i][1] - mat[l][1]);
    return sqrt(pow(a, 2) + pow(b, 2));
}

double dist(ll p0, ll p1)
{
    double result = INF;
    for (auto &i : childs[p0])
    {
        for (auto &l : childs[p1])
        {
            double d = _dist(i, l);
            if (d <= m)
            {
                result = min(result, d);
            }
        }
    }

    return result;
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
        parents[i] = i;
        childs[i].emplace_back(i);
    }

    for (ll a, b, i = 0; i < w; ++i)
    {
        cin >> a >> b;
        merge(--a, --b);
    }

    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < n; ++l)
        {
            ll p0 = _parent(i), p1 = _parent(l);
            if (p0 != p1 && mat[p0][p1] == -INF)
            {
                mat[p0][p1] = mat[p1][p0] = dist(p0, p1);
            }
        }
    }

    cout << mat[0][4] << "\n";
    cout << parents[0] << " " << parents[4] << "\n";

    return 0;
}