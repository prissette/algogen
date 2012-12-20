/** \file population.h
 * \author Cyril Prissette (Laboratoire LSIS - UMR 7296)
 * \version   0.1
 * \date      2012
 * \warning   Travail de recherche, ne pas utiliser les yeux fermés
 * Header pour la classe Population
 */
 
 #ifndef __INDIVIDU__
#define __INDIVIDU__

#include <iostream>
#include <vector>
using namespace std;

#include "individu.h"

/** \class Population
 *  \brief Decrit une population constituée d'Individu.
 *
 * Une Population est un ensemble d'Individu ayant chacun son génôme et sa fonction fitness.
 * Afin d'explorer differentes variantes d'algorithme génétique, la fonction fitness n'est pas 
 * définie au niveau de la Population. Il est néanmoins possible de passer cette fonction lors 
 * de la création et la manipulation de la Population pour que tous les nouveaux Individu de cette population soient affectés. 
 */
class Population
    {
	protected :
		/// Ensemble des Individu constituant la population
        vector< Individu > _population; 
    
    public :
		Population();
		Population(const Population&);
		Population& operator=(const Population&);
		~Population();
		
		// constructeurs additionnels
		Population(int); // nombre d'Individus
		Population(int, int); // nombre d'Individus, taille des Individus
		Population(int, int, double (*_fitness)(const Individu &p)); // nombre d'Individus, taille des Individus, fonction fitness
		
		// interfaces
		int size();
		void set_size(int);
		
		int size_gene();
		void set_size_gene();
		
		void set_fitness(double (*_fitness)(const Individu &p));
	};

#endif
		
