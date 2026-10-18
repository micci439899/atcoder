# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  //vector<int> a(7);

  unordered_map<int, int> um;
  rep(i, 7){
    int a;
    cin >> a;
    if(um.count(a)){
      um.at(a)++;
    } else {
      um[a] = 1;
    }
  }


  bool gt3 = false;
  bool gt2 = false;
  for(auto p : um) {
    if(p.second >= 3) {
      if(gt3){
        gt2 = true;
      }else{
        gt3 = true;
      }
    } else if(p.second >= 2) {
      gt2 = true;
    }
  }

  if(gt2 && gt3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }









  return 0;

}











