#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<vector<int> > a(n+1);
	vector<int> b(n), p(n);
	for(int i=1;i<n;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
	}
	int count=0;
	stack<int> s;
	s.push(k);
	while(!s.empty()){
		int t=s.top();
		s.pop();
		if(!b[t]){
			b[t]=1;
		}
		for(vector<int>::iterator it=a[t].begin(); it!=a[t].end(); ++it){
			if(!b[*it]){
				++count;
				p[*it]=t;
				s.push(*it);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i]<k)continue;
		else{
			int j=p[p[i]];
			while(j>=k){
				++count;
				j=p[j];
			}
		}
	}
	printf("%d\n", count);
	return 0;
}