#include<iostream>

using namespace std;
//template<class T>
class vector2d
{
private:
    float x, y;

public:
    vector2d(const vector2d &old)
    :x(old.x), y(old.y)
    {
        cout << *this <<"copy" <<endl;
    }
    vector2d(float x, float y)
        :x(x), y(y)
    {
        cout << "vector2d constructor of " << x << "," << y << endl;
    }
    vector2d add(const vector2d& other)const
    {
        return vector2d(x + other.x, y + other.y);
    }
    vector2d operator + (const vector2d &other)const
    {
        return vector2d(x + other.x, y + other.y);
    }
    vector2d operator * (const vector2d &other)const
    {
        return vector2d(x*other.x, y*other.y);
    }
    friend vector2d operator/(const vector2d &a, const vector2d &b);
    friend ostream& operator << (std::ostream& stream, const vector2d &a);

};
vector2d operator/(const vector2d &a, const vector2d &b)
{
    return vector2d(a.x/b.x, a.y/b.y);
}
ostream& operator << (std::ostream& stream, const vector2d &a)
{
    stream << a.x <<", " << a.y << endl;
    return stream;
}
int main()
{
    vector2d p1(1, 2), p2(2, 4);
    vector2d result1 = p1.add(p2);
    vector2d result2 = p1 + p2;
    vector2d result3 =  p1*p2;
    vector2d p3 = p2/p1;

    cout << p3;
    return 0;
}
