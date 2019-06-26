#include "Reptile.h"



Reptile::Reptile(string place, int weight, bool bite_death) : Animal("Reptile", place, weight)
{
	this->bite_death = bite_death;
}


