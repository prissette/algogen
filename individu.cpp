#include "individu.h"
using namespace std;


// pour initialiser le générateur pseudo-aleatoire une seule fois
bool Individu::_initrand=false;
void Individu::initrand(int s=-1)
{
if (_initrand)
	return;

if (s==-1)
	srand(time(NULL));
else 
	srand(s);

_initrand=true;
}


/** \fn Individu::Individu()
 *  \brief Constructeur par defaut
 * 
 * Construction d'un individu de taille 0, sans fonction d'évaluation (NULL).
 */

Individu::Individu()
	{
	initrand();	

	_fitness=NULL;
	}

/** \fn Individu::Individu(unsigned int t)
 *  \param t	Taille du génôme
 *  \brief Constructeur d'un Individu avec un génôme de taille t
 *  
 *  Construction d'un individu de taille t avec un génôme binaire aléatoire et sans fonction d'évaluation (NULL).
 */

Individu::Individu(unsigned int t)
	{
	initrand();	

	_gene.resize(t);
	for (int i=0; i<t; i++)
		_gene[i]=rand()%2;

	_fitness=NULL;
	}

/** \fn Individu::Individu(const Individu& ind)
 *  \param ind Individu à recopier
 *  \brief Constructeur par recopie 
 */

Individu::Individu(const Individu& ind)
	{
	_gene = ind._gene;
	_fitness= ind._fitness;
	}

/** \fn Individu&::operator=(const Individu& ind)
 *  \param ind Individu à affecter
 *  \brief Operateur d'affectation 
 */

Individu& Individu::operator=(const Individu& ind)
	{
	if (&ind == this)
		return *this;

	_gene = ind._gene;
	_fitness= ind._fitness;
	return *this;
	}


/** \fn float ~Individu()
 *  \brief Destructeur
 */

Individu::~Individu()
	{
	}


/** \fn void Individu::set_taille(unsigned int t)
 *  \brief Redimensionne le gênome de l'Individu
 *  \param t Longueur du génôme
 * 
 * Redimensionne le gênome binaire de l'Individu. 
 * Si la nouvelle taille est inférieur, le génôme est tronqué.
 * Si la nouvelle taille est supérieur, les nouveaux bits sont remplis aléatoirement.
 */
void Individu::set_taille(unsigned int t)
	{
		unsigned int to;
		
		to=_gene.size();
		_gene.resize(t);
		
		for (int i=to; i<t; i++)
			_gene[i]=rand()%2;
	}


/** \fn unsigned int Individu::taille(void)
 *  \brief Renvoie la taille du génôme
 */
unsigned int Individu::taille(void) const
	{
		return _gene.size();
	}





/** \fn void Individu::set_fitness( double (*f)(const Individu &) )
 *  \brief Change la fonction fitness de l'Individu
 *  \param f : fonction fitness à utiliser
 * 
 *  La fonction fitness doit renvoyer un double compris entre 0 et 1, respectivement 
 *  pour un individu totalement inadapté et pour un individu parfaitement adapté.
 * 
 * Exemple : fonction qui récompense les individus 0101..0101 ou 1010..1010
 * 
 * \code{.cpp}
 * 
 * double fitness_blink(const Individu &ind)
 * {
 * 	int f=0;
 * 	for (int i=0; i<ind.taille(); i++)
 * 		if (ind[i]!=ind[i+1])
 * 			f++;
 * 	return ((double) f) / (TAILLE-1);
 * }
 * \endcode
 */

void Individu::set_fitness( double (*f)(const Individu &p) )
{
	_fitness=f;
}

/** \fn float Individu::fitness(void)
 *  \brief Calcule le fitness
 *  \return La valeur du fitness
 *  \tparam TAILLE : longueur du génôme
 * 
 *  Fitness est calculé à l'aide de la fonction pointée par l'Individu.
 *  Si la fonction pointée est NULL, la fonction fitness employée est celle du One Max Problem (récompense les individu ayant le plus grand poids de Hamming).
 */

double Individu::fitness(void) const
	{
	if (_fitness == NULL) // calcul le fitness du One Max Problem
		{
		int p=0;
		for (int i=0; i<taille(); i++)
			if (_gene[i]) p++;
		 
		return  ((float) p) / taille(); 
		}
	else
		return _fitness(*this);
	}

/** \fn bool& Individu::operator[](int pos)
 * \param pos Le bit auquel on veut accéder
 * \brief Renvoie une reference vers le ieme bit du genome
 */
int& Individu::operator[](int pos)
	{
		return _gene[pos];
	}

/** \fn bool Individu::operator[](int pos) const
 * \param pos Le bit auquel on veut accéder
 * \brief renvoie la valeur du ieme bit du genome
 */
int Individu::operator[](int pos) const
	{
		return _gene[pos];
	}



/** \relates Individu
 * \fn ostream& operator<<(ostream& c, const Individu& ind)
 * \param c Le flux sur lequel afficher
 * \param ind L'Individu à afficher
 * \brief Surcharge de l'operateur d'affichage
 * 
 *  Affiche le génôme et le fitness de l'Individu passé en paramêtre.
 */
	
ostream& operator<<(ostream& c, const Individu& ind)
	{
	for (int i=0; i<ind.taille(); i++)
		c << ind._gene[i];
	
	c << " (" << ind.fitness() << ")";
	return c;
	}
