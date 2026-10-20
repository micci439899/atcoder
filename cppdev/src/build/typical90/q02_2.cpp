# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

bool is_valid_parenthesis_sequence(string &s){
  int paren_level = 0;
  for(auto c : s){
    if(c == '(') {
      paren_level++;
    }else if(c == ')'){
      paren_level--;
    }else{
      assert(true);
    }

    if(paren_level < 0) return false;
  }

  return paren_level == 0;
}

int main() {
  int n;
  cin >> n;

  if(n%2 == 1) return 0;

  vector<string> ans;
  for(int i = 0; i < 1<<n; i++){

    string s;
    for(int j = n-1; j >= 0; j--){
      if((i & 1<<j) == 0){
        s += '(';
      }else{
        s += ')';
      }
    }

    if(is_valid_parenthesis_sequence(s)){
      ans.push_back(s);
    }
  }

  rep(i, ans.size()){
    cout << ans.at(i) << endl;
  }

  return 0;  
}
