#include<iostream>

using namespace std;

int N , M;
char g[200][200];
int dx[8] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
int dy[8] = {-1 ,  0 ,  1, -1 , 1 , -1 , 0 ,1};

void dfs(int r , int c){

  int nx , ny;
  g[r][c] = '.';
  for(int i = 0 ; i < 8 ; i++)
    for(int j = 0 ; j < 8 ; j++){
      nx = r+dx[i];
      ny = c+dy[i];
      if(nx<N && nx>=0 && ny<M && ny>=0 && g[nx][ny] == 'W'){
	dfs(nx,ny);
      }
    }
}

		      



int main(){
  int res = 0;
  cin>>N>>M;
  for(int i = 0 ; i < N ; i++)
    for(int j = 0 ; j < M ; j++){
      cin>>g[i][j];
    }
  for(int i = 0 ; i < N ; i++)
    for(int j = 0 ; j < M ; j++){
      if(g[i][j]=='W'){
	dfs(i,j);
	res++;
      }
    }
  
  cout<<res<<endl;

}
