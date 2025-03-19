#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
const int MAX = 1e5 + 5;
 
int a[MAX];
vector <int> gaps;
 
int main() {
	int n, m, k;
	cin >> n>> m >> k;
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	}
	
	int worst_case = a[n-1] - a[0] + 1;
	
	for(int i = 0; i < n - 1; i++){
	    gaps.push_back(a[i+1] - a[i] - 1);
	}
	
	sort(gaps.rbegin(), gaps.rend());
	
	long long sub = 0LL;
	for(int i = 0; i < k - 1; i++){
	    sub += gaps[i];
	}
	
	long long answer = worst_case - sub;
	cout << answer;
	return 0;
}