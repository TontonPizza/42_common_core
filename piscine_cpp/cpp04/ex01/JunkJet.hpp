#ifndef INC_42_JunkJet_HPP
#define INC_42_JunkJet_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "AWeapon.hpp"

class JunkJet : public virtual AWeapon {
public:
				JunkJet();
				JunkJet(JunkJet & T);
	virtual 	~JunkJet();
	void 		attack() const;
	JunkJet &	operator=(const JunkJet & T);
private:


};

#endif //INC_42_JunkJet_HPP
