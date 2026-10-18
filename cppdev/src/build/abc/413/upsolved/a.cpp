#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  int sm = 0;
  for (int i = 0; i < N; i++) {
    int a_i;
    cin >> a_i;
    sm += a_i;
  }
  
  if (sm <= M) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  


}