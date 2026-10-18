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
  ll n, q; cin >> n >> q;

  vector<vector<pll>> ev(q);

  while(q--){
    ll l, r, x; cin >> l >> r >> x;
    l--; r--; x--;
    ev.at(x).emplace_back(l, 1);
    ev.at(x).emplace_back(r+1, -1);
  }

  vector<ll> ans(n+1, 0);
  rep(i, ev.size()){
    if(ev.at(i).size() == 0) continue;
    sort(ev.at(i).begin(), ev.at(i).end());

    rep(j, ev.at(i).size()-1){
      ev.at(i).at(j+1).second += ev.at(i).at(j).second;
      if(ev.at(i).at(j).second){
        ans.at(ev.at(i).at(j).first)++;
        ans.at(ev.at(i).at(j+1).first)--;
      }
    }
  }
  rep(i, ans.size()-1){
    ans.at(i+1) += ans.at(i);
  }

  rep(i, ans.size()-1){
    if(i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
}

int main() {

  solve();

  return 0;
}
