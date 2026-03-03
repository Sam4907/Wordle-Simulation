# Wordle (C++ Console Version)

A terminal-based implementation of the Wordle game written in C++.
This project represents the initial version of a larger effort to build and refine a complete Wordle clone while practicing core C++ concepts and clean game logic design.

---

## Overview

The program selects a random five-letter word from a dictionary file and allows the player six attempts to guess it. After each guess, feedback is provided using color-coded output:

* Green: correct letter in the correct position
* Yellow: correct letter in the wrong position
* White: letter not present in the word

The game ends when the word is guessed correctly or all attempts are used.

---

## Features

* Random word selection using `mt19937`
* Input validation:

  * Five-letter words only
  * Alphabetic characters only
  * No repeated guesses
  * Guess must exist in the dictionary
* Duplicate letter handling that mirrors Wordle logic
* ANSI-colored terminal output
* Typewriter-style text display effect
* Structured attempt tracking with visual board display

---

## Project Structure

```
.
├── main.cpp
├── list.txt
└── README.md
```

* `main.cpp` — Core game implementation
* `list.txt` — Dictionary file containing valid five-letter words

---

## Design Notes

This version focuses on implementing correct Wordle mechanics and reinforcing fundamental C++ concepts, including:

* Standard Template Library containers (`vector`, `pair`)
* File I/O operations
* Random number generation
* String transformation and validation
* Algorithm usage (`binary_search`, `sort`)
* Console formatting with ANSI escape codes

The implementation prioritizes correctness, clarity, and structured gameplay logic as a foundation for future enhancements.

---

## Future Development

*Refactor into OOP design
*Configurable word length
*Keyboard status tracker
*Replay feature
*Possible GUI version

---

## Learning Goals

This project was built to strengthen understanding of:

*C++ STL
*Game logic design
*Algorithmic thinking
*Handling edge cases 
*User input validation
*Clean terminal output

## Status

Initial working version complete. Further refinements and extensions are in progress.

## Author

Sameeha Yasmin: [samyasmin49@gmail.com](mailto:samyasmin49@gmail.com)

GitHub: https://github.com/Sam4907
