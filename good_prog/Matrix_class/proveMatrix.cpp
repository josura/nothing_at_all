#include <cstdlib>
//#include<iostream>


#include "MatrixMat.h"

int main(){
	Matrix<float> piss(3,0.0);
	for(int i=0;i<piss.get_rows();i++){
		for(int j=0;j<piss.get_cols();j++){
			cin>>piss(i,j);
		}
	}
	cout<<piss;
	//shit.operator<<(cout);
	Matrix<float> shit=piss.inverse();
	cout<<"\n \n \n"<<shit;
	
}
