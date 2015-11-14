#include<iostream>

using namespace std;
string S , T;
int n , k ;
bool compare_sa(int i , int j){
  if( rank[i] != rank[j]) return rank[i] < rank[j];
  else{
    int ri = j+ k <= n ? rank[i+k]:-1;
    int rj = j+ k <= n ? rank[j+k]:-1;
    return ri<rj;
  }
}
int compare_sa(const void* pi , const void* pj){
  int i = * ((int*)pi) , j = *((int*)pj);
  
  if(rank[i]<rank[j])
    return 1;

  if(rank[i]>rank[j])
    return -1;

  int ri = i+k <= n ? rank[i + k] : -1;
  int rj = j+k <= n ? rank[j + k] : -1;
  if(ri<rj)
    return 1;
  else
    return -1;
}
void construct_sa(string S, int* sa ){
  n = S.length();
  //initialize
  for(int i = 0; i <= n ; i++){
    sa[i] = i;
    rank[i] = i < n ? S[i] : -1;
  } 
  //compute suffix array;
  for(int k = 1 ; k <= n ; k = k* 2){
    //int (*pf)(const void*,const void*) = compare_sa;
    //qsort(sa, n + 1, sizeof(sa[0]), pf);
    bool (*pf)(int,int) = compare_sa;
    sort(sa,sa+n+1,pf);
    temp[sa[0]] = 0;
    for(int i = 1 ; i <= n ; i++){
      temp[sa[i]] = temp[sa[i-1]] + (compare_sa(sa[i-1],sa[i])? 1 : 0);
    }
    for(int i = 0 ; i <= n ; i++){
      rank[i] = temp[i];
    }
  }
}


void construct_lcp(string S ,int *sa, int* lcp){
  int n = S.length();
  for(int i = 0 ; i <= n ; i++)
    rank[sa[i]] = i;

  int h = 0 ;
  lcp[0] = 0;
  for(int i = 0 ; i < n ; i++){
    int j = sa[rank[i] -1];

    if(h>0) h--;
    for(; j + h < n && i + h < n; h++){
      if (S[j+h] != S[i+h]) break;
    }

    lcp[rank[i]-1] = h;
  }  
}
