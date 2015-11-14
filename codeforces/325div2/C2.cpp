#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stdlib.h>
#define pb(x) push_back(x)
#define P pair<int,int>
#define X first
#define Y second
#define MAX_N (4000)
#define LIMIT 1000000
using namespace std;
int n, v[MAX_N], d[MAX_N], p[MAX_N];
vector<int> ans;
bool flag[MAX_N];
void read_data(){
  cin>>n;
  for(int i = 0 ; i < n ; i++){
    cin>>v[i]>>d[i]>>p[i];
  }
  
}


void check(int idx){
  int acc = 0;
  int c = 0 ;
  for(int i = idx + 1 ; i < n ; i++){
    if(flag[i])continue;
    p[i] -= max(0,(v[idx]-c)) + acc;
    if(p[i]<0){
      flag[i] = true;
      if(acc<LIMIT)acc += d[i];
    }
    c++;
  }
}


int solve(){
  //  cout<<"solving..."<<endl;
  int idx = 0;
  while(idx < n){
    if(flag[idx]){
      idx++;
      continue;
    }
    ans.pb(idx);
    check(idx);
    idx++;
  }
}

void run(){
  read_data();
  solve();
  cout<<ans.size()<<endl;
  for(int i = 0 ; i < ans.size() ; i++){
    cout<<ans[i]+1<<' ';
  }
  cout<<endl;
	     
}
int main(){
  run();
}
