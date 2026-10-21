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
  ll n, k; cin >> n >> k;

  vector<ll> h(n);
  rep(i, n) cin >> h.at(i);

  vector<ll> top;
  rep(i, n-2){
    if(h.at(i) < h.at(i+1) && h.at(i+1) > h.at(i+2)){
      top.push_back(i+1);
    }
  }

  if(top.size() == 0){
    cout << 0 << endl;
  }

  // debug(top);

  ll ans = 0;
  rep(i, top.size()){
    ll idx = top.at(i);

    int j = idx-1;
    while(j >= 0 && h.at(j) < h.at(j+1)){
      j--;
      if(j < 0){
        j = 0;
        break;
      }
    }


    int kk = idx+1;
    while(kk+1 < h.size() && h.at(kk) > h.at(kk+1)){
      kk++;
      if(kk >= h.size()){
        kk = h.size()-1;
        break;
      }
    }

    // debug(h.at(j));
    // debug(h.at(idx));
    // debug(h.at(k));
    ll mi = min(h.at(j), h.at(kk));
    ll diff = h.at(idx) - mi;

    if(diff < k) continue;

    ll len = kk-j+1;
    // debug(j);
    // debug(idx);
    // debug(kk);
    ans = max(ans, len);
  }

  cout << ans << endl;


/*
  ll inc_cnt = 0;
{
  ll s_idx = 0;
  rep(i, n-1){
    if(h.at(i) < h.at(i+1)){
      inc_cnt = max(inc_cnt, i-s_idx);
    }else{
      s_idx = i+1;
    }
  }
}

  ll dec_cnt = 0;
{
  ll s_idx = 0;
  rep(i, n-1){
    if(h.at(i) > h.at(i+1)){
      dec_cnt = max(inc_cnt, i-s_idx);
    }else{
      s_idx = i+1;
    }
  }
}
*/





}



int main() {

  solve();

  return 0;
}
