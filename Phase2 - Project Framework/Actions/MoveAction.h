#include "AddTriAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class MoveAction : public Action
{
	Point P;
	int SelecFigCount;
	CFigure** SelectedFigList;
	int DistX, DistY;

public:
	MoveAction(ApplicationManager* pmanager);
	virtual void ReadActionParameters();
	virtual void Execute();

};