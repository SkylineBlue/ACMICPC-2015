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
bool dp[100][100][100];

void init(){
  for(int i = 0 ; i < 3 ; i++)
    ts[i].clear();
  for(int i = 0 ; i < 100 ; i++)
    for(int j = 0 ; j < 100 ; j++)
      for(int k = 0 ; k < 100 ; k++)
	dp[i][j][k] = false;
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
  cout<<"start row="<<sr<<endl;
  for(int i = 0 ; i < 3 ; i++){
    cout<<"row "<<i<<endl;
    for(int j = 0 ; j < ts[i].size() ; j++)
      cout<<"start="<< ts[i][j].F<<" end="<<ts[i][j].S<<endl;
  }
}

bool check(int t , int r , int c){
  for(int i = 0 ; i < ts[r].size() ; i++){
    int st = ts[r][i].F-2*(t-1);
    int end = ts[r][i].S-2*(t-1);
    if(st<=c&&c<=end)return false;
  }
  // cout<<"checked"<<" t="<<t<<" r="<<r<<" c="<<c<<endl;
  return true;  
}

void fill_dp(int t){
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < ts[i].size(); j++){
      int st = ts[i][j].F - 2*(t) , end = ts[i][j].S - 2*(t);
      for(int k = st ; k <=end ; k++){
	dp[t][i][k] = false;
      }
    }
  }
}
bool cb(int r , int c){
  return 0<=r && r< 3 && 0<=c && c<n;
}


void print_dp(int t){

  cout<<"at "<<t<<" second"<<endl;
  cout<<"dp table:"<<endl;
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < n ; j++){
      cout<<dp[t][i][j]<<' ';
    }
    cout<<endl;
  }
  cout<<"end dp table"<<endl;
}
void solve(){
  //set initial state
  dp[sr][0] = true;

  for(int c = 0 ; c < n ; c++){
    
  }
  cout<<"NO"<<endl;
}




int main(){
  init();
  read_data();
  process_data();
  solve();
}
