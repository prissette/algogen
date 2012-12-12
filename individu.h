/** \file individu.h
 * \author Cyril Prissette (Laboratoire LSIS - UMR 7296)
 * \version   0.1
 * \date      2012
 * \warning   Travail de recherche, ne pas utiliser les yeux fermés
 * Header pour les classes Individu et Population
 * Les classes Individu et Population sont des classes templates, seul ce fichier d'entête est nécessaire.
 */

#ifndef __INDIVIDU__
#define __INDIVIDU__

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#include <stdlib.h>
#include <time.h>



/** \class Individu
 *  \brief decrit un unique individu, avec son génome
 * 
 *  \tparam TAILLE : longueur du génôme
 */
template <int TAILLE>
class Individu
    {
    public :
        bitset<TAILLE> _gene; /// génôme binaire de l'individu individu
		float _fitness; // fitness de l'individu

		Individu();
		Individu(bool b);
		Individu(const Individu<TAILLE>&);
		Individu<TAILLE>& operator=(const Individu<TAILLE>&);
		virtual ~Individu();
			
		virtual double fitness(void); // a changer quand on herite pour un autre probleme

		template <int T>	
		friend ostream& operator<<(ostream&, const Individu<T>&);

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
 *  \tparam TAILLE : longueur du génôme
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
 *  \tparam TAILLE : longueur du génôme
 */
template <int TAILLE>
Individu<TAILLE>::Individu(bool b)
	{
	initrand();	

	for (int i=0; i<TAILLE; i++)
		_gene.set(i,b);

	_fitness=b?1:0;
	}

/** \fn Individu<TAILLE>::Individu(const Individu<TAILLE>&)
 *  \brief constructeur par recopie 
 *  \tparam TAILLE : longueur du génôme
 */
template <int TAILLE>
Individu<TAILLE>::Individu(const Individu<TAILLE>& ind)
	{
	_gene = ind._gene;
	_fitness= ind._fitness;
	}

/** \fn Individu<TAILLE>&::operator=(const Individu<TAILLE>&)
 *  \brief constructeur par recopie 
 *  \tparam TAILLE : longueur du génôme
 */
template <int TAILLE>
Individu<TAILLE>& Individu<TAILLE>::operator=(const Individu<TAILLE>& ind)
	{
	if (&ind == this)
		return *this;

	_gene = ind._gene;
	_fitness= ind._fitness;
	return *this;
	}


/** \fn float ~Individu()
 *  \brief destructeur
 *  \tparam TAILLE : longueur du génôme
 */
template <int TAILLE>
Individu<TAILLE>::~Individu()
	{
	}


/** \fn float Individu<TAILLE>::fitness(void)
 *  \brief recalcule le fitness
 *  \return la valeur du fitness
 *  \tparam TAILLE : longueur du génôme
 * 
 *  Fitness pour le One Max Problem, pour tester la bibliothèque
 */
template <int TAILLE>
double Individu<TAILLE>::fitness(void)
	{
	_fitness = ( (float) _gene.count()) / TAILLE; // one-max problem
	return _fitness;
	}

/** \fn ostream& operator<<(ostream& c, const Individu<TAILLE>& ind)
 *  \brief surcharge de l'operateur d'affichage
 *  \tparam TAILLE : longueur du génôme
 * 
 *  Affiche le génôme et le fitness de l'individu
 */
template <int TAILLE>	
ostream& operator<<(ostream& c, const Individu<TAILLE>& ind)
	{
	c << ind._gene << " (" << ind._fitness << ")";
	return c;
	}

//**********************************************************************
//**                                                                  **
//**                           POPULATION                             **
//**                                                                  **
//**********************************************************************

/** \class Population
 *  \brief ensemble d'Individu
 * 
 *  \tparam TAILLE : longueur du génôme des individus
 *  \tparam NB_INDIVIDU : nombre d'individus de la population
 */
template <int NB_INDIVIDU, int TAILLE> // taille population, taille des genes 
class Population
	{
	public :
		vector< Individu<TAILLE> > _individus;
		int _taille_population;
		
		Population();
		Population(const Population<NB_INDIVIDU, TAILLE>&);
		Population<NB_INDIVIDU, TAILLE>& operator=(const Population<NB_INDIVIDU, TAILLE>&);
		virtual ~Population();
		
		
		template <int N, int T>	
		friend ostream& operator<<(ostream&, const Population<N,T>&);

	};

/** \fn Population<NB_INDIVIDU, TAILLE>::Population()
 *  \brief constructeur par défaut
 * 
 *  Génère une population aléatoire.
 */
template <int NB_INDIVIDU, int TAILLE>
Population<NB_INDIVIDU, TAILLE>::Population()
	{
	_taille_population=NB_INDIVIDU;	

	for (int i=0; i<_taille_population; i++) _individus.push_back(Individu<TAILLE>());
	}

/** \fn Population<NB_INDIVIDU, TAILLE>::Population()
 *  \brief constructeur par recopie
 *  \param p : population à recopier
 * 
 *  Recopie la population p.
 */
template <int NB_INDIVIDU, int TAILLE>
Population<NB_INDIVIDU, TAILLE>::Population(const Population<NB_INDIVIDU, TAILLE> &p)
	{
	_taille_population=p._taille_population;
	
	for (int i=0; i<_taille_population; i++) _individus.push_back( p._individus[i] );
	}

/** \fn Population<NB_INDIVIDU, TAILLE>& Population<NB_INDIVIDU, TAILLE>::operator=(const Population<NB_INDIVIDU, TAILLE>&p)
 *  \brief surcharge de l'opérateur d'affectation
 *  \param p : population à recopier
 * 
 *  Recopie la population p.
 */	
template <int NB_INDIVIDU, int TAILLE>
Population<NB_INDIVIDU, TAILLE>& Population<NB_INDIVIDU, TAILLE>::operator=(const Population<NB_INDIVIDU, TAILLE>&p)
	{
	if (&p == this)
		return *this;
	
	for (int i=0; i<_taille_population; i++) _individus.push_back( p._individus[i] );

	return *this;
	
	}

/** \fn Population<NB_INDIVIDU, TAILLE>::~Population()
 *  \brief destructeur
 * 
 *  Detruit la population p.
 */	
template <int NB_INDIVIDU, int TAILLE>
Population<NB_INDIVIDU, TAILLE>::~Population()
	{
	
	}
	
/** \fn ostream& operator<<(ostream& c, const Population<NB_INDIVIDU, TAILLE>& p)
 *  \brief surcharge de l'opérateur d'affichage
 *  \param c : le flux de sortie
 *  \param p : la population à afficher
 * 
 *  Affiche la population p, à l'aide de l'opérateur d'affichage d'un individu.
 */	
template <int NB_INDIVIDU, int TAILLE>	
ostream& operator<<(ostream& c, const Population<NB_INDIVIDU, TAILLE>& p)
	{
	for (int i=0; i<p._taille_population; i++) c << p._individus[i] << endl;
	
	return c;
	}

#endif



