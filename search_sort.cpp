#include<iostream>
using namespace std;
void merge(int* a,int* aux, int from, int mid, int to){
    int first1=from;
    int last1=mid;
    int first2=mid+1;
    int last2=to;
    int index=from;
    while(first1<=last1 && first2<=last2){
        if(a[first1]<=a[first2]){
            aux[index++]=a[first1++];
        }
        else{
            aux[index++]=a[first2++];
        }
    }
    while(first1<=last1){
        aux[index++]=a[first1++];
    }
    while(first2<=last2){
        aux[index++]=a[first2++];
    }
    for(int i=from; i<=to;i++){
        a[i]=aux[i];
    }
}
void mergeSort(int* a,int* aux, int from, int to){
    if(from<to){
        int mid=(from+to)/2;
        mergeSort(a,aux,from,mid);
        mergeSort(a,aux,mid+1,to);
        merge(a,aux,from, mid, to);
    }
}
void quickSort(int arr[], int first, int last){
    int pivot=arr[(first+last)/2];
    int i=first, j=last;
    while(i<=j){
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<=j){
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    if(first < j) quickSort(arr, first, j);
    if(i < last) quickSort(arr, i, last);
}
int main(){
    int arr[]={1,5,7,2,4,3,9,8,6,123,86867,45};
    quickSort(arr,0,11);
    for(int i=0 ; i<12; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}