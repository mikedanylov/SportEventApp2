#pragma once
class Athlete{

friend ostream& operator<<(ostream&, Athlete);

private:
	int number;
	string name;
	int time;
public:
	Athlete(string);
	void setNum(int);
	void readTime();
	int getTime();
};

