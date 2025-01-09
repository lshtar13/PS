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

cll MAX_N = 20;
ll n, arr2[21] = { 1 }, cubes[MAX_N][2] = { {} };

ll
solve (ll len, ll wid, ll height)
{
  ll result;
  for (ll a, b, i = n - 1; i >= 0; --i)
    {
      a = arr2[cubes[i][0]], b = cubes[i][1];
      if (b && a <= len && a <= wid && a <= height)
        {
          --cubes[i][1], result = solve (len - a, wid -)
        }
    }
}

int
main (void)
{
  ios::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);

  for (ll i = 0; i <= 20; ++i, arr2[i] = arr2[i - 1] * 2)
    {
    }

  ll len, wid, hegith;
  cin >> len >> wid >> height >> n;
  for (ll i = 0; i < n; ++i)
    {
      cin >> cubes[i][0] >> cubes[i][1];
    }

  cout << solve (len, wid, height) << "\n";

  return 0;
}