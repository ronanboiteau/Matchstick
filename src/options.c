#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int	_usage(char *prog_name)
{
  my_dprintf(STDERR, "Usage: %s [-m dumb|easy|medium|hard] [-l LINES]\n",
	     prog_name);
  return (-1);
}

int		_get_lines_nbr(int argc, char **argv)
{
  int		lines;
  int		idx;

  lines = 4;
  idx = 1;
  while (idx < argc)
    {
      if (my_cmp("-l", argv[idx]))
	{
	  if (!my_str_isnum(argv[idx + 1]))
	    {
	      my_dprintf(STDERR, "Numeric argument required with \"-l\"\n");
	      return (-1);
	    }
	  lines = my_atoi(argv[idx + 1]);
	}
      idx += 1;
    }
  if (lines > 256 || lines <= 0)
    {
      my_dprintf(STDERR, "Number of lines out of range! {1..256}\n");
      return (-1);
    }
  return (lines);
}

int		_is_help(int argc, char **argv)
{
  int		idx;

  idx = 1;
  while (idx < argc)
    {
      if (my_cmp("--help", argv[idx]))
	return (_usage(argv[0]));
      idx += 1;
    }
  return (EXIT_SUCCESS);
}

char		_get_mode(int argc, char **argv)
{
  char		mode;
  int		idx;

  mode = 2;
  idx = 1;
  while (idx < argc)
    {
      if (my_cmp("-m", argv[idx]))
	{
	  if (my_cmp("easy", argv[idx + 1]))
	    mode = 0;
	  else if (my_cmp("medium", argv[idx + 1]))
	    mode = 1;
	  else if (my_cmp("hard", argv[idx + 1]))
	    mode = 2;
	  else if (my_cmp("dumb", argv[idx + 1]))
	    mode = 3;
	  else
	    return (_usage(argv[0]));
	}
      idx += 1;
    }
  return (mode);
}
