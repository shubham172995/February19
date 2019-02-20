#include<iostream>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int p[n], b[m+1];
    for(int i=0;i<=m;i++)
    b[i]=0;
    for(int i=0;i<n;i++){
        int x=0;
        scanf("%d %d", &p[i], &x);
        if(p[i]>b[x])
        b[x]=p[i];
    }
    int res=0;
    for(int i=0;i<=m;i++)
    res+=b[i];
    printf("%d\n", res);
    return 0;
}
