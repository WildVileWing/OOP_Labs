#include <iostream>
using std::cout;
using std::endl;

template<typename T>
int sortArray(T array[], int amount, T key)
{
    for (int i = 0; i < amount; i++)
    {
        if (array[i] == key) return i;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[] = { 59, 88, 90, 2, 45 };
    double arrD[] = { 1.1, 0.3, 22.5, 4, 17.8, -10 };
    long arrL[] = { 15646, 654068, 0, -4564, 654, -555 };
    char arrC[] = { 'a', 'b', 'z', 'g', 'a', 'u' };
    cout << "index:" << sortArray(arr, sizeof(arr) / sizeof(arr[0]), 2) << endl;
    cout << "index:" << sortArray(arrD, sizeof(arrD) / sizeof(arrD[0]), 0.3) << endl;
    cout << "index:" << sortArray(arrL, (sizeof(arrL) / sizeof(arrL[0])), 11l) << endl;
    cout << "index:" << sortArray(arrC, sizeof(arrC) / sizeof(arrC[0]), 'a') << endl;
}
