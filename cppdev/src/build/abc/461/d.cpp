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
  int h, w, k; cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  vector<vector<int>> cum_g(h+1, vector<int>(w+1, 0));
  rep(i, h)rep(j, w){
    int a = s.at(i).at(j) == '1' ? 1 : 0;
    cum_g.at(i+1).at(j+1) = a + cum_g.at(i+1).at(j) + cum_g.at(i).at(j+1) - cum_g.at(i).at(j);
  }

  // rep(i, h){
  //   debug(cum_g.at(i));
  // }

  ll ans = 0;
  rep(i, h)rep(j, w){
    for(int ii = i+1; ii < h+1; ii++)for(int jj = j+1; jj < w+1; jj++){
      if(cum_g.at(ii).at(jj) - cum_g.at(i).at(jj) - cum_g.at(ii).at(j) + cum_g.at(i).at(j) == k){
        ans++;
      }
    }
  }
  cout << ans << endl;

/*
  vector<vector<int>> imos(h+1, vector<int>(w+1, 0));

  rep(i, h)rep(j, w)if(s.at(i).at(j) == '1'){
    imos.at(i).at(j)

  }
*/



/*

  vector<vector<int>> cum_h(h, vector<int>(w+1, 0));
  vector<vector<int>> cum_w(w, vector<int>(h+1, 0));

  rep(i, h){
    vector<int> v(w+1, 0);
    rep(j, w){
      int a = s.at(i).at(j) == '1' ? 1 : 0;
      v.at(j+1) = v.at(j) + a;
    }
    cum_h.at(i) = v;
  }

  rep(j, w){
    vector<int> v(h+1, 0);
    rep(i, h){
      int a = s.at(i).at(j) == '1' ? 1 : 0;
      v.at(i+1) = v.at(i) + a;
    }
    cum_w.at(j) = v;
  }

  debug(cum_h);
  debug(cum_w);

  vector<vector<int>> cum_g(h+1, vector<int>(w+1, 0));

  rep(i, h+1)rep(j, w){
    cum_g.at(i+1).at(j) += cum_g.at(i).at(j);
  }



  ll ans = 0;
  rep(i, h)rep(j, w){


  }
*/

}

int main() {

  solve();

  return 0;
}
