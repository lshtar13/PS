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

ll n;

class info{
    public:
        int level;
        string name, prefix;
        map<string, info*> childs;

        info(int _level)
        {
            level = _level;
            prefix = string(level, ' ');
        }

        info(string &_name, int _level)
        {
            name = _name;
            level = _level;
            prefix = string(level, ' ');
        }

        void push(vector<string> &names, int tgt)
        {
            if(tgt>=names.size())
            {
                return;
            }
            string _name = names[tgt];
            if(childs.find(_name) == childs.end())
            {
               childs[_name] = new info(_name, level+1);
            }
            childs[_name]->push(names, tgt+1);
        }

        void printChild()
        {
            for(auto &pair: childs)
            {
                cout<<prefix<<pair.first<<"\n";
                pair.second->printChild();
            }
        }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    info root(0);
    
    cin>>n;
    cin.ignore();
    for(ll i = 0; i<n; ++i)
    {
        string input, name;
        vector<string> inputs;
        getline(cin, input);
        stringstream ss(input);
        while(getline(ss, name, '\\'))
        {
            inputs.push_back(name);
        }

        root.push(inputs, 0);
    }

    root.printChild();

    return 0;
}