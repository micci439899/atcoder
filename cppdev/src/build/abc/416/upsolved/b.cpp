# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  string s;
  cin >> s;

  bool is_replaced = false;
  string t = "";
  for(auto c : s){
    if(c == '#'){
      t.push_back(c);
      is_replaced = false;
    }else{
      if(!is_replaced){
        t.push_back('o');
        is_replaced = true;
      }else{
        t.push_back(c);
      }
    }

  }

  cout << t << endl;



  return 0;

}


