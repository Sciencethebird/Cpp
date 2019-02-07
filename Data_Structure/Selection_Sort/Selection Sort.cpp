#include<iostream>
#include<string>
using namespace std;

void selection_sort(int a[], int sz)
{
    for(int i = 0 ; i < sz; i++)
    {
        int index = i;///need to set to i
        int min = a[i];
        for(int j = i+1; j<sz; j++)
        {
            if(a[j] < min)
            {
                min = a[j];
                index = j;
            }
        }
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}
int main()
{
    int a[100], sz, temp;
    cout << sizeof(a)/sizeof(int) << endl;
    cout << "Enter size of array you want to sort: ";
    cin >> sz;
    cout << "Enter Array: ";
    for(int i = 0; i< sz; i++){
        cin >> a[i];
    }
    selection_sort(a, sz);

    for(int i = 0; i<sz; i++){
        cout << a[i] << " ";
    }
    return 0;

}
