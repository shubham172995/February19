#include<iostream>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k;
		scanf("%d %d", &n, &k);
		int a[n];int count=0;
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);
			if(a[i]%2==0)
				++count;
		}
		if(count>=k&&k!=0)
			printf("YES\n");
		else if(k==0&&count==n)printf("NO\n");
		else if(k==0&&count!=n)printf("YES\n");
		else if(count<k)printf("NO\n");
	}
	return 0;
}