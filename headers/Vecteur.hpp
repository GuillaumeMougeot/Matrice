#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <vector>
#include <iostream>
#include <fstream>

/* DECLARATION */
template <class T>
class Vecteur
{
public:
	// Constructeurs et destructeurs
	Vecteur(int taille);
	Vecteur(T nombre, int taille);
	Vecteur(std::vector<T> const& vecteur);
	~Vecteur();
	
	// Accesseurs
	int getTaille() const {return m_taille;}
	T& operator[](std::size_t indice) {return m_vecteur[indice];}
	
	// Surcharge d'operateurs
	Vecteur<T>& operator=(Vecteur<T> const& vecteur);
	Vecteur<T>& operator=(Vecteur<T> const& vecteur);
	//T operator*(Vecteur<T> const& A, Vecteur<T> const& B);
	
	// Surcharge de l'operateur particulier <<
	template <class U>
	friend std::ostream& operator<<(std::ostream& flux, Vecteur<U> const& vecteur);
	
	// Utile
	
private:
	int m_taille;
	std::vector<T> m_vecteur;
	
	// Affichage
	void afficher(std::ostream& out) const;
};

/* IMPLEMENTATION */
template <class T>
Vecteur<T>::Vecteur(int taille)
{
	m_taille = taille;
	// On initialise la vecteur de base 0
	for(int i = 0; i < m_taille; i++)
	{
		m_vecteur.push_back(0);
	}
}

template <class T>
Vecteur<T>::Vecteur(T nombre, int taille)
{
	m_taille = taille;
	for(int i = 0; i < m_taille; i++)
	{
		m_vecteur.push_back(nombre);
	}
}

template <class T>
Vecteur<T>::Vecteur(std::vector<T> const& vecteur)
{
	m_taille = vecteur.size();
	vecteur = m_vecteur;
}

template <class T>
Vecteur<T>::~Vecteur()
{
	m_vecteur.clear();
}

template <class T>
Vecteur<T>& Vecteur<T>::operator=(Vecteur<T> const& vecteur)
{
	m_taille = vecteur.m_taille;
	m_vecteur = vecteur.m_vecteur;
	return *this;
}

template <class T>
Vecteur<T> operator+(Vecteur<T>& A, Vecteur<T>& vecteur)
{
	Vecteur<T> resultat(matrice.getLigne());
	if (matrice.getColonne() != vecteur.getTaille())
	{
		std::cout << "[Erreur] Les dimensions ne correspondent pas. Multipliation echouee." << std::endl;
	}
	else
	{
		for(int i = 0; i < matrice.getLigne(); i++)
		{
			for(int j = 0; j < matrice.getColonne(); j++)
			{
				resultat[i] += matrice[i][j] * vecteur[j];
			}
		}
	}
	
	return resultat;
}

// template <class T>
// T Vecteur<T>::operator*(Vecteur<T> const& A, Vecteur<T> const& B)
// {
	// T resultat = 0;
	// if (A.m_taille != B.m_taille)
	// {
		// std::cout << "[Erreur] Les tailles ne correspondent pas. Abandon." << std::endl;
	// }
	// else
	// {
		// for (int i = 0; i < A.m_taille; i++)
		// {
			// resultat += A.m_vecteur[i]*B.m_vecteur[i];
		// }
	// }
	// return resultat;
// }

template <class T>
void Vecteur<T>::afficher(std::ostream& out) const
{
	out << '[';
	for(int i = 0; i < m_taille; i++)
	{
		out << m_vecteur[i];
		if (i < m_taille-1)
		{
			out << std::endl;
		}
	}
	out << ']' << std::endl;
}

template <class T>
std::ostream& operator<<(std::ostream& flux, Vecteur<T> const& vecteur)
{
	vecteur.afficher(flux);
	return flux;
}

#endif






