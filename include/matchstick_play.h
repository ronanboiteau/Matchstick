#ifndef ALLUM1_PLAY_H_
# define ALLUM1_PLAY_H_

int		_ai_dumb(t_line *board);
int		_ai_easy(t_line *board);
int		_ai_hard(t_line *board);
int		_ai_insane(t_line *board);
int		_ai_medium(t_line *board);
int		_computer_turn(t_line *board, char mode);
int		_player_turn(t_line *board, char mode);

#endif /* !ALLUM1_PLAY_H_ */
