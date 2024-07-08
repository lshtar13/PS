#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string t;
    getline(cin, t);

    string p;
    getline(cin, p);

    vector<int> kmp(p.size());
    kmp[0] = -1;
    for(int i = 1; i<kmp.size(); ++i)
    {
        int _kmp = kmp[i-1];
        while(_kmp != -1 && p[i]!=p[_kmp+1])
        {
            _kmp = kmp[_kmp];
        }
        
        kmp[i] = p[_kmp+1] == p[i]?_kmp+1:-1;
    }

    vector<int> result;
    int i = 0, j = 0;
    while(i<t.size())
    {
        if(t[i] == p[j])
        {
            ++i, ++j;
        }
        else
        {
            if(!j)
            {
                ++i;
            }
            else
            {
                j = kmp[j-1]+1;
            }
        }

        if(j == p.size())
        {
            j = kmp[j-1]+1;
            result.push_back(i-p.size());
        }
    }

    cout<<result.size()<<"\n";
    for(auto r: result)
    {
        cout<<r+1<<" ";
    }

    // cout<<"\nkmp: ";
    // for(auto a: kmp)
    // {
    //     cout<<a<<" ";
    // }

    return 0;
}