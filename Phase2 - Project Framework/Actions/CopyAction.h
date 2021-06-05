#pragma once
#include "Action.h"
#include "..\\Figures\CFigure.h"
class CopyAction: public Action
{
private:
	int Cx, Cy;
	CFigure* fig;

public:
	CopyAction(ApplicationManager* pApp);     //Constructor
	~CopyAction();     //Destructor

	//Reads parameters needed for the execution
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();


};