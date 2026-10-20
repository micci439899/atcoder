# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

bool is_orderable(vector<int> &v, set<pair<int, int>> st){
  rep(i, v.size()-1){
    int x = min(v.at(i), v.at(i+1));
    int y = max(v.at(i), v.at(i+1));

    pair<int, int> p = make_pair(x, y);
    if(st.count(p)){
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n, 1));
  rep(i, n)rep(j, n) cin >> a.at(i).at(j);

  int m;
  cin >> m;

  set<pair<int, int>> xy;
  rep(i, m){
    int x, y;
    cin >> x >> y;
    pair<int, int> p = make_pair(x, y);
    xy.insert(p);
  }

  // athletes: 1 ~ n
  vector<int> athletes(n);
  iota(athletes.begin(), athletes.end(), 1);

  int ans = INT_MAX/2;

  // 計算値があるか（組み合わせがあるか）
  bool has_score = false;

  do{
    if(!is_orderable(athletes, xy)) continue;

    has_score = true;
    int score = 0;
    rep(i, n){
      score += a.at(athletes.at(i)-1).at(i);
    }
    ans = min(ans, score);

  }while(next_permutation(athletes.begin(), athletes.end()));

  if(has_score){
    cout << ans << endl;
  }else{
    cout << -1 << endl;
  }

  return 0;  
}
