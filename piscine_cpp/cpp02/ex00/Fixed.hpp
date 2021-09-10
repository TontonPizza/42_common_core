#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
public:
						Fixed();
						Fixed(Fixed & T);
						Fixed(int val);
						~Fixed();
						Fixed &operator=(const Fixed & T);
	int 				getRawBits(void) const;
	void 				setRawBits(int const raw);

private:

	int					_fixed_point_value;
	static const int	_fractional_bits = 8;
};


#endif //CPP02_FIXED_HPP
