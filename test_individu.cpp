#include <iostream>
#include "individu.h"

int main(void)
    {
    Individu<10> I,J;

	cout << I._gene << endl;
	cout << I.fitness() << endl;

	cout << J._gene << endl;
	cout << J.fitness() << endl;


    cout << "fin" << endl;
    }
