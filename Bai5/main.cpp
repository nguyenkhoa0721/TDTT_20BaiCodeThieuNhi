#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const long long base=round(1e9)+7;
struct matran
{
    int a[55][55];
};
matran nhanmatran(matran a, matran b){
    matran tmp;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            tmp.a[i][j]=0;
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            for (int k=1;k<=n;++k){
                tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
                tmp.a[i][j]%=base;
            }
        }
    }
    return tmp;
}
matran mu(matran a,long long b){
    if (b==1){
        return a;
    }
    long long tmp=b/2;
    matran x=mu(a,b/2);
    x=nhanmatran(x,x);
    if (b%2==0) return x;
    else return nhanmatran(x,a);
}
int main(){
    cin>>n>>m>>k;
    matran coban;
    for (int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        coban.a[u][v]++;
    }
    matran res=mu(coban,k);
    int q;
    cin>>q;
    for (int i=1;i<=q;++i){
        int u,v;
        cin>>u>>v;
        cout<<res.a[u][v]<<"\n";
    }
}