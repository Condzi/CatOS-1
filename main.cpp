#include "Cat.h"

int main()
{
	Cat cat(725, 725, "CatOS 1 | 1");
	cat.Init("Data/");
	cat.Run();

	return 0;
}
