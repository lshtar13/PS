#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const ll N = 50;
ll n, m, city[N][N] = {{}};
vector<pll> chickens, houses;

inline ll dist(pll a, pll b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll calculateMinDistance(vector<int> &selected)
{
    ll totalDistance = 0;
    for (auto &h : houses)
    {
        ll minDist = LLONG_MAX;
        for (int i : selected)
        {
            minDist = min(minDist, dist(h, chickens[i]));
        }
        totalDistance += minDist;
    }
    return totalDistance;
}

void selectChickens(int start, int count, vector<int> &selected, ll &minDistance)
{
    if (count == m)
    {
        minDistance = min(minDistance, calculateMinDistance(selected));
        return;
    }
    if (start >= chickens.size())
        return;

    // Select the current chicken
    selected.push_back(start);
    selectChickens(start + 1, count + 1, selected, minDistance);
    selected.pop_back();

    // Skip the current chicken
    selectChickens(start + 1, count, selected, minDistance);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < n; ++j)
        {
            cin >> city[i][j];
            if (city[i][j] == 2)
            {
                chickens.emplace_back(make_pair(i, j));
            }
            else if (city[i][j] == 1)
            {
                houses.emplace_back(make_pair(i, j));
            }
        }
    }

    ll result = LLONG_MAX;
    vector<int> selected;
    selectChickens(0, 0, selected, result);

    cout << result << "\n";

    return 0;
}