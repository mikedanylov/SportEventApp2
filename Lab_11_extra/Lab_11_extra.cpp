// Lab_11_extra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// specify '\n' as the only separator
struct field_reader : ctype<char> { 
	field_reader() : ctype<char>(get_table()) {}
	static ctype_base::mask const *get_table() {
		static vector<ctype_base::mask>
			rc(table_size, ctype_base::mask());
		rc['\n'] = ctype_base::space;
		return &rc[0];
	}
};

int randGen(int i) {
	return rand() % i;
}

int _tmain(int argc, _TCHAR* argv[])
{	
	srand(time(NULL));
	ifstream myfile("athletes.txt");
	// use our own separator list
	myfile.imbue(locale(locale(), new field_reader()));
	
	vector<Athlete> athletes;
	istream_iterator<string> istr_it(myfile);
	istream_iterator<string> istr_it_eof;
	ostream_iterator<Athlete> ostr_it(cout, "\n"); 
	copy(istr_it, istr_it_eof, back_inserter(athletes));
	
	// shuffle vector objects
	random_shuffle(athletes.begin(), athletes.end(),randGen);
	
	// numbering vector objects
	Numbering numbering;
	for_each(athletes.begin(), athletes.end(), numbering);
	
	
	for_each(athletes.begin(), athletes.end(), mem_fun_ref(&Athlete::readTime));
	
	//do something with vector
	cout << "\nFinal results are:\n";
	Sort s;
	sort(athletes.begin(), athletes.end(), s);
	copy(athletes.begin(), athletes.end(), ostr_it);
	

	return 0;
}

