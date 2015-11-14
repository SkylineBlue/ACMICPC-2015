// Pacific Northwest Region Problem G
// 11/06/2015
#include <cstdio>
using namespace std;

long long tribValue[68] = {0};

long long tribblenacci(int n) {
  if(tribValue[n])
    return tribValue[n];
  else {
    long long curr = tribblenacci(n-1) + tribblenacci(n-2) + tribblenacci(n-3) + tribblenacci(n-4);
    tribValue[n] = curr;
    return curr;
  }
}
  
int main() {
  tribValue[0] = 1;
  tribValue[1] = 1;
  tribValue[2] = 2;
  tribValue[3] = 4;
  int total;
  scanf("%d", &total);
  while(total) {
    total--;
    int n;
    scanf("%d", &n);
    long long trib = tribblenacci(n);
    printf("%lld\n", trib);
  }

  return 0;    
}
