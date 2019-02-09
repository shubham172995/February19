#include<bits/stdc++.h>

int main(){
	int n;
	scanf("%d", &n);
	long long d;
	scanf("%lld", &d);
	std::vector<int> a(n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	std::sort(a.begin(), a.end());
	int ans=0;
	for(int i=0;i<n-1;){
		if(a[i+1]-a[i]<=d){
			++ans;
			i+=2;
		}
		else ++i;
	}
	printf("%d\n", ans);
	return 0;
}