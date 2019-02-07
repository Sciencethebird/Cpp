#include<iostream>
#include<cmath> ///use M_PI in the library
#include<string>
using namespace std;
template<class t>
void a_function(t a){

    cout << a << endl;
}
template<class t> ///t of template is only used in the following functions/class
void func_replica(t b){
    cout << b << endl;
}

template<typename birb>
birb a_function_again(birb a){
    cout << a << endl;
}

template<typename T, int N>

class Array
{
private:
	T m_array[N];
public:
	int getsize() const { return N; }
};

int main()
{

    a_function<int>(5);
    func_replica<double>(M_E);

    a_function_again<float>(M_PI);

    a_function_again<string>("sciecne");


    Array<int, 50> newarray;
    cout << "array size = " << newarray.getsize() << endl;
    return 0;
}
