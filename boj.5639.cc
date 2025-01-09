#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void destruct(vector<int> &preorder, int start, int end)
{
    if(start == end)
    {
        printf("%d\n", preorder[start]);
        return ;
    }
    else if(start>end)
    {
        return;
    }

    int parent = preorder[start], m;
    m = upper_bound(preorder.begin()+start, preorder.begin()+end+1, parent) 
        - preorder.begin();

    destruct(preorder, start+1, m-1);
    destruct(preorder, m, end);
    printf("%d\n", parent);
}

int main(void)
{
    vector<int> preorder;
    for(int num; cin>>num; preorder.push_back(num))
        ;
        
    destruct(preorder, 0, preorder.size()-1);
    return 0;
}