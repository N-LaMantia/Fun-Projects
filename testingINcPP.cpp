// c++ 

#include <iostream>
long factorial(int n); 

int main() {

    int number; 

    std::cout << "Enter a positive integer: ";
    std::cin >> number; 

    std::cout << "\n" << std::endl; 

    if (number < 0) {
        std::cout << "Negative numbers are undefined." << std::endl; 
        return 1; 
    }

    long factial = factorial(number); 

    std::cout << "Factorial of " << number << " is " << factial << "." << std::endl;
    
}

long factorial(int n) { //method to calculate factorial

    long result = 1; 

    if (n <= 1) {
        return 1; 
    }
    
    for (int i =2; i <= n; ++i) {
        result *= i; 
    }
    return result; 

}