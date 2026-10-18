#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  string S;
  cin >> N >> A >> B >>S;
  
  for (int i = A; i < N - B; i++) {
    cout << S.at(i);
  }
  
  cout << endl;

 

  
}