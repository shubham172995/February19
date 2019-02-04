#include<iostream>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long n;
		scanf("%lld", &n);
		long long res=0;
		res+=(n*(n+1))/2;
		res+=n;
		printf("%lld\n", res);
	}
	return 0;
}