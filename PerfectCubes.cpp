#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<vector<int> > a(n);int mx=0;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d", &k);
		a[i]=vector<int> (501);
		for(int j=0;j<k;j++){
			int temp;
			scanf("%d", &temp);
			int k=2;
			while(temp!=1){
				if(temp%k==0){
					++a[i][k];
					temp/=k;
					mx=mx>k?mx:k;
				}
				else ++k;
				//cout<<k<<endl<<temp<<endl;
			}
			/*++a[i][temp];
			mx=mx>temp?mx:temp;*/
		}
	}
	/*for(int i=0;i<n;i++)
		for(int j=0;j<mx;j++)
			cout<<j<<" "<<a[i][j]<<endl;*/
	int ans=0;
	for(int i=0;i<n;i++){
		vector<int> temp(mx+1);
		for(int t=1;t<=mx;t++)
			temp[t]+=a[i][t];
		for(int j=i+1;j<n;j++){
			for(int t=1;t<=mx;t++)
				temp[t]+=a[j][t];
			for(int k=j+1;k<n;k++){
				for(int t=1;t<=mx;t++)
					temp[t]+=a[k][t];
				for(int l=k+1;l<n;l++){
					int c=0;
					for(int t=1;t<=mx;t++){
						temp[t]+=a[l][t];
						//cout<<t<<endl<<temp[t]<<endl;
						if(temp[t]%3==0||t==1)
							++c;
						temp[t]-=a[l][t];
						//cout<<t<<endl<<temp[t]<<endl;
					}
					if(c==mx)++ans;
				}
				for(int t=1;t<=mx;t++)
					temp[t]-=a[k][t];
			}
			for(int t=1;t<=mx;t++)
				temp[t]-=a[j][t];
		}
		for(int t=1;t<=mx;t++)
			temp[t]-=a[i][t];
	}
	cout<<ans<<endl;
	return 0;
}