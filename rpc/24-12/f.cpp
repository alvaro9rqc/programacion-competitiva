#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin>>n;
    vector<string> predicted(n);
    vector<string> final(n);

    for(int i = 0; i < n; i++) {
        cin>>predicted[i];
    }

    for(int i = 0; i<n; i++) {
        cin>>final[i];
    }
    
    unordered_map<string, int> predicted_positions;
    for (int i = 0; i < n; i++) {
        predicted_positions[predicted[i]] = i;
    }

    string favorite = "";
    int max_advance = 0; 
    bool any_advance = false; 

    for (int i = 0; i < n; i++) {
        string name = final[i];
        int predicted_pos = predicted_positions[name];
        int advance = predicted_pos - i; 

        if(advance > 0) { 
            any_advance = true;
            if (advance > max_advance) {
                max_advance = advance;
                favorite = name;
            }
        }
    }

    if(!any_advance) {
        cout<<"suspicious"<<endl;
    } else {
        cout<<favorite<<endl;
    }

    return 0;
}
