#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> arr;
int dr[] = {1,0,0,-1};
int dc[] = {0,-1,1,0};
char put;
int H, W; 
ll compo = 0;
ll tamtemp = 0;
ll tamtotal = 0;
ll diametro = 0;

vector<vector<ll>> dis;

void dfs2(int r, int c, ll padre) {
	multiset<ll> d;
	d.insert(padre);
	arr[r][c] = '#';
	for(int i = 0; i < 4; ++i) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (not (
				(0 <= nr and nr < H) and 
				(0 <= nc and nc < W)
				) or
				arr[nr][nc] != 'x'
			) continue;
		d.insert(dis[nr][nc]);
	}
	if (d.size() == 1u) {
		diametro = max(diametro, *(--d.end()) + 1);
	} else{
		auto it1 = d.end();
		it1--;
		auto c1 = *it1;
		d.erase(it1);
		auto it2 = d.end();
		it2--;
		auto c2 = *it2; d.erase(it2);
		for(int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (not (
						(0 <= nr and nr < H) and 
						(0 <= nc and nc < W)
					) or
					arr[nr][nc] != 'x'
			   ) continue;
			ll nd = c1;
			if (c1 == dis[nr][nc]) nd = c2;
			dfs2(nr, nc, nd+1);
		}
	}

}

ll dfs1(int r, int c) {
	tamtemp++;
	arr[r][c] = put;
	ll son = 0;
	for(int i = 0; i < 4; ++i) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if ((0 <= nr and nr < H) and (0 <= nc and nc < W) and arr[nr][nc] == '.') {
			dis[nr][nc] = dfs1(nr, nc);
			son = max(dis[nr][nc], son);
		}
	}
	return son +1;
}

int main(){
	int t; cin>>t;
	int cas=1;
	while(t--){
		compo = 0;
		tamtemp = 0;
		tamtotal = 0;
		diametro = 0;
		cin>>H>>W;
		dis.assign(H, vector<ll>(W,0));
		arr.assign(H, "");
		for(auto &x: arr) cin>>x;
		for(int r = 0; r < H; ++r) {
			for (int c = 0; c < W; ++c) {
				if (arr[r][c] == '.') {
					//cerr << r << " ggaaaa " << c << '\n';
					tamtemp = 0;
					compo++;
					put = 'x';
					dfs1(r, c);
					if (tamtemp > tamtotal) tamtotal = tamtemp;
					//for(auto& x: dis){
          //  for(auto& e: x) {
          //    cerr << e << ' ';
          //  }
          //  cerr << '\n';
					//}
					dfs2(r,c, 0);
				}

			}
		}

		cout<<"Case "<<cas<<": "; 
		cout<<compo<<" "<<tamtotal << " " << diametro-1<<'\n';

		cas++;
	}


}
