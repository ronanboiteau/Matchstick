#include <stdbool.h>
#include <stdlib.h>
#include "matchstick_board.h"
#include "matchstick_chk.h"
#include "my.h"

static int	_get_line_nbr(int *ok, int *error)
{
  char		*input;
  int		line;

  my_printf("Line: ");
  input = NULL;
  input = get_next_line(STDIN);
  if (input == NULL)
    {
      *error = true;
      *ok = false;
      return (EXIT_FAILURE);
    }
  else if (input[0] == '\0')
    {
      my_printf("Error: invalid input (positive number expected)\n");
      *ok = false;
      return (EXIT_FAILURE);
    }
  line = my_atoi(input);
  free(input);
  return (line);
}

static int	_get_matches_to_rm(int *ok, int *error)
{
  char		*input;
  int		matches;

  my_printf("Matches: ");
  input = NULL;
  input = get_next_line(STDIN);
  if (input == NULL)
    {
      *error = true;
      *ok = false;
      return (EXIT_FAILURE);
    }
  else if (input[0] == '\0')
    {
      my_printf("Error: invalid input (positive number expected)\n");
      *ok = false;
      return (EXIT_FAILURE);
    }
  matches = my_atoi(input);
  free(input);
  return (matches);
}

static void	_init_turn(int mode, int *ok)
{
  my_printf("\nYour turn:\n");
  (void)mode;
  *ok = false;
  return ;
}

static void	_init_input(int *ok, int *error, int *line)
{
  *error = false;
  *ok = true;
  *line = _get_line_nbr(ok, error);
  return ;
}

int		_player_turn(t_line *board, int mode)
{
  int		line;
  int		matches;
  int		ok;
  int		error;

  _init_turn(mode, &ok);
  while (!ok)
    {
      _init_input(&ok, &error, &line);
      if (error == true)
	return (-2);
      if (ok == true)
	{
	  if ((ok = _chk_line_nbr(board, line, &ok)) == true)
	    {
	      matches = _get_matches_to_rm(&ok, &error);
	      if (error == true)
		return (-2);
	      if (ok == true && _remove_matches(board, line, matches) == 1)
		ok = false;
	    }
	}
    }
  my_printf("Player removed %i match(es) from line %i\n", matches, line);
  return (matches);
}
