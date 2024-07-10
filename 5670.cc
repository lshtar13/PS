#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const char END = '0';

class info{
    public:
        int nword;
        char c;
        map<char, info*> childs;

        info(char _c)
        {
            c = _c;
            nword = 0;
        }

        ~info()
        {
            for(auto c: childs)
            {
                delete c.second;
            }
        }

        int push(string &word, int tgt)
        {
            if(tgt>=word.size())
            {
                return 0;
            }

            bool isExist; 
            int result = 0;

            if(isExist = childs.find(word[tgt]) == childs.end())
            {
               childs[word[tgt]] = new info(word[tgt]);
            }

            result += isExist&&childs.size()==2?nword:0;
            result += word[tgt]!=END && childs.size()>1?1:0;

            // cout<<word<<" "<<word[tgt]<<" "<<result<<"\n";
            
            nword += word[tgt]!=END?1:0;
            result += childs[word[tgt]]->push(word, tgt+1);

            return result;
        }
};

double solve(int n)
{
    string ENDSTR= "0", dum = "1";
    info rootInfo(END);
    rootInfo.push(ENDSTR, 0);
    rootInfo.push(dum, 0);

    int cnt = 0;
    for(int i = 0; i<n; ++i)
    {
        string input;
        cin>>input;
        input += ENDSTR;
        // cout<<rootInfo.push(input, 0)<<"\n";
        cnt += rootInfo.push(input, 0);
    }

    double result = double(cnt)/double(n);
    result *=100;
    result = round(result);
    result /= 100;

    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<fixed;
    cout.precision(2);

    int n;
    while(cin>>n)
    {
        cout<<solve(n)<<"\n";
    }

    return 0;
}