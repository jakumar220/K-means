#pragma once
#include "Centroid.h"
#include <limits>

class Clustering {
public:
	void ClusterAssignPoints(std::vector<Point>&Points, std::vector<Centroid>&Centroids)//funkcja do przyporz¹dowwywania punktów do centroidów
	{
		
		int c = 0; //licznik do sprawdzania ilosci iteracji while
		std::pair<double, double> JPoint; // Zmienna tymczasowa do Punktu [j]
		std::pair<double, double> KCentroid; //Zmienna tymczasowa do Centroidu [k]
		std::pair<double, double> JCentroid; //Zmienna tymczasowa do Centroidu [j]
 		std::vector<Point> CentroidPoints; //Zmienna z punktami centroidu		
		

		while (c<Centroids.size()*5) //petla wykonujaca sie, az algorytm bedzie wystarczajaco efektywny
		{
			
			c++;// iteracja licznika
			
			
				for (int j = 0; j < Points.size(); j++) //petla do przyporzadkowania punktu
				{
					JPoint = Points[j].getPoint();
					double minDistance = std::numeric_limits<double>::max(); //ustawienie odleglosci na max
					int centroidNum = 0;
					
					for (int k = 0; k < Centroids.size(); k++)
					{
						KCentroid = Centroids[k].getPoint();//wrzucenie punktu do zmiennej tymczasowej
						double distance = (JPoint.first - KCentroid.first)*(JPoint.first - KCentroid.first) + (JPoint.second - KCentroid.second)*(JPoint.second - KCentroid.second); //odleglosc euklidesa
						if (distance < minDistance)//sorawdzanie czy punkt jest w najblizsym centroidzie
						{
							centroidNum = k;
							minDistance = distance;
						}
					}
					Centroids[centroidNum].assignPoint(Points[j]); //przypisanie punktu do centroidu
				}
				

				for (int j = 0; j < Centroids.size();j++) //petla do obliczania nowych wspolrzednych centroidu
				{
					CentroidPoints = Centroids[j].getCentroidPoints();//pobranie punktow centroidu
					double sumX = 0; //wspolrzedna x
					double sumY = 0; //wspolrzedna y
					double meanX = 0; //srednia wspolrzednych x
					double meanY = 0; //srednia wspolrzednych y
					int numOfPoints = Centroids[j].getNumOfPoints();//ilosc punktow w clusterze centroidu

					for (int k = 0; k < numOfPoints;k++)// petla do liczenia sumy wszystkich wspolrzednych punktow 
					{
						JCentroid = CentroidPoints[k].getPoint();
						sumX += JCentroid.first; //inkrementacja sumy wspolrzednych x
						sumY += JCentroid.second; //inkrementacja sumy wspolrzednych y
					}
					meanX = round(sumX/numOfPoints); //liczenie sredniej x
					meanY = round(sumY/numOfPoints); //liczenie sredniej y
		
					
					Centroids[j].changeCentroid(meanX,meanY); //zmiana wspolrzednych centoridu
					if (c != Centroids.size() * 5 ) //jesli to nie ostatnia iteracja to czysci cluster
				{
					Centroids[j].saveLast(); //czyszczenie clustera
				}
				}
					
				}
				
				
	}


};

