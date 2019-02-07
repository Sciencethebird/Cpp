#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
#include<array>
using namespace std;
//template < typename T > void printList( const list < T > &listref );
void printlist(const list<int> &s)
{
    list<int>::const_iterator i;
    for(i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;
}

int main()
{

    int a;
    const size_t size = 10;
    array <int, size> data = {0, 4, 5, 6, 7, 2, 98, 43, 1, 87};
    list< int > test(data.begin(), data.end());
    std::list< int > :: iterator it;
    it = test.begin();

    //cout << "list begin = " << it <<endl;
    /*for(int i = 0; i <10; i++)
    {
        cin >> a;
        test.push_back(a);
    }*/
    printlist(test);///this is how you print list by hand

    for (auto v : test)/// this is a cheeky way of printing the list
        cout << v << "\n";

    ///it += 5; error
    ///Only random access iterator support this kind of operator (vector, array, deque)
    ///list is a bidirectional iterator

    ///test.insert.at(7) = 10; error
    ///again, list is not support random access iterator.

    it ++; ///list does support this operator
    test.insert(it, 1111);
    test.remove(87);
    printlist(test);
    //test.sort();

    ///sort(test.begin(), test.end());
    ///I can't understand quiet well why it does not work, but this line will bring you something cooooool;

    test.sort();  ///this is sort in <list.h> not in <algorithm>

    printlist(test);
    return 0;
}
