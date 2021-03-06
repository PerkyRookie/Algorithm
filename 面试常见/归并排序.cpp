#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> tmp;
    int i=start, j=mid+1;
    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
            tmp.push_back(arr[i++]);
        else
            tmp.push_back(arr[j++]);
    }
    while(i <= mid)
        tmp.push_back(arr[i++]);
    while(j <= end)
        tmp.push_back(arr[j++]);
    for(int i=0; i<tmp.size(); i++)
        arr[start+i] = tmp[i];
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if(start < end)
    {
        int mid = (start+end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    vector<int> arr = {5,3,7,1,8,2,9,4,7,2,6,6,10,3,11};

    mergeSort(arr, 0, arr.size()-1);

    for(auto i : arr)
        cout << i << " ";
    cout << endl;
}