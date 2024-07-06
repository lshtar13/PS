#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<string, int> parse(string cmd)
{
    string type;
    int n;


    return make_pair(type, n);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int s = 0, m;
    cin>>m;
    while(m--)
    {
        int n;
        string cmd, type = "";

        cin>>type;
        cin>>n;
        cout<<type;
        n = 1<<n;
        if(type == "add")
                s |= n;
        else if(type == "remove")
                s &= ~n;
        else if(type == "check")
        {
            n &= s;
            cout<<(n?1:0)<<"\n";
        }
        else if(type == "toggle")
            s ^= n;
        else if(type == "all")
            s = -1;
        else if(type == "empty")
            s = 0;
    }
    return 0;
}