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


using namespace std;

int n ;
int a[2][101],b[101];


void read_data(){
  cin>>n;
  for(int i = 0 ; i < n - 1 ; i++){
    cin>>a[0][i];
  }
  for(int i = 0 ; i < n - 1 ; i++){
    cin>>a[1][i];
  }
  for(int i = 0 ; i < n ; i++){
    cin>>b[i];
  }
}

int computeDis(int c1 , int c2){
  int res = b[c1]+b[c2];
  int p1 = n-1;
  if(c1<c2)swap(c1,c2);
  int acc = 0;
  //end to first avenue
  while(p1>c1){
    acc += a[1][p1-1];
    p1--;
  }
  res+= acc*2;
  //shop to second avenue
  p1 = 0 ;
  acc = 0 ;
  while(p1<c2){
    acc+=a[0][p1];
    p1++;
  }
  res += acc*2;
  //between 2 avenues
  p1 = c2 ;
  while(p1<c1){
    res+= a[1][p1] + a[0][p1];
    p1++;
  }
  return res;
}


int solve(){
  int ans = 1<<30;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      if(i==j)continue;
      int res = computeDis(i,j);
      //cout<<"choose "<<i<<" and "<<j<<" avenue :"<< res<<endl;
      ans = min(ans,res);
    }
  }
  return ans;

}

int run(){
  read_data();
  cout<<solve()<<endl;
}


int main(){
    run();
}
