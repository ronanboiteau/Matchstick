#ifndef ALLUM1_HARD_H_
# define ALLUM1_HARD_H_

void		_fill_stack(int *stack, int *idx, int nbr);
void		_finish_him(t_line *board,
			      int *line,
			      int *matches,
			      int one_match_lines);
int		_malloc_failed(void);

#endif /* !ALLUM1_HARD_H_ */
