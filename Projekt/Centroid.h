#pragma once
#include "Point.h"
#include "vector"
#include <random>
#include <algorithm>
class Centroid : public Point{
protected:
	std::vector<Point>centroid; //wektor punktow nalezacych do clustera centroidu

public:

	void setCentroid( double rangeX, double rangeY) { //funkcja wybierajaca losowe wspolrzedne centroidu
		static std::default_random_engine gen1;
		static std::default_random_engine gen2;
		std::uniform_int_distribution<int> dist1(0, rangeX);
		std::uniform_int_distribution<int> dist2(0, rangeY);
		position.first = dist1(gen1);
		position.second = dist2(gen2);
	}
	void assignPoint(Point &points)//funkcja dodajaca punkt do clustera centroidu
	{

		centroid.push_back(points);
	}
	void saveLast()//funkcja czyszczaca cluster centroidu
	{
		centroid.erase(centroid.begin(), centroid.end());
	}
	void changeCentroid(double x, double y) //funkcja zmieniajaca wspolrzedne centroidu
	{
		position.first = x;
		position.second = y;
	}
	std::vector<Point> getCentroidPoints() //funkcja zwracajaca cluster centroidu
	{
		return centroid;
	}
	
	int getNumOfPoints() //funkcja liczaca ilosc punktow w clusterze centroidu
	{
		return centroid.size();
	}
};