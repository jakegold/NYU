#ifndef PRINCESS_H
#define PRINCESS_H

#include <string>

namespace Fantasy{

	class FrogPrince;



	class Princess{
	public:
		Princess(const std::string & name); 
		void display() const;
	private:
		std::string name;
		FrogPrince* spouse;
	};
}

#endif