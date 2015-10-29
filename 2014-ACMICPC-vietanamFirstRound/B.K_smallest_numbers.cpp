#include<iostream>

using namespace std;

typedef long long ll;
void solve(ll N ,ll K , ll S , ll C1 ,ll C2, ll M)
{
  ll A1 = S;
  ll *a = new ll[M];
  for(int i = 0 ; i < M ; i++)a[i] = 0;
  if(S<M) a[S]++;
  for(int i = 1 ; i < N ; i++){
    A1 = (C1 *A1 +C2) % M;
    a[A1]++;
  }

  //output
  ll pos = 0;
  ll c = 0;
  while(pos<M && c<K){
    for(int i = 0 ; c<K && i <a[pos] ; i++){
      cout<<pos<<' ';
      c++;
    }
    pos++;
  }
  if(c<K)cout<<S;
  cout<<endl;
  delete a;
}







int main(){
  ios::sync_with_stdio(false);
  ll T;
  cin>>T;
  
  for(int i = 0 ; i< T ; i++){
    ll N,K,S,C1,C2,M;
    cin>>N>>K>>S>>C1>>C2>>M;
    solve(N,K,S,C1,C2,M);
  }
}
