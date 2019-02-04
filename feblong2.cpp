#include<iostream>
#include<vector>

int main(){
	int t;
	std::cin>>t;
	while(t--){
		int n;
		std::cin>>n;
		std::vector<int> a(n), d(n);
		for(int i=0;i<n;i++)
			std::cin>>a[i];
		for(int i=0;i<n;i++)
			std::cin>>d[i];
		int max=0;
		for(int i=0;i<n;i++){
			if(i==0){
				if((a[n-1]+a[1])<d[0])
					max=max>d[0]?max:d[0];
				}
			else if(i==n-1){
				if((a[i-1]+a[0])<d[i])
					max=max>d[n-1]?max:d[n-1];
				}
			else{
				if((a[i-1]+a[i+1])<d[i])
					max=max>d[i]?max:d[i];
				}
		}
		if(max==0)
			printf("-1\n");
		else printf("%d\n", max);
	}
	return 0;
}