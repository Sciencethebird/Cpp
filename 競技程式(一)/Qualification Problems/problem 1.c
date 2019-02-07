#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    /// Using Euclidean algorithm (輾轉相除法)
    //printf("\n%d\n", m%n);
    /// 10%3=1 3%10=3 (10*0+3=3)
    while(n!=0){
        int r = m % n;
        m = n;
        n = r;
    }
    /// Modify the result for negative numbers
    if(m<0 || n<0){
        m = -m;
    }
    printf("%d", m);
    return 0;
}
