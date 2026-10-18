#include <bits/stdc++.h>
using namespace std;


int main() {
  // 入力を受け取る
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.at(i) = a;
  }
  int X;
  cin >> X;
  
  bool hasX = false;
  for (int i = 0; i < N; i++) {
    if (A.at(i) == X) {
      hasX = true;
      break;
    }
  }
  if(hasX) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}