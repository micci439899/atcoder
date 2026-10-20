# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

ll base_n_to_10(string s, int base){
  reverse(s.begin(), s.end());

  ll res = 0;
  ll n = 1;
  for(auto c : s){
    res += (ll)(c - '0') * n;
    n *= (ll)base;
  }
  return res;
}

string base_10_to_n(ll value, int base){
  if(value == 0){
    return "0";
  }

  string s = "";
  while(value > 0){
    ll r = value % (ll)base;
    value /= (ll)base;
    s += to_string(r);
  }

  reverse(s.begin(), s.end());
  return s;
}

void replace_8_5(string &s){
  rep(i, s.size()){
    if(s.at(i) == '8'){
      s.at(i) = '5';
    }
  }
}


int main() {
  string s;
  cin >> s;

  int k;
  cin >> k;

  rep(i, k){
    ll val10 = base_n_to_10(s, 8);
    string val9 = base_10_to_n(val10, 9);
    replace_8_5(val9);
    s = val9;
  }

  cout << s << endl;






  return 0;  
}
