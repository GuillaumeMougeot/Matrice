#include <Matrice.hpp>
#include <fstream>

const double tabR[3][3] = {
	{0.999964371102955, 0, -0.00844135798738914},
	{0.000899868340938075, 0.994301737644801, 0.106598521347620},
	{0.00839325691494284, -0.106602319470685, 0.994266311770559}
};
const double vectT[3] = {0, 0, 16.0685085618962};


int main()
{
	Matrice<double> R(3, 3);
	Matrice<double> I(3, 3);
	Vecteur<double> t(3);
	Vecteur<double> crt(3);
	double tab[9];
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			R[i][j] = tabR[i][j];
		}
		t[i] = vectT[i];
	}
	
	crt = (R + I)*t;
	std::cout << crt;
	// std::ifstream fichier("nuage_1000.txt");
	// std::ofstream out("nuage_out.txt");
	// if(!fichier)
	// {
		// return 1;
	// }
	// while(!fichier.eof())
	// {
		// for(int i = 0; i < 9; i++)
		// {
			// fichier >> tab[i];
		// }
		// for(int i = 0; i < 3; i++)
		// {
			// crt[i] = tab[i];
		// }
		// crt = (R*crt) + t;
	// }
	return 0;
}