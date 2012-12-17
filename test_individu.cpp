#include <iostream>
#include "individu.h"

double fitness_blink(const Individu&p)
{
	int f=0;
	for (int i=0; i<p.taille()-1; i++)
		if (p[i]!=p[i+1])
			f++;
	return ((float) f) / (p.taille()-1);
}



int main(void)
    {
    Individu I,J;
	cout << I << endl;
	I.set_taille(21);

	cout << I << endl;
	I.set_fitness( fitness_blink );
	cout << I << endl;
	
	cout << fitness_blink(I) << endl;
	
    }

