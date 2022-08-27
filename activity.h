// =================================================================
//
// File: activity.h
// Author: Ernesto Guillén Guerrero
// Date: 26/08/2022
//
// =================================================================
#ifndef ACTIVITY_H
#define ACTIVITY_H

// =================================================================
// sumaIterativa. Calculate the sum from 1 to n with an iterative
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	??
// =================================================================
unsigned int sumaIterativa(unsigned int n) {
	int acum, suma=0;
	if (n==0){
		return 0;
	}
	else {
		acum = 1;
		while(acum <= n){
			suma += acum;
			acum ++;
		}
		return suma;
	}
}

// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with an recursive
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	??
// =================================================================
unsigned int sumaRecursiva(unsigned int n) {
	if (n==0){
			return 0;
		}
		else {
			n = n+sumaRecursiva(n-1);
		}
		return n;
}

// =================================================================
// sumaDirecta. Calculate the sum from 1 to n with a mathematical
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	??
// =================================================================
unsigned int sumaDirecta(unsigned int n) {
	if (n==0){
		return 0;
	}
	else {
		n = (n*(n+1)/2);
		return n;
	}
}
make

#endif /* ACTIVITY_H */
