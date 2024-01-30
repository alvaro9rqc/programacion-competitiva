#include <bits/stdc++.h>

using namespace std;
	

const int INF = 1e9;

int getMaxElement(const vector<int>& nums) {
	if (nums.empty()) {
		// lanzar un tipo de error
		return -INF;
	}
	int maxi = nums[0]; 
	for (auto val : nums) {
		maxi = max(maxi, val);
	}
	return maxi;
}

int main (){
	// para acelrar la lectura y salida del cin y cout
	ios_base::sync_with_stdio(false);
	
	vector<int> nums = {2, -1, 0, 9};
	cout << "recorrer el array a traves de su indice\n";
	for (int i = 0 ; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	nums[1] = 5;
	// nums = [2, 5, 0 , 9] 
	cout << "version simplificada de recorrer por valor\n";
	for (auto val : nums) {
		cout << val << " ";
	}
	cout << endl;
	//         it,	,   ,   ,it.end()
	// nums = [2 , 5, 0 , 9] 
	cout << "recorrer el array con un iterador\n";
	for(auto it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	int maxi = *max_element(nums.begin(), nums.end());
	cout << "usando la funcion *max_element del STL del C++ = " << maxi << endl;
	cout << "usando la funcion getMaxElement implementada por nosotros = " << getMaxElement(nums) << endl;	

	nums.assign(3, 100);
	// nums = [100, 100, 100]
	vector<int> nums2(10);
	nums2.push_back(12);
	// nums2 = [12]
	nums2.push_back(-23);
	// nums2 = [12, -23]


	vector<vector<int>> nums2d = {{1, 2 , 3}, {4 , 5, 6}, {7, 8, 9}};
	       0  1  2 columnas
	// 0   1, 2, 3
	// 1   4, 5, 6
	// 2   7, 8, 9
	cout << nums2d[1][2] << endl;
	for(int row = 0; row < nums2d.size(); row++) {
		for(int col = 0; col < nums2d[row].size(); col++) {
			cout << nums2d[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
	


	return 0;	
}