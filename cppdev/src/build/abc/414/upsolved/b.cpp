#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;

  int total_len = 0;
  string ans = "";  
  for (int i = 0; i < N; i++) {
    string c;
    int l;
    cin >> c >> l;
    
    total_len += l;
    if(total_len > 100) {
      cout << "Too Long" << endl;
      return 0;
    }
    for (int j = 0; j < l; j++) {
      ans += c;
    }

  }
  cout << ans << endl;
  
}
