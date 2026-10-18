#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> ss(h);
  rep(i, h){
    cin >> ss.at(i);
  }

  int min_h = 1000;
  int max_h = 0;
  int min_w = 1000;
  int max_w = 0;

  rep(i, h){
    rep(j, w){
      if(ss.at(i).at(j) == '#'){
        min_h = min(min_h, i);
        max_h = max(max_h, i);
        min_w = min(min_w, j);
        max_w = max(max_w, j);
      }
    }
  }

  for(int i = min_h; i < max_h+1; i++){
    for(int j = min_w; j < max_w+1; j++){
      if(ss.at(i).at(j) == '.'){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
  
}
