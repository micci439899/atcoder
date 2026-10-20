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

const ll INFL = LONG_LONG_MAX - 1;

void calculate_dist(ll u, vector<vector<ll>> &g, vector<ll> &dist){
  queue<ll> q;
  q.push(u);
  dist.at(u) = 0;

  while(!q.empty()){
    ll from = q.front(); q.pop();
    for(ll to : g.at(from)){
      if(dist.at(to) == INFL){
        dist.at(to) = dist.at(from) + 1;
        q.push(to);
      }
    }
  }
}

ll find_tree_diameter(ll n, vector<vector<ll>> &g){
  vector<ll> dist0(n, INFL);
  calculate_dist(0, g, dist0);

  ll max_dist0 = -1;
  ll max_id0 = -1;
  rep(i, n){
    if(max_dist0 < dist0.at(i)){
      max_dist0 = dist0.at(i);
      max_id0 = i;
    }
  }

  vector<ll> dist1(n, INFL);
  calculate_dist(max_id0, g, dist1);

  return *max_element(dist1.begin(), dist1.end());
}


void solve(){
  ll n;
  cin >> n;

  vector<vector<ll>> g(n);
  vector<ll> a(n);
  rep(i, n-1){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }

  ll diameter = find_tree_diameter(n, g);

  cout << diameter+1 << endl;
}

int main() {

  solve();

  return 0;  
}
