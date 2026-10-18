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

const ll INFL = LONG_LONG_MAX/2;

void solve(){
  ll x, q; cin >> x >> q;

  vector<ll> med;
  med.push_back(x);
  // vector<ll> med(5);
  // med.at(0) = -INFL;
  // med.at(1) = -INFL;
  // med.at(2) = x;
  // med.at(3) = INFL;
  // med.at(4) = INFL;

  min_priority_queue<ll> pq;
  pq.push(x);

  while(q--){
    ll a, b; cin >> a >> b;

    med.push_back(a);
    med.push_back(b);
    sort(med.begin(), med.end());

    if(med.size()>5){
      vector<ll> med2;
      rep(i, med.size()){{
        if(i == 0 || i == med.size()-1)continue;
        med2.push_back(med.at(i));
      }}
      med = med2;
    }

/*
    int l_cnt = 0;
    int u_cnt = 0;
    if(med.size() > 5){
      if(a < med.at(med.size()/2)){
        l_cnt++;
        // med.pop_back();
      }else{
        u_cnt++;
        // med.erase(med.begin());
      }
      if(b < med.at(med.size()/2)){
        l_cnt++;
        // med.pop_back();
      }else{
        u_cnt++;
        // med.erase(med.begin());
      }
    }
    debug(med.at(med.size()/2));
    debug(med.size());
    debug(med);
    debug(l_cnt);
    debug(u_cnt);
    while(l_cnt--)med.erase(med.begin());
    while(u_cnt--)med.pop_back();

    debug(med);
*/
    cout << med.at(med.size()/2) << endl;
  }

}

int main() {

  solve();

  return 0;
}
