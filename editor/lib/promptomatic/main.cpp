#include	<iostream>
#include	<string>
#include	"arguments.hpp"

int	main(int argc, char **argv)
{
  if (argc > 1)
    {
      promptomatic::Arguments	args((std::string(argv[1])));

      for (size_t i(0); i < args.argc(); i++)
	std::cout << args[i] << std::endl;
    }
}
