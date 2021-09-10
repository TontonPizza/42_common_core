#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
public:
						Fixed();
						Fixed(const Fixed & T);
						Fixed(const int i_val);
						Fixed(const float f_val);
						~Fixed();
						Fixed &operator=(const Fixed & T);
	int 				getRawBits(void) const;
	void 				setRawBits(int const raw);

	float 				toFloat(void) const;
	int 				toInt(void) const;
private:

	int					_fixed_point_value;
	static const int	_fractional_bits = 8;
};

std::ostream 			&operator<<(std::ostream & os, const Fixed & T);

#endif //CPP02_FIXED_HPP
