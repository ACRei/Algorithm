#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(...) emplace_back(__VA_ARGS__)
#define PII pair<int,int>
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define lowbit(x) (-x&x)
#define YESS printf("Yes\n")
#define NOO printf("No\n")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)2e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
int s[MAXN],res[MAXN];
PII a[MAXN];

void update(int x) {
    for(int i=x;i<=n;i+=lowbit(i)) {
        s[i]++;
    }
}

int query(int x,int res=0){
    for(int i=x;i!=0;i-=lowbit(i)) {
        res+=s[i];
    }
    return res;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read();
    for(int i=1;i<=n;i++) {
        a[i].fi=read(),a[i].se = i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<n;j++) {
            int l=(a[i].se-1)*j+2,r=min(j*a[i].se+1,n);
            if(l>r) {
                break;
            }
            res[j]+=(query(r)-query(l-1));
        }
        update(a[i].se);
    }
    for(int i=1;i<n;i++) {
        printf("%d%c",res[i]," \n"[i==(n-1)]);
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
    }
    return 0;
}