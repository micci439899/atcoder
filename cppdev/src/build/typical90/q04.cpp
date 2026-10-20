# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> a(h, vector(w, 0));
  rep(j, h)rep(i, w){
    cin >> a.at(j).at(i);
  }

  vector<int> h_sum(h);
  rep(j, h){
    int sm = 0;
    rep(i, w){
      sm += a.at(j).at(i);
    }
    h_sum.at(j) = sm;
  }

  vector<int> w_sum(w);
  rep(i, w){
    int sm = 0;
    rep(j, h){
      sm += a.at(j).at(i);
    }
    w_sum.at(i) = sm;
  }

  vector<vector<int>> b(h, vector(w, 0));
  rep(j, h)rep(i, w){
    b.at(j).at(i) = h_sum.at(j) + w_sum.at(i) - a.at(j).at(i);
  }

  print_vec2d(b);

  return 0;  
}
