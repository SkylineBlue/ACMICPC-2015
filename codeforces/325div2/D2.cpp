#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#define F first
#define S second
#define pb push_back
#define P pair<int,int> 
using namespace std;
int t , n , k;
char cg[100][100];
int sr;
vector<P > ts[3];
bool dp[100][100];

void init(){
  for(int i = 0 ; i < 3 ; i++)
    ts[i].clear();
  for(int i = 0 ; i < 100 ; i++)
    for(int j = 0 ; j < 100 ; j++)
     	dp[i][j] = false;
  sr = -1;
}

void read_data(){
  cin>>n>>k;
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < n ; j++){
      cin>>cg[i][j];
      if(cg[i][j]=='s')sr = i;
    }
  }
}

void process_data(){
  for(int i = 0 ; i < 3 ; i++){
    int j = 0 ;
    while(j<n){
      if('A'<=cg[i][j] && cg[i][j] <='Z'){
	int st = j;
	while(j+1<n && cg[i][j] == cg[i][j+1])j++;
	int end = j;
	ts[i].pb(P(st,end));
      }
      j++;
    }
  }
  /*
  cout<<"start row="<<sr<<endl;
  for(int i = 0 ; i < 3 ; i++){
    cout<<"row "<<i<<endl;
    for(int j = 0 ; j < ts[i].size() ; j++)
      cout<<"start="<< ts[i][j].F<<" end="<<ts[i][j].S<<endl;
      }
  */
}

bool check(int r , int c){
  int t = c ;
  for(int i = 0 ; i < ts[r].size() ; i++){
    int st = ts[r][i].F-2*(t-1);
    int end = ts[r][i].S-2*(t-1);
    if(st<=c&&c<=end)return false;
  }
  // cout<<"checked"<<" t="<<t<<" r="<<r<<" c="<<c<<endl;
  return true;  
}

bool cb(int r , int c){
  return 0<=r && r< 3 && 0<=c && c<n;
}

void fill_dp(int c ){
  int t = c ;
  for(int i = 0 ; i <3 ; i ++){
    for(int j = 0 ; j < ts[i].size() ; j++){
      int s = max(0,ts[i][j].F-t*2);
      int e = max(0,ts[i][j].S-t*2);
      for(int k = s ; k <= e ; k++){
	dp[i][k] = false;
      }
    }
  }
}

void print_dp(int t){
  cout<<"time="<<t<<" dp_table:"<<endl;
  for(int i = 0 ; i < 3 ; i ++){
    for(int j = 0 ; j < n ; j ++){
      cout<<dp[i][j]<<' ';
    }
    cout<<endl;
  }
}
void solve(){
  //set initial state
  dp[sr][0] = true;

  for(int c = 1 ; c < n ; c++){
    for(int r = 0 ; r < 3 ; r ++){
      if(!check(r,c))continue;
      dp[r][c] |= cb(r,c-1) && dp[r][c-1];
    }
    for(int r = 0  ; r< 3 ; r++){
      if(!check(r,c))continue;
      dp[r][c] |= cb(r+1,c-1) && dp[r+1][c] && dp[r+1][c-1];
      dp[r][c] |= cb(r-1,c-1) && dp[r-1][c] && dp[r-1][c-1];

      if(c==n-1 && dp[r][c]){
	cout<<"YES"<<endl;
	return;
      }
    }
    /*
    cout<<"before fill:"<<endl;
    print_dp(c);
    */
    fill_dp(c);
    /*
    cout<<"after fill:"<<endl;
       print_dp(c);
    */
  }
   cout<<"NO"<<endl;
}




int run(){
  init();
  read_data();
  process_data();
  solve();
}

int main(){
  cin>>t;
  while(t--){
    run();
  }
}
