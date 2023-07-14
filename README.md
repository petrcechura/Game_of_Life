# Game_of_Life
Simple Qt app (written in C++) to show and modify Game of Life:
see https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

Program uses Cmake (version 3.22) to handle building a compiling.

# Hierarchy
* MainWindow (window) – Used to link all widgets, their signals, cell positions etc
    ** CellMatrix (Widget) – Visualises living and dead cells, calculated in Backend
    ** Statistics (Widget) – Shows useful informations about the Game
    ** Controls (Widget) – Contains all user entries, allows user to control the Game
    ** Backend – Manages all calculations with positions
    ** PopCreator (Window) – popup window that allow user to manually create and save own population to start with 
# Goals
* Widget to show current state of Game of Life visually (*DONE*)
* Widget to see amount of current living cells, population number, stability etc.  (*TODO*)
* Independent backend where all calculations are made (*DONE*)
* Widget to control current flow of Game of Life (manage speed, start, stop, restart, manage rules dynamicly)
* Window that can be used to create custom default matrix via buttons (*TODO*)
