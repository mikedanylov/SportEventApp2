#include "stdafx.h"
#include "Athlete.h"


Athlete::Athlete(string name){
	this->number = 0;
	this->name = name;
	this->time = 0;
}

ostream& operator<<(ostream& out, Athlete a){
	out << a.number << ". " << a.name << "\t" << a.time;
	return out;
}

void Athlete::setNum(int num){
	this->number = num;
}

void Athlete::readTime(){
	cout << "Give time for ";
	cout << this->name << " ? ";
	cin >> this->time;
}

int Athlete::getTime(){
	return this->time;
}
