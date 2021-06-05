#pragma once
#include "Action.h"
#include "..\\Figures\CFigure.h"
#include "..\\Figures\CRectangle.h"
#include "..\\Figures\CLine.h"
#include "..\\Figures\CTriangle.h"
#include "..\\Figures\CCircle.h"
class PasteAction : public Action
{
private:
	int Cx, Cy;  //Center point of the figure
	CFigure* fig;
public:
	PasteAction(ApplicationManager* pApp);     //Constructor
	~PasteAction();     //Destructor

	//Reads parameters needed for the execution
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();
};