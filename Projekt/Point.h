#pragma once
#include <utility>

class Point {
protected:
	std::pair<double, double>position;


public:
	Point() { position.first = 1; position.second = 1; } //konstruktor domyslny
	Point(const std::pair<double, double>&position) :position(position) {}//konstruktor
	
	virtual std::pair<double, double> getPoint() { return position; }; //funkcja zwracajaca wspolrzedne punktu
	
	virtual void setPoint(const double &first, const double&second) //funkcja ustawiajaca wspolrzedne punktu
	{
		
		position.first = first;
		position.second = second;
	};
	
};