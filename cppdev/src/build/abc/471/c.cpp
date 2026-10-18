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
  ll n; cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  set<ll> a_st;
  rep(i, n) a_st.insert(a.at(i));

  ll ans = 0;
  ll pos = 0;

  while(a_st.size() > 0){
    auto it = a_st.lower_bound(pos);
    if(it == a_st.end()){
      it--;
      ans += abs(*it - pos);
      pos = *it;
      a_st.erase(it);
    }else if(it != a_st.begin()){
      auto pre = it;
      pre--;
      ll dist1 = abs(*it - pos);
      ll dist2 = abs(*pre - pos);
      if(dist1 == dist2){
        ans += dist1;
        if(*it < *pre){
          pos = *it;
          a_st.erase(it);
        }else{
          pos = *pre;
          a_st.erase(pre);
        }
      }else if(dist1 < dist2){
        ans += abs(*it - pos);
        pos = *it;
        a_st.erase(it);
      }else{
        ans += abs(*pre - pos);
        pos = *pre;
        a_st.erase(pre);
      }
    }else{
      ans += abs(*it - pos);
      pos = *it;
      a_st.erase(it);
    }
  }

  cout << ans << endl;
}



int main() {

  solve();

  return 0;
}
