#include "stdafx.h"
#include "Numbering.h"

void Numbering::operator()(Athlete& ath){
	i++;
	ath.setNum(i);
}
