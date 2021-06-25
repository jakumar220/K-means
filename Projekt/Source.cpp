#include <iostream>
#include "verification.h"
#include "Clustering.h"
#include "SaveOut.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int main(int argc, char** argv)
{
	

	char* filename = nullptr; //nazwa pliku z argumentu
	int centroids_number = 0; //liczba centroidow
	if (!ver_arg(argc, argv, filename, centroids_number)) {	
		system("PAUSE");
		return 99;
	}
	
	std::vector<Point> MyPoints; //wektor punktow
	std::vector<Centroid> MyCentroids(centroids_number); //wektor centroidow
	Clustering MyClustering;//instancja klasy Clustering
	SaveOut TimeToSave;//instancja klasy SaveOut
	
	Point TempPoint; //punkt
	string wordX; //stringi na przechowywanie pobranego ciagu znakow 
	string wordY;
	double x,y; //zmienne ze wspolrzednymi punktow 
	double maxX=0, maxY=0; //zmienne na zakres punktow
	std::ifstream FileIn(filename); //otworzenie pliku wejsciowego
	while (FileIn >> wordX)//zapis z pliku do stringow
	{
		FileIn >> wordY;
		try {
			x = std::stod(wordX); //zamiana string na double
		}
		catch (const std::logic_error& le)
		{
			std::cerr << "Bledne dane wejsciowe w X " << std::endl;
			system("PAUSE");
			return -1;
		}
		try {
			y = std::stod(wordY);
		}
		catch (const std::logic_error& le)
		{
			std::cerr << "Bledne dane wejsciowe w Y " << std::endl;
			system("PAUSE");
			return -2;
		}
		TempPoint.setPoint(x, y); //wpisanie wspolrzednych do punktu
		MyPoints.push_back(TempPoint);//wpisanie do wektora punktow
		if (x>maxX)//liczenie zakresu x
		{
			maxX = x;
		}
		if (y>maxY)//liczenie zakresu y
		{
			maxY = y;
		}

	}
	FileIn.close(); //zamkniecie pliku
	for (int i = 0; i < centroids_number; i++)//petla do podawania wspolrzednych 
	{
		MyCentroids[i].setCentroid(maxX,maxY);//podanie zakresu dla wspolrzednych losowego centroidu
	}
	MyClustering.ClusterAssignPoints(MyPoints, MyCentroids);//funkcja do przypisywania punktow do clusterow danych centroiddow
	TimeToSave.SaveCluster(MyCentroids); //zapis clusterow do plikow



}