# Millionaire Game

Millionaire Game is a simple text-based command-line game written in C++. It simulates the famous "Who Wants to Be a Millionaire" quiz show. The game reads questions from a text file, presents them to the player, and awards money for each correct answer. The game ends if the player answers incorrectly or if all questions are answered.

## Features
- Single-player mode: Play the game alone and try to answer as many questions correctly as possible.
- Multiplayer mode for playing the game with multiple players in turns
- Load questions from a text file: Questions are stored in a text file in a specific format and are loaded into the game.
- Handle very large amounts of money

## Installation
1. Clone the repository or download the source code files.
2. Make sure you have a C++ compiler installed on your system.
3. Compile the source code files using a C++ compiler:
   ```bash
   ./build.sh
   ```

## Usage
1. Ensure you have compiled the program as described in the installation steps.
2. Prepare a text file containing questions in the following format:
```txt
Question
Option A
Option B
Option C
Option D
Correct Option: Option B
```

4. Run the compiled executable file:
```bash
./millionaire_game
```
4. Follow the on-screen prompts to select the game mode and play the game.

## Roadmap
- Fetch questions from an API
- Shuffle Questions
- Shuffle Answers
- Countdown timer for each question to increase the challenge.
- Lifelines: Implement lifelines such as "50:50", "Ask the Audience", and "Phone a Friend" to help the player.
- Difficulty levels: Allow the player to choose the difficulty level of the questions.
- Scoreboard: Display a scoreboard at the end of the game to show players' rankings.
- Sound effects to enhance the gaming experience.

## License
This project is licensed under the [MIT LICENSE](./LICENSE) - see the LICENSE file for details.