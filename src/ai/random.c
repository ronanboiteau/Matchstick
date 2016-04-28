#include <stdlib.h>
#include "matchstick_board.h"
#include "my.h"

int		_get_rand_matches(t_line *board, int line)
{
  t_line	*tmp;
  int		idx;

  idx = 1;
  tmp = board;
  while (idx < line)
    {
      if (tmp == NULL)
	return (1);
      tmp = tmp->next;
      idx++;
    }
  return (tmp->matches);
}

static int	_count_lines(t_line *board)
{
  t_line	*tmp;
  int		nb_lines;

  nb_lines = 0;
  tmp = board;
  while (tmp != NULL)
    {
      if (tmp->matches != 0)
	nb_lines++;
      tmp = tmp->next;
    }
  return (nb_lines);
}

int		*_get_lines(t_line *board, int *nb_lines)
{
  int		*lines;
  int		pos;
  int		idx;

  *nb_lines = _count_lines(board);
  if ((lines = malloc(sizeof(int) * (*nb_lines + 1))) == NULL)
    {
      my_dprintf(STDERR, "ERROR: Out of memory! malloc() failed\n");
      return (NULL);
    }
  pos = 1;
  idx = 0;
  while (board != NULL)
    {
      if (board->matches != 0)
	{
	  lines[idx] = pos;
	  idx++;
	}
      pos++;
      board = board->next;
    }
  lines[idx] = 0;
  return (lines);
}
