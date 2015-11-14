#include<iostream>


using namespace std;


int main(){
  int cases;
  ios::sync_with_stdio(false);
  cin>>cases;
  while(cases--){
    int len , n ;
    cin>>len>>n;
    int ans1 = 1<<31, ans2 = -(1<<30);
    for(int i = 0 ; i < n ; i++){
      int x;
      cin>>x;
      int foo = min(len-x,x);
      int bar = max(len-x,x);
      ans1 = max(ans1,foo);
      ans2 = max(ans2,bar);
    }
    
    cout<<ans1<<' '<<ans2<<endl;
  }
}
