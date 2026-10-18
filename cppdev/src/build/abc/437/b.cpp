# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  vector<vector<int>> a(h, vector<int>(w, 0));
  rep(i, h)rep(j, w) cin >> a.at(i).at(j);

  vector<int> b(n);
  rep(i, n) cin >> b.at(i);

  int ma = 0;
  rep(i, h){
    int res = 0;
    rep(j, w){
      auto it = find(b.begin(), b.end(), a.at(i).at(j));
      if(it != b.end())res++;
    }
    ma = max(res, ma);
  }

  cout << ma << endl;




  return 0;
}


