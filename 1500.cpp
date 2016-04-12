#include <iostream>
/*问题陈述：找出两个最接近给定合数的素数，使得一个大于该合数，一个小于该合数，求两个素数之间的间隔。实际上是要快速生成素数表，可以使用素数筛法。
素数筛法:1.最简单的情况是简单的线性筛法，但会出现重复。该思想是在考虑2的时候，将2*5这种情况也考虑进去（一个合数可以表示为若干个素数的乘积），而10在5*2的情况下也会被考虑，因此出现重复。可以增加一个判断条件，使得重复的情况不发生。还可以只考虑奇数的情况，因为偶数肯定不可能是素数（2除外）。该方法是基于简单的线性筛法的。
*/
#include <memory.h>
#include <math.h>
#define N 1299710
using namespace std;


bool prime[N];


int primeGap(int num) {
    if (prime[num]) return 0;
    else {
       int i = num - 1;
         int j = num + 1;
         while (!prime[i]) {
               i--;
         }
         while (!prime[j]) {
               j++;      
         }
         return j - i;
    }
}
int main() {
	//最简单的素数筛法
    memset(prime, true, sizeof(prime)); //筛法求N以内的素数。
    for(int i=2; i<=sqrt(N); i++)
        if(prime[i])
			//步长为i
            for(int j=i+i; j<N; j=j + i)
                prime[j] = false;
     int n;
     while (cin >> n && n != 0) {
           cout << primeGap(n) << endl;
     }
     return 0;

