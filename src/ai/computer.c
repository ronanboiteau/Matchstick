#include "matchstick_board.h"
#include "matchstick_play.h"

int		_computer_turn(t_line *board, char mode)
{
  int		matches;

  if (mode == 0)
    matches = _ai_easy(board);
  if (mode == 1)
    matches = _ai_medium(board);
  if (mode == 2)
    matches = _ai_hard(board);
  if (mode == 3)
    matches = _ai_dumb(board);
  return (matches);
}
