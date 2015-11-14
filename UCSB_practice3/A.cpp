// Pacific Northwest Region Problem A
// 11/06/2015
#include <cstdio>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t) {
    t--;
    int total = 0;
    int n;
    double distance;
    scanf("%d %lf", &n, &distance);
    while(n) {
      n--;
      int velocity, fuel, consump;
      scanf("%d %d %d", &velocity, &fuel, &consump);
      if(consump*distance/velocity <= fuel)
	total++;
    }
  printf("%d\n", total);
  }
  return 0;    
}
