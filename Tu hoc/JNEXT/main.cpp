#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int t,n;
    cin>>n;
    vector <int> st;
    for (int i=0; i<n; i++)
    {
        cin>>t;
        st.push_back(t);
    }
    auto tam=st.end();
    while (true)
    {
        if (*st.tam > *st.(tam-1))
        {
            int tmp = *st.tam;
            *st.tam=*st.(tam-1);
            *st.(tam-1)=tmp;
            auto t1=(tam-1);
            break;
        }
        tam-=1;
    }
    st.sort(t1,st.end())

    return 0;
}
