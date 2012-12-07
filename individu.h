#ifndef __INDIVIDU__
#define __INDIVIDU__

#include <iostream>
#include <bitset>
using namespace std;

#include <stdlib.h>
#include <time.h>
template <int TAILLE>
class Individu
    {
    public :
        bitset<TAILLE> _gene;
		float _fitness;

		Individu();
		Individu(bool b);
		Individu(const Individu<TAILLE>&);
		Individu<TAILLE>& operator=(const Individu<TAILLE>&);
		virtual ~Individu();
			

		float fitness(void);

	// pour initialiser le générateur pseudo-aleatoire une seule fois
	private :
		static bool _initrand;
		void initrand(int);
		
    };


// pour initialiser le générateur pseudo-aleatoire une seule fois
template <int TAILLE>
bool Individu<TAILLE>::_initrand=false;

template <int TAILLE>
void Individu<TAILLE>::initrand(int s=-1)
{
if (_initrand)
	return;

if (s==-1)
	srand(time(NULL));
else 
	srand(s);

_initrand=true;
}


/** \fn Individu<TAILLE>::Individu()
 *  \brief constructeur par defaut d'un Individu aleatoire
 */
template <int TAILLE>
Individu<TAILLE>::Individu()
	{
	initrand();	

	for (int i=0; i<TAILLE; i++)
		_gene.set(i,rand()%2);

	fitness();
	}

/** \fn Individu<TAILLE>::Individu(bool)
 *  \brief constructeur d'un Individu (0..0) ou (1..1)
 */
template <int TAILLE>
Individu<TAILLE>::Individu(bool b)
	{
	initrand();	

	for (int i=0; i<TAILLE; i++)
		_gene.set(i,b);

	_fitness=b?1:0;
	}

/** \fn Individu<TAILLE>::Individu(const Individu&)
 *  \brief constructeur par recopie 
 */
template <int TAILLE>
Individu<TAILLE>::Individu(const Individu<TAILLE>& ind)
	{
	_gene = ind._gene;
	_fitness= ind.fitness;
	}

/** \fn Individu<TAILLE>::Individu(const Individu&)
 *  \brief constructeur par recopie 
 */
template <int TAILLE>
Individu<TAILLE>& Individu<TAILLE>::operator=(const Individu<TAILLE>& ind)
	{
	if (&ind == this)
		return *this;

	_gene = ind._gene;
	_fitness= ind.fitness;
	return *this;
	}


/** \fn float ~Individu()
 *  \brief destructeur
 */
template <int TAILLE>
Individu<TAILLE>::~Individu()
	{
	}



/** \fn float Individu<TAILLE>::fitness(void)
 *  \brief recalcule le fitness
 *  \return la valeur du fitness
 */
template <int TAILLE>
float Individu<TAILLE>::fitness(void)
	{
	_fitness = ( (float) _gene.count()) / TAILLE; // one-max problem
	return _fitness;
	}

#endif


