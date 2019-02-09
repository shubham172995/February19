#include<bits/stdc++.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		std::vector<int> a(n), b(100005), c(n), d(n);
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);
			++b[a[i]];
		}
		for(int i=0;i<n;i++)
			c[i]=b[a[i]];
		std::stack<int> s;
		s.push(0);
		for(int i=1;i<n;i++){
			if(c[s.top()]>c[i])
				s.push(i);
			else{
				while(!s.empty() && c[s.top()]<c[i]){
					d[s.top()]=a[i];
					s.pop();
				}
				s.push(i);
			}
		}
		while(!s.empty()){
			d[s.top()]=-1;
			s.pop();
		}
		for(int i=0;i<n;i++){
			printf("%d ", d[i]);
		}
		printf("\n");
	}
	return 0;
}