#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cin>>n;
    for(int num, i = 0; i<n; ++i)
    {
        cin>>num;
        maxHeap.push(num);
        if(maxHeap.size() - minHeap.size() > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top()>minHeap.top())
        {
            int maxTop = maxHeap.top(), minTop = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(minTop);
        }

        cout<<maxHeap.top()<<"\n";
    }

    return 0;
}