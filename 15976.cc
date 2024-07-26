#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M, a, b;
    cin>>N;
    vector<ll> idxA(N), numA(N);
    for(ll i = 0; i<N; ++i)
    {
        cin>>idxA[i]>>numA[i];
    }

    cin>>M;
    vector<ll> idxB(M), sumB(M, 0);
    for(ll num, i = 0; i<M; ++i)
    {
        cin>>idxB[i]>>num;
        sumB[i] = (i ? sumB[i-1] : 0) + num;
    }

    ll result = 0;
    cin>>a>>b;
    for(ll i = 0; i<N; ++i)
    {
        ll idx = idxA[i], left = idx+a, right = idx+b;

        ll leftIdx = lower_bound(idxB.begin(), idxB.end(), left) 
                    - idxB.begin(),
            rightIdx = lower_bound(idxB.begin(), idxB.end(), right+1) 
                        - idxB.begin();
        ll leftSum= leftIdx ? sumB[leftIdx-1] : 0,
            rightSum= rightIdx ? sumB[rightIdx-1] : 0;

        result += numA[i]*(rightSum - leftSum);
    }

    cout<<result<<"\n";

    return 0;
}