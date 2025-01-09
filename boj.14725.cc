#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class info{
    public:
        int level;
        string name, prefix;
        map<string, info*> childs;

        info(int _level)
        {
            level = _level;
            prefix = string(level*2, '*');
        }

        info(string &_name, int _level)
        {
            name = _name;
            level = _level;
            prefix = string(level*2, '-');
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

    info rootInfo(0);
    int n;
    cin>>n;
    cin.ignore();

    for(int i = 0, k; i<n; ++i)
    {
        string input;
        getline(cin, input);
        stringstream ss(input);
        ss>>k;

        vector<string> inputs(k);
        for(int j = 0; j<k; ++j)
        {
            ss>>inputs[j];
        }

        rootInfo.push(inputs, 0);
    }
    
    rootInfo.printChild();
    //rootInfo.childs["A"]->printChild();

    return 0;
}