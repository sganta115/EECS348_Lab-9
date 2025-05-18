#include "matrix.hpp"
#include <fstream>



template <typename T>
Matrix<T>::Matrix(size_t N) : matrix(N, std::vector<int>(N,0)) {
    // initializes member variable matrix with N vectors consisting of N 0's
   
    
}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> nums) : matrix(nums){ //initializes member variable matrix with given "nums" matrix
    
}

template <typename T>
//addition overloading operator
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const{
    Matrix result(matrix.size());
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
}
    return result;
}

template <typename T>
//multiplication overloading operator
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const{
    size_t N = matrix.size();
    Matrix<T> result(matrix.size());
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            for(size_t k = 0; k < N; k++){
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
}
    return result;

}

template <typename T>
//sets matrix element to given parameter
void Matrix<T>::set_value(std::size_t i, std::size_t j, T n){
   matrix[i][j] = n;

}

template <typename T>
//returns matrix element at given indices
T Matrix<T>::get_value(std::size_t i, std::size_t j) const {
    if(i >= matrix.size() || j >= matrix.size()){
        throw std::out_of_range("indices out of range");
    }

    return matrix[i][j];
}

template <typename T>
//gets size of matrix
T Matrix<T>::get_size() const{
    return matrix.size();

}


template <typename T>
//sums the major diagonal elemnts (top left to bottom right)
T Matrix<T>::sum_diagonal_major() const{ //main diagonal
    T sum =0;
    T size = matrix.size();

    for(int i = 0; i < size; i++){ //iterates through the matrix and gets the diagonal element
        sum += matrix[i][i];

    }
    return sum;
    

}

//sums the minor diagonal elemnts (top right to bottom left)

template <typename T>
T Matrix<T>::sum_diagonal_minor() const{
    T sum =0;
    T size = matrix.size();

    for(int i = 0; i < size; i++){//iteratoes through the matrix and gets the diagonal element
        sum += matrix[i][size-1-i];

    }
    return sum;
    


}

template <typename T>
//swaps rows within a given matrix
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2){
    if (r1 >= matrix.size() || r2 >= matrix.size()){ //makes sure parameters are within bounds
        throw std::out_of_range("Not within bounds");
    }

    T temp = matrix[r1]; //creates a temp variable that stores a vector
    matrix[r1] = matrix[r2]; //swaps the rows
    matrix[r2] = temp;



}

template <typename T>
//swaps columns in a matrix
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2){
    if (c1 >= matrix.size() || c2 >= matrix.size()){ //makes sure parameters are valid
        throw std::out_of_range("Not within bounds");

    }

    for(auto& row : matrix){ //iterates through each row in the matrix by reference
        T temp = row[c1]; //swaps the individual elements in each row
        row[c1] = row[c2];
        row[c2] = temp;


    }

    




}







template <typename T>
void Matrix<T>::print_matrix() const {
    // print out the matrix
    for(const auto& row : matrix){//iterates through each row in the matrix my reference
        for(const auto& element : row){//iterates through each element in each row
            std::cout << element << " "; //prints out the element
        }
        std::cout << '\n';//adds a new line after each row
    }
    

}


template <typename T>
std::pair<Matrix<T>,Matrix<T>> create_matrices(std::string file_name){
    //read from file and get 2 matrices
    std::ifstream file(file_name);
    std::size_t N;
    file >> N;
    T flag;
    file >> flag;

    if (flag==0){ //int matrices
        std::vector<std::vector<int>> matrixData1(N, std::vector<int>(N));
        std::vector<std::vector<int>> matrixData2(N, std::vector<int>(N));

        for (std::size_t i = 0; i < N; i++){
            for(std::size_t j = 0; j < N; j++){

                file >> matrixData1[i][j];
            }
        }

        for (std::size_t i = 0; i < N; i++){
            for(std::size_t j = 0; j < N; j++){

                file >> matrixData2[i][j];
            }
    }
    return {Matrix<int>(matrixData1),Matrix<int>(matrixData2)};

    


    }

    else{
        std::vector<std::vector<double>> matrixData1(N, std::vector<double>(N));
        std::vector<std::vector<double>> matrixData2(N, std::vector<double>(N));

        for (std::size_t i = 0; i < N; i++){
            for(std::size_t j = 0; j < N; j++){

                file >> matrixData1[i][j];
            }
    }

    for (std::size_t i = 0; i < N; i++){
        for(std::size_t j = 0; j < N; j++){

            file >> matrixData2[i][j];
        }
    }


    return {Matrix<double>(matrixData1),Matrix<double>(matrixData2)};
    }
   




}