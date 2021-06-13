#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class PickByAreaAction : public Action
{
private:
	CFigure** fig;
	int Cx, Cy;
	int no_of_figs;
	int no_to_pick;            //Number of figures to be picked to win and finish the game
	int rightPick, wrongPick;
	int num_of_each_fig[4];    //Array where each element in it contains the number of specific type of figures
	bool IsCorrect;
	float MaxArea;

public:
	PickByAreaAction(ApplicationManager*);   //Constructor
	~PickByAreaAction();                     //Destructor
	void ReadActionParameters();
	void Execute();
	virtual void Undo();
	virtual void Redo();
	void printScore(int);
};
