#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"
class PickByColorAction :public Action
{
private:
	CFigure** fig;
	int Cx, Cy;
	int no_of_figs;
	int no_to_pick;            //Number of figures to be picked to win and finish the game
	int rightPick, wrongPick;
	int num_of_each_color[9];    //Array where each element in it contains the number of figures of a specific color (we have 8 colors, last index for noncolored)
	int w, b, r, g, blue, y, p, o, uncolored;            //Integers used to state the color of the figure which is required to be picked in the game

public:
	PickByColorAction(ApplicationManager*);   //Constructor
	~PickByColorAction();                     //Destructor
	void ReadActionParameters();
	void Execute();
	void printScore(int);
};