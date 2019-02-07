#include<iostream>

using namespace std;
template<class T>
class myvector
{
public:
    T x, y;
    myvector()  ///default constructor is needed
    {
    }
    myvector(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    myvector operator+(const myvector other)const
    {
        return myvector<T>(x + other.x, y + other.y);
    }
    myvector operator*(const myvector other)const;
    void printlol(int n); /// definition has no curly brackets!!!

};
template<typename T>
void myvector<T>::printlol(int n)
{
    for(int i = 0; i< n; i++)
    {
        cout << "lol" << endl;
    }
}
template<typename T>
myvector<T> myvector<T>::operator*(const myvector<T> other)const
{
    return myvector<T>(x * other.x, y * other.y);
};

template<class T>
std::ostream& operator<<(std::ostream& stream, const myvector<T>& other )
{
    stream  << other.x << ", "<<other.y;
    return stream;
}
int main()
{

    myvector<float> p1(2, 3);
    cout << p1 ;
    return 0;
}



