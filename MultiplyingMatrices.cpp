// Multiplying matricies

#include <iostream> 
#include <vector>

//function which multiplies matrices
std::vector<std::vector<int>> multMat(const std::vector<std::vector<int>>& mat1, 
const std::vector<std::vector<int>>& mat2) {

    int row1 = mat1.size(); //the number of rows in vector 1
    int col1 = mat1[0].size();  //the number of columns in vector 1
    int row2 = mat2.size();
    int col2 = mat2[0].size(); 

    //initialization
    std::vector<std::vector<int>> product(row1, std::vector<int>(col2, 0));

    //check if poss
    if (col1 != row2) {
        std::cout << "Number of columns in the first matrix must be equivalent to the number of rows in the second." << std::endl;
        return product;

    }

    //if it is...
    for (int i = 0; i < row1; ++i){
        for (int l = 0; l < col2; ++l){
            for (int k = 0; k < col1; k++) {
                product[i][l] += mat1[i][k] * mat2[k][l];
            }
        }
    }

return product;

}// end multiplying function

//printing the matrix function
void printMat(const std::vector<std::vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl; 
    }
}//end print function

//main function
int main() {

    int row1, col1 = 0, row2, col2 = 0;

    std::cout << "Enter number of rows and columns of the 1st matrix: ";
    std::cin >> row1, col1; 
    std::vector<std::vector<int>> mat1(row1, std::vector<int>(col1));

    std::cout << "Enter the elements of the first matrix: \n";
    for (int i = 0; i < row1; ++i){
        for (int c = 0; c < col1; ++c){
            std::cin >> mat1[i][c];
        }
    }

    //second matrix, same thing...
    std::cout << "Enter number of rows and columns of the 2nd matrix: ";
    std::cin >> row2, col2; 
    std::vector<std::vector<int>> mat2(row2, std::vector<int>(col2));

    std::cout << "Enter the elements of the second matrix: \n";
    for (int i = 0; i < row2; ++i){
        for (int c = 0; c < col2; ++c){
            std::cin >> mat2[i][c];
        }
    }

    //multiply the two matrices 
    std::vector<std::vector<int>> result = multMat(mat1, mat2); 

    std::cout << "Results: " << std::endl; 
    printMat(result);

    return 0; 


}




