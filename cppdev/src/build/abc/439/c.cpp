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


void solve(){
  ll n;
  cin >> n;

  vector<ll> sq;
  for(int i = 1; i*i <= n; i++){
    sq.push_back(i*i);
  }
  set<ll> st;
  for(ll x_i = 0; x_i<sq.size(); x_i++){
    ll x = sq.at(x_i);
       // debug(x);
    for(ll y_i = x_i+1; y_i<sq.size(); y_i++){
      ll y = sq.at(y_i);
      // debug(y);
  // for(ll x = 1; x*x <= n/2; x++){
  //   for(ll y = x+1; y*y <= n; y++){
      // ll m = x*x + y*y;
       ll m = x + y;
      if(m > n)continue;
      if(st.count(m)){
        st.erase(m);
      }else{
        st.insert(m);
      }
    }
  }
  vector<ll> ans{st.begin(), st.end()};
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  out_vec(ans);

/*
  vector<ll> sq;
  for(int i = 1; i*i <= n; i++){
    sq.push_back(i*i);
  }

  out_vec(sq);

  set<ll> ans;
  for(int m = 2; m*m <= n; m++){
    for(int y = 1; y*y <= m; y++){
      int x_sq = m - y*y;
      if(x_sq >= y*y) continue;
      auto it = lower_bound(sq.begin(), sq.end(), x_sq);

      if(*it == x_sq){
        debug(m);
        debug(x_sq);
        if(ans.count(m)){
          ans.erase(m);
        }else{
          ans.insert(m);
        }
      }

      //ll n_ans = i*i + (*it)*(*it);
      //if(*it == x) debug(i); debug(*it);
    }

  }

  vector<ll> ans_vec{ans.begin(), ans.end()};
  sort(ans_vec.begin(), ans_vec.end());

  out_vec(ans_vec);
*/
}

int main() {

  solve();

  return 0;  
}
