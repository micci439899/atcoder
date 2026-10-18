# include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << " " << x << " " << endl;

template<class T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T&a, T b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T&a, T b){if(b<a){a=b;return true;}return false;}

template<class T, class U>ostream&operator<<(ostream&os, pair<T,U>p){os<<"("<<p.first << "," << p.second<<")";return os;}
template<class T>ostream&operator<<(ostream&os, const vector<T>&v){os<<"[";for(int i = 0; i < v.size(); i++){cout << v.at(i);if(i != v.size()-1){cout << ",";}}os<<"]";return os;}
template<class T>ostream&operator<<(ostream&os, const set<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void solve(){
  int n, m; cin >> n >> m;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  vector<int> b(n-1);
  rep(i, n-1) cin >> b.at(i);

  const int INF = 1<<30;
  int ans = INF;
  rep(k, 2){
    vector<int> x = a;
    x.at(0) = k;
    rep(i, n-1){
      x.at(i) = (x.at(i) + x.at(i+1))%m;
    }
    int res = 0;
    rep(i, n){
      if(a.at(i) != x.at(i)) res++;
    }
    chmin(ans, res);
  }
  cout << ans << endl;
/*
  int n, m; cin >> n >> m;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  vector<int> b(n-1);
  rep(i, n-1) cin >> b.at(i);

  vector<int> x(n-1);
  rep(i, n-1){
    x.at(i) = (a.at(i) + a.at(i+1))%m;
  }

  debug(x);

  vector<int> dp(n-1, 0);
  rep(i, n-1){
    ll c = (a.at(i) + a.at(i+1))%m;
    if(b.at(i) != c){

    }
  }
*/

/*
  vector<vector<int>> dp(2, vector<int>(n-1. 0));
  rep(i, n-2){
    if(x.at(i) != b.at(i) && x.at(i+1) != b.at(i+1)){
      dp.at(0).at(i+1) = 
    }else{
      dp.at(0).at(i+1) = dp.at(0).at(i);
      dp.at(1).at(i+1) = dp.at(1).at(i);
    }
  }
*/
/*
  rep(i, n-2){
    if(x.at(i) == b.at(i) && x.at(i+1) == b.at(i+1)) continue;

    if(x.at(i) == b.at(i+1) && x.at(i+1) == b.at(i)) ans+=2;
    else ans+=1;
  }
  cout << ans << endl;
*/
}



int main() {

  solve();

  return 0;
}
