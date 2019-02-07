#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include<algorithm>
#include<array>
using namespace std;
//template < typename T > void printList( const list < T > &listref );
void printvector(const vector<int> &s)
{
    vector<int>::const_iterator i;
    for(i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;
}

int main()
{

    ///array is for simple input to vector
    const size_t size = 15;
    array <int, size> data = {0, 54, 5, 5, 87, 9487, 6, 7,5, 5, 2, 98, 43, 1, 87};

    vector < int > test(data.begin(), data.end());

    static std::vector< int > :: iterator it;
    it = test.begin();
    it+=5;
    test.insert(it, 11111);
    printvector(test);

    ///if you use it again, unexpected result will happen,
    ///since after you insert the element,
    ///the vector is not the same
    ///it+= 4;    <---- this code will not work;
    int a = 8;
    test.insert(test.cbegin()+a, 17);
    printvector(test);

    test.erase(test.cbegin()+9);
    printvector(test);
    test.erase(test.cend()-1);///cend() is not the last element in vector
    printvector(test);

    sort(test.begin(), test.end());///this is sort in <algorithm>
    printvector(test);

    cout << test.size() << endl;
    ///there are 16 numbers in the vector


    return 0;
}
