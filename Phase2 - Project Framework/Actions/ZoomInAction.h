#pragma once
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "Action.h"


class ZoomInAction : public Action
{

	int SelecFigCount;
	CFigure** SelectedFigList;

public:
	ZoomInAction(ApplicationManager* pmanager);
	virtual void ReadActionParameters();
	virtual void Execute();
	void ZoomIN(string scale);
};
