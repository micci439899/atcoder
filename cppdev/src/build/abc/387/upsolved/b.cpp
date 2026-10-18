# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int x;
  cin >> x;

  int ans = 0;
  for(int i = 1; i <= 9; i++){
    for(int j = 1; j <= 9; j++){
      if(i*j == x)continue;

      ans += i*j;
    }
  }

  cout << ans << endl;




  return 0;

}











