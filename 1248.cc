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

cll N = 10;
ll n, mat[N][N] = {{}};

bool search(vll &nums, vll &sums)
{
    ll s = nums.size();
    if (s == n)
    {
        for (ll &num : nums)
        {
            cout << num << " ";
        }
        return true;
    }

    sums.emplace_back(0);
    for (ll num = -10; num <= 10; ++num)
    {
        bool isOk = true;
        for (ll _sum, sign, i = s; i >= 0; --i)
        {
            // mat[i-1][s-1]
            _sum = sums[i] + num, sign = mat[i][s];
            if ((_sum < 0 && sign >= 0) || (_sum > 0 && sign <= 0) || (_sum == 0 && sign != 0))
            {
                isOk = false;
                break;
            }
        }

        if (isOk)
        {
            nums.emplace_back(num);
            for (auto &_sum : sums)
            {
                _sum += num;
            }
            if (search(nums, sums))
            {
                return true;
            }
            for (auto &_sum : sums)
            {
                _sum -= num;
            }
            nums.pop_back();
        }
    }
    sums.pop_back();

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = i; l < n; ++l)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case '+':
                mat[i][l] = 1;
                break;
            case '-':
                mat[i][l] = -1;
                break;
            default:
                mat[i][l] = 0;
            }
        }
    }

    vll sums, nums;
    search(nums, sums);

    return 0;
}