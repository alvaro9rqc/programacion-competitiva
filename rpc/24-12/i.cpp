#include <bits/stdc++.h>
#define int long long
using namespace std;
bool suc(int n, int a1, int d) {
    if (n < a1) return false;
    return (n - a1) % d == 0;
}


signed main(){
	int n, w;
	cin>>n>>w;
	vector<tuple<int, int, int>> waves;
	
	while(n--){
		char ch; cin>>ch;
		if(ch == '!'){
			int p,l,a; cin>>p>>l>>a;
			waves.push_back({p,l,a});
			
		}else{
			int p; cin>>p;
			if(p > w){
				continue;
			}
			int ans = 0;
						

			for(auto &[a, b, c]: waves){
				
				if (p >= b + a) continue;
				
				if (suc(p, a, 4)) {
				    ans += c;
				} else if (suc(p, a + 2, 4)) {
				    ans -= c;
				}
			}
			cout<<ans<<endl;
		}
	}
	
	
	
	return 0;
}
