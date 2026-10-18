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

const ll INFL = 1LL<<60;

void solve(){
  ll n, q; cin >> n >> q;

  vector<vector<pll>> g(n+1);
  vector<ll> a(2*n);
  rep(i, n){
    ll ai; cin >> ai;
    ll j = (i+1)%n;
    g.at(i).push_back({j, ai});
    g.at(j).push_back({i, ai});
    a.at(i) = ai;
    a.at(i+n) = ai;
  }

  rep(i, n){
    ll b; cin >> b;
    g.at(i).push_back({n, b});
    g.at(n).push_back({i, b});
  }

  vector<ll> cum_a(2*n+1, 0);
  rep(i, 2*n) cum_a.at(i+1) = cum_a.at(i) + a.at(i);

  vector<ll> dist(n+1, INFL);
  dist.at(n) = 0;

  min_priority_queue<pll> pq;
  pq.push({0, n});
  while(!pq.empty()){
    auto [d, v] = pq.top(); pq.pop();
    for(pll p : g.at(v)){
      auto [u, w] = p;
      ll nd = d + w;
      if(chmin(dist.at(u), nd)){
        pq.push({dist.at(u), u});
      }
    }
  }

  while(q--){
    ll s, t; cin >> s >> t;
    s--; t--;

    if(t == n){
      cout << dist.at(s) << endl;
    }else{
      ll cand1 = dist.at(s) + dist.at(t);
      ll cand2 = cum_a.at(t) - cum_a.at(s);
      ll cand3 = cum_a.at(s+n) - cum_a.at(t);
      ll mi = min(cand1, min(cand2, cand3));
      cout << mi << endl;
    }
  }
}

int main() {

  solve();

  return 0;
}