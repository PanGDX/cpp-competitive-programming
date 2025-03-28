#include <iostream>
#include <vector>
using namespace std;



void init(vector<int> A, vector<int> B) {
	// your code here
	int curheight = a[L];
	int move;
	for(int i=L;i<=R;i++){
		
	}
}

int min_fuel(int L, int R) {
	// your code here
	
	return -1;
}



int main() {
	int N, Q, L, R;
	vector<int> A, B;
	cin >> N >> Q;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	init(A, B);
	for (int i = 0; i < Q; i++) {
		cin >> L >> R;
		cout << min_fuel(L, R) << '\n';
	}
}
