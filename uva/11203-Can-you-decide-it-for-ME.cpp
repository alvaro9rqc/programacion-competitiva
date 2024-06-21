#include <bits/stdc++.h> 
using namespace std;
int main () {
  //string s = "??M?E???";
  //regex r(R"(^\?+M\?+E\?+)");

  //if (regex_search(s, r)) 
  //  cout << "El string contiene al menos un signo de interrogación\n";

  int n;
  cin >> n;
  string line;
  getline(cin, line);
  smatch match;
  regex r(R"((^\?+)M(\?+)E(\?+))");
  while (n--) {
    getline(cin, line);
    if (regex_match(line, match, r))
    {
      //cout << match[1].str() << " " << match[1].str().size() << '\n';
      //cout << match[2].str() << " " << match[2].str().size() << '\n';
      //if (match[1].str().size() == match[2].str().size() - 1)
      if (( match[1].str().size() + match[2].str().size() ) == match[3].str().size())
      {
        cout << "theorem\n";
        continue;
      }
    }
    cout << "no-theorem\n";
  }
  return 0;
}

