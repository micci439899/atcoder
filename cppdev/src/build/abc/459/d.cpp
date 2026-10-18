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
  ll t; cin >> t;

  while(t--){
    string s; cin >> s;

    vector<pair<ll, char>> cnt(26);
    rep(i, 26) cnt.at(i) = {0, 'a'+i};
    for(char c : s){
      cnt.at(c-'a').first++;
    }
    sort(cnt.rbegin(), cnt.rend());

    string t = "";

    priority_queue<pair<ll, char>> pq;
    rep(i, cnt.size())if(cnt.at(i).first > 0) pq.push(cnt.at(i));
    pair<ll, char> prv = pq.top(); pq.pop();
    t += prv.second;
    pair<ll, char> new_cur = prv;
    new_cur.first--;
    if(new_cur.first > 0) pq.push(new_cur);

    while(!pq.empty()){
      bool is_same = pq.top().second == prv.second;

      if(is_same && pq.size() > 1){
        pair<ll, char> ma = pq.top(); pq.pop();
        while(!pq.empty() && pq.top().first == prv.first){
          pair<ll, char> cur = pq.top(); pq.pop();
          t += cur.second;
          cur.first--;
          if(cur.first > 0) pq.push(cur);
        }

        pair<ll, char> cur = pq.top(); pq.pop();
        t += cur.second;
        cur.first--;
        if(cur.first > 0) pq.push(cur);

        pq.push(ma);
      }else{
        while(pq.top().first == prv.first){
          pair<ll, char> cur = pq.top(); pq.pop();
          t += cur.second;
          cur.first--;
          if(cur.first > 0) pq.push(cur);
        }

        pair<ll, char> cur = pq.top(); pq.pop();
        t += cur.second;
        cur.first--;
        if(cur.first > 0) pq.push(cur);

      }
    }


/*
    priority_queue<pair<ll, char>> pq;
    rep(i, cnt.size())if(cnt.at(i).first > 0) pq.push(cnt.at(i));
    pair<ll, char> prv = pq.top(); pq.pop();
    t += prv.second;
    pair<ll, char> new_cur = prv;
    new_cur.first--;
    if(new_cur.first > 0) pq.push(new_cur);

    while(!pq.empty()){
      while(pq.top().first == prv.first){
        pair<ll, char> cur = pq.top(); pq.pop();
        t += cur.second;
        cur.first--;
        if(cur.first > 0) pq.push(cur);
      }

      pair<ll, char> cur = pq.top(); pq.pop();
      t += cur.second;
      cur.first--;
      if(cur.first > 0) pq.push(cur);
    }
    debug(t);
*/

/*
    int idx = 0;
    while(cnt.at(0).first > 0){
      t += cnt.at(idx).second;
      cnt.at(idx).first--;
      idx++;
      if(cnt.at(idx).first == 0)idx=0;
    }
*/
    bool is_ok = true;
    rep(i, t.size()-1){
      if(t.at(i+1) == t.at(i)){
        is_ok = false;
        break;
      }
    }

    if(is_ok){
      out_yn(true);
      cout << t << endl;
    }else{
      out_yn(false);
    }
  }



}

int main() {

  solve();

  return 0;
}
