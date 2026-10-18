#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  
  long long ans = 0;
  map<int, int> m;
  for (int i = 0; i < N; i++) {
    int a_i;
    cin >> a_i;
    
    if(m.count(i + a_i)) {
      m[i + a_i]++;
    } else {
      m[i + a_i] = 1;
    }
    
    if(m.count(i - a_i)) {
      ans += m[i - a_i];
    }
  }
  
  cout << ans << endl;
  

}