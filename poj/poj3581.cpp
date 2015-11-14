#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define FOR(i,n) for(int (i) = 0 ; (i) < (n) ; i++)
#define FORR(i,s,n) for(int (i) = (s) ; (i) < (n) ; i++)
#define MAX_N (200001)
using namespace std;

////////////////////////////
// suffix array
int n , k ;
int rank[MAX_N+1];
int temp[MAX_N+1];

bool compare_sa(int i , int j){
  if( rank[i] != rank[j]) return rank[i] < rank[j];
  else{
    int ri = j+ k <= n ? rank[i+k]:-1;
    int rj = j+ k <= n ? rank[j+k]:-1;
    return ri<rj;
  }
}


void construct_sa(string S, int *sa){
  n = S.length();
  //initialize, for every char just use ASCII
  FOR(i,n+1){
    sa[i] = i;
    rank[i] = i<n?S[i]:-1;
  }
  // use k for 2*k
  for(int k = 1 ; k <= n ; k*=2){
    sort(sa, sa+n+1, compare_sa);

    temp[sa[0]] = 0;
    FORR(i,1,n+1){
      temp[sa[i]] = temp[sa[i-1]] + (compare_sa(sa[i-1] , sa[i])? 1 : 0);
    }
    FOR(i,n+1){
      rank[i] = temp[i];
    }
  }
}

void construct_sa(int * a , int nn , int* sa){
  n = nn;
  FOR(i,n+1){
    sa[i] = i;
    rank[i] = i < n ? a[i] : -1 ;
  }
  for(int k = 1 ; k <=n ; k*=2){
    sort(sa,sa+n+1,compare_sa);
    temp[sa[0]] = 0;
    FORR(i,1,n+1)
      temp[sa[i]] = temp[sa[i-1]] + (compare_sa(sa[i-1] , sa[i]) ? 1:0);
    FOR(i,n+1)
      rank[i] = temp[i];	
  }
  
}



///





//poj problem
int N,A[MAX_N];
int rev[MAX_N * 2], sa[MAX_N*2];

void solve(){
  //reverse A , compute its suffix array;
  reverse_copy(A , A + N , rev);
  construct_sa(rev, N , sa);

  //get the point of first segment
  int p1;
  FOR(i,N){
    p1 = N - sa[i];
    if(p1 >= 1 && N - p1 >= 2)break;
  }

  //reverse the string after p1 twice, compute suffix array again

  int m = N-p1;
  reverse_copy(A+p1 , A+N, rev);
  reverse_copy(A+p1, A+N, rev+m);
  construct_sa(rev, m*2 , sa);

  //get the second point

  int p2;
  for(int i = 0 ; i <= 2 * m ; i++){
    p2 = p1 + m - sa[i];
    if(p2 - p1 >= 1 && N -p2 >= 1) break;
  }
  reverse(A,A+p1);
  reverse(A+p1,A+p2);
  reverse(A+p2,A+N);
  FOR(i,N){
    cout<<A[i]<<endl;
  }
  
}

int main(){

  cin>>N;
  FOR(i,N){
    cin>>A[i];
  }
  solve();
  
}
