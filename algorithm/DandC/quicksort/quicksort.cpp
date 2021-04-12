#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
quicksort는 아무위치의 pivot을 설정한뒤, 작은수는 앞으로 보내고, 크거나 같은 수는
뒤로 보내며 정렬하는 알고리즘. 보통 pivot은 (low+high)/2 의 위치를 사용함.
*/
int a[100];
int choosePivot(int low, int high)
{
    return (low+high)/2;
}

int partition(int low, int high)
{
    int pivotIndex = choosePivot(low,high);
    int pivotValue = a[pivotIndex];
    swap(a[pivotIndex], a[high]);
    int storeIndex = low;
    for(int i=low;i<high;i++)
    {
        if(a[i] < pivotValue)
        {
            swap(a[i], a[storeIndex]);
            storeIndex += 1;
        }
    }
    swap(a[storeIndex], a[high]);
    return storeIndex;
}

void quicksort(int low, int high)
{
    if(low < high)
    {
        int pivot = partition(low,high);
        quicksort(low,pivot-1);
        quicksort(pivot+1,high);
    }
}