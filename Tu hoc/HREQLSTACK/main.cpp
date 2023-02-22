#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue <int> a,b,c;
    long long int s1=0,s2=0,s3=0;
    long long int x,y,z,t;
    cin>>x>>y>>z;
    for (int i=0; i<x; i++)
    {
        cin>>t;
        a.push(t);
        s1+=t;
    }
    for (int i=0; i<y; i++)
    {
        cin>>t;
        b.push(t);
        s2+=t;
    }
    for (int i=0; i<z; i++)
    {
        cin>>t;
        c.push(t);
        s3+=t;
    }
    bool kt=false;
    while ((s1!=s2) || (s1!=s3))
    {
        while (s1>s2)
        {
            s1-=a.front();
            a.pop();
        }
        while (s1<s2)
        {
            s2-=b.front();
            b.pop();
        }
        while (s3>s2)
        {
            s3-=c.front();
            c.pop();
        }
        while (s3<s2)
        {
            s2-=b.front();
            b.pop();
        }
        if ((s1==s2) && (s1==s3))
        {
            kt=true;
            break;
        }
    }
    if (kt) cout<<s1<<endl;
    else cout<<0<<endl;
    return 0;
}
