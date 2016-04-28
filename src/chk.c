#include <stdbool.h>
#include <stdlib.h>
#include "matchstick_board.h"
#include "my.h"

static int	_quit_empty(int *ok)
{
  my_printf("Error: this line is empty\n");
  *ok = false;
  return (false);
}

static int	_quit_out_of_range(int *ok)
{
  my_printf("Error: this line is out of range\n");
  *ok = false;
  return (false);
}

int		_chk_line_nbr(t_line *board, int line, int *ok)
{
  int		idx;

  if (line < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      *ok = false;
      return (false);
    }
  else if (line == 0)
    return (_quit_out_of_range(ok));
  idx = 1;
  while (idx != line)
    {
      if (board->next == NULL)
	return (_quit_out_of_range(ok));
      board = board->next;
      idx += 1;
    }
  if (board->matches == 0)
    return (_quit_empty(ok));
  return (true);
}
