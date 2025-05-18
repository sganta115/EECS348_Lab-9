#include "matrix.hpp"
#include <fstream>
#include <variant>

using MatrixVariant = std::variant<Matrix<int>, Matrix<double>>;

int main() {
    
    std::ifstream file("input.txt");
    std::size_t N;
    std::size_t flag;
    file >> N;
    file >> flag;
    file.close();

    MatrixVariant Matrix1, Matrix2;

   
   if(flag == 0){
    auto matrices = create_matrices<int>("input.txt");
    Matrix Matrix1 = matrices.first;
    Matrix Matrix2 = matrices.second;


   }
   else{
    auto matrices = create_matrices<double>("input.txt");
    Matrix Matrix1 = matrices.first;
    Matrix Matrix2 = matrices.second;
    
   }

    std::visit([](const auto m) {m.print_matrix();}, Matrix1);
   

    
   
}
