#pragma once
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Action.h"

class RotateAction : public Action
{
	int SelecFigCount;
	CFigure** SelectedFigList; //Array of pointers

public:
	RotateAction(ApplicationManager* pmanager);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~RotateAction();
};