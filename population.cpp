#include "population.h"

Population::Population()
	{
	}

Population::Population(const Population& p)
	{
	_population=p._population;
	}

Population& Population::operator=(const Population&)
{
}

Population::~Population()
{
}
	
// constructeurs additionnels
Population::Population(int nb) // nombre d'Individus
{
	for (int i=0; i<nb; i++) _population.push_back(Individu());
}

Population::Population(int nb, int t) // nombre d'Individus, taille des Individus
{
	for (int i=0; i<nb; i++) _population.push_back(Individu(t));
}

Population::Population(int nb, int t, double (*_fitness)(const Individu &p)) // nombre d'Individus, taille des Individus, fonction fitness
{
	for (int i=0; i<nb; i++) 
		{
		_population.push_back(Individu(t));
		_population[i].set_fitness( _fitness );
		}
}
		
// interfaces
int Population::size()
{
	return _population.size();
}

void Population::set_size(int nb)
{
}

		
int Population::size_gene()
{
}

void Population::set_size_gene()
{
}

		
void Population::set_fitness(double (*_fitness)(const Individu &p))
{
}
