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

  string s = "";
  vector<int> a{0};
  vector<int> b{0};

  while(q--){
    int q_type;
    cin >> q_type;

    if(q_type == 1){
      char c;
      cin >> c;
      int level = c == '(' ? 1 : -1;
      a.push_back(a.back() + level);
      b.push_back(min(b.back(), a.back()));
      s.push_back(c);
    }else{
      a.pop_back();
      b.pop_back();
      s.pop_back();
    }

    out_yn(a.back() == 0 && b.back() >= 0);
  }

  return 0;  
}
