# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n){
    cin >> a.at(i);
  }

  rep(i, n-2){
    if(a.at(i) * a.at(i+2) != a.at(i+1) * a.at(i+1)){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;



  return 0;

}











