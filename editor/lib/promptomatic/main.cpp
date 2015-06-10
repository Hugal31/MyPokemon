#include	<iostream>
#include	<string>
#include	"promptomatic.hpp"

namespace
{
  int	put_bite(const promptomatic::Arguments &args)
  {
    std::cout << "bite." << std::endl;
    return (0);
  }
}

int	main(int argc, char **argv)
{
  promptomatic::Prompt	prompt;

  prompt.map_command("bite", put_bite, "put \"bite.\"");
  prompt.input_loop();
}
