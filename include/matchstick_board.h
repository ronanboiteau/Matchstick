#ifndef ALLUM1_BOARD_H_
# define ALLUM1_BOARD_H_

typedef struct	s_line
{
  int		line;
  int		matches;
  int		stack_1;
  int		stack_2;
  int		stack_4;
  int		stack_8;
  int		stack_16;
  int		stack_32;
  int		stack_64;
  int		stack_128;
  int		stack_256;
  struct s_line	*next;
}		t_line;

t_line		*_add_line(t_line *list_ptr, int matches, int idx);
void		_free_board(t_line *board);
void		_print_board(t_line *list_start, int lines);
int		_remove_matches(t_line *board, int line, int matches);

#endif /* !ALLUM1_BOARD_H_ */
