#include<iostream>

using namespace std;
int T;
char g[300][300];
char i2c[3];
void init(){
  i2c[0] = 'b';
  i2c[1] = 'w';
  i2c[2] = 'w';
}

void solve(int n){
  int pos = n%3;
  int foo = pos;
  init();
  switch(pos){
  case(0):
    pos = (3-foo)%3;
    break;
  case(1):
    pos = foo;
    break;
  case(2):
    pos = (3 - (n-1)%3) %3;
  }

  //  cout<<"pos = "<<pos<<endl;

  //get top left
  for(int c = 0 ; c < n ; c++){
    for(int r = 0 ; r < n ; r++){
      g[r][c] = i2c[(pos+r)%3];
    }
    pos++;
  }
  //include row n col n
  int p1 = 0;
  
  for(int i = n ; i >= 0 ; i--){
    g[i][n] = g[n][i] = i2c[p1];
    p1 = (p1+1)%3;
  }
  

  

  // use symmetric

  //left down
  for(int r = n + 1 ; r < 2*n + 1 ; r++){
    for(int c = 0 ; c <= n ; c++){
      g[r][c] = g[n-(r-n)][c];
    }
  }

  //right up
  for(int c = n + 1 ; c < 2*n+1 ; c++){
    for(int r = 0 ; r <= n ; r++){
      g[r][c] = g[r][n-(c-n)];
    }
  }
  


  //right down

  for(int r = n+1 ; r < 2*n+1 ; r++){
    for(int c = n+1 ; c < 2*n+1; c++){
      g[r][c] = g[n-(r-n)][c]; 
    }
  }

  

  n = n * 2 + 1 ;
  //output
  for(int i = 0 ; i < n ; i ++){
    for(int j = 0 ; j < n ; j++){
      cout<<g[i][j];
    }
    cout<<endl;
  }
  
}








int run(){
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    solve(n);
  }
  
}
void test(){
  while(1){
    int n ;
    cin>>n;
    solve(n);
  }
}

int main(){
  //  test();
  run();
}
