#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define mx6 1000010
using namespace std;

int Tree[1000010][27];
char s[1000010] ,c, ans;
int n,q,type,idx,l,r,k,cnt;

void update(int p1, int p2, int val) {
    while(p1 <= mx6){
        Tree[p1][p2] += val;
        p1 = (p1 + (p1 & (-p1)));
    }
    return;
}

int query(int p1, int p2) {
    int ans=0;
    while(p1 > 0){
        ans += Tree[p1][p2];
        p1 = (p1 - (p1 & (-p1)));
    }
    return ans;
}

int main() {
    si(n), si(q);
    scanf("%s",s);

    for(int i=0; i<strlen(s); i++) {
        update(i+1, s[i]-96, 1);
    }

    while(q--) {
		si(type);

        if(type==0) {

            si(idx);
            scanf(" %c",&c);
            update(idx, s[idx-1]-96, -1);
            s[idx-1]=c;
            update(idx, s[idx-1]-96, 1);

        } else {
            si(l), si(r), si(k);
            cnt=0;
			ans = '$';

            for(int i=1; i<=26; i++) {
                cnt += (query(r, i) - query(l-1, i));
                if(cnt >= k) {
                    ans = (i-1)+'a';
                    break;
                }
            }

            if(ans == '$') {
                printf("Out of range\n");

            } else {
                printf("%c",ans);
				putchar('\n');
            }
        }
    }

	return 0;
}
