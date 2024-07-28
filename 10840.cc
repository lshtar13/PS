#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s0, s1;
const ull MAX_SIG = 1500, MAX_HASH = 26*MAX_SIG;
ull sum0[MAX_SIG+1] = {0}, sum1[MAX_SIG+1] = {0}, len0, len1,
    cmps0[MAX_SIG+1][26]= {{0}}, cmps1[MAX_SIG+1][26] = {{0}},
    hashMap[MAX_HASH*100][27] = {{0}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s0);
    getline(cin, s1);
    len0 = s0.length(), len1 = s1.length();

    for(int c, i = 0; i<len0; ++i)
    {
        c = s0[i] - 'a';
        sum0[i+1] = sum0[i] + c;
        for(int l = 0; l<26; ++l)
        {
            cmps0[i+1][l] = cmps0[i][l] + ull(c == l);
        }
    }
    for(int c, i = 0; i<len1; ++i)
    {
        c = s1[i] - 'a';
        sum1[i+1] = sum1[i] + c;
        for(int l = 0; l<26; ++l)
        {
            cmps1[i+1][l] = cmps1[i][l] + ull(c == l);
        }
    }
    
    for(int s = 0; s<len0; ++s)
    {
        for(int e = s+1; e<=len0; ++e)
        {
            ull _hash = (sum0[e] - sum0[s])%MAX_HASH;
            while(hashMap[_hash][26])
            {
                _hash += MAX_HASH;
            }
            for(int i = 0; i<26; ++i)
            {
                hashMap[_hash][i] = cmps0[e][i] - cmps0[s][i];
            }
            hashMap[_hash][26] = 1;
        }
    }

    ull maxLen = 0;
    for(ull s = 0; s<len1; ++s)
    {
        for(ull e = s+1; e<=len0; ++e)
        {
            for(ull _hash = (sum0[e] - sum0[s])%MAX_HASH;
                _hash < MAX_HASH*100 && hashMap[_hash][26];
                _hash += MAX_HASH)
            {
                bool accord = true;
                for(int i = 0; accord && i<26; ++i)
                {
                    if(hashMap[_hash][i] != cmps1[e][i] - cmps1[s][i])
                    {
                        accord = false;
                    }
                }

                if(accord)
                {
                    maxLen = max(maxLen, e-s);
                    break;
                }

            }
        }
    }
    
    cout<<maxLen<<"\n";

    return 0;
}