#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie{
    std::string	name;
	public :
		Zombie( void );
		Zombie( std::string Name );
		void	announce( void );
		Zombie*	newZombie( std::string name );
		void 	randomChump( std::string name );
		~Zombie( void );
};

#endif