#include <stdbool.h>
#include <stdlib.h>
#include "matchstick_board.h"
#include "my.h"

int		_is_stack256_ok(t_line *board)
{
  int		sum;

  sum = 0;
  while (board != NULL)
    {
      sum += board->stack_256;
      board = board->next;
    }
  if (sum % 2 == 1)
    return (false);
  return (true);
}

int		_is_stack128_ok(t_line *board)
{
  int		sum;

  sum = 0;
  while (board != NULL)
    {
      sum += board->stack_128;
      board = board->next;
    }
  if (sum % 2 == 1)
    return (false);
  return (true);
}

int		_is_stack64_ok(t_line *board)
{
  int		sum;

  sum = 0;
  while (board != NULL)
    {
      sum += board->stack_64;
      board = board->next;
    }
  if (sum % 2 == 1)
    return (false);
  return (true);
}

int		_is_stack32_ok(t_line *board)
{
  int		sum;

  sum = 0;
  while (board != NULL)
    {
      sum += board->stack_32;
      board = board->next;
    }
  if (sum % 2 == 1)
    return (false);
  return (true);
}

int		_is_stack16_ok(t_line *board)
{
  int		sum;

  sum = 0;
  while (board != NULL)
    {
      sum += board->stack_16;
      board = board->next;
    }
  if (sum % 2 == 1)
    return (false);
  return (true);
}
