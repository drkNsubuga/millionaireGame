#ifndef PLAYER_FUNCTIONS_H
#define PLAYER_FUNCTIONS_H

#include <vector>
#include "question_functions.h"

long long playSinglePlayer(const std::vector<Question>& questions);
void playMultiPlayer(const std::vector<Question>& questions);

#endif // PLAYER_FUNCTIONS_H