# Miss Mia's Mystery Mansion

This was one of my first C++ programs with file reading, random selection, and game logic. It was written for a fun final project in my first C++ class!

## Overview

**Miss Mia's Mystery Mansion** is a Clue style console game where the player takes on the role of a detective trying to solve a mysterious murder at the mansion. The game randomly selects a murderer from a list of suspects, then lets the player make up to four guesses and giving clues after each incorrect guess based on a clue file.

- The program reads a list of suspects and their clues from a file.
- A random suspect is chosen as the murderer.
- The user is prompted to guess who the murderer is (up to 4 times).
- After each wrong guess, a clue is revealed.
- The player either solves the case or is "caught" by the murderer!

## Features

- Uses a `vector` of suspect names and a `map` of associated clues.
- Reads data from an external file (`clue_data.txt`) with formatted clues.
- Randomly selects a suspect as the murderer using `rand()`.
- Validates player input to ensure it matches a valid suspect name.
- Introduces each suspect with a fun description.
- Offers interactive console gameplay with clues and feedback.
- Includes a win/lose ending based on the user’s guesses.

## File Structure

- **main.cpp** — the main C++ source file with all game logic.
- **clue_data.txt** — a formatted text file with suspect clues (3 per suspect).
  
**Example format for `clue_data.txt`:**
```
Miss Scarlet
Psst.. Here is a clue: Mr. Boddy's wound looks like it was made by something sharp.
They are not the murderer. You need to hurry! Here is some more info I found: The murderer must have been quick thinking, there is hardly any evidence.
That is incorrect. This is your last chance. Be careful! Clue: I heard the murderer charmed Mr. Boddy with their looks.

Mr. Green
Psst.. Here is a clue: Mr. Boddy seems to have died from a hit to the head.
They are not the murderer. You need to hurry! Here is some more info I found: There were dusty hand prints all over the scene.
That is incorrect. This is your last chance. Be careful! Clue: The way the murderer got out of the room so quickly without being caught is strange.

... (and so on for each suspect)
```

Each suspect should have:
- Their name on the first line.
- Three clues (each on a new line).
- A blank line between each suspect’s clue set.

## How to Run

1. Make sure you have a C++ compiler (like `g++`) installed on your system.
2. Save `main.cpp` and `clue_data.txt` in the same folder.
3. Compile and run the program using your terminal:

```
g++ main.cpp -o mystery_game
./mystery_game
```

4. Follow the prompts to play and try to solve the murder!

> Since this is an early project, there may be some limited error handling. Unexpected input (like typos or missing files) might cause it to crash. Play gently!

## What I Learned

- How to read and parse structured text files in C++
- Using `vector` and `map` for data storage
- Random number generation and seeding with `srand(time(0))`
- Validating user input in a loop
- Structuring interactive console applications
- Combining creativity and logic in programming!

## Credits

Project by Mia Palmer  
Created for CSC1060 at FRCC — thanks for playing Detective!
