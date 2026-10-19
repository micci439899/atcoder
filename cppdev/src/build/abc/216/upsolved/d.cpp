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
  ll n, m;
  cin >> n >> m;

  // 各筒のqueue
  vector<queue<ll>> a(m);

  // 各ボールが筒の先頭であれば、筒の番号を保持
  vector<vector<ll>> top_balls(n);
  rep(i, m){
    ll k;
    cin >> k;

    rep(j, k){
      ll a_ij;
      cin >> a_ij;
      a_ij--;
      a.at(i).push(a_ij);
    }
    top_balls.at(a.at(i).front()).push_back(i);
  }

  // 取り出すことができるボール（の色）
  queue<ll> que;
  rep(i, n){
    if(top_balls.at(i).size() == 2){
      que.push(i);
    }
  }

  while(!que.empty()){
    ll ball = que.front(); que.pop();
    vector<ll> pipes = top_balls.at(ball);

    // debug(ball);
    // debug(pipes);

    for(ll pipe : pipes){
      queue<ll> &balls = a.at(pipe);
      balls.pop();
      if(!balls.empty()){
        top_balls.at(balls.front()).push_back(pipe);
        // debug(top_balls);
        if(top_balls.at(balls.front()).size() == 2){
          // cout << "push queue" << endl;
          que.push(balls.front());
        }
      }
    }
  }


  for(auto q : a){
    // 取り出せるだけ取り出した後、まだ残ってる筒があればNo
    if(!q.empty()){
      // debug(q.front());
      out_yn(false);
      return;
    }
  }
  out_yn(true);

}


int main() {

  solve();

  return 0;
}
