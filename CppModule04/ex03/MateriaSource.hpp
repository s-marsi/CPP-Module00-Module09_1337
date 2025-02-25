#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *slots[4];
        int slots_counter;
        t_garbage *garbage;
    public:
        MateriaSource();
        MateriaSource(MateriaSource &copy);
        MateriaSource &operator=(MateriaSource &copy);
        void learnMateria(AMateria *copy);
        AMateria* createMateria(std::string const & type);
        virtual ~MateriaSource();
};