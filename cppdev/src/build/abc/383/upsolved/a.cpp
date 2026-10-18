# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int n;
  cin >> n;

  int previous_t=0;
  int current_v=0;
  rep(i, n){
    int t, v;
    cin >> t >> v;
    if(previous_t > 0){
      current_v -= (t-previous_t);
    }
    if(current_v < 0){
      current_v = 0;
    }
    current_v += v;
    previous_t = t;
  }

  cout << current_v << endl;







  return 0;
}
