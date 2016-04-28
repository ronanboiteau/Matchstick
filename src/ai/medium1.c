#include <stdlib.h>
#include "matchstick_board.h"
#include "matchstick_marienbad.h"
#include "matchstick_medium.h"
#include "matchstick_random.h"
#include "my.h"

static void	_finish_him(t_line *board,
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

static int	_get_problematic_stack(t_line *board)
{
  if (!_is_stack256_ok(board))
    return (256);
  if (!_is_stack128_ok(board))
    return (128);
  if (!_is_stack64_ok(board))
    return (64);
  if (!_is_stack32_ok(board))
    return (32);
  if (!_is_stack16_ok(board))
    return (16);
  if (!_is_stack8_ok(board))
    return (8);
  if (!_is_stack4_ok(board))
    return (4);
  if (!_is_stack2_ok(board))
    return (2);
  if (!_is_stack1_ok(board))
    return (1);
  return (-1);
}

int		_ai_medium(t_line *board)
{
  int		line;
  int		nb_lines;
  int		*lines;
  int		matches;
  int		one_match_lines;

  my_printf("\nAI's turn...\n");
  if ((lines = _get_lines(board, &nb_lines)) == NULL)
    {
      my_dprintf(STDERR, "ERROR: Out of memory! malloc() failed\n");
      return (-1);
    }
  one_match_lines = _count_one_match_lines(board);
  if (_count_remaining_stacks(board) - one_match_lines == 1)
    _finish_him(board, &line, &matches, one_match_lines);
  else if ((matches = _get_problematic_stack(board)) == -1 ||
	   (line = _get_problematic_line(board, matches)) == -1)
    {
      line = lines[(rand() % nb_lines)];
      matches = (rand() % _get_rand_matches(board, line)) + 1;
    }
  _remove_matches(board, line, matches);
  my_printf("AI removed %i match(es) from line %i\n", matches, line);
  free(lines);
  return (matches);
}
