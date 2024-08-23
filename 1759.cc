#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;

ll l, c;
char candidate[15] = {0}, vowel[5] = {'a', 'i', 'o', 'u', 'e'};

void search(ll idx)
{
    static ll ncyper = 0, nvowel = 0, nconsonant = 0;
    static char cyper[16] = {0};

    if(ncyper == l)
    {
        if(nvowel>=1 && nconsonant>=2)
        {
            cout<<cyper<<"\n";
        }
        return;
    }
    else if(idx>=c)
    {
        return;
    }

    ++nconsonant;
    for(ll i = 0; i<5; ++i)
    {
        if(vowel[i] == candidate[idx])
        {
            --nconsonant, ++nvowel;
        }
    }
    cyper[ncyper++] = candidate[idx];
    search(idx+1);
    cyper[--ncyper] = 0;
    --nconsonant;
    for(ll i = 0; i<5; ++i)
    {
        if(vowel[i] == candidate[idx])
        {
            ++nconsonant, --nvowel;
        }
    }
    
    search(idx+1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>l>>c;
    for(ll i = 0; i<c; ++i)
    {
        cin>>candidate[i];
    }
    sort(candidate, candidate+c);

    search(0);

    return 0;
}