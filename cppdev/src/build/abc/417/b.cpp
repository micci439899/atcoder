#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> A(N);
  vector<int> B(M);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < M; i++) {
    cin >> B.at(i);
  }

  int idx = 0;  
  for (int i = 0; i < M; i++) {
    for (int j = idx; j < N; j++) {
      if(B.at(i) == A.at(j)) {
        //cout << "found B_i:" << B.at(i) << " i:" << i << " j:" << j << endl;
        A.at(j) = -1;
        //idx = j+1;
        break;
      }
    }
  }
  
  vector<int> C;
  for (int i = 0; i < N; i++) {
    if (A.at(i) > 0) {
      C.push_back(A.at(i));
    }
  }
  if ((int)C.size() == 0) {
    return 0;
  }

  for (int i = 0; i < (int)C.size(); i++) {
      cout << C.at(i);
    if (i != N - 1) {
      cout << " ";
    }
  }
  cout << endl;
  
  return 0;

}