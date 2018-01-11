#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "MatrixMat.h"

// Parameter Constructor 
template<typename T>
Matrix<T>::Matrix(unsigned n, const T& _initial):cols(n),rows(n) {
  	mat.resize(n);
  	for (unsigned i=0; i<mat.size(); i++) {
   		mat[i].resize(n, _initial);
  	}
}
                                                                                                                                                     
template<typename T>
Matrix<T>::Matrix(unsigned _rows, unsigned _cols, const T& _initial) {
  	mat.resize(_rows);
  	for (unsigned i=0; i<mat.size(); i++) {
   		mat[i].resize(_cols, _initial);
  	}
  	rows = _rows;
  	cols = _cols;
}

// Copy Constructor                                                                                                                                                           
template<typename T>                                               //a little useless because the compiler give one for default
Matrix<T>::Matrix(const Matrix<T>& rhs) {
  	mat = rhs.mat;
  	rows = rhs.get_rows();
  	cols = rhs.get_cols();
}

// (Virtual) Destructor                                                                                                                                                       
template<typename T>
Matrix<T>::~Matrix() {}


// Assignment Operator                                                                                                                                                        
template<typename T>                                             //this is useful because it resizes the Matrix and assign values to each rows and columns of the matrix
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
  	if (&rhs == this)
    	return *this;
  	unsigned new_rows = rhs.get_rows();
  	unsigned new_cols = rhs.get_cols();
  	mat.resize(new_rows);
  	for (unsigned i=0; i<mat.size(); i++) {
    	mat[i].resize(new_cols);
  	}

  	for (unsigned i=0; i<new_rows; i++) {
    	for (unsigned j=0; j<new_cols; j++) {
      		mat[i][j] = rhs(i, j);
    	}
  	}
  	rows = new_rows;
  	cols = new_cols;
  	return *this;
}

// Addition of two matrices                                                                                                                                                   
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
  	Matrix result(rows, cols, 0.0);
  	for (unsigned i=0; i<rows; i++) {
   		for (unsigned j=0; j<cols; j++) {
      		result(i,j) = this->mat[i][j] + rhs(i,j);
    	}
  	}
  	return result;
}

// Cumulative addition of this matrix and another                                                                                                                             
template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs) {
  	unsigned rows = rhs.get_rows();
  	unsigned cols = rhs.get_cols();
  	for (unsigned i=0; i<rows; i++) {
    	for (unsigned j=0; j<cols; j++) {
    	  this->mat[i][j] += rhs(i,j);
    }
  }

  return *this;
}

// Subtraction of this matrix and another                                                                                                                                     
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) {
  	unsigned rows = rhs.get_rows();
  	unsigned cols = rhs.get_cols();
  	Matrix result(rows, cols, 0.0);
  	for (unsigned i=0; i<rows; i++) {
    	for (unsigned j=0; j<cols; j++) {
      		result(i,j) = this->mat[i][j] - rhs(i,j);
    	}
  	}
  	return result;
}

// Cumulative subtraction of this matrix and another                                                                                                                          
template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs) {
  	unsigned rows = rhs.get_rows();
  	unsigned cols = rhs.get_cols();
  	for (unsigned i=0; i<rows; i++) {
    	for (unsigned j=0; j<cols; j++) {
      		this->mat[i][j] -= rhs(i,j);
    	}
  	}
  	return *this;
}

// Left multiplication of this matrix and another                                                                                                                              
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) {
	if(cols==rhs.get_rows()){
  		unsigned rows = rhs.get_rows();
  		unsigned cols = rhs.get_cols();
  		Matrix result(rows, cols, 0.0);
  		for (unsigned i=0; i<rows; i++) {
    		for (unsigned j=0; j<cols; j++) {
      			for (unsigned k=0; k<rows; k++) {
        			result(i,j) += this->mat[i][k] * rhs(k,j);
      			}
    		}
  		}
  		return result;	
  	}
  	else 
  		cerr<<"the two matrix cannot be moltiplicated";
  		return mat;
}

// Cumulative left multiplication of this matrix and another                                                                                                                  
template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs) {
  	Matrix result = (*this) * rhs;
  	(*this) = result;
  	return *this;
}

// Matrix/scalar addition                                                                                                                                                     
template<typename T>
Matrix<T> Matrix<T>::operator+(const T& rhs) {
  	Matrix result(rows, cols, 0.0);
  	for (unsigned i=0; i<rows; i++) {
    	for (unsigned j=0; j<cols; j++) {
      		result(i,j) = this->mat[i][j] + rhs;
    	}
  	}
  	return result;
}

// Matrix/scalar subtraction                                                                                                                                                  
template<typename T>
Matrix<T> Matrix<T>::operator-(const T& rhs) {
  	Matrix result(rows, cols, 0.0);
  	for (unsigned i=0; i<rows; i++) {
    	for (unsigned j=0; j<cols; j++) {
      		result(i,j) = this->mat[i][j] - rhs;
    	}
  	}	
  	return result;
}

// Matrix/scalar multiplication                                                                                                                                               
template<typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs) {
  	Matrix result(rows, cols, 0.0);
  	for (unsigned i=0; i<rows; i++) {
    	for (unsigned j=0; j<cols; j++) {
      		result(i,j) = this->mat[i][j] * rhs;
    	}
  	}
  	return result;
}

// Matrix/scalar division                                                                                                                                                     
template<typename T>
Matrix<T> Matrix<T>::operator/(const T& rhs) {
  	Matrix result(rows, cols, 0.0);
  	for (unsigned i=0; i<rows; i++) {
    	for (unsigned j=0; j<cols; j++) {
      		result(i,j) = this->mat[i][j] / rhs;
    	}
  	}
  	return result;
}

// Calculate a transpose of this matrix                                                                                                                                       
template<typename T>
Matrix<T> Matrix<T>::transpose() {
  	Matrix result(rows, cols, 0.0);
  	for (unsigned i=0; i<rows; i++) {
    	for (unsigned j=0; j<cols; j++) {
      		result(i,j) = this->mat[j][i];
    	}
  	}
  	return result;
}

//minor
template<typename T>
Matrix<T> Matrix<T>::getMinor(Matrix<T> A,unsigned p, unsigned q,unsigned n) {
    int i = 0, j = 0;
    Matrix minor(rows-1,cols-1,0.0);
    for (int row = 0; row<n; row++){
        for (int col = 0; col<n; col++){
            if (row != p && col != q){
                minor(i,j++) = A(row,col);
                if (j == rows - 1){
                    j = 0;
                    i++;
                }
            }
        }
    }
    return minor;
}

//determinant
template<typename T>
T Matrix<T>::determinant(Matrix<T> A,unsigned n){
    T deter=0;
    if (n==1)
        return A(0,0);
    else if(n==2) 
		return((A(0,0)*A(1,1))-(A(0,1)*A(1,0))); 
	else if(n==3)
		return((A(0,0)*A(1,1)*A(2,2))+(A(0,1)*A(1,2)*A(2,0))+(A(1,0)*A(2,1)*A(0,2))-(A(0,2)*A(1,1)*A(2,0))-(A(0,1)*A(1,0)*A(2,2))-(A(1,2)*A(2,1)*A(0,0)));	  
 	Matrix tempCofactor(n,0.0); 
    int sign = 1;  // To store sign multiplier 
     // first row fixed
    for (int f = 0; f < n; f++){
        tempCofactor=getMinor(A,0, f, n);
        deter += sign * A(0,f) * determinant(tempCofactor, n - 1);         //cofactor =sign * A[0][f] * determinant(tempCofactor, n - 1)
        sign = -sign;
    } 
    return deter;
}

template<typename T>
T Matrix<T>::determinant(){
    T deter=0;
    if (rows==1)
        return mat[0][0];
    else if(rows==2) 
		return((mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0])); 
	else if(rows==3)
		return((mat[0][0]*mat[1][1]*mat[2][2])+(mat[1][0]*mat[1][2]*mat[2][0])+(mat[1][0]*mat[2][1]*mat[0][2])-(mat[0][2]*mat[1][1]*mat[2][0])-(mat[0][1]*mat[1][0]*mat[2][2])-(mat[1][2]*mat[2][1]*mat[0][0]));	  
 	Matrix tempCofactor(rows,0.0); 
    int sign = 1;  // To store sign multiplier 
     // first row fixed
    for (int f = 0; f < rows; f++){
    	Matrix whygod=*this;
        tempCofactor=getMinor(whygod, 0, f, rows);
        deter += sign * mat[0][f] * determinant(tempCofactor, rows - 1);         //cofactor =sign * A[0][f] * determinant(tempCofactor, n - 1)
        sign = -sign;
    } 
    return deter;
}

//adjugate
template<typename T>
Matrix<T> Matrix<T>::Adjugate(){
    if (rows == 1){
    	Matrix adj(1,0.0);
        adj(0,0) = 1;
        return adj;
    }
    int sign = 1; 
    Matrix adj(rows,0.0);
    for (int i=0; i<rows; i++){
        for (int j=0; j<rows; j++){
        	Matrix mamma=*this;
            Matrix temp=getMinor(mamma, i, j, rows);
            sign = ((i+j)%2==0)? 1: -1;
            adj(j,i) = (sign)*(determinant(temp, rows-1));      //transpose of the cofactors matrix
        }
    }
    return adj;
}


//inverse
template<typename T>
Matrix<T> Matrix<T>::inverse(){
	if(rows!=cols){
		cerr<<"the matrix is not quadratic, punk";
		return *this;
	}
	else{
		T det = determinant();
    	if (det == 0){
    	    cout << "Singular matrix, can't find its inverse";
        	return *this;
	    }
	    Matrix inver=(Adjugate())/float(det);                      // i should implement this whole thing with a class fractions
 	return inver;
	}
}



// Multiply a matrix with a vector                                                                                                                                            
template<typename T>
vector<T> Matrix<T>::operator*(const vector<T>& rhs) {
  	vector<T> result(rhs.size(), 0.0);
  	for (unsigned i=0; i<rows; i++) {
    	for (unsigned j=0; j<cols; j++) {
      		result[i] = this->mat[i][j] * rhs[j];
    	}
  	}
  	return result;
}

// Obtain a vector of the diagonal elements                                                                                                                                   
template<typename T>
vector<T> Matrix<T>::diag_vec() {
  	vector<T> result(rows, 0.0);
  	for (unsigned i=0; i<rows; i++) {
    	result[i] = this->mat[i][i];
  	}
  	return result;
}

// Access the individual elements                                                                                                                                             
template<typename T>
T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) {
  	return this->mat[row][col];
}

// Access the individual elements (const)                                                                                                                                     
template<typename T>
const T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) const {
  	return this->mat[row][col];
}

// Get the number of rows of the matrix                                                                                                                                       
template<typename T>
unsigned Matrix<T>::get_rows() const {
  	return this->rows;
}

// Get the number of columns of the matrix                                                                                                                                    
template<typename T>
unsigned Matrix<T>::get_cols() const {
  	return this->cols;
}

template<typename T>
ostream& operator << (ostream& os,const Matrix<T>& rhs){
	for(unsigned i=0;i<rhs.get_rows();i++){
		for(unsigned j=0;j<rhs.get_cols();j++){
			os<<rhs(i,j)<<setw(4);
		}
		os<<"\n";
	}
	return os;
}

#endif
