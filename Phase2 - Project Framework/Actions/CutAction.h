#pragma once
#include "Action.h"
#include "..\\Figures\CFigure.h"
class CutAction :public Action
{
private:
	int Cx, Cy;
	CFigure* fig;

public:
	CutAction(ApplicationManager* pApp);     //Constructor
	~CutAction();     //Destructor

	//Reads parameters needed for the execution
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

};