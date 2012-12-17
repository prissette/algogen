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
 */
class Individu
    {
    public :
        vector<int> _gene; /// génôme binaire 
		double (*_fitness)(const Individu &p); /// fonction fitness de l'individu

		Individu();
		Individu(unsigned int);
		Individu(const Individu&);
		Individu& operator=(const Individu&);
		virtual ~Individu();
			
		void set_fitness( double (*_fitness)(const Individu &p) );
		double fitness(void) const;
		
		unsigned int taille(void) const;
		void set_taille(unsigned int);
		
		int& operator[](int);
		int operator[](int) const;
		
		friend ostream& operator<<(ostream&, const Individu&);

	// pour initialiser le générateur pseudo-aleatoire une seule fois
	private :
		static bool _initrand;
		void initrand(int);
		
    };


//**********************************************************************
//**                                                                  **
//**                           POPULATION                             **
//**                                                                  **
//**********************************************************************
/*
/** \class Population
 *  \brief ensemble d'Individu
 * 
 *  \tparam TAILLE : longueur du génôme des individus
 *  \tparam NB_INDIVIDU : nombre d'individus de la population
 *
template <int NB_INDIVIDU, int TAILLE> // taille population, taille des genes 
class Population
	{
	public :
		vector< Individu > _individus;
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
 *
template <int NB_INDIVIDU, int TAILLE>
Population<NB_INDIVIDU, TAILLE>::Population()
	{
	_taille_population=NB_INDIVIDU;	

	for (int i=0; i<_taille_population; i++) _individus.push_back(Individu());
	}

/** \fn Population<NB_INDIVIDU, TAILLE>::Population()
 *  \brief constructeur par recopie
 *  \param p : population à recopier
 * 
 *  Recopie la population p.
 *
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
 *
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
 *
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
 *
template <int NB_INDIVIDU, int TAILLE>	
ostream& operator<<(ostream& c, const Population<NB_INDIVIDU, TAILLE>& p)
	{
	for (int i=0; i<p._taille_population; i++) c << p._individus[i] << endl;
	
	return c;
	}
*/
#endif



