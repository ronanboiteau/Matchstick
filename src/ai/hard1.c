#include <stdlib.h>
#include "matchstick_board.h"
#include "matchstick_hard.h"
#include "matchstick_marienbad.h"
#include "matchstick_random.h"
#include "my.h"

static int	_count_one_match_lines(t_line *board)
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

static int	_count_remaining_stacks(t_line *board)
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

static int	_get_line(t_line *board, int *stack, int *matches)
{
  t_line	*tmp;
  int		idx;

  tmp = board;
  *matches = 0;
  idx = 0;
  while (stack[idx] != -1)
    {
      *matches += stack[idx];
      idx++;
    }
  while (tmp != NULL)
    {
      if (tmp->matches >= *matches)
	return (tmp->line);
      tmp = tmp->next;
    }
  *matches = stack[idx - 1];
  return (_get_problematic_line(board, stack[0]));
}

static void	_get_problematic_stack(t_line *board, int *stack)
{
  int		idx;

  idx = 0;
  if (!_is_stack256_ok(board))
    _fill_stack(stack, &idx, 256);
  if (!_is_stack128_ok(board))
    _fill_stack(stack, &idx, 128);
  if (!_is_stack64_ok(board))
    _fill_stack(stack, &idx, 64);
  if (!_is_stack32_ok(board))
    _fill_stack(stack, &idx, 32);
  if (!_is_stack16_ok(board))
    _fill_stack(stack, &idx, 16);
  if (!_is_stack8_ok(board))
    _fill_stack(stack, &idx, 8);
  if (!_is_stack4_ok(board))
    _fill_stack(stack, &idx, 4);
  if (!_is_stack2_ok(board))
    _fill_stack(stack, &idx, 2);
  if (!_is_stack1_ok(board))
    _fill_stack(stack, &idx, 1);
  stack[idx] = -1;
  return ;
}

int		_ai_hard(t_line *board)
{
  int		line;
  int		nb_lines;
  int		*lines;
  int		*stack;
  int		matches;
  int		one_match_lines;

  my_printf("\nAI's turn...\n");
  one_match_lines = _count_one_match_lines(board);
  if ((lines = _get_lines(board, &nb_lines)) == NULL ||
      (stack = malloc(sizeof(int) * 10)) == NULL)
    return (_malloc_failed());
  _get_problematic_stack(board, stack);
  if (_count_remaining_stacks(board) - one_match_lines == 1)
    _finish_him(board, &line, &matches, one_match_lines);
  else if (stack[0] == -1 || (line = _get_line(board, stack, &matches)) == -1)
    {
      line = lines[(rand() % nb_lines)];
      matches = (rand() % _get_rand_matches(board, line)) + 1;
    }
  _remove_matches(board, line, matches);
  my_printf("AI removed %i match(es) from line %i\n", matches, line);
  free(lines);
  free(stack);
  return (matches);
}
