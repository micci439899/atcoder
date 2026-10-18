# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int n, r;
  cin >> n >> r;

  vector<int> d(n);
  vector<int> a(n);
  rep(i, n){
    cin >> d.at(i) >> a.at(i);
  }

  rep(i, n){
    if(d.at(i) == 1){
      if(1600 <= r && r <= 2799){
        r += a.at(i);
      }
    } else {
      if(1200 <= r && r <= 2399){
        r += a.at(i);
      }
    }
  }

  cout << r << endl;






  return 0;

}











