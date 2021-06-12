#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"
class PickByTypeAction :public Action
{
private:
	CFigure** fig;
	int Cx, Cy;
	int no_of_figs;
	int no_to_pick;            //Number of figures to be picked to win and finish the game
	int rightPick, wrongPick;
	int num_of_each_fig[4];    //Array where each element in it contains the number of specific type of figures
	int r, l, t, c;            //Integers used to state the type of the figure which is required to be picked in the game

public:
	PickByTypeAction(ApplicationManager*);   //Constructor
	~PickByTypeAction();                     //Destructor
	void ReadActionParameters();
	void Execute();
	virtual void Undo();
	virtual void Redo();
	void printScore(int);
};