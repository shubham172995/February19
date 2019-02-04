#include<bits/stdc++.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		std::vector<int> a(n);
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		std::sort(a.begin(), a.end(), std::greater<int>());
		int total=0;
		for(int i=0;i<n;i+=4){
			if(i+1<n)
				total+=a[i]+a[i+1];
			else
				total+=a[i];
		}
		printf("%d\n",total);
	}
	return 0;
}