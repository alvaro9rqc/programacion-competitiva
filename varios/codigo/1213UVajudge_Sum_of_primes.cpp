#include <bits/stdc++.h>
#define bug1(x) cout<<#x<<" = "<<x<<endl
#define bug2(x,y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl
#define bug3(x,y,z) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<endl
#define bug4(x,y,z,m) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<" "<<#m<<" = "<<m<<endl

using namespace std;

template<class L, class R> 
ostream& operator<<(ostream &os, const pair<L,R> &input) {
    os << "(";
	os << input.first << "," << input.second;
	return os << ")";
}

template<class T> 
ostream& operator<<(ostream &os, const vector<T> &input) {
    os << "[ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "]";
}

template<class T> 
ostream& operator<<(ostream &os, const set<T> &input) {
    os << "{ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "}";
}

template<class T> 
ostream& operator<<(ostream &os, const unordered_set<T> &input) {
    os << "{ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "}";
}

template<class T> 
ostream& operator<<(ostream &os, const multiset<T> &input) {
    os << "{ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "}";
}

template<class T> 
ostream& operator<<(ostream &os, const unordered_multiset<T> &input) {
    os << "{ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "}";
}

template<class L, class R> 
ostream& operator<<(ostream &os, const map<L,R> &input) {
    os << "{ ";
    for(auto elem : input) { 
		os << "(" << elem.first << " , " << elem.second << ") ";
	}
	return os << "}";
}

template<class L, class R> 
ostream& operator<<(ostream &os, const unordered_map<L,R> &input) {
    os << "{ ";
    for(auto elem : input) { 
		os << "(" << elem.first << " , " << elem.second << ") ";
	}
	return os << "}";
}

#define ll long long
const int MAXN = 500005;
const int INF = 1e9;
const int MOD = 1e9 + 7;

// int memo[1025][1025][25];

class TaskE {
private:
int n;
vector<int> primes;
vector<vector<vector<int>>> memo;

int ways(int i, int leaftSum, int k) {
	if (i == primes.size()) {
		if (leaftSum == 0 && k == 0) {
			return 1;
		} else {
			return 0;
		}
	}
	if(memo[i][leaftSum][k] != -1) {
		return memo[i][leaftSum][k];
	} 
	int ans = 0;
	// considero el primo actual
	if (primes[i] <= leaftSum && k > 0){
		ans += ways(i+1, leaftSum - primes[i], k-1);
	}
	// no considero el primo actual
	ans += ways(i+1, leaftSum, k);

	return memo[i][leaftSum][k] = ans;
}

bool isPrime(int x) {
	for(int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

// generate primes up to n
void generatePrimes(int n) {
	for(int p = 2; p <= n; p++) {
		if(isPrime(p)) {
			primes.push_back(p);
		}
	}
}

public:
	void solveOne(int it){
		int k;
		cin >> n >> k;
		generatePrimes(n);
		// bug1(primes);
		// alternativamente un array
		memo.assign(primes.size(), vector<vector<int>>(n+1, vector<int>(k+1, -1)));
		cout << ways(0, n, k) << "\n";
	}

	void solve(){
		int tc = 1;
		// cin >> tc;
		for(int it = 1; it <= tc; it++){
			solveOne(it);
		}
	}
};


int main(){
	ios_base::sync_with_stdio(false);
	TaskE solver;
	solver.solve();
	return 0;
}
