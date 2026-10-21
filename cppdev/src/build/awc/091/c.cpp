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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

void solve(){
  ll h, w, q; cin >> h >> w >> q;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  vector<vector<bool>> is_front(h, vector<bool>(w, false));

  ll ans = 0;
  rep(i, h)rep(j, w){
    if(s.at(i).at(j) != 'B') continue;
    rep(k, 4){
      int ni = i + dy.at(k);
      int nj = j + dx.at(k);
      if(!is_within(nj, ni, w, h)) continue;
      if(s.at(ni).at(nj) == 'R'){
        is_front.at(i).at(j) = true;
        ans++;
        break;
      }
    }
  }

  while(q--){
    ll u, d, l, r; cin >> u >> d >> l >> r;
    u--;d--;l--;r--;
    for(int i = u; i <= d; i++)for(int j = l; j <= r; j++){
      if(s.at(i).at(j) == 'E'){
        s.at(i).at(j) = 'R';
        if(i == u || i == d || j == l || j == r){
          rep(k, 4){
            int ni = i + dy.at(k);
            int nj = j + dx.at(k);
            if(!is_within(nj, ni, w, h)) continue;
            if(s.at(ni).at(nj) == 'B' && !is_front.at(ni).at(nj)){
              is_front.at(ni).at(nj) = true;
              ans++;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
}



int main() {

  solve();

  return 0;
}
