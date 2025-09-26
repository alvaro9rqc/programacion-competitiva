#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k; cin>>n>>m>>k;
    map<int, int> mpS;
   
    vector<int> mult(m + 1, 0);

    for(int i = 0; i < k; i++){
        int p, c; cin>>p>>c;
        if (!mpS.count(c)){
            mpS[c] = p;
        }else{
            int st = mpS[c]; 

            if(p == st){
                mult[c] += 100;
            }else{
                mult[c] += abs(p-st);
            }
            mpS.erase(c); 
        }
    }
    
    for(auto p: mpS){
        mult[p.first] += 100;
    }
    for(int i = 1; i <= m; i++){
        if(i == m){
            cout<<mult[i];
        }else{
            cout<<mult[i]<<" ";
        }
    }
}
