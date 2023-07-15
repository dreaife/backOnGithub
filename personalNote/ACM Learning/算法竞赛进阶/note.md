# 基本算法

## 位运算

### a^b

a的b次方对p取模
$$
b = c_{k-1}2^{k-1}+c_{k-2}2^{k-2}+...+c_{0}2^{0}
$$

$$
a^b=a^{c_{k-1}2^{k-1}}*a^{c_{k-2}2^{k-2}}*...*a^{c_{0}2^{0}}
$$

$$
a^{2^i}=(a^{2^{i-1}})^2
$$

可以从后往前推出结果。

```c++
int pow(int a,int b,int p){
    int res = 1 % p;
    while(b){
        if(b&1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }return res;
}
```

### 64位整数乘法

求 a 乘 b 对 p 取模的值。

1. 二进制分解

$$
a*b=a*{c_{k-1}2^{k-1}}+a*{c_{k-2}2^{k-2}}+...+a*{c_{0}2^{0}}
$$

同理从后往前推即可。

```c++
ll mul(ll a,ll b,ll p){
    ll res = 0;
    for(;b;b>>=1){
        if(b&1) res = (res + a) % p;
        a = a*2%p;
    }return res;
}
```

2. 高位舍弃

`a*bmod = a*b - [a*b/p]*p`

long double在十进制下有效数字为18-19位，long long同样。结果最终在0~p-1之间，即高位对于结果无影响。

```c++
ll mul(ll a,ll b,ll p){
    a %= p;b %= p;
    ll c = (long double)a*b/p;
    ll ans = a*b-c*p;
    if(ans<0) ans += p;
    else if(ans >= p ) ans -= p;
    return ans;
}
```

### 最短Hamilton路径（二进制状压）

`f[i,j] = min(f[i,j],f[i^1<<j,k]+w[k,j])//k 0...n-1`

```c++
int n,w[50][50],f[2<<20][20];
void solve(){
    memset(f,0x3f,sizeof f);
    cin>>n;f[1][0]=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        cin>>w[i][j];
    for(int i=1;i< 1<<n;i++)
        for(int j=0;j<n;j++) if(i>>j & 1)
            for(int k=0;k<n;k++) if((i^1<<j)>>k & 1)
                f[i][j] = min(f[i][j],f[i^1<<j][k]+w[k][j]);
    cout<<f[(1<<n )- 1][n-1]<<endl;
}
```

### 起床困难综合症

从大到小贪心最大可选值即可。

```c++
int n,m;
pair<string,int> a[100005];
int calc(int bit,int t){
    for(int i=0;i<n;i++){
        int x = a[i].second >> bit & 1;
        if(a[i].first == "AND") t &= x;
        else if(a[i].first == "OR") t |= x;
        else t ^= x;
    }return t;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;int t;
        cin>>s>>t;
        a[i] = make_pair(s,t);
    }
    int ans = 0,val = 0;
    for(int i=29;i>=0;i--){
        int t1 = calc(i,1),t0 = calc(i,0);
        if(val + (1<<i)<=m && t1>t0)
            ans += t1<<i,val += 1<<i;
        else ans += t0<<i;
    }cout<<ans<<endl;
}
```

## 递推和递归

### 奇怪的汉诺塔（四塔）

$$
d(n)=2*d(n-1)+1
$$

$$
f(n)=\min\limits_{1\le i<n}(2*f(i)+d(n-i))
$$

### 约数之和（分治）

当c为奇数
$$
sum(p,c)&=&(1+p+...+p^{\frac{c-1}{2}})+(p^{\frac{c+1}{2}}+...+p^c) \\
&=& (1+p+...+p^{\frac{c-1}{2}})+p^{\frac{c+1}{2}}*(1+p+...+p^{\frac{c-1}{2}}) \\
&=& (1+p^{\frac{c+1}{2}})*sum(p,\frac{c-1}{2})
$$
当c为偶数
$$
sum(p,c) = (1+p^{\frac{c}{2}})*sum(p,\frac{c}{2}-1)+p^c
$$

```c++
#define int long long
int a,b,ans;
const int mod = 9901;
map<int,int> f;
int pow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = (res * a)%mod;
        a = (a*a)%mod;b>>=1;
    }return res;
}
int calc(int a,int p){
    if(p==0) return 1;
    if(p%2){
        return (pow(a,(p+1)>>1)+1)*calc(a,(p-1)>>1) % mod;
    }else{
        return (pow(a,p)+(pow(a,p>>1)+1)*calc(a,(p/2)-1)%mod)%mod;
    }
}
signed main(){
    cin>>a>>b;ans = 1;int t = a;
    for(int j = 2;j <= t/j;j++){
        while(t%j==0){
            f[j]++;t/=j;
        }
    }if(t>1) f[t]++;
    for(auto i:f){
        int x = i.first,y = i.second * b;
        ans = (ans*calc(x,y))%mod;
    }if(!a) ans = 0;
    cout<<ans<<endl;
    return 0;
}
```

## 前缀和与差分

### 激光炸弹（前缀和）

$$
sum(l,r)=\sum_{i=l}^{r}A[i]=S[r]-S[l-1]
$$

### IncDec序列（差分）

$min(p,q)+|p-q|$次操作，$|p-q|+1$种序列。

## 二分

### 最佳牛围栏

1. 求没有长度限制最大平均值

   在子段和大于等于0的集合内

2. 长度不小于L时

   $\max\limits_{i-j>=L}\{A_{j+1}+...+A_i\}=\max\limits_{L\le i\le n}\{sum_i - \min\limits_{0\le j \le L}(sum_j)\}$

   当i增加时，最小值的取值空间只会加1，即只需跟随循环记录当前最小值即可。

最后通过二分平均值即可解决。

```c++
double a[N],d[N],p[N];
bool check(double mid){
    double minv = 1e10,ans = -1e10;
    for(int i=1;i<=n;i++) d[i]=a[i]-mid,p[i]=p[i-1]+d[i];
    for(int i=m;i<=n;i++){
        minv = min(minv,p[i-m]);
        ans = max(ans,p[i]-minv);
    }return ans>=0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    double l=1.0,r=2000.0;
    while(r-l > 1e-5){
        double mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout<<(int)(1000*r)<<endl;
    return 0;
}
```

## 排序





