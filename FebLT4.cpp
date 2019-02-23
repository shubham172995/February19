#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		int x, y;
		scanf("%d %d", &x, &y);
		--x;--y;
		vector<vector<int> > a(n), b(n);
		for(int i=0;i<n;i++){
			a[i]=vector<int> (m);
			b[i]=vector<int> (m);
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		}
		b[x][y]=0;int temp=1;
		int moves=0;
		for(int i=x;i<n;i++){
			for(int j=y;j<m;j++){
				if(i==x&&j==y)continue;
				if(i==0){
					if(j%3==0)
						b[i][j]=b[i][j-3]+2;
					else if(j%3==1&&i+2<n)
						b[i][j]=b[i][j-1]+3;
					else if(j%3==2&&i+2<n)
						b[i][j]=b[i][j-1]+1;
				}
				else if(i%3==0&&i>=3){
					if(j%3==0)
						b[i][j]=b[i-3][j]+2;
					else if(j%3==1)
						b[i][j]=b[i-3][j-1]+3;
					else
						b[i][j]=b[i-3][j-2]+4;
				}
				else if(i%3==1){
					if(j%3==0&&j!=0)
						b[i][j]=b[i-1][j-3]+3;
					else if(j==0)
						b[i][j]=b[i-1][j]+3;
					else if(j%3==1&&(i+2)<n&&(j+1)<m)
						b[i][j]=b[i-1][j-1]+6;
					else if(j%3==2&&(i+2)<n&&(j+2)<m)
						b[i][j]=b[i-1][j-2]+7;
				}
				else if(i%3==2&&(j+2)<m){
					if(j%3==0&&j!=0)
						b[i][j]=b[i-2][j-2]+4;
					else if(j==0)
						b[i][j]=b[i-2][j]+4;
					else if(j%3==1&&(i+1)<n&&(j+2)<m)
						b[i][j]=b[i-2][j-1]+6;
					else if(j%3==2&&(i+1)<n&&(j+2)<m)
						b[i][j]=b[i-2][j-2]+7;
				}
				if(b[i][j]==0&&i+j>0)
					b[i][j]=-1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<b[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}