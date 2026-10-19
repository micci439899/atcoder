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

  vector<pll> train(n, {-1, -1});
  while(q--){
    int type; cin >> type;

    if(type == 1){
      ll x, y; cin >> x >> y;
      x--; y--;
      train.at(x).second = y;
      train.at(y).first = x;
      // cout << 1 << endl;
      // debug(train);
    }else if(type == 2){
      ll x, y; cin >> x >> y;
      x--; y--;
      train.at(x).second = -1;
      train.at(y).first = -1;
      // cout << 2 << endl;
      // debug(train);
    }else{
      ll x; cin >> x;
      x--;

      // debug(x);
      // debug(train);
      // debug(train.at(x));

      ll prev_idx = train.at(x).first;
      stack<ll> stk;
      // while(prev_idx >= 0 && train.at(prev_idx).first >= 0){
      while(prev_idx >= 0){
        // debug(prev_idx);
        stk.push(prev_idx);
        prev_idx = train.at(prev_idx).first;
      }

      ll next_idx = train.at(x).second;
      queue<ll> que;
      // while(next_idx >= 0 && train.at(next_idx).second >= 0){
      while(next_idx >= 0){
        // debug(next_idx);
        que.push(next_idx);
        next_idx = train.at(next_idx).second;
      }

      ll prev_sz = stk.size();
      ll next_sz = que.size();

      cout << prev_sz + next_sz + 1;
      while(!stk.empty()){
        ll idx = stk.top(); stk.pop();
        cout << " " << idx+1;
      }
      cout << " " << x+1;
      while(!que.empty()){
        ll idx = que.front(); que.pop();
        cout << " " << idx+1;
      }
      cout << endl;
    }
  }
}

int main() {

  solve();

  return 0;
}
