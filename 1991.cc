#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string preorder(vector<pair<int, int>> &bt, int node)
{
    if(node == -1)
    {
        return "";
    }

    return char(node+'A') 
        + preorder(bt, bt[node].first) + preorder(bt, bt[node].second);
}

string inorder(vector<pair<int, int>> &bt, int node)
{
    if(node == -1)
    {
        return "";
    }

    return  inorder(bt, bt[node].first) + char(node+'A')
         + inorder(bt, bt[node].second);
}

string postorder(vector<pair<int, int>> &bt, int node)
{
    if(node == -1)
    {
        return "";
    }
    return postorder(bt, bt[node].first) + postorder(bt, bt[node].second)
        + char(node+'A'); 
}

int main(void)
{
    int n;
    scanf("%d",&n);
    cin.ignore();

    vector<pair<int, int>> bt(26);
    for(char i = 0, node, lc, rc; i<n; ++i)
    {
        string input;
        getline(cin, input);
        node = input[0] - 'A';
        lc = input[2] == '.' ? -1 : input[2] - 'A';
        rc = input[4] == '.' ? -1 : input[4] - 'A';
        bt[node] = make_pair(lc, rc);
    }

    printf("%s\n%s\n%s\n",preorder(bt,0).c_str(),
                            inorder(bt,0).c_str(),
                            postorder(bt,0).c_str());

    return 0;
}