#include <stdlib.h>
#include "matchstick_board.h"
#include "matchstick_random.h"
#include "my.h"

int		_ai_dumb(t_line *board)
{
  int		matches;
  int		line;
  int		nb_lines;
  int		*lines;

  my_printf("\nAI's turn...\n");
  (void)board;
  if ((lines = _get_lines(board, &nb_lines)) == NULL)
    {
      my_dprintf(STDERR, "ERROR: Out of memory! malloc() failed\n");
      return (-1);
    }
  line = lines[(rand() % nb_lines)];
  matches = (rand() % _get_rand_matches(board, line)) + 1;
  if (_remove_matches(board, line, matches) == EXIT_FAILURE)
    {
      my_dprintf(STDERR, "AI crashed! KO victory...\n");
      return (-1);
    }
  my_printf("AI removed %i match(es) from line %i\n", matches, line);
  free(lines);
  return (matches);
}
