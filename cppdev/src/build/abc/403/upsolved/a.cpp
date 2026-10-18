# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int N;
  cin >> N;

  int ans = 0;
  rep(i, N) {
    int a;
    cin >> a;
    if(i%2==1)continue;
    ans += a;
  }



  cout << ans << endl;





  return 0;
}
