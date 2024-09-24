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

cll MAX_N = 100;
ll n, mat[MAX_N][MAX_N] = {{}}, directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

inline bool isValidCord(ll i, ll l)
{
    return i >= 0 && i < n && l >= 0 && l < n;
}

bool isValid(ll gap)
{
    vector<vll> maxV(n, vll(n, 201)), minV(n, vll(n, -1));
    qll q;
    q.push(0);
    maxV[0][0] = mat[0][0], minV[0][0] = mat[0][0];
    while (!q.empty())
    {
        ll i = q.front() / n, l = q.front() % n;
        q.pop();
        if (i == n - 1 && l == n - 1)
        {
            return true;
        }

        for (auto &d : directions)
        {
            ll _i = i + d[0], _l = l + d[1];
            if (!isValidCord(_i, _l))
            {
                continue;
            }

            ll _maxV = max(maxV[i][l], mat[_i][_l]), _minV = min(minV[i][l], mat[_i][_l]);
            if ((_maxV < maxV[_i][_l] || _minV > minV[_i][_l]) && (_maxV - _minV <= gap))
            {
                maxV[_i][_l] = _maxV, minV[_i][_l] = _minV;
                q.push(_i * n + _l);
            }
        }
    }

    return false;
}

int main(void)
{
    // auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll mx = 0, mn = 200;
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < n; ++l)
        {
            cin >> mat[i][l];
            st = min(mx, mat[i][l]), en = max(mn, mat[i][l]);
        }
    }

    ll st = mx - mn, en = 0, mid, ans;
    while (st <= en)
    {
        // cout << st << " " << en << '\n';
        mid = (st + en) / 2;
        if (isValid(mid))
        {
            ans = mid, en = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    cout << ans << "\n";

    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << "실행 시간: " << duration.count() << "ms" << "\n";
    return 0;
}