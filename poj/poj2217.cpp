#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<cstring>
#define MAX_L (100000)
#define maxn 30000
using namespace std;
struct Suffix
{
    int r[maxn];
    int sa[maxn],rank[maxn],height[maxn];
    int t[maxn],t2[maxn],c[maxn],n,m;
    void init(string s)
    {
        n=s.size();
        for(int i=0;i<n;i++) r[i]=(int)s[i];
        m=128;
    }
    int cmp(int *r,int a,int b,int l) {return r[a]==r[b]&&r[a+l]==r[b+l];}
    void build()
    {
        int i,k,p,*x=t,*y=t2;
        r[n++]=0;
        for (i=0; i<m; i++) c[i]=0;
        for (i=0; i<n; i++) c[x[i]=r[i]]++;
        for (i=1; i<m; i++) c[i]+=c[i-1];
        for (i=n-1; i>=0; i--) sa[--c[x[i]]]=i;
        for (k=1,p=1; k<n; k*=2,m=p)
        {
            for (p=0,i=n-k; i<n; i++) y[p++]=i;
            for (i=0; i<n; i++) if (sa[i]>=k) y[p++]=sa[i]-k;
            for (i=0; i<m; i++) c[i]=0;
            for (i=0; i<n; i++) c[x[y[i]]]++;
            for (i=1; i<m; i++) c[i]+=c[i-1];
            for (i=n-1; i>=0; i--) sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;
            x[sa[0]]=0;
            for (i=1; i<n; i++) x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?p-1:p++;
        }
        n--;
    }
    void LCP()
    {
        int i,j,k=0;
        for (i=1; i<=n; i++) rank[sa[i]]=i;
        for (i=0; i<n; i++)
        {
            if (k) k--;
            j=sa[rank[i]-1];
            while (r[i+k]==r[j+k]) k++;
            height[rank[i]]=k;
        }
    }
    int LCS(string s1,string s2)
    {
        int len=s1.size();
        s1=s1+"$"+s2;
        init(s1);
        build();
        LCP();
        int ans=0;
        for(int i=2;i<=n;i++)
            if((sa[i-1]<len)!=(sa[i]<len)) ans=max(ans,height[i]);
        return ans;
    }
};

int sa[MAX_L], lcp[MAX_L];
int rank[MAX_L+1];
int temp[MAX_L+1];

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

int solve(){

  //cout<<"S="<<S<<" T="<<T<<endl;
  int s1 = S.length();
  S += '\0' + T;
  construct_sa(S,sa);
  for(int i = 0 ; i < n ; i++) //cout<<"sa["<<i<<"]="<<sa[i]<<endl;
  construct_lcp(S,sa,lcp);

  int ans = 0 ;
  for(int i = 0 ; i < S.length() ; i++){
    //cout<<"lcp="<<lcp[i]<<endl;
    if ((sa[i] < s1) != (sa[i+1] <s1)){
      ans = max(ans,lcp[i]);
    }
    
  }
  //  cout<<"Nejdelsi spolecny retezec ma delku "<<ans<<"."<<endl;
  return ans;
}

string SS ,TT;
void generate_data(){
  int n = 1000;
  T = S = "";
  
  for(int i = 0 ; i < n ; i++){
    S += (char)(65+rand()%26);
    T += (char)(65+rand()%26);
  }
  SS = S;
  TT = T;
  // cout<<"S="<<S<<" T="<<T<<endl;

}





void test(){
  generate_data();
  Suffix s;
  int r2 = s.LCS(SS,TT);
  int r1 = solve();
  cout<<"r1="<<r1<<" r2="<<r2<<endl;
  cout<< (r1==r2?"TRUE":"FALSE") << endl;
}

int main(){
  srand(time(0));
  for(int i = 0; i < 20 ; i++)
    test();
}

/*

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  Suffix s;
  getline(cin,S);
  while(t--){
    getline(cin,S);
    getline(cin,T);
    solve();
  
  }
}

*/
