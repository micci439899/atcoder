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

const ll INFL = LONG_LONG_MAX/2;

void solve(){
  ll t;
  cin >> t;

  while(t--){
    ll n, d;
    cin >> n >> d;

    vector<ll> a(n);
    rep(i, n) cin >> a.at(i);
    vector<ll> b(n);
    rep(i, n) cin >> b.at(i);


    vector<pll> c(n);
    rep(i, n){
      c.at(i) = {a.at(i), b.at(i)};
    }

    queue<pll> q;
    q.emplace(c.at(0).first - c.at(0).second, 0);

    ll rem = 0;
    for(int i = 1; i < n; i++){
      // debug(rem);
      pll ab = c.at(i);
      rem += ab.first;
      rem -= ab.second;

      ll diff = rem > ab.second ? ab.first : ab.first - (rem - ab.second);
      q.push({diff, i});

      while(!q.empty() && i - q.front().second > d){
        // debug(q.front());
        rem -= q.front().first;
        q.pop();
        // pll ab = q.front(); q.pop();
      }
    }

    while(!q.empty()){
      // debug(q.front());
      rem += q.front().first; q.pop();
    }

    cout << rem << endl;



    /*

    ll day = 0;
    ll rem = 0;
    queue<pll> q;
    // while(!q.empty()){
    rep(i, n){
      // pll ab = q.front();
      // q.pop();

      pll ab = c.at(i);
      rem += ab.first;
      rem -= ab.second;

      ll diff = rem > ab.second ? ab.first : ab.first - (rem - ab.second);

      q.push(diff, i);

      while()

    }
    */





  }






}

int main() {

  solve();

  return 0;  
}
