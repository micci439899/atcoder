# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)



bool is_contained_t(int m, const vector<string> &s, const vector<string> &t, int sx, int sy){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++){
      if(s.at(sx+i).at(sy+j) != t.at(i).at(j)){
        return false;
      }
    }
  }
  return true;
}



int main() {
  int n, m;
  cin >> n >> m;

  vector<string> s(n);
  rep(i, n){
    cin >> s.at(i);
  }

  vector<string> t(m);
  rep(i, m){
    cin >> t.at(i);
  }

  for(int sx = 0; sx < n-m+1; sx++){
    for(int sy = 0; sy < n-m+1; sy++){
      if(is_contained_t(m, s, t, sx, sy)){
        cout << sx+1 << " " << sy+1 << endl;
        return 0;
      }
    }
  }



  return 0;

}











