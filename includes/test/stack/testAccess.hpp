#ifndef TESTACCESS_HPP
#define TESTACCESS_HPP 

#include "test.hpp"

	template<typename T>
	void	accessTestConst(ft::vector<T> const & vector)
	{
		std::cout << "-- size: --" << std::endl;
		std::cout << vector.size() << std::endl;

		std::cout << "-- Front: --" << std::endl;
		std::cout << vector.front() << std::endl;
		std::cout << "--operator[7]: " << std::endl;
		std::cout << vector[7] << std::endl;
		std::cout << "--at(19): " << std::endl;
		std::cout << vector.at(19) << std::endl;
		std::cout << "--at(30): " << std::endl;
		try {
			std::cout << vector.at(30) << std::endl;
		}
		catch(std::out_of_range & e)
		{
			std::cout << "catch: " << e.what() << "\n";
		}
		std::cout << "-- Back: --" << std::endl;
		std::cout << vector.back() << std::endl;
	}

	template<typename T>
	void	accessTest(ft::vector<T>& vector)
	{
		std::cout << "-- size: --" << std::endl;
		std::cout << vector.size() << std::endl;

		std::cout << "-- Front: --" << std::endl;
		std::cout << vector.front() << std::endl;
		std::cout << "--operator[7]: " << std::endl;
		std::cout << vector[7] << std::endl;
		std::cout << "--at(19): " << std::endl;
		std::cout << vector.at(19) << std::endl;
		std::cout << "--at(30): " << std::endl;
		try {
			std::cout << vector.at(30) << std::endl;
		}
		catch(std::out_of_range & e)
		{
			std::cout << "catch: " << e.what() << "\n";
		}
		std::cout << "-- Back: --" << std::endl;
		std::cout << vector.back() << std::endl;
		vector[25] = 99;
		std::cout << "-- Back: --" << std::endl;
		std::cout << vector.back() << std::endl;
	}

#endif