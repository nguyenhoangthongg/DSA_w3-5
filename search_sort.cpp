#include<iostream>
#include<time.h>
using namespace std;
void merge(int* a, int from, int mid, int to){
    int first1=from, last1=mid;
    int first2=mid+1,last2=to;
    int index=from;
    int* aux=new int[to+1];
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
    delete aux;
}
int mergeSort(int* a, int from, int to){
    if(from<to){
        int mid=(from+to)/2;
        mergeSort(a,from,mid);
        mergeSort(a,mid+1,to);
        merge(a,from, mid, to);
    }
    return 0;
}
int quickSort(int* arr, int first, int last){
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
    return 0;
}
int shellSort(int* arr, int l, int r){
    for(int gap=(r-l+1)/2; gap>0; gap/=2){
        for(int i=gap; i<=r; i+=1){
            int temp=arr[i];
            int j;
            for(j=i; j>=gap && arr[j-gap]>temp; j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
    return 0;
}
void shakerSort(int* arr, int l, int r){
    int left=l;
    int right=r;
    int k=0;
    for(int i=left;i<right; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
            k=i;
        }
    }
    right=k;
    for(int i=right; i>left; i--){
        if(arr[i]<arr[i-1]){
            swap(arr[i], arr[i - 1]);
			k = i;
        }
    }
    left=k;
}
void sort( int* arr, int n){
    for(int i=0; i<n-1 ;i++){
        for( int j=i+1; j<n; j++){
            if(arr[i]>arr[j]) swap(arr[i], arr[j]);
        }
    }
}
void process(){
    int Size_set[]={1000,3000,10000,30000,100000};
    string state_set[]={"sorted","reversed","random"};
    for(int size=0; size<5; size++){

    }
}
int main(){
    
}