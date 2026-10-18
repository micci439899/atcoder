# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int n, d;
  cin >> n >> d;

  vector<int> t(n);
  vector<int> l(n);
  rep(i, n){
    cin >> t.at(i) >> l.at(i);
  }

  rep(i, d){
    int max_value = 0;
    rep(j, n){
      max_value = max(max_value, t.at(j) * (l.at(j)+i+1));
    }
    cout << max_value << endl;
  }



  return 0;

}











