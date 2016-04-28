#include <stdlib.h>
#include "my.h"
#include "matchstick_board.h"

static int	_get_stack(int *matches, int size)
{
  int		stack;

  stack = *matches / size;
  *matches %= size;
  return (stack);
}

static void	_compute_stacks(t_line *list_ptr)
{
  int		matches;

  matches = list_ptr->matches;
  list_ptr->stack_256 = _get_stack(&matches, 256);
  list_ptr->stack_128 = _get_stack(&matches, 128);
  list_ptr->stack_64 = _get_stack(&matches, 64);
  list_ptr->stack_32 = _get_stack(&matches, 32);
  list_ptr->stack_16 = _get_stack(&matches, 16);
  list_ptr->stack_8 = _get_stack(&matches, 8);
  list_ptr->stack_4 = _get_stack(&matches, 4);
  list_ptr->stack_2 = _get_stack(&matches, 2);
  list_ptr->stack_1 = _get_stack(&matches, 1);
  return ;
}

static t_line	*_malloc_failed_board(void)
{
  my_dprintf(STDERR, "ERROR: Out of memory! malloc() failed\n");
  return (NULL);
}

t_line		*_add_line(t_line *list_ptr, int matches, int idx)
{
  t_line	*list_start;

  list_start = list_ptr;
  if (list_start == NULL)
    {
      if ((list_start = malloc(sizeof(t_line))) == NULL)
	return (_malloc_failed_board());
      list_start->line = 1;
      list_start->matches = matches;
      _compute_stacks(list_start);
      list_start->next = NULL;
      return (list_start);
    }
  while (list_ptr->next != NULL)
    list_ptr = list_ptr->next;
  if ((list_ptr->next = malloc(sizeof(t_line))) == NULL)
    return (_malloc_failed_board());
  list_ptr = list_ptr->next;
  list_ptr->line = idx;
  list_ptr->matches = matches;
  _compute_stacks(list_ptr);
  list_ptr->next = NULL;
  return (list_start);
}

int		_remove_matches(t_line *board, int line, int matches)
{
  int		idx;

  idx = 1;
  while (idx != line)
    {
      if (board == NULL)
      	return (EXIT_FAILURE);
      board = board->next;
      idx += 1;
    }
  if (matches <= 0 || matches > board->matches)
    {
      if (matches < 0)
	my_printf("Error: invalid input (positive number expected)\n");
      else if (matches == 0)
	my_printf("Error: you have to remove at least one match\n");
      else if (matches > board->matches)
	my_printf("Error: not enough matches on this line\n");
      return (EXIT_FAILURE);
    }
  board->matches -= matches;
  _compute_stacks(board);
  return (EXIT_SUCCESS);
}
