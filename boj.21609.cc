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

cll N = 20, M = 5, directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m, mat[N][N] = {{}};

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < n;
}

pll findGroup(ll i, ll l, bool visited[][N]) {
  ll nblock = 1, nrainbow = bool(mat[i][l] == 0);
  qpll q;
  q.push({i, l});
  visited[i][l] = true;
  while (!q.empty()) {
    ll a, b;
    tie(a, b) = q.front();
    q.pop();

    for (auto &d : directions) {
      ll na = a + d[0], nb = b + d[1];
      if (!isValidCord(na, nb) || visited[na][nb]) {
        continue;
      } else if (mat[na][nb] != mat[i][l] && mat[na][nb] != 0) {
        continue;
      }

      visited[na][nb] = true;
      ++nblock, nrainbow += bool(mat[na][nb] == 0);
      q.push({na, nb});
    }
  }

  return {nblock, nrainbow};
}

ll findMaxGroup() {
  ll result = -1;
  pll stat(1, 1);
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      bool visited[N][N] = {{}};
      if (mat[i][l] <= 0) {
        continue;
      }

      pll nstat = findGroup(i, l, visited);
      if (nstat >= stat) {
        stat = nstat;
        result = i * n + l;
      }
    }
  }
  cout << stat.first << "/" << stat.second << "\n";
  return result;
}

void getGravity() {
  for (ll i = n - 1; i >= 0; --i) {
    for (ll l = 0; l < n; ++l) {
      if (mat[i][l] < 0) {
        continue;
      }

      for (ll ni = i + 1; ni < n && mat[ni][l] == -2; ++ni) {
        mat[ni][l] = mat[ni - 1][l];
        mat[ni - 1][l] = -2;
      }
    }
  }
}

void turn() {
  ll nmat[N][N] = {{}};
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      nmat[n - 1 - l][i] = mat[i][l];
    }
  }

  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      mat[i][l] = nmat[i][l];
    }
  }
}

ll eliminate(ll i, ll l) {
  ll nblock, nrainbow;
  bool visited[N][N] = {{}};
  tie(nblock, nrainbow) = findGroup(i, l, visited);
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      if (visited[i][l]) {
        mat[i][l] = -2;
      }
    }
  }

  return nblock * nblock;
}

void print() {
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cout << setw(5) << mat[i][l] << " ";
    }
    cout << "\n";
  }
  cout << "------------\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cin >> mat[i][l];
    }
  }

  ll score = 0;
  for (ll pt, i, l; (pt = findMaxGroup()) >= 0;) {
    i = pt / n, l = pt % n;
    cout << i << " " << l << "\n";
    score += eliminate(i, l);
    print();
    getGravity();
    // print();
    turn();
    // print();
    getGravity();
    print();
  }

  cout << score << "\n";

  return 0;
}