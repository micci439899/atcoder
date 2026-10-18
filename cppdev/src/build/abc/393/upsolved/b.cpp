# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++){
      for(int k = j+1; k < n; k++){
        if(j-i != k-j)continue;

        if(s.at(i) == 'A' && s.at(j) == 'B' && s.at(k) == 'C') cnt++;
      }
    }
  }

  cout << cnt << endl;




  return 0;

}











