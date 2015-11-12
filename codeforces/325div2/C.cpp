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

using namespace std;
int n, v[MAX_N], d[MAX_N], p[MAX_N];
vector<int> ans;
bool flag[MAX_N];
queue<int> cryq;

void read_data(){
  cin>>n;
  for(int i = 0 ; i < n ; i++){
    cin>>v[i]>>d[i]>>p[i];
  }
  
}



void inroom(int idx){
  int c = 0;
  int pos = idx+1;
  while(pos<n && c<v[idx]){
    if(flag[pos]){
      pos++;
      continue;
    }
    else{
      c++;
      p[pos] -= v[idx] - c;
      if(p[pos] < 0 ){
	flag[pos] = true;
	cryq.push(pos);
      }
      pos++;
    }
  }
}

void cry(int idx){
  for(int i = idx + 1 ; i < n ; i++){
    if(flag[i])continue;
    p[i]-=d[idx];
    if(p[i]<0){
      flag[i] = true;
      cryq.push(i);
    }
  }
}

void all_cry(){
  cout<<"in all cry"<<endl;
  while(!cryq.empty()){
    int idx = cryq.front();
    cryq.pop();
    cry(idx);
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
    inroom(idx);
    all_cry();
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
