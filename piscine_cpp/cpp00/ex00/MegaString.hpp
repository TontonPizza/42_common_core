#ifndef CPP_MEGASTRING_H
#define CPP_MEGASTRING_H

#include <string>

class MegaString {

public:
	MegaString(char *input);
	~MegaString(void);
	void 	display(void) const;
private:
	std::string	text;
};

#endif //CPP_MEGASTRING_H
