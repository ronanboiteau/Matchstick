#include "matchstick_board.h"
#include "my.h"

void		_finish_him(t_line *board,
			    int *line,
			    int *matches,
			    int one_match_lines)
{
  while (board->matches <= 1)
    board = board->next;
  *line = board->line;
  *matches = board->matches;
  if (one_match_lines % 2 == 0)
    *matches -= 1;
  return ;
}

void		_fill_stack(int *stack, int *idx, int nbr)
{
  stack[*idx] = nbr;
  *idx += 1;
  return ;
}

int		_malloc_failed(void)
{
  my_dprintf(STDERR, "ERROR: Out of memory! malloc() failed\n");
  return (-1);
}
