# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int f(int x){
  int res = 0;
  while(true){
    res += x%10;
    x = x/10;
    if(x == 0)break;
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n+1);
  rep(i, n+1){
    int a_i = 0;
    if(i == 0){
      a_i = 1;
    }else{
      int f_res = 0;
      for(int j = 0; j < i; j++){
        // cout << j << ":" << f(a.at(j)) << endl;
        f_res += f(a.at(j));
      }
      a_i = f_res;
    }
    a.at(i) = a_i;
  }

  cout << a.back() << endl;

  // out_vec(a);


/*
  vector<int> a;
  a.push_back(1);
  for(int i = 1; i < n+1; i++){
    int a_i = 0;
    for(int j = 0; j < i; j++){
      a_i += j == 0 ? a.at(0) : f(j);
      cout << "f(A_" << j << "):" << a_i << endl;
    }
    a.push_back(a_i);
  }

  out_vec(a);

  int ans = a.back();

  cout << ans << endl;
*/



  return 0;
}


