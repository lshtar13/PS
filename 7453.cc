#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;

ll n;
pll arr[16000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int num[4] = {0}, i = 0; i<n; ++i)
    {
        cin>>num[0]>>num[1]>>num[2]>>num[3];
        for(int l = 0; l<4; ++l)
        {
            arr[4*i + l] = make_pair(num[l], l);
        }
    }
    sort(arr, arr+4*n);

    ll result = 0;
    for(ll st0 = 0; st0<4*n; ++st0)
    {
        for(ll sum0, sum1, st, en, st1 = st0+1; arr[st0].second != arr[st1].second && st1<4*n; ++st1)
        {
            st = st1+1, en = 4*n-1, sum0 = arr[st0].first+ arr[st1].first;

            while(en>st)
            {
                sum1 = arr[st].first + arr[en].first;
                if(sum0 + sum1 > 0)
                {
                    while(en-1>st && arr[en-1] == arr[en])
                    {
                        --en;
                    }
                    --en;
                }
                else if(sum0 + sum1 < 0)
                {
                    while(st+1 < en && arr[st+1] == arr[st])
                    {
                        ++st;
                    }
                    ++st;
                }
                else
                {

                    ll num0 = 1, num1 = 1, check = 0;
                    while(arr[st+1])
                    check|=(1<<arr[st0].second);
                    check|=(1<<arr[st1].second);
                    check|=(1<<arr[st].second);
                    check|=(1<<arr[en].second);
                    if(check == 15){
                    cout<<arr[st0].second<<" "<<arr[st1].second<<" "<<arr[st].second<<" "<<arr[en].second<<"\n";
                        ++result;
                    }
                    ++st;
                }
            }
        }
    }

    cout<<result<<"\n";

    return 0;
}