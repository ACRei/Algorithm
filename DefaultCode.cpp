#include<bits/stdc++.h>
using namespace std;
int qrd(){int re=0,ch=getchar();while (ch<'0' || ch>'9') ch=getchar();while (ch>='0' && ch<='9'){re=re*10+ch-'0';ch=getchar();}return re;}

int n;

void Solve()
{
    n=qrd();
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
