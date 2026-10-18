#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      if (j - i == A.at(i) + A.at(j)) {
        cnt++;
      }
    }
  }
  
  cout << cnt << endl;

  
}
