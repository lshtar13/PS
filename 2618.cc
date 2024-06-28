#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int n, w, cases[1001] = {0}, dp[1001][1001] = {{0,}};
    pair<int, int> cases[1001];
    scanf("%d %d", &n, &w);
    for(int i = 1, a, b; i<=w; ++i)
    {
        scanf("%d %d", &a, &b);
        cases[i].first = --a, cases[i].second = --b;
    }

    int a, b, a1, b1, a2, b2;
    queue<pair<int>> q;
    a=cases[1].first, b = cases[1].second;
    dp[0][1] = abs(a-n+1) + abs(b-n+1);
    dp[1][0] = abs(a) + abs(b);
    q.push(make_pair(0,2));
    q.push(make_pair(2,0));

    return 0;
}