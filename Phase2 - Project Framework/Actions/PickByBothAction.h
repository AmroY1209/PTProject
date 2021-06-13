#include "..\Figures\CFigure.h"
#include "Action.h"
class PickByBothAction :public Action
{
private:
	CFigure** fig;
	int Cx, Cy;
	int no_of_figs;
	int no_to_pick;            //Number of figures to be picked to win and finish the game
	int rightPick, wrongPick;
	int num_of_combinations[35];    //Array where each element in it contains the number of a specific type of figures with a specific color 
	// we have 8 colors & 4 types = 32 + uncolored for 3 types, so total 35 combinations
	
	//Integers used to state the color of the figure which is required to be picked in the game
	int wR, wT, wC, wL;
	int bR, bT, bC, bL;
	int rR, rT, rC, rL;
	int gR, gT, gC, gL;
	int blueR, blueT, blueC, blueL;
	int yR, yT, yC, yL;
	int pR, pT, pC, pL;
	int oR, oT, oC, oL;
	int uncoloredR, uncoloredT, uncoloredC;            

public:
	PickByBothAction(ApplicationManager*);   //Constructor
	~PickByBothAction();                     //Destructor
	void ReadActionParameters();
	void Execute();
	virtual void Undo();
	virtual void Redo();
	void printScore(int);
};