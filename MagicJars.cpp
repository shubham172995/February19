#include<iostream>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		long long a[n];
		long long max=0;
		for(int i=0;i<n;i++){
			scanf("%lld", &a[i]);
			max+=a[i];
		}
		max-=n;
		max+=1;
		printf("%lld\n", max);
	}
	return 0;
}