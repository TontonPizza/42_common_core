#ifndef CPP04_TACTICALMARINE_HPP
#define CPP04_TACTICALMARINE_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include "ISpaceMarine.hpp"

class TacticalMarine: public virtual ISpaceMarine {
public:
							TacticalMarine();
							TacticalMarine(TacticalMarine & T);
		virtual				~TacticalMarine();
							TacticalMarine &operator=(const TacticalMarine & T);
		void 				doNothing() const;

		TacticalMarine * 	clone() const;
		void 				battleCry() const;
		void 				rangedAttack() const;
		void 				meleeAttack() const ;
private:


};



#endif //CPP04_TACTICALMARINE_HPP
