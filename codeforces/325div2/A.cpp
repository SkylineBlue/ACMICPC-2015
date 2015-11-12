#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#define pb(x) push_back(x)
#define P pair<int,int>
#define X first
#define Y second


using namespace std;

int n , a[1000];

void read_data(){
  cin>>n;
  for(int i = 0 ; i < n ; i++)
    cin>>a[i];
}

int solve(){
  int res = n;
  int pos = 0 ;
  int end = n - 1 ;
  while(pos<=end && a[pos]==0){
    pos++;
    res--;
  }
  while(pos<=end && a[end]==0){
    end--;
    res--;
  }
  while(pos<end){
    if(a[pos]==1){
      pos++;
      continue;
    }
    else{
      if(a[pos+1]==0)
	res--;
      while(pos<end && a[pos+1]==0){
	res--;
	pos++;
      }
      pos++;
    }
      
    
  }
  return res;	

}

int run(){
  
  read_data();
  int ans = solve();
  cout<<ans<<endl;
}
int main(){
    run();
}
