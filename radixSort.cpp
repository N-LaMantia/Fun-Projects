//Radix Sort is a non-comparative sorting algorithm 
//that works by sorting numbers digit by digit, 
//starting from the least significant digit 
//to the most significant digit.

// Code to showcase the radix sort.

#include <iostream>
#include <vector>
#include <algorithm>

int getMaximum(const std::vector<int>& arr);
void numSort(std::vector<int>& arr, int digit);
void radix(std::vector<int>& arr);

int main() {

    std::vector<int> arr = {100, 54, 95, 80, 755, 901, 2, 43};

    std::cout << "Origin array: " << std::endl; 
    for (int n : arr){
        std::cout << n << " "; 
    }

    std::cout << "\n"; 

    radix(arr); 

    std::cout << "Sorted array: " << std::endl; 
    for (int i : arr) {
        std::cout << i << " "; 
    }
    std::cout << "\n"; 

    return 0; 

}

int getMaximum(const std::vector<int>& arr) { 

    return *std::max_element(arr.begin(), arr.end());
} //gets max 

void numSort(std::vector<int>& arr, int digit) { 

    int size = arr.size(); 
    std::vector<int> product(size); 
    std::vector<int> arrC(10, 0); 

    for (int i = 0; i < size; ++i){
        arrC[(arr[i] / digit) % 10] ++; 
    } //store counts of occurences of each digit

    for (int k = 1; k < 10; ++k) {

        arrC[k] += arrC[k-1]; 
    }

    for (int i = size - 1; i >= 0; --i) {

        product[arrC[(arr[i] / digit) % 10] - 1] = arr[i];
        arrC[(arr[i] / digit) % 10]--;

    } //constructs the output array

    for (int i = 0; i < size; ++i) {
        arr[i] = product[i]; 
    }


} //preforms counting sort

void radix(std::vector<int>& arr) {

    int maximum = getMaximum(arr);
    //find max to determine # of digits 

    for (int n = 1; maximum / n > 0; n *= 10) {

        numSort(arr, n); 
        //applies counting sort to numbers 
    }

}

