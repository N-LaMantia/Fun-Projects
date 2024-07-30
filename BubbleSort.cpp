// this code is to showcase the bubble sorting technique 
// this code filters numbers bigger first.

#include <iostream>

void printArr(int arr[], int n);
void bubbleSort(int arr[], int k);

int main() {

    int arr[] = {88, 34, 35, 92, 40, 1, 2, 4, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]); 

    std::cout << "Unsorted array: ";
    printArr(arr, n); 
    std::cout << "\n" << "Sorted array: ";
    bubbleSort(arr, n);
    printArr(arr, n); 


    return 0; 
}

void bubbleSort(int arr[], int k) {

    bool replaced;

    for (int i = 0; i < k -1; ++i){
        replaced = false; 
        for (int n = 0; n < k -1; ++n){

            if (arr[n] > arr[n+1]){
                int temp = arr[n];
                arr[n] = arr[n+1];
                arr[n+1] = temp; 
                replaced = true;
            }
        }

        if (!replaced) {
            break; 
        }
    }


}

void printArr(int arr[], int big) {

    for (int k = 0; k < big; ++k) {

        std::cout << arr[k] << " ";

    }
    std::cout << std::endl; 

}