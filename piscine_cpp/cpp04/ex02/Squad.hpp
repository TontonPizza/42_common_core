#ifndef CPP04_SQUAD_HPP
#define CPP04_SQUAD_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include "ISquad.hpp"


class Squad: public virtual ISquad {
public:
						Squad();
						Squad(Squad & T);
	virtual 			~Squad();
						Squad &operator=(const Squad & T);

	int 				getCount() const;
	ISpaceMarine *		getUnit(int n) const;
	int 				push(ISpaceMarine * T);
private:

	typedef struct		s_unit
	{
		ISpaceMarine	*unit;
		struct s_unit	*next;
	}					t_unit;

	int 				_count;
	t_unit				*_unitPtr;
	void				destroyUnits(t_unit *ptr);
	void				copyUnits(t_unit *source);
	void				incrementCount();
};



#endif //CPP04_SQUAD_HPP
