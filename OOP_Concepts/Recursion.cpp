#include<iostream>

void recneverends()
{
    std::cout <<" for the lols" << std :: endl;
    return recneverends();


}
long long factorial(int x)
{
    std::cout << "called" << std::endl;
    if(x == 1)
    {
        return 1;
    }
    else
    {
        return x * factorial(x-1);
    }
}
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}



int main()
{
    //recneverends();
    std::cout << factorial(20) << std :: endl;
    int a, b;
    while(std::cin >> a >> b)
    {
        std::cout << "a = " << a << ",b = " << b << std::endl;
        std::cout <<"GCD = "<< gcd(a, b) << std::endl;
    }
    return 0;
}
