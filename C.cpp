#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long ull;

int mod = 1000000007;

void solve(){
	ull n, k; cin>>n>>k;
	ull ans = 1;
	
	if(n == 0 && k == 0){
		cout<<0<<endl;
		return;
	}
	
	if((n+1) %2 == 0){
		ans = ((n+1)/2) % mod;
		ans = (ans*(n+2)) % mod;
		ans = (ans*(k+1)) % mod;
		cout<<ans<<endl;
	}else{
		ans = ((n+2)/2) % mod;
		ans = (ans*(n+1)) % mod;
		ans = (ans*(k+1)) % mod;
		cout<<ans<<endl;
	}
	
	return;
}

int main(){
	int t; cin>>t;
	while(t--)
		solve();
	return 0;
}
