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

ll n, m, k, mat[1001][1001] = {{}}, degree[1001] = {};
map<string, ll> nameMap;
vector<string> idxMap;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    idxMap.push_back("");
    cin>>n;
    for(ll i = 1; i<=n; ++i)
    {
        string name;
        cin>>name;
        nameMap[name] = i;
        idxMap.push_back(name);
    }

    cin>>m;
    for(ll i = 0; i<m; ++i)
    {
        string x, y;
        cin>>x>>y;
        mat[nameMap[y]][nameMap[x]] = 1, ++degree[nameMap[x]];
    }

    vll roots;
    vector<string> rootNames;
    for(ll i = 1; i<=n; ++i)
    {
        if(!degree[i])
        {
            roots.push_back(i);
            rootNames.push_back(idxMap[i]);
        }
    }
    k = roots.size();

    vector<vector<string>> result(1001);
    for(auto &root : roots)
    {
        qll q;
        q.push(root);

        while(!q.empty())
        {
            ll parent = q.front();
            q.pop();

            for(ll child = 1; child<=1000; ++child)
            {
                if(mat[parent][child] && !--degree[child])
                {
                    result[parent].push_back(idxMap[child]);
                    q.push(child);
                }
            }
            sort(result[parent].begin(), result[parent].end());
        }
    }

    sort(rootNames.begin(), rootNames.end());

    cout<<rootNames.size()<<"\n";
    for(auto &root: rootNames)
    {
        cout<<root<<" ";
    }
    cout<<"\n";

    for(auto &pair: nameMap)
    {
        string name = pair.first;
        ll idx = pair.second;
        cout<<name<<" "<<result[idx].size()<<" ";
        for(auto &_name:result[idx])
        {
            cout<<_name<<" ";
        }
        cout<<"\n";
    }

    return 0;
}