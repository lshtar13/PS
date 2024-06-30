#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string findRoot(map<string, string> &friends, string name)
{
    if(friends.find(name)==friends.end())
    {
        friends.insert({name, name});
    }
    return friends[name] = 
        friends[name] == name ? name : findRoot(friends, friends[name]);
}

int merge(map<string, string> &friends, map<string, int> &cnts,
    string f0, string f1)

{
    string root0 = findRoot(friends, f0), root1 = findRoot(friends, f1);
    int cnt0 = cnts[root0] ? cnts[root0] : ++cnts[root0], 
        cnt1 = cnts[root1] ? cnts[root1] : ++cnts[root1];
    if(root0==root1)
    {
        return cnt0;
    }
    else
    {
        friends[root1] = root0;
        return cnts[root0] += cnts[root1];
    }
}

void solve()
{
    int f;
    cin>>f;

    map<string, string> friends;
    map<string, int> cnts;
    while(f--)
    {
        string f0, f1, root0, root1;
        cin>>f0>>f1;
        cout<<merge(friends, cnts, f0, f1)<<"\n";
    }
}

int main(void)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}