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

const ll INFL = LONG_LONG_MAX/4;

void solve(){
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> dist(n+1, vector<ll>(n+1, INFL));
  rep(i, n+1) dist.at(i).at(i) = 0;
  rep(i, m){
    ll a, b, c; cin >> a >> b >> c;
    a--; b--;
    chmin(dist.at(a).at(b), c);
    chmin(dist.at(b).at(a), c);
  }

  ll k, t; cin >> k >> t;
  rep(i, k){
    ll d; cin >> d; d--;
    chmin(dist.at(d).at(n), t);
    chmin(dist.at(n).at(d), 0LL);
  }

  rep(kk, n+1)rep(i, n+1)rep(j, n+1){
    chmin(dist.at(i).at(j), dist.at(i).at(kk) + dist.at(kk).at(j));
  }

  ll q; cin >> q;
  while(q--){
    int type; cin >> type;

    if(type == 1){
      ll x, y, tt; cin >> x >> y >> tt; x--; y--;
      chmin(dist.at(x).at(y), tt);
      chmin(dist.at(y).at(x), tt);

      rep(i, n+1)rep(j, n+1){
        chmin(dist.at(i).at(j), dist.at(i).at(x) + dist.at(x).at(y) + dist.at(y).at(j));
        chmin(dist.at(i).at(j), dist.at(i).at(y) + dist.at(y).at(x) + dist.at(x).at(j));
      }
    }else if(type == 2){
      ll x; cin >> x; x--;
      chmin(dist.at(x).at(n), t);
      chmin(dist.at(n).at(x), 0LL);

      rep(i, n+1)rep(j, n+1){
        chmin(dist.at(i).at(j), dist.at(i).at(x) + dist.at(x).at(n) + dist.at(n).at(j));
        chmin(dist.at(i).at(j), dist.at(i).at(n) + dist.at(n).at(x) + dist.at(x).at(j));
      }
    }else{
      ll sm = 0;
      rep(i, n)rep(j, n) sm += dist.at(i).at(j) == INFL ? 0 : dist.at(i).at(j);
      cout << sm << endl;
    }
  }


}

int main() {

  solve();

  return 0;
}
