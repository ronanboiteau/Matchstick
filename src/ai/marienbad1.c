#include <stdbool.h>
#include <stdlib.h>
#include "matchstick_board.h"
#include "matchstick_marienbad.h"
#include "my.h"

int		_get_problematic_line(t_line *board, int stack)
{
  while (board != NULL)
    {
      if (board->matches >= stack)
	return (board->line);
      board = board->next;
    }
  return (-1);
}

int		_is_stack8_ok(t_line *board)
{
  int		sum;

  sum = 0;
  while (board != NULL)
    {
      sum += board->stack_8;
      board = board->next;
    }
  if (sum % 2 == 1)
    return (false);
  return (true);
}

int		_is_stack4_ok(t_line *board)
{
  int		sum;

  sum = 0;
  while (board != NULL)
    {
      sum += board->stack_4;
      board = board->next;
    }
  if (sum % 2 == 1)
    return (false);
  return (true);
}

int		_is_stack2_ok(t_line *board)
{
  int		sum;

  sum = 0;
  while (board != NULL)
    {
      sum += board->stack_2;
      board = board->next;
    }
  if (sum % 2 == 1)
    return (false);
  return (true);
}

int		_is_stack1_ok(t_line *board)
{
  int		sum;

  sum = 0;
  while (board != NULL)
    {
      sum += board->stack_1;
      board = board->next;
    }
  if (sum % 2 == 1)
    return (false);
  return (true);
}
