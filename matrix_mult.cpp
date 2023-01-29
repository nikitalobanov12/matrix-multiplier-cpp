//  g++ -pedantic -Wall -Wextra -std=c++17 matrix_mult.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>




 // read in a matrix from a file
 std::vector<std::vector<int> > readIn(std::string file){
    std::ifstream fin;
    fin.open(file);
    int row,col;
    fin >> row;
    fin >> col;
    std::vector<std::vector<int> > m(row,std::vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            fin >> m[i][j];
        }
    }
    return m;

}
//function that takes in 2 matrices and multiplies them
std::vector<std::vector<int> > matrixMult(std::vector<std::vector<int> > m1, std::vector<std::vector<int> > m2){
    //check if the matrices can be multiplied
    if(m1[0].size() != m2.size()){
        std::cout << "The matrices cannot be multiplied" << std::endl;
        return m1;
    }
    //create the new matrix
    std::vector<std::vector<int> > m3(m1.size(),std::vector<int>(m2[0].size()));
    //m1.size() has to be a variable because of error messages
    int m1Size = m1.size();
    //multiply the matrices
    for(int i = 0; i < m1Size; i++){
            //m2[0].size() has to be a variable because of error messages
        int m2Size = m2[0].size();
        for(int j = 0; j < m2Size; j++){
            //m1[0].size() has to be a variable because of error messages
            int m1Size2 = m1[0].size();
            for(int k = 0; k < m1Size2; k++){
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return m3;
}

//function that will print out the multiplication of 2 matrices
void printMatrix(std::vector<std::vector<int> > m){
    //m.size() has to be a variable because of error messages
    int mSize = m.size();
    for(int i = 0; i < mSize; i++){
        // m[0].size() has to be a variable because of error messages
        int mSize2 = m[0].size();
        for(int j = 0; j < mSize2; j++){
            std::cout << std::setw(4) << m[i][j];
        }
        std::cout << std::endl;
    }
}


int main(){
    //ask the user for 2 matrix files
    std::string file1;
    std::string file2;
    std::cout << "Enter the name of the first matrix file: ";
    std::cin >> file1;
    std::cout << "Enter the name of the second matrix file: ";
    std::cin >> file2;
    //read in the matrices
    std::vector<std::vector<int> > m1 = readIn(file1);
    std::vector<std::vector<int> > m2 = readIn(file2);

    //multiply the matrices
    std::vector<std::vector<int> > m3 = matrixMult(m1,m2);
    //print the matrix
    printMatrix(m3);


    return 0;
}

/* sample output
Enter the name of the first matrix file: matrix1.txt
Enter the name of the second matrix file: matrix2.txt
    15 8
    16 9

Enter the name of the first matrix file: m1.txt
Enter the name of the second matrix file: m4.txt
The matrices cannot be multiplied
   2   1   2
   3   2   1

Enter the name of the first matrix file: m2.txt
Enter the name of the second matrix file: m3.txt
   7   4
  12   7
  14   8


*/