#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
mergesort는 배열의 모든수를 반으로 나누어가며, 모두 크기가 1인 배열로 나누어지면,
merge함수로 배열들을 정렬하면서 합치는 알고리즘.
*/
int a[100];
int b[100];
void sort(int start, int end)
{
    if(start==end)
    {
        return;
    }
    int mid = (start+end)/2;
    sort(start,mid);
    sort(mid+1,end);
    merge(start,end);
}

void merge(int start, int end)
{
    int mid = (start+end)/2;
    int i = start, j = mid + 1, k = 0;
    while(i<=mid&&j<=end)
    {
        if(a[i]<=a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i<=mid) b[k++] = a[i++];
    while(j<=end) b[k++] = a[j++];
    for(int i=start;i<=end;i++)
    {
        a[i] = b[i-start];
    }
}