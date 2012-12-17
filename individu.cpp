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
 *  \brief constructeur par defaut d'un Individu aleatoire
 *  \tparam TAILLE : longueur du génôme
 */

Individu::Individu()
	{
	initrand();	

	for (int i=0; i<taille(); i++)
		_gene[i]=rand()%2;

	_fitness=NULL;
	}

/** \fn Individu::Individu(unsigned int t)
 *  \brief constructeur d'un Individu avec un génôme de taille non nulle
 *  \param t : longueur du génôme
 */

Individu::Individu(unsigned int t)
	{
	initrand();	

	_gene.resize(t);
	for (int i=0; i<t; i++)
		_gene[i]=rand()%2;

	_fitness=NULL;
	}

/** \fn Individu::Individu(const Individu&)
 *  \brief constructeur par recopie 
 *  \tparam TAILLE : longueur du génôme
 */

Individu::Individu(const Individu& ind)
	{
	_gene = ind._gene;
	_fitness= ind._fitness;
	}

/** \fn Individu&::operator=(const Individu&)
 *  \brief constructeur par recopie 
 *  \tparam TAILLE : longueur du génôme
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
 *  \brief destructeur
 *  \tparam TAILLE : longueur du génôme
 */

Individu::~Individu()
	{
	}


/** \fn void Individu::set_taille(unsigned int t)
 *  \brief redimensionne un Individu
 *  \param t : longueur du génôme
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
 *  \brief taille du genome
 */
unsigned int Individu::taille(void) const
	{
		return _gene.size();
	}





/** \fn void Individu::set_fitness( double (*f)(const Individu &p) )
 *  \brief change la fonction fitness d'un individu
 *  \param f : fonction fitness à utiliser
 * 
 *  Si la fonction fitness n'est pas définie (_fitness vaut NULL),
 *  calcule le fitness pour le One Max Problem.
 * 
 *  La fonction fitness doit renvoyer un double compris entre 0 et 1, respectivement 
 *  pour un individu totalement inadapté et pour un individu parfaitement adapté
 * 
 * Exemple : fonction qui récompense les individu 0101..0101 ou 1010..1010
 * 
 * \code{.cpp}
 * 
 * double fitness_blink(const Individu &p)
 * {
 * 	int f=0;
 * 	for (int i=0; i<TAILLE-1; i++)
 * 		if (p._gene[i]!=p._gene[i+1])
 * 			f++;
 * 	return ((float) f) / (TAILLE-1);
 * }
 * \endcode
 */

void Individu::set_fitness( double (*f)(const Individu &p) )
{
	_fitness=f;
}

/** \fn float Individu::fitness(void)
 *  \brief recalcule le fitness
 *  \return la valeur du fitness
 *  \tparam TAILLE : longueur du génôme
 * 
 *  Fitness pour le One Max Problem, pour tester la bibliothèque
 */

double Individu::fitness(void) const
	{
	if (_fitness == NULL)
		{
		int p=0;
		for (int i=0; i<taille(); i++)
			if (_gene[i]) p++;
		 
		return  ((float) p) / taille(); // one-max problem
		}
	else
		return _fitness(*this);
	}

/** \fn bool& Individu::operator[](int pos)
 * \brief renvoie une reference vers le ieme bit du genome
 */
int& Individu::operator[](int pos)
	{
		return _gene[pos];
	}

/** \fn bool Individu::operator[](int pos) const
 * \brief renvoie la valeur du ieme bit du genome
 */
int Individu::operator[](int pos) const
	{
		return _gene[pos];
	}



/** \fn ostream& operator<<(ostream& c, const Individu& ind)
 *  \brief surcharge de l'operateur d'affichage
 * 
 *  Affiche le génôme et le fitness de l'individu
 */
	
ostream& operator<<(ostream& c, const Individu& ind)
	{
	for (int i=0; i<ind.taille(); i++)
		c << ind._gene[i];
	
	c << " (" << ind.fitness() << ")";
	return c;
	}
