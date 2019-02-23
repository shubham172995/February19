#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long a;int d1, d2;d1=d2=0;
		cin>>a;
		long long profit=0;
		profit=a-1;
		int i=1;
		if(profit>0){
			d1=d2=1;
			while(profit>0){
				profit+=a;
				long long temp=pow(2, i);
				long long amt=a-temp;
				if(amt>0)++d1;
				profit-=temp;
				++i;++d2;
			}
		}
		if(profit<0)--d2;
		cout<<d2<<" "<<d1<<endl;
	}
	return 0;
}