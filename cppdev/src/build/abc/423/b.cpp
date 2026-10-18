# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

int main() {
  int n;
  cin >> n;

  vector<int> l(n);
  rep(i, n){
    cin >> l.at(i);
  }

  bool is_first = true;
  int f_idx = -1;
  int l_idx = -1;

  rep(i, n){
    if(l.at(i) == 1){
      if(is_first){
        f_idx = i;
        is_first = false;
      }
      l_idx = i;
    }
  }

  if(f_idx == -1){
    cout << 0 << endl;
  }else if(f_idx == l_idx){
    cout << 0 << endl;
  }else{
    cout << l_idx - f_idx << endl;
  }

  return 0;
}


