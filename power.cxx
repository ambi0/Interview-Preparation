/*
 * Recursively computes the power of X^Y.
 *
 */

#include <iostream>

int pow(int, int);
int pow_optimized(int, int);

int main(){
	std::cout << pow(2,5) << std::endl;
	std::cout << pow_optimized(2,8) << std::endl;
}

int pow(int x, int y){
	if(y==0)
		return 1;

	return x*pow(x,y-1);
}

//using the mathematical property of the exponent laws: X^Y = [X^(Y/2)]*[X^(Y/2)]
int pow_optimized(int x, int y){
	if(y==0)
		return 1;

	if(!(y&1))//even
		return pow(x,y/2)*pow(x,y/2);

	return x*pow(x,y-1);
}