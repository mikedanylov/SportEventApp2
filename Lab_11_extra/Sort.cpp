#include "stdafx.h"
#include "Sort.h"

bool Sort::operator()(Athlete i, Athlete j){
	if (i.getTime() < j.getTime())
		return true;
	else
		return false;
}
