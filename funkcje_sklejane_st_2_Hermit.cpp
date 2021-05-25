#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;

void oblicz_hi(vector<double> &ti, int n, vector<double> &hi)
{
	double p;
	for(int i=0;i<n;i++)
	{
		p=ti[i+1]-ti[i];
		hi.push_back(p);
	}
}

void oblicz_bi(vector<double> &yi, vector<double> &hi, int n, vector<double> &bi)
{
	double p;
	for(int i=0;i<n;i++)
	{
		p=(1/hi[i])*(yi[i+1]-yi[i]);
		bi.push_back(p);
	}
}

void oblicz_ui(vector<double> &hi, int n, vector<double> &ui)
{
	double p;
	for(int i=1;i<n;i++)
	{
		if(i==1)
		{
			p=2*(hi[0]+hi[1]);
			ui.push_back(p);
		}
		else
		{
			p=2*(hi[i-1]+hi[i])-(hi[i-1]*hi[i-1])/ui[i-1];
			ui.push_back(p);
		}
	}
}

void oblicz_vi(vector<double> &bi, vector<double> &hi, vector<double> &ui, int n, vector<double> &vi)
{
	double p;
	for(int i=1;i<n;i++)
	{
		if(i==1)
		{
			p=6*(bi[1]-bi[0]);
			vi.push_back(p);
		}
		else
		{
			p=6*(bi[i]-bi[i-1])-(hi[i-1]*vi[i-1])/ui[i-1];
			vi.push_back(p);
		}
	}
}

void oblicz_zi(vector<double> &vi, vector<double> &hi, vector<double> &ui, int n, vector<double> &zi)
{
	double p;
	for(int i=n;i>=0;i--)
	{
		if(i==0)
		{
			zi.push_back(0);
		}
		else if(i==n)
		{
			zi.push_back(0);
		}
		{
			p=vi[i]-(hi[i]*zi[i+1])/ui[i];
			zi.push_back(p);
		}
	}
	
}

int main()
{
	int lpunktow;
	
	cout << "Liczba znanych punktow: ";
	cin >> lpunktow;
	
	vector<double> ti;
	vector<double> yi;
	vector<double> hi;
	vector<double> bi;
	vector<double> ui;
	vector<double> vi;
	vector<double> zi;
	double pom;
	
	for(int i=0;i<lpunktow;i++)
	{
		cout << "\nt" << i << " = ";
		cin >> pom;
		ti.push_back(pom);
		cout << "\ny" << i << " = ";
		cin >> pom;
		yi.push_back(pom);
	}
	
	oblicz_hi(ti, lpunktow-1, hi);
	oblicz_bi(yi, hi, lpunktow-1, bi);
	
	oblicz_ui(hi, lpunktow-1, ui);
	oblicz_vi(bi, hi, ui, lpunktow-1, vi);
	
	oblicz_zi(vi, hi, ui, lpunktow, zi);
	
	for(int i=0;i<2;i++)
	{
		cout << "\nS" << i << "(x) = (" << zi[i+1] << " / 6 * " << hi[i] << ") * (x - " << ti[i] << ")^3 + ((" << yi[i+1] << " / " << hi[i] << ") - ((" << hi[i] << " / 6) * " << zi[i+1] << ") * (x - " << ti[i] << ") + ((" << yi[i] << " / " << hi[i] << ") - (" << hi[i] << " / 6) * " << zi[i] << ") * (" << ti[i+1] << " - x)\n\n";
	}
	
	getch();
	return 0;
}
