#ifndef SOURCE_CPP07_RECTANGLE_HPP
#define SOURCE_CPP07_RECTANGLE_HPP


#include <string>
#include <iostream>
#include <cstdlib>

class rectangle {
public:
						rectangle(int x, int y);
						rectangle(const rectangle & T);
						~rectangle();
						rectangle &operator=(const rectangle & T);
				int 	area() const;
				int 	getX() const;
				int 	getY() const;
				bool 	operator>(const rectangle & T);
				bool 	operator<(const rectangle & T);
private:
	rectangle();
	int 	x;
	int		y;

};

std::ostream  & operator<<(std::ostream & os, const rectangle & T);


#endif //SOURCE_CPP07_RECTANGLE_HPP
