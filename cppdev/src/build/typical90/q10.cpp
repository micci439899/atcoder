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

  vector<int> c(n);
  vector<int> p(n);
  rep(i, n){
    cin >> c.at(i) >> p.at(i);
  }

  vector<int> cum_sum1(n+1, 0);
  vector<int> cum_sum2(n+1, 0);

  for(int i = 0; i < n; i++){
    if(c.at(i) == 1){
      cum_sum1.at(i+1) = cum_sum1.at(i) + p.at(i);
      cum_sum2.at(i+1) = cum_sum2.at(i);
    }else{
      cum_sum1.at(i+1) = cum_sum1.at(i);
      cum_sum2.at(i+1) = cum_sum2.at(i) + p.at(i);
    }
  }

  int q;
  cin >> q;

  rep(i, q){
    int l, r;
    cin >> l >> r;
    int a = cum_sum1.at(r) - cum_sum1.at(l-1);
    int b = cum_sum2.at(r) - cum_sum2.at(l-1);
    cout << a << " " << b << endl;
  }


  return 0;  
}
