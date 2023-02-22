#include <bits/stdc++.h>>
using namespace std;
void process_op(vector<int>& val, char op)
{
    int r = val.back(); val.pop_back();
    int l = val.back(); val.pop_back();
    switch(op)
    {
    case '+':  val.push_back(l + r); break;
    case '-': val.push_back(l - r); break;
    }
}
int evaluate(string s)
{
    vector<int> val;
    vector<char> op;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            int number = 0;
            while (i < (int)s.size() && isdigit(s[i]))
            {
                number = number * 10 + s[i] - '0';
                ++i;
            }
            val.push_back(number);
            --i;
        }
        else
        {
            if (!op.empty())
            {
                process_op(val, op.back());
                op.pop_back();
            }
            op.push_back(s[i]);
        }
    }
    while (!op.empty())
    {
        process_op(val, op.back());
        op.pop_back();
    }
    return val.back();
}
int main()
{
    string s;
    cin>>s;
    cout<<evaluate(s);
}
