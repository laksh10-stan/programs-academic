#include<bits/stdc++.h>
using namespace std;
int keyops = 0;
// Recursive function (MSD approach)
vector<int> MSDSort(vector<int>& arr, int n, int l, int k ){
    if(n<=1){
        return arr;
    }
    vector<vector<int>> buckets (10);
    
    int decPlace = pow(10,k-l);

    // passing numbers in buckets
    for(int i=0;i<n;i++){
        int d = (arr[i]/decPlace)%10;
        buckets[d].push_back(arr[i]);
        keyops++;
    }

    if(l<k){
        // recursive sorting 
        for(int i=0;i<10;i++){
            buckets[i] = MSDSort(buckets[i],buckets[i].size(),l+1,k);
        }
    }

    int p = 0;
    
    // restore numbers to original vector
    for(int i=0;i<10;i++){
        for(int j=0;j<buckets[i].size();j++){
            arr[p] = buckets[i][j];
            p++;
            keyops++;
        }
    }
    return arr;
}

int getMax(vector<int>& arr, int n) {
    int mx=-1;
    for(int i=0;i<n;i++){
        mx = max(mx,arr[i]);
    }
    return mx;
}

void radSortMSD(vector<int>& arr, int n) {
    int maximumNumber = getMax(arr,n);
    int maxDigits = log10(maximumNumber)+1;
    vector<int> sortedArray = MSDSort(arr,n,1,maxDigits);
    for(int i=0;i<n;i++){
        arr[i] = sortedArray[i];
    }
}

int main(){
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    vector<int> arr(n);
    srand((unsigned) time(0));
    cout << "Randomly generated numbers are:\n";
    for(int i = 0; i<n; i++){
        // sub routine to generate c random numbers (max 4 digits) and store them in arr. 
        int result = 1 + (rand() % 9999);
        cout<<result<<"\n";
        arr[i] = result;
    }
    radSortMSD(arr,n);
    // Print Result (Sorted array)
    cout<<"Sorted array is:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    cout<<keyops<<endl;

    return 0;
}
