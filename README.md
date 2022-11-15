# 42_fillit
Fill It is a program that will determine the smallest square possible, using all the Tetris pieces described in a file.

![oie_FC2Iwigk3JLY](https://user-images.githubusercontent.com/52746061/201969927-c2b306f2-2653-4dba-a97d-3c4bc4542051.png)

# Output Example

![oie_N4TZTb1iUDQy](https://user-images.githubusercontent.com/52746061/201970011-57582dc8-c746-468a-bb8e-1bab41c3f227.png)

## Install
Create or update the Fill It program from sources.

`make`

## Reinstall
Recompile completely the program.

`make re`

## Clean
Delete object files created during installation.

`make clean`

## Uninstall
Delete object files but also the compiled program.  
It will not affect the source code.

`make fclean`

## Usage

`./fillit Tetriminos_Files/file_correct/valid_15`

## Notes

The program use Backtracking Algorithm and get mid-high performance (compared with other 42 teams).  
Unlike most projects using Backtracking, it has the particularity to be designed with full iterative loops instead of recursive loops.
