# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


int main() {
  int q;
  cin >> q;

  int paren_level = 0;
  string prev = "";
  bool is_ng = false;

  while(q--) {
    int q_type;
    cin >> q_type;

    if(q_type == 1) {
      string q_s;
      cin >> q_s;
      prev = q_s;

      if(q_s == "(") {
        paren_level++;
      } else if(q_s == ")") {
        paren_level--;
      } else {
        assert(false);
      }
    } else if(q_type == 2) {

      if(prev == "(") {
        paren_level--;
      } else if(prev == ")") {
        paren_level++;
      } else {
        assert(false);
      }
    } else {
      assert(false);
    }

    //cout << "is_ng:" << is_ng << endl;
    //cout << "paren_level: " << paren_level << endl;

    // 一度でもマイナスになると以降NG
    //if(is_ng = false && paren_level < 0){
    if(paren_level < 0){
      //cout << "aaa" << endl;
      is_ng = true;
    }

    if(is_ng){
      out_yn(false);
    } else {
      out_yn(paren_level == 0);
    }

  }


  return 0;  
}
