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
#define FOR2(a, b, A, B)                                                       \
  for (ll a = 0; a < A; ++a)                                                   \
    for (ll b = 0; b < B; ++b)

cll N = 200, K = 5, D = 100, NODE = 302, INF = N * K + 1;
ll n, k, d, source = 0, foodStart = 1, memberStart, sink,
            cap[NODE][NODE] = {{}}, flow[NODE][NODE] = {{}};
vpll edges[NODE];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // network flow
  // source 0
  // foods 1 ~ 100
  // members 101 ~ 300
  // sink  301
  cin >> n >> k >> d;
  memberStart = foodStart + d, sink = memberStart + n;
  for (ll food = foodStart, limit; food < foodStart + d; ++food) {
    cin >> limit;
    cap[source][food] = limit;
  }
  for (ll member = memberStart, nkind; member < memberStart + n; ++member) {
    cin >> nkind;
    for (ll i = 0, food; i < nkind; ++i) {
      cin >> food;
      cap[food][member] = 1;
    }
    cap[member][sink] = k;
  }

  ll result = 0;
  while (true) {
    ll parents[NODE] = {};
    memset(parents, -1, sizeof(parents));
    parents[source] = source;
    qll q;
    q.push(source);

    for (ll node; !q.empty() && parents[sink] == -1;) {
      node = q.front();
      q.pop();

      for (ll av = source; av <= sink; ++av) {
        if (cap[node][av] - flow[node][av] > 0 && parents[av] == -1) {
          parents[av] = node;
          q.push(av);
        }
      }
    }

    if (parents[sink] == -1) {
      break;
    }

    ll amount = INF;
    for (ll node = sink; node != source; node = parents[node]) {
      amount =
          min(amount, cap[parents[node]][node] - flow[parents[node]][node]);
    }

    for (ll node = sink; node != source; node = parents[node]) {
      flow[parents[node]][node] += amount;
      flow[node][parents[node]] -= amount;
    }

    result += amount;
  }

  cout << result << "\n";

  return 0;
}