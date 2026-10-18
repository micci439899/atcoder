# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h){
    cin >> s.at(i);
  }


  bool is_one_row = h == 1;
  bool is_one_col = w == 1;
  bool has_sharp = false;

  int ans = 0;
  rep(i, h){
    rep(j, w){
      if(s.at(i).at(j) != '#'){
        continue;
      }

      has_sharp = true;

      //cout << "i: " << i << " j: " << j << endl;

      bool is_first_row = i == 0;
      bool is_last_row = i == h-1;
      bool is_first_col = j == 0;
      bool is_last_col = j == w-1;

      int cnt = 0;

      if(is_first_row && is_last_row && is_first_col && is_last_col){
        //if(s.at(i).at(j-1) == '#') cnt++;
        //if(s.at(i).at(j+1) == '#') cnt++;
        //if(s.at(i-1).at(j) == '#') cnt++;
        //if(s.at(i+1).at(j) == '#') cnt++;

      } else if(is_first_row && is_last_row && is_first_col && !is_last_col){
        //if(s.at(i).at(j-1) == '#') cnt++;
        if(s.at(i).at(j+1) == '#') cnt++;
        //if(s.at(i-1).at(j) == '#') cnt++;
        //if(s.at(i+1).at(j) == '#') cnt++;

      } else if(is_first_row && is_last_row && !is_first_col && is_last_col){
        if(s.at(i).at(j-1) == '#') cnt++;
        //if(s.at(i).at(j+1) == '#') cnt++;
        //if(s.at(i-1).at(j) == '#') cnt++;
        //if(s.at(i+1).at(j) == '#') cnt++;

      } else if(is_first_row && is_last_row && !is_first_col && !is_last_col){
        if(s.at(i).at(j-1) == '#') cnt++;
        if(s.at(i).at(j+1) == '#') cnt++;
        //if(s.at(i-1).at(j) == '#') cnt++;
        //if(s.at(i+1).at(j) == '#') cnt++;

      } else if(is_first_row && !is_last_row && is_first_col && is_last_col){
        //if(s.at(i).at(j-1) == '#') cnt++;
        //if(s.at(i).at(j+1) == '#') cnt++;
        //if(s.at(i-1).at(j) == '#') cnt++;
        if(s.at(i+1).at(j) == '#') cnt++;

      } else if(is_first_row && !is_last_row && is_first_col && !is_last_col){
        //if(s.at(i).at(j-1) == '#') cnt++;
        if(s.at(i).at(j+1) == '#') cnt++;
        //if(s.at(i-1).at(j) == '#') cnt++;
        if(s.at(i+1).at(j) == '#') cnt++;

      } else if(is_first_row && !is_last_row && !is_first_col && is_last_col){
        if(s.at(i).at(j-1) == '#') cnt++;
        //if(s.at(i).at(j+1) == '#') cnt++;
        //if(s.at(i-1).at(j) == '#') cnt++;
        if(s.at(i+1).at(j) == '#') cnt++;

      } else if(is_first_row && !is_last_row && !is_first_col && !is_last_col){
        if(s.at(i).at(j-1) == '#') cnt++;
        if(s.at(i).at(j+1) == '#') cnt++;
        //if(s.at(i-1).at(j) == '#') cnt++;
        if(s.at(i+1).at(j) == '#') cnt++;

      } else if(!is_first_row && is_last_row && is_first_col && is_last_col){
        //if(s.at(i).at(j-1) == '#') cnt++;
        //if(s.at(i).at(j+1) == '#') cnt++;
        if(s.at(i-1).at(j) == '#') cnt++;
        //if(s.at(i+1).at(j) == '#') cnt++;

      } else if(!is_first_row && is_last_row && is_first_col && !is_last_col){
        //if(s.at(i).at(j-1) == '#') cnt++;
        if(s.at(i).at(j+1) == '#') cnt++;
        if(s.at(i-1).at(j) == '#') cnt++;
        //if(s.at(i+1).at(j) == '#') cnt++;

      } else if(!is_first_row && is_last_row && !is_first_col && is_last_col){
        if(s.at(i).at(j-1) == '#') cnt++;
        //if(s.at(i).at(j+1) == '#') cnt++;
        if(s.at(i-1).at(j) == '#') cnt++;
        //if(s.at(i+1).at(j) == '#') cnt++;

      } else if(!is_first_row && is_last_row && !is_first_col && !is_last_col){
        if(s.at(i).at(j-1) == '#') cnt++;
        if(s.at(i).at(j+1) == '#') cnt++;
        if(s.at(i-1).at(j) == '#') cnt++;
        //if(s.at(i+1).at(j) == '#') cnt++;

      } else if(!is_first_row && !is_last_row && is_first_col && is_last_col){
        //if(s.at(i).at(j-1) == '#') cnt++;
        //if(s.at(i).at(j+1) == '#') cnt++;
        if(s.at(i-1).at(j) == '#') cnt++;
        if(s.at(i+1).at(j) == '#') cnt++;

      } else if(!is_first_row && !is_last_row && is_first_col && !is_last_col){
        //if(s.at(i).at(j-1) == '#') cnt++;
        if(s.at(i).at(j+1) == '#') cnt++;
        if(s.at(i-1).at(j) == '#') cnt++;
        if(s.at(i+1).at(j) == '#') cnt++;

      } else if(!is_first_row && !is_last_row && !is_first_col && is_last_col){
        if(s.at(i).at(j-1) == '#') cnt++;
        //if(s.at(i).at(j+1) == '#') cnt++;
        if(s.at(i-1).at(j) == '#') cnt++;
        if(s.at(i+1).at(j) == '#') cnt++;

      } else if(!is_first_row && !is_last_row && !is_first_col && !is_last_col){
        if(s.at(i).at(j-1) == '#') cnt++;
        if(s.at(i).at(j+1) == '#') cnt++;
        if(s.at(i-1).at(j) == '#') cnt++;
        if(s.at(i+1).at(j) == '#') cnt++;
      }




      if(cnt == 2 || cnt == 4) ans++;



    }
  }

  if(!has_sharp){
    cout << "Yes" << endl;
    return 0;
  }

  if(ans > 0){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }




  return 0;

}


