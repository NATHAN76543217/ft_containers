#ifndef TESTACCESS_HPP
#define TESTACCESS_HPP 

#include "test.hpp"


	template<typename T>
	void	accessTestConst(std::vector<T> const & vector_stl, ft::vector<T> const & vector_me)
	{
		std::cout << "-- size: --" << std::endl;
		std::cout << vector_stl.size() << std::setw(10) << vector_me.size() << std::endl;

		std::cout << "-- Front: --" << std::endl;
		std::cout << vector_stl.front() << std::setw(10) << vector_me.front() << std::endl;
		std::cout << "--operator[7]: " << std::endl;
		std::cout << vector_stl[7] << std::setw(10) << vector_me[7] << std::endl;
		std::cout << "--at(19): " << std::endl;
		std::cout << vector_stl.at(19) << std::setw(10) << vector_me.at(19) << std::endl;
		std::cout << "--at(30): " << std::endl;
		try {
			std::cout << vector_stl.at(30) << std::endl;
		}
		catch(std::out_of_range & e)
		{
			std::cout << "catch: " << e.what() << "\n";
		}
		try {
			std::cout << vector_me.at(30) << std::endl;
		}
		catch(std::out_of_range & e)
		{
			std::cout << "catch: " << e.what() << "\n";
		}
		std::cout << "-- Back: --" << std::endl;
		std::cout << vector_stl.back() << std::setw(10) << vector_me.back() << std::endl;
	}

	template<typename T>
	void	accessTest(std::vector<T>& vector_stl, ft::vector<T>& vector_me)
	{
		std::cout << "-- size: --" << std::endl;
		std::cout << vector_stl.size() << std::setw(10) << vector_me.size() << std::endl;

		std::cout << "-- Front: --" << std::endl;
		std::cout << vector_stl.front() << std::setw(10) << vector_me.front() << std::endl;
		std::cout << "--operator[7]: " << std::endl;
		std::cout << vector_stl[7] << std::setw(10) << vector_me[7] << std::endl;
		std::cout << "--at(19): " << std::endl;
		std::cout << vector_stl.at(19) << std::setw(10) << vector_me.at(19) << std::endl;
		std::cout << "--at(30): " << std::endl;
		try {
			std::cout << vector_stl.at(30) << std::endl;
		}
		catch(std::out_of_range & e)
		{
			std::cout << "catch: " << e.what() << "\n";
		}
		try {
			std::cout << vector_me.at(30) << std::endl;
		}
		catch(std::out_of_range & e)
		{
			std::cout << "catch: " << e.what() << "\n";
		}
		std::cout << "-- Back: --" << std::endl;
		std::cout << vector_stl.back() << std::setw(10) << vector_me.back() << std::endl;
		vector_stl[25] = 99;
		vector_me[25] = 99;
		std::cout << "-- Back: --" << std::endl;
		std::cout << vector_stl.back() << std::setw(10) << vector_me.back() << std::endl;
	}

#endif