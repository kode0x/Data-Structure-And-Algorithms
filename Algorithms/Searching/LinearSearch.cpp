#include <bits/stdc++.h>
using namespace std;
/*
    int linearSearch(int arr[], int length, int key)
    {
        for (int index = 0; index < length; index++)
        {
            if (arr[index] == key)
            {
                return index;
            }
        }
        return -1;
    }
*/

// Improved Linear Search (Using Transposition)
int linearSearch(int arr[], int length, int key)
{
    for (int index = 0; index < length; index++)
    {
        if (arr[index] == key)
        {
            if (index > 0)
            {
                swap(arr[index], arr[index - 1]); // Transposition
                // Another Method (Moving To Front/Moving To Head)
                // swap(arr[index], arr[0])
                return index - 1;
            }
            return index;
        }
    }
    return -1;
}

int main()
{
}
