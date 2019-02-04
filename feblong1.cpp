#include<bits/stdc++.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		std::vector<int> a(26);
		std::vector<std::string> S(n);
		for(int i=0;i<n;i++){
			std::cin>>S[i];
			std::sort(S[i].begin(), S[i].end());
			for(int j=0;j<S[i].length();j++){
				if(j==0||S[i][j]!=S[i][j-1])
					a[S[i][j]-'a']+=1;
			}
		}
		int ans=0;
		for(int i=0;i<26;i++){
			if(a[i]==n)
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}