#include <iostream>

using namespace std;
void print(int arr[][10]){
    cout << arr[0][0] << endl;
}
void print(int* arr[]){
    cout << arr[0][0] << endl;
}
void print2(int **arr){
    cout << arr[0][0] << endl;
}
int main(){

    /// Fixed sized array
    int arr[10][10];
    print(arr);

    /// Pointers to 1D array
    int m = 5, n = 5;
    int* arr2[m];
    for(int i = 0; i<m; i++)
        arr2[i] = new int [n];
    print(arr2);

    /// Pass by pointer of pointer
    int **arr3;
    arr3 = new int*[m];
    for(int i = 0; i< n; i++)
        arr3[i] = new int [n];
    print(arr3);
    return 0;
}
