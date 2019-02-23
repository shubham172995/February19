#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k, v;
		cin>>n>>k>>v;
		vector<int> a(n);long long sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		long long res=v;
		res*=(n+k);
		res-=sum;
		if(res%k==0&&res>0)
			cout<<(res/k)<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}