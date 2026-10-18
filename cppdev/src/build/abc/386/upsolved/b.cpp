# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  string s;
  cin >> s;


  int i=0;
  int ans=0;
  while(true){
    if(i > s.size()-1)break;

    if(i <= s.size()-2 && s.at(i) == '0' && s.at(i+1) == '0'){
      i += 2;
    } else {
      i++;
    }
    ans++;
  }

  cout << ans << endl;



  return 0;

}











