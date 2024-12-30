#include<bits/stdc++.h>
using namespace std;

vector<string> tr(vector<string>& tk){
	map<string, int> lastOc;
	vector<string> res;
	for(int i = 0; i < tk.size(); i++){
		if(tk[i].size() == 1 && isalpha(tk[i][0])){
				if(lastOc.find(tk[i]) == lastOc.end()){
				res.push_back("0");
			}else{
				res.push_back(to_string(i-lastOc[tk[i]]));
			}
			lastOc[tk[i]] = i;
		}else{
			res.push_back(tk[i]);
		}
	}
	return res;
}

int main(){
	int n; cin>>n;
	vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	vector<vector<string>> suffixes;
	
    for (int i = 0; i < n; i++) {
        vector<string> sel(arr.begin() + i, arr.end());
		auto trans = tr(sel);	
        suffixes.push_back(trans);
    }
	
	sort(suffixes.begin(), suffixes.end());
	
	int q; cin>>q;
	while(q--){
		int ql;
		cin>>ql;
		vector<string> qtk(ql);
		for(int i = 0; i < ql; i++){
			cin>>qtk[i];
		}
		vector<string> trQ = tr(qtk);
		bool f = false;
		for(const auto& suffix: suffixes){
			if(suffix.size() >= trQ.size()){
				if (equal(trQ.begin(), trQ.end(), suffix.begin())) {
                    f = true;
                    break;
                }
			}
		}		
		if(f){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
