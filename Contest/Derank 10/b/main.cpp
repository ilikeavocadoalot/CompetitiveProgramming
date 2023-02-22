#include <bits/stdc++.h>
using namespace std;
string t,s;
int main()
{
    cin>>s;
    t="oxx";
    if (s==t)
    {
        cout<<"Yes";
        exit;
    }
    for (int ii=1; ii<=100000; ii++)
    {
        t=t+"oxx";
        for (int i= 0; i < T2.length(); i++) {
        // So sánh với vị trí đầu tiên của chuỗi T1
        if (T2[i] == T1[0]) {
            int count = 0;

            // Nếu điều kiện trên xảy ra, tiếp tục duyệt các vị trí
            // nằm kề i của T2 và nằm kề j của chuỗi T1
            for (int j = 0; j < T1.length(); j++) {
                if (T2[j + i] == T1[j])
                    count += 1;
            }

            // Sử dụng biến đếm count với mục đích đếm có bao nhiêu
            // kí tự trong chuỗi T2 trùng với T1, qua một lượt đếm (tức là vòng lặp j hoàn thành)
            // nếu biến count bằng chiều dài của chuỗi T1 tức là tồn tại
            // chuỗi T1 trong T2, trả về vị trí trùng, tức là vị trí i
            if (count == T1.length()) return i;
        }
        if (s in t)
        {
            cout<<"Yes";
            exit;
        }
    }
    cout<<"No";
    return 0;
}
