#include <iostream>
#include "individu.h"

int main(void)
    {
    Individu<10> I,J;

	cout << I << endl;
	cout << J << endl;
	I=J;
	cout << I << endl;
	

	Population<10,5> P;

    cout << P << endl;
    }
