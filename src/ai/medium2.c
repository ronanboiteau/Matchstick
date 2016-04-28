#include <stdlib.h>
#include "matchstick_board.h"

int		_count_one_match_lines(t_line *board)
{
  int		lines;

  lines = 0;
  while (board != NULL)
    {
      if (board->matches == 1)
	lines += 1;
      board = board->next;
    }
  return (lines);
}

int		_count_remaining_stacks(t_line *board)
{
  int		stacks;

  stacks = 0;
  while (board != NULL)
    {
      if (board->matches != 0)
	stacks += 1;
      board = board->next;
    }
  return (stacks);
}
