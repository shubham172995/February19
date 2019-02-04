#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		unsigned long long n, a, b, k;
		cin>>n>>a>>b>>k;
		unsigned long long res=0;
		if(a==b){
			cout<<"Lose\n";
			continue;
		}
		else if(a%b==0){
			res+=n/b;
			res-=n/a;
			if(res>=k)
				cout<<"Win\n";
			else
				cout<<"Lose\n";
		}
		else if(b%a==0){
			res+=n/a;
			res-=n/b;
			if(res>=k)
				cout<<"Win\n";
			else
				cout<<"Lose\n";
		}
		else{
			res+=n/a;
			res+=n/b;
			res-=2*(n/(a*b));
			if(res>=k)
				cout<<"Win"<<endl;
			else
				cout<<"Lose"<<endl;
	}
	}
	return 0;
}