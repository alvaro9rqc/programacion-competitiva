#include <bits/stdc++.h>
using namespace std;

string tr(const vector<string>& tk) {
    unordered_map<string, int> lastOc;
    string res;
    for (int i = 0; i < tk.size(); i++) {
        if (tk[i].size() == 1 && isalpha(tk[i][0])) {
            if (lastOc.find(tk[i]) == lastOc.end()) {
                res += "0 ";
            } else {
                res += to_string(i - lastOc[tk[i]]) + " ";
            }
            lastOc[tk[i]] = i;
        } else {
            res += tk[i] + " ";
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<string> suffixes;

    for (int i = 0; i < n; i++) {
        suffixes.emplace_back(tr(vector<string>(arr.begin() + i, arr.end())));
    }

    sort(suffixes.begin(), suffixes.end());

    int q;
    cin >> q;
    while (q--) {
        int ql;
        cin >> ql;
        vector<string> qtk(ql);
        for (int i = 0; i < ql; i++) {
            cin >> qtk[i];
        }
        string trQ = tr(qtk);
        auto it = lower_bound(suffixes.begin(), suffixes.end(), trQ);
        if (it != suffixes.end() && it->substr(0, trQ.size()) == trQ) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
