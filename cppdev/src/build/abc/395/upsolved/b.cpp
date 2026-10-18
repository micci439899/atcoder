# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int n;
  cin >> n;

  vector<string> ans(n);
  rep(i, n) {
    string s = "";
    rep(j, n){
      s.push_back('#');
    }
    ans.at(i) = s;
  }

  for(int i = 1; 2*i < n+1; i++) {
    for(int j = i; j < n-i; j++) {
      if(i%2==0){
        ans.at(i).at(j) = '#';
        ans.at(j).at(i) = '#';
        ans.at(n-i-1).at(j) = '#';
        ans.at(j).at(n-i-1) = '#';
      } else {
        ans.at(i).at(j) = '.';
        ans.at(j).at(i) = '.';
        ans.at(n-i-1).at(j) = '.';
        ans.at(j).at(n-i-1) = '.';
      }
    }
  }

  rep(i, n){
    cout << ans.at(i) << endl;
  }






  return 0;

}











