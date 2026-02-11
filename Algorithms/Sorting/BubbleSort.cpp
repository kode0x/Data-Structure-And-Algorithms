#include <bits/stdc++.h>
#include <algorithm>

void bubbleSort(int array[], int size)
{
    for (int one = 0; one < size - 1; one++)
    {
        for (int two = 0; two < size - one - 1; two++)
        {
            if (array[two] > array[two + 1])
            {
                std::swap(array[two], array[two + 1]);
            }
        }
    }
}

int main() {}
