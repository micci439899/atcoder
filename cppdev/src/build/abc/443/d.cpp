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
    ll n;
    cin >> n;

    ll mi = INFL;

    vector<bool> is_pushed(n, false);

    queue<ll> q;
    vector<ll> r(n);

    rep(i, n){
      ll r_i;
      cin >> r_i;
      r_i--;
      r.at(i) = r_i;

      if(r_i == 0){
        is_pushed.at(i) = true;
        q.push(i);
      }

      chmin(mi, r_i);
    }

    ll ans = 0;
    if(mi != 0){
      rep(i, n){
        r.at(i) -= mi;
        if(r.at(i) == 0){
          is_pushed.at(i) = true;
          q.push(i);
        }
      }
      // ans += (mi * n);
    }


    while(!q.empty()){
      ll idx = q.front(); q.pop();

      // debug(idx);

      if(idx != 0 && idx != n-1){
        ll r_p = r.at(idx-1);
        if(r_p - r.at(idx) > 1){
          ans += r_p - r.at(idx) - 1;
          r.at(idx - 1) = r.at(idx) + 1;
        }

        ll r_n = r.at(idx+1);
        if(r_n - r.at(idx) > 1){
          ans += r_n - r.at(idx) - 1;
          r.at(idx + 1) = r.at(idx) + 1;
        }

        if(!is_pushed.at(idx+1)){
          q.push(idx+1);
          is_pushed.at(idx+1) = true;
        }
        if(!is_pushed.at(idx-1)){
          q.push(idx-1);
          is_pushed.at(idx-1) = true;
        }

        // cout << "both" << endl;
        // debug(r.at(idx));
      }else if(idx == 0){
        ll r_n = r.at(idx+1);
        if(r_n - r.at(idx) > 1){
          ans += r_n - r.at(idx) - 1;
          r.at(idx + 1) = r.at(idx) + 1;
          //q.push(idx+1);
        }

        // cout << "0" << endl;
        // debug(r.at(idx));

      }else{
        ll r_p = r.at(idx-1);
        if(r_p - r.at(idx) > 1){
          ans += r_p - r.at(idx) - 1;
          r.at(idx - 1) = r.at(idx) + 1;
          //q.push(idx-1);
        }
        // cout << "n-1" << endl;
        // debug(r.at(idx));
      }
    }

    cout << ans << endl;
  }




}


int main() {

  solve();

  return 0;
}
