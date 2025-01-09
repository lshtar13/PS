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
typedef vector<vll> vvll;

cll N = 1e5;
ll n, result = 0, cords[N][3] = {};
bool selected[N] = {};
vector<pll> xCord, yCord, zCord;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> cords[i][0] >> cords[i][1] >> cords[i][2];
        parents[i] = i;
        xCord.emplace_back(make_pair(cords[i][0], i));
        yCord.emplace_back(make_pair(cords[i][1], i));
        zCord.emplace_back(make_pair(cords[i][2], i));
    }
    sort(xCord.begin(), xCord.end());
    sort(yCord.begin(), yCord.end());
    sort(zCord.begin(), zCord.end());

    priority_queue<pll, vector<pll>, graeter<pll>> pq;
    while (!pq.empty())
    {
        ll idx = pq.top().second, dist = pq.top().first;
        pq.pop();
        if (selected[idx])
        {
            continue;
        }

        result += dist;
        selected[idx] = true;

        
    }

    return 0;
}