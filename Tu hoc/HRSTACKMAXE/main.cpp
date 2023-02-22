#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    stack <int> st;
    priority_queue <int> pq;
    bool b[100000];
    long long int n,i,t;
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>t;
        int x;
        if (t==1)
        {
            cin>>x;
            st.push(x);
            pq.push(x);
        }
        else
        {
            if (t==2)
            {
                if (st.top() == pq.top())
                {
                    b[st.top()]=true;
                    pq.pop();
                    st.pop();
                }
                else
                {
                    b[st.top()]=true;
                    st.pop();
                }
            }
            else
            {
                if (b[pq.top()]==false) cout<<pq.top()<<endl;
                else
                {
                    while (!pq.empty())
                    {
                        if (b[pq.top()]==true) pq.pop();
                        else break;
                    }
                    cout<<pq.top()<<endl;
                }
            }
        }
    }
    return 0;
}
