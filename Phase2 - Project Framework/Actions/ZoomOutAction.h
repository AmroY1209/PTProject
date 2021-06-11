#pragma once
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "Action.h"


class ZoomOutAction : public Action
{

	int SelecFigCount;
	CFigure** SelectedFigList;

public:
	ZoomOutAction(ApplicationManager* pmanager);
	virtual void ReadActionParameters();
	virtual void Execute();
	void ZoomOut(string scale);
};
