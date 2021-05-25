#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;

double oblicz_Lx(double wprowadzone_x, vector <double> &x, vector <double> &wybrane_wartosci)
{
	int pom=0;
	double wynik_Lx=0, p=0;
	for(int i=0;i<wybrane_wartosci.size();i++)
	{
		pom++;
		wynik_Lx = wynik_Lx + wybrane_wartosci[i];
		cout << wynik_Lx << endl; 
		for(int j=0;j<pom;j++)
		{
			p = wynik_Lx * (wprowadzone_x - x[j]);
		}
		wynik_Lx += p;
	}
	return wynik_Lx;

}

double roznica_dzielona(double x1, double x2, double y1, double y2)
{
	double wynik=0;
	return wynik = (y2-y1)/(x2-x1);
}

void roznice_dzielone(vector<vector <double> > &tabela, int numer_kolumny, int liczba_znanych_zmiennych){
	vector<double> pom;
	double wynik;
	for (int i=1;i<liczba_znanych_zmiennych;i++)
	{
		pom.push_back(roznica_dzielona(tabela[0][i-1], tabela[0][numer_kolumny+i-1], tabela[numer_kolumny][i-1], tabela[numer_kolumny][i]));
	}
	tabela.push_back(pom);
}

int main()
{
	int liczba_znanych_zmiennych;
	vector<vector<double> > tabela;
	vector<double> x;
	vector<double> y;  
	double pom;
	
	cout << "Podaj liczbe znanych wartosci" << endl;
	cin >> liczba_znanych_zmiennych;
	
	
	for(int i=0;i<liczba_znanych_zmiennych;i++)
	{
		cout << "Podaj " << i+1 << " x" << endl;
		cin >> pom;
		x.push_back(pom);
		cout << "Podaj wartosc f(" << pom << ")" << endl;
		cin >> pom;
		y.push_back(pom);
	}
	
	tabela.push_back(x);
	tabela.push_back(y);
	
	int kolumny = liczba_znanych_zmiennych;
	
	for(int i=1;i<liczba_znanych_zmiennych;i++)
	{
		roznice_dzielone(tabela, i, kolumny);
		kolumny--;
	}
	
	vector <double> wybrane_wartosci/*[liczba_znanych_zmiennych]*/;
	for (int i=1;i<=liczba_znanych_zmiennych;i++)
	{
		wybrane_wartosci.push_back(tabela[i][0]);
	}
	
	cout << "\nPrzyblizona funkcja L(x)\n\n";
	
	string funkcja_string = "";
	for(int i=0;i<liczba_znanych_zmiennych;i++)
	{
		cout << "(" << wybrane_wartosci[i] << ")" << funkcja_string;
		if (i+1<liczba_znanych_zmiennych)
		{
			cout << " + ";
		}
		funkcja_string = funkcja_string + "*(x - " + to_string(x[i]) + ")";
	}
	
	double wprowadzono_x;
	
	cout << "\n\nDla jakiego x chcesz obliczyc L(x)?\n\n";
	
	cin >> wprowadzono_x;
	
	cout << "\n\nWynik L(" << wprowadzono_x << ") to " << oblicz_Lx(wprowadzono_x, x, wybrane_wartosci);

}
