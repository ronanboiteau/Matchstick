#ifndef ALLUM1_MARIENBAD_H_
# define ALLUM1_MARIENBAD_H_

int		_get_problematic_line(t_line *board, int stack);
int		_is_stack1_ok(t_line *board);
int		_is_stack2_ok(t_line *board);
int		_is_stack4_ok(t_line *board);
int		_is_stack8_ok(t_line *board);
int		_is_stack16_ok(t_line *board);
int		_is_stack32_ok(t_line *board);
int		_is_stack64_ok(t_line *board);
int		_is_stack128_ok(t_line *board);
int		_is_stack256_ok(t_line *board);

#endif /* !ALLUM1_MARIENBAD_H_ */
