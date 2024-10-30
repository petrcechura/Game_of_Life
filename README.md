# Game_of_Life
Simple Qt app, written in C++, that runs a Game of Life with specified rules (default 23/3 as known).
see https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life for more information.

# How to run the app
The app is managed by a **qmake** build system which automatically generates the Makefile for C++ compilation
## Dependencies (for Linux)
* Qt5
* make (4.3)
* qmake (3.1)
* g++ (13.2)
## How to build the app
* Install all dependencies
	* Qt (https://www.qt.io/download-dev)
	* make
		* Ubuntu: ```sudo apt install make```
	* qmake
		* It should be installed along with Qt5
		* If not present, try to reinstall Qt5 or manually install qmake via Qt Maintance tool
	* g++
		* Ubuntu: ```sudo apt install g++```
* Run ```make all``` in a root directory for a complete build
	* A binary file is present inside ```bin/``` directory
* Run ```make run``` to run an app after successful build
## How to use the app
* The content on the field is generated randomly after each run.
	* use **pause** to stop the time, then **start** again
	* use **restart** to restart entire population to a random state
	* use the bottom field to change rules a game is based on
		- formatting is *[cells around to survive]/[cells around to be born]*
		- use **apply** button to apply custom rules
		- rules are immediately in use
		- see https://cs.wikipedia.org/wiki/Hra_%C5%BEivota#P%C5%99ehled_tvar%C5%AF for cool custom rules

# Hierarchy
* MainWindow (window) – Used to link all widgets, their signals, cell positions etc
    * CellMatrix (Widget) – Visualises living and dead cells, calculated in Backend
    * Statistics (Widget) – Shows useful informations about the Game
    * Controls (Widget) – Contains all user entries, allows user to control the Game
    * Backend – Manages all calculations with positions
    * PopCreator (Window) – popup window that allow user to manually create and save own population to start with 
# Goals
* Widget to show current state of Game of Life visually (*DONE*)
* Widget to see amount of current living cells, population number, stability etc.  (*TODO*)
* Independent backend where all calculations are made (*DONE*)
* Widget to control current flow of Game of Life (manage speed, start, stop, restart, manage rules dynamicly)
* Window that can be used to create custom default matrix via buttons (*TODO*)
