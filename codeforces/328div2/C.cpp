#include<iostream>
#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll x , ll y){
  return x==0?y:gcd(y%x,x);
}
ll Min(ll x, ll y){
  return y<x?y:x;
}


int main(){
  ll r, s1 ,s2 ;
  cin>>r>>s1>>s2;
  ll p1 = min(s1,s2);
  ll d = gcd(s1,s2);
  double bar = (double)s1/d*s2;
  ll ans;
  if(bar>5e18+1){
    ans = min(p1-1,r);
  }
  else{
    ll dd = s1/d*s2;
    ll foo = r/dd;
    ans = foo * (1 + p1 - 1) - 1;
    ans +=  Min(r%dd+1,p1);
  }
  
  d = gcd(ans,r);

  cout<<ans/d<<'/'<<r/d<<endl;
}
