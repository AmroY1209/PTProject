#pragma once
#include "Action.h"
#include "..\\Figures\CFigure.h"
class CutAction :public Action
{
private:
	int Cx, Cy;
	int SelecFigCount;
	CFigure** SelectedFig_List; //Array of pointers
	int Temp_Count;
	int DelID;

public:
	CutAction(ApplicationManager* pApp);     //Constructor
	~CutAction();     //Destructor

	//Reads parameters needed for the execution
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

};