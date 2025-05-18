#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <cstdint>
#include <vector>
#include <variant>
template <typename T>


class Matrix {
private:
    std::vector<std::vector<T>> matrix;

public:
    Matrix() : matrix(0){}
    Matrix(std::size_t N); //empty matrix constructor
    Matrix(std::vector<std::vector<T>> nums); //matrix with values constructor

    Matrix<T> operator+(const Matrix<T> &rhs) const; //addition operator
    Matrix operator*(const Matrix<T> &rhs) const; //multiplication operator
    void set_value(std::size_t i, std::size_t j, T n); 
    T get_value(std::size_t i, std::size_t j) const;
    T get_size() const;
    T sum_diagonal_major() const;
    T sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
    

};

template <typename T>
std::pair<Matrix<T>,Matrix<T>> create_matrices(std::string file_name);


#endif // __MATRIX_HPP__