#include <stdlib.h>
#include "matchstick_board.h"

void		_free_board(t_line *board)
{
  t_line	*tmp;
  t_line	*next;

  tmp = board;
  while (tmp != NULL)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
  return ;
}
