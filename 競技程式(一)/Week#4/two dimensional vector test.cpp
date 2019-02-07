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

    vector< vector<int> > numbers;
    vector<int> tempVector;

    tempVector.push_back(20);
    tempVector.push_back(40);

    numbers.push_back(tempVector);
    tempVector.clear();

    tempVector.push_back(87);
    tempVector.push_back(8);
    tempVector.push_back(9);
    tempVector.push_back(17);

    numbers.push_back(tempVector);
    tempVector.clear();

    tempVector.push_back(101010);


    numbers.push_back(tempVector);
    tempVector.clear();

    cout << "numbers[2][0] = ";
    cout << numbers[2][0] << endl;

    numbers[2].erase(numbers[2].cbegin());
    cout << "size = "<<numbers[2].size() << endl;

    numbers[1].push_back(9487);
    printvector(numbers[2]);
    //cout << numbers[1][0] << endl;

    cout << numbers[1].size() << endl;
}
