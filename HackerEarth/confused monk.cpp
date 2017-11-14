#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define fck std::ios::sync_with_stdio(false);
#define mx5 100010
#define mx6 1000010
#define mod 1000000007
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

int a[102];
ll power(ll x,int y,int m) {
    if(y==0) {
		return 1;
    }
    ll p = power(x, y/2, m);
    p = (p*p)%m;
    if(y%2 == 0) {
        return p;
    } else {
        return (x*p)%m;
    }
}

int gcd(int a,int b) {
    if(a==0) {
		return b;
    }
    return gcd(b%a,a);
}

int main() {
    int n;
    si(n);
    int g;
    ll prod=1LL;
    for(int i=0;i<n;i++) {
		si(a[i]);
        prod=(prod*(ll)a[i]);
        prod%=mod;
        if(i==0){
            g=a[i];
        } else {
            g=gcd(g,a[i]);
        }
    }
    ll ans = power(prod,g,mod);
    printf("%lld\n",ans);
    return 0;
}

