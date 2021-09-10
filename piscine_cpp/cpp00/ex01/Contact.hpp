#ifndef PISCINE_CPP_CONTACT_H
#define PISCINE_CPP_CONTACT_H

#include "phonebook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>

class Contact {

public:
					Contact();
					~Contact();
	void			editData(int field, std::string data);
	std::string		getData(int field) const;
	void 			displaySample(int index);
	void 			displayFull();

private:
	std::string		data[DATA_LEN];
	void 			displayField(std::string word);
};


#endif //PISCINE_CPP_CONTACT_H
