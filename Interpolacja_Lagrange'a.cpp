#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

double roznica_dzielona(double x1, double x2, double y1, double y2)
{
	double w=0;
	w = (y2-y1)/(x2-x1);
	return w;
}

double roznice_dzielone(vector <vector <double>> &tabela, int numer_wiersza, int numer_kolumny)
{
	double p[numer_kolumny];
	double wynik=0;
	for(int i=1;i<numer_kolumny;i++)
	{
		wynik=roznica_dzielona(tabela[0][i-1], tabela[0][numer_kolumny+i-1],tabela[numer_wiersza][i-1],tabela[numer_wiersza][i]);
		p[i-1]=wynik;
	}
	return p;
}

int main()
{
	int liczba_wartosci_fx=0;
	vector <double> x;
	vector <double> y;
	vector <vector <double>> tabela;
	
	cout << "Podaj liczb\251 znanych warto\230ci f(x)\n";
	cin >> liczba_wartosci_fx;
	
	double pom, wyniki[liczba_wartosci_fx];
	
	for(int i=0;i<liczba_wartosci_fx;i++)
	{
		cout << "\nPodaj " << i+1 << " x: ";
		cin >> pom;
		x.push_back(pom);
		cout << "\nPodaj " << i+1 << " f(" << pom << "): ";
		cin >> pom;
		y.push_back(pom);
	}
	tabela.push_back(x);
	tabela.push_back(y);
	wyniki[0]=tabela[1][0];
	cout << "\n\n\tx\tf(x)\n----------------------------\n";
	
	for(int i=0;i<liczba_wartosci_fx;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout << "\t" << tabela[j][i] << "\t";
		}
		cout << endl;
	}
	
	double pom_tab[liczba_wartosci_fx-2];
	int pom1=liczba_wartosci_fx;
	for(int i=0;i<liczba_wartosci_fx;i++)
	{
		pom_tab=roznice_dzielone(tabela, i, pom1);
		wyniki[i+1]=pom_tab[0];
		pom1--;
	}
	for(int i=0;i<liczba_wartosci_fx;i++)
		cout << wyniki[i] << endl;
	/*int pom3=3;
	cout << "\n\nTabela:\n";
	for(int i=0;i<pom3;i++)
	{
		for(int j=2;j<5;j++)
		{
			cout << "\t" << tabela[j][i] << "\n";
		}
		//cout << endl;
		pom3--;
	}*/
	/*string function = "";
	cout << "Funkcja ta to w przyblizeniu: " << endl;
	for (int k=1;k<=liczba_wartosci_fx;k++){
		cout << tabela[k][0] << function;
		if (k!=liczba_wartosci_fx){
			cout << " + ";
		}
		function = function + " * ( x -" + to_string(tabela[0][k-1]) + " )";
	}*/
	
	getch();
	return 0;
}
