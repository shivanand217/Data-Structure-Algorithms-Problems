// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
using namespace std;

int ar[102];
int n;

template<typename T>
void read_(T &x)
{
 char r;
 int start=0,neg=0;
 x=0;

 while(1)
{
 r=getchar();
 if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
    {continue;}
 if((r-'0'<0 || r-'0'>9) && r!='-' && start)
    {break;}

 if(start)
    x*=10;

  start=1;

 if(r=='-')
    neg=1;
 else x += r-'0';
 }

 if(neg)
    x*=-1;
}

int gcd(int a,int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

void print_array()
{
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
}

void juggling(int d)
{
    int i,j,k,tmp;

    for(i=n-1; i>=n-gcd(n,d); i--)
    {
        tmp = ar[i];
        j=i;
        while(1)
        {
            k = j-d;
            if(k<0)
            {
                k+=n;
            }
            if(k==i)
                break;
            ar[j] = ar[k];
            j = k;
        }
        ar[j]=tmp;
    }
}

int main()
{
    read_(n);
    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }
    int d;
    read_(d);

    //exception
    if(d > n)
    {
        d%=n;
    }

    juggling(d);
    print_array();

    return 0;
}
