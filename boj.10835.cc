#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, deckA[2000] = {0}, deckB[2000] = {0}, dp[2001][2001] = {{0}};

ll score(int idxA, int idxB)
{
    if(idxA == n || idxB == n)
    {
        return 0;
    }
    else if(dp[idxA][idxB] != -1)
    {
        return dp[idxA][idxB];
    }

    dp[idxA][idxB] = max(dp[idxA][idxB], score(idxA+1, idxB+1));
    dp[idxA][idxB] = max(dp[idxA][idxB], score(idxA+1, idxB));
    if(deckA[idxA] > deckB[idxB])
    {
        dp[idxA][idxB] = max(dp[idxA][idxB], deckB[idxB] + score(idxA, idxB+1));
    }

    return dp[idxA][idxB];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i = 0; i<n; ++i)
    {
        cin>>deckA[i];
    }
    for(int i = 0; i<n; ++i)
    {
        cin>>deckB[i];
    }

    cout<<score(0, 0)<<"\n";
    return 0;
}