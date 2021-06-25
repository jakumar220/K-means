#pragma once
#include "Centroid.h"
#include "Clustering.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
class SaveOut
{
public:
	void SaveCluster(std::vector<Centroid>&Centroids) //funkcja do zapisywania clusterow w osobnych plikach
	{
		int NumOfPoints;
		for (int i = 0; i < Centroids.size(); i++)//petla tworzaca plik wyjsciowy dla [i] clusteru
		{
			std::string ClusterName = "Cluster Number "; //nazwa pliku
			std::stringstream ss;
			ss << i;
			ClusterName += ss.str(); //numer centroidu dodawany do nazwy

			std::ofstream FileOut; //tworzenie pliku
			FileOut.open(ClusterName+".txt"); //ustawianie nazwy pliku
			if (FileOut.is_open())
			{
				NumOfPoints = Centroids[i].getNumOfPoints();//liczenie liczby punktow w clusterze [i] centroidu
				std::vector<Point>TempCluster(NumOfPoints);//tworzenie tymczasowego wektroa clustera
				TempCluster = Centroids[i].getCentroidPoints();//wpisanie do niego punktow [i] centroidu
				FileOut << "Wspolrzedne Centroidu: X = " << Centroids[i].getPoint().first << " Y = " << Centroids[i].getPoint().second << std::endl;
				FileOut << "Liczba punktow: " << NumOfPoints<< std::endl;
				for (int j = 0; j < NumOfPoints; j++)//petla do zapisywania wszystkich punktow clustera do pliku
				{
					FileOut << TempCluster[j].getPoint().first << " " << TempCluster[j].getPoint().second << std::endl;
				}

			}
			else
			{
				std::cerr << "Nie udalo sie utworzyc pliku: " <<ClusterName<<" program zakonczy dzialanie"; //zgloszenie bledu
				system("PAUSE");
				exit(1);
			}
			FileOut.close();
		}

	}


};