Noughts and Crosses
===================

Noughts and Crosses also known as [Tic-tac-toe](http://en.wikipedia.org/wiki/Tic-tac-toe) is a simple game for two players, X and O, who take turns marking the spaces in a 3×3 grid. The player who succeeds in placing three respective marks in a horizontal, vertical, or diagonal row wins the game.

Game features
=============

* Singleplayer mode (you vs computer) with 2 difficulty levels
* Multiplayer mode (play against your friend sitting next to you)
* Stunning console-like graphics

Compilation
===========

Just use attached Makefile and type in console `make all` or in short `make`.
To get rid of object files and executable file type `make clean`.

To do
=====

Add unbeatable hard difficulty level (you can lose or tie only). Implement it with [minimax](http://en.wikipedia.org/wiki/Minimax) or even better [alpha–beta pruning](http://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning) algorithm.

Example of gameplay
===================

```
==========================================================================
|                                                                        |
|                                                                        |
|                                                                        |
|        '|.   '|'                          '||        .                 |
|         |'|   |    ...   ... ...    ... .  || ..   .||.   ....         |
|         | '|. |  .|  '|.  ||  ||   || ||   ||' ||   ||   ||. '         |
|         |   |||  ||   ||  ||  ||    |''    ||  ||   ||   . '|..        |
|        .|.   '|   '|..|'  '|..'|.  '||||. .||. ||.  '|.' |'..|'        |
|                                   .|....'                              |
|                                                                        |
|                                             '||                        |
|                        ....   .. ...      .. ||                        |
|                       '' .||   ||  ||   .'  '||                        |
|                       .|' ||   ||  ||   |.   ||                        |
|                       '|..'|' .||. ||.  '|..'||.                       |
|                                                                        |
|                                                                        |
|           ..|'''.|                                                     |
|         .|'     '  ... ..    ...    ....   ....    ....   ....         |
|         ||          ||' '' .|  '|. ||. '  ||. '  .|...|| ||. '         |
|         '|.      .  ||     ||   || . '|.. . '|.. ||      . '|..        |
|          ''|....'  .||.     '|..|' |'..|' |'..|'  '|...' |'..|'        |
|                                                                        |
|                                                                        |
|                                                                        |
==========================================================================
| :::: MAIN MENU ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   1. Play                                                              |
|   2. Quit                                                              |
|                                                                        |
|   Type number: 1                                                       |
|                                                                        |
==========================================================================
| :::: NUMBER OF PLAYERS ::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   1. One player (you vs computer)                                      |
|   2. Two players (you vs friend)                                       |
|                                                                        |
|   Type number: 1                                                       |
|                                                                        |
==========================================================================
| :::: DIFFICULTY LEVEL :::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   1. Easy                                                              |
|   2. Normal                                                            |
|                                                                        |
|   Type number: 2                                                       |
|                                                                        |
==========================================================================
| :::: INSTRUCTIONS :::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   Let's flip a coin:                                                   |
|   YOU start the game!                                                  |
|                                                                        |
|                                 |     |                                |
|                              1  |  2  |  3                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                              4  |  5  |  6                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                              7  |  8  |  9                             |
|                                 |     |                                |
|                                                                        |
|   Type number: 5                                                       |
|                                                                        |
==========================================================================
| :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   COMPUTER is making a move!                                           |
|                                                                        |
|                                 |     |                                |
|                                 |     |                                |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  X  |                                |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |     |                                |
|                                 |     |                                |
|                                                                        |
|   Thinking...                                                          |
|   Type number: 3                                                       |
|                                                                        |
==========================================================================
| :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   YOUR turn now, make a move!                                          |
|                                                                        |
|                                 |     |                                |
|                                 |     |  O                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  X  |                                |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |     |                                |
|                                 |     |                                |
|                                                                        |
|   Type number: 9                                                       |
|                                                                        |
==========================================================================
| :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   COMPUTER is making a move!                                           |
|                                                                        |
|                                 |     |                                |
|                                 |     |  O                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  X  |                                |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |     |  X                             |
|                                 |     |                                |
|                                                                        |
|   Thinking...                                                          |
|   Type number: 1                                                       |
|                                                                        |
==========================================================================
| :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   YOUR turn now, make a move!                                          |
|                                                                        |
|                                 |     |                                |
|                              O  |     |  O                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  X  |                                |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |     |  X                             |
|                                 |     |                                |
|                                                                        |
|   Type number: 2                                                       |
|                                                                        |
==========================================================================
| :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   COMPUTER is making a move!                                           |
|                                                                        |
|                                 |     |                                |
|                              O  |  X  |  O                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  X  |                                |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |     |  X                             |
|                                 |     |                                |
|                                                                        |
|   Thinking...                                                          |
|   Type number: 8                                                       |
|                                                                        |
==========================================================================
| :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   YOUR turn now, make a move!                                          |
|                                                                        |
|                                 |     |                                |
|                              O  |  X  |  O                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  X  |                                |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  O  |  X                             |
|                                 |     |                                |
|                                                                        |
|   Type number: 6                                                       |
|                                                                        |
==========================================================================
| :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   COMPUTER is making a move!                                           |
|                                                                        |
|                                 |     |                                |
|                              O  |  X  |  O                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  X  |  X                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  O  |  X                             |
|                                 |     |                                |
|                                                                        |
|   Thinking...                                                          |
|   Type number: 4                                                       |
|                                                                        |
==========================================================================
| :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   YOUR turn now, make a move!                                          |
|                                                                        |
|                                 |     |                                |
|                              O  |  X  |  O                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                              O  |  X  |  X                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                                 |  O  |  X                             |
|                                 |     |                                |
|                                                                        |
|   Type number: 77                                                      |
|   Type number: 7                                                       |
|                                                                        |
==========================================================================
| :::: GAMEBOARD ::::::::::::::::::::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|                                                                        |
|                                 |     |                                |
|                              O  |  X  |  O                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                              O  |  X  |  X                             |
|                            _____|_____|_____                           |
|                                 |     |                                |
|                              X  |  O  |  X                             |
|                                 |     |                                |
|                                                                        |
|                              IT'S A TIE!                               |
|                                                                        |
==========================================================================
| :::: DO YOU WANT TO PLAY AGAIN? :::::::::::::::::::::::::::::::::::::: |
==========================================================================
|                                                                        |
|   1. Yes                                                               |
|   2. No                                                                |
|                                                                        |
|   Type number: 2                                                       |
|                                                                        |
==========================================================================
```