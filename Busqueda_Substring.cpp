// Busqueda_Substring.cpp 
// Kevin Cabrera

#include<iostream>
#include<string>
using namespace std;

// Metodo que busca dentro del string principal el patron de strings a encontrar
bool search(string str, string pattern)
{
	int n = str.length();
	int m = pattern.length();

	// Ciclo que recorre la posicion del string
	for (int i = 0; i <= n - m; i++)
	{
		int j;
		for (j = 0; j < m; j++)
		{
			if (str[i + j] != pattern[j])
				break;
		}
		if (j == m)
			return true;
	}
	return false;
}

// Funcion principal en donde se declara el string y se declara el substring a encontrar
int main()
{
	string str = "desarrollodevideojuegos";
	string pattern = "llodevid";

	// Si se encuentra el substring se desplegara un mensaje
	if (search(str, pattern))
	{
		cout << "El substring esta presente en el string principal" << endl;
	}
	// De lo contrario se imprimira que no esta presente el substring
	else
	{
		cout << "El substring no esta presente" << endl;
	}

	return 0;
}
