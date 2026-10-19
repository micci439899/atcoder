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
int ctoi(char c){return int(c-'0');}
char itoc(int x){return x+'0';}

const int INF = INT_MAX/2;

vector<string> rotate(vector<string> &s){
  vector<string> ans = s;
  rep(i, s.size())rep(j, s.at(i).size()){
    ans.at(s.size()-j-1).at(i) = s.at(i).at(j);
  }
  return ans;
}

void solve(){
  ll n;
  cin >> n;

  vector<string> s(n);
  rep(i, n) cin >> s.at(i);

  vector<string> t(n);
  rep(i, n) cin >> t.at(i);

  int sx_min = INF, sx_max = -1, sy_min = INF, sy_max = -1;

  rep(i, s.size())rep(j, s.at(i).size()){
    if(s.at(i).at(j) == '#'){
      chmin(sx_min, j);
      chmax(sx_max, j);
      chmin(sy_min, i);
      chmax(sy_max, i);
    }
  }

  rep(k, 4){
    t = rotate(t);
    int tx_min = INF, tx_max = -1, ty_min = INF, ty_max = -1;

    rep(i, t.size())rep(j, t.at(i).size()){
      if(t.at(i).at(j) == '#'){
        chmin(tx_min, j);
        chmax(tx_max, j);
        chmin(ty_min, i);
        chmax(ty_max, i);
      }
    }

    bool is_same_range = sx_max - sx_min == tx_max - tx_min && sy_max - sy_min == ty_max - ty_min;
    if(!is_same_range) continue;

    int x_offset = tx_max - sx_max;
    int y_offset = ty_max - sy_max;

    bool is_ok = true;
    for(int i = sy_min; i <= sy_max; i++){
      for(int j = sx_min; j <= sx_max; j++){
        if(s.at(i).at(j) != t.at(i + y_offset).at(j + x_offset)){
          is_ok = false;
          break;
        }
      }
    }

    if(is_ok){
      out_yn(true);
      return;
    }
  }

  out_yn(false);

}

int main() {

  solve();

  return 0;  
}
