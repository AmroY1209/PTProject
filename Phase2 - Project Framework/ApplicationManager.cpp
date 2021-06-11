#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\SelectAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"
#include "Actions\MoveAction.h"
#include "Actions\ResizeAction.h"
#include "Actions\CutAction.h"
#include "Actions\PickByTypeAction.h"
#include "Figures\CCircle.h"
#include "Figures\CRectangle.h"
#include "Figures\CLine.h"
#include "Figures\CTriangle.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddTriAction.h"
#include "Actions/AddLineAction.h"
#include "Actions/AddCircAction.h"
#include "Actions/SelectAction.h"
#include "Actions/CopyAction.h"
#include "Actions/PasteAction.h"
#include "Actions/MoveAction.h"
#include "Actions/ResizeAction.h"
#include "Actions/SaveAction.h"
#include "Actions/LoadAction.h"
#include"Actions/ZoomInAction.h"
#include"Actions/ZoomOutAction.h"
#include "Figures/CCircle.h"
#include "Figures/CRectangle.h"
#include "Figures/CLine.h"
#include "Figures/CTriangle.h"
#include "DEFS.h"
#include "CMUgraphicsLib/CMUgraphics.h"



int CFigure::ID = 0;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	filled = false;
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelecFigCount = 0;
	ClipboardCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	for (int i = 0; i < MaxSelecCount; i++)
	{
		SelectedFigList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this, filled);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriAction(this, filled);
		break;

	case DRAW_CIRC:
		pAct = new AddCircAction(this, filled);
		break;

	//case colors for change DRAW COLOR 
	///////////////////////////////////////////////////////////////////////////////

	case CHNG_DRAW_CLR:
		pOut->CreateDrawClrToolBar();
		pOut->PrintMessage("Choose color from following");
		break;

	case COLOR_WHITE:
		pOut->CreateDrawToolBar();
		UI.DrawColor = WHITE;
		pOut->ClearStatusBar();
		break;

	case COLOR_BLACK:
		pOut->CreateDrawToolBar();
		UI.DrawColor = BLACK;
		pOut->ClearStatusBar();
		break;

	case COLOR_RED:
		pOut->CreateDrawToolBar();
		UI.DrawColor = RED;
		pOut->ClearStatusBar();
		break;

	case COLOR_GREEN:
		pOut->CreateDrawToolBar();
		UI.DrawColor = GREEN;
		pOut->ClearStatusBar();
		break;

	case COLOR_BLUE:
		pOut->CreateDrawToolBar();
		UI.DrawColor = BLUE;
		pOut->ClearStatusBar();
		break;

	case COLOR_YELLOW:
		pOut->CreateDrawToolBar();
		UI.DrawColor = YELLOW;
		pOut->ClearStatusBar();
		break;

	case COLOR_PURPLE:
		pOut->CreateDrawToolBar();
		UI.DrawColor = PURPLE;
		pOut->ClearStatusBar();
		break;

	case COLOR_ORANGE:
		pOut->CreateDrawToolBar();
		UI.DrawColor = ORANGE;
		pOut->ClearStatusBar();
		break;

	/////////////////////////////////////////////////////////////////////////////////

	case CHNG_FILL_CLR:	//Change the filling color
		pOut->CreateFillClrToolBar();
		pOut->PrintMessage("Choose color from following");
		filled = true;
		break;

	case FILL_WHITE:
		pOut->CreateDrawToolBar();
		UI.FillColor = WHITE;
		pOut->ClearStatusBar();
		break;

	case FILL_BLACK:
		pOut->CreateDrawToolBar();
		UI.FillColor = BLACK;
		pOut->ClearStatusBar();
		break;

	case FILL_RED:
		pOut->CreateDrawToolBar();
		UI.FillColor = RED;
		pOut->ClearStatusBar();
		break;

	case FILL_GREEN:
		pOut->CreateDrawToolBar();
		UI.FillColor = GREEN;
		pOut->ClearStatusBar();
		break;

	case FILL_BLUE:
		pOut->CreateDrawToolBar();
		UI.FillColor = BLUE;
		pOut->ClearStatusBar();
		break;

	case FILL_YELLOW:
		pOut->CreateDrawToolBar();
		UI.FillColor = YELLOW;
		pOut->ClearStatusBar();
		break;

	case FILL_PURPLE:
		pOut->CreateDrawToolBar();
		UI.FillColor = PURPLE;
		pOut->ClearStatusBar();
		break;

	case FILL_ORANGE:
		pOut->CreateDrawToolBar();
		UI.FillColor = ORANGE;
		pOut->ClearStatusBar();
		break;

	////////////////////////////////////////////////////////////////////////////////////////////

	case CHNG_BK_CLR:	//Change background color
		pOut->CreateBackClrToolBar();
		pOut->PrintMessage("Choose color from following");
		break;

	case BCFILL_WHITE:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = WHITE;
		pOut->ClearStatusBar();
		pOut->ClearDrawArea();
		break;

	case BCFILL_BLACK:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = BLACK;
		pOut->ClearStatusBar();
		pOut->ClearDrawArea();
		break;

	case BCFILL_RED:

		pOut->CreateDrawToolBar();
		UI.BkGrndColor = RED;
		pOut->ClearStatusBar();
		pOut->ClearDrawArea();
		break;

	case BCFILL_GREEN:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = GREEN;
		pOut->ClearStatusBar();
		pOut->ClearDrawArea();
		break;

	case BCFILL_BLUE:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = BLUE;
		pOut->ClearStatusBar();
		pOut->ClearDrawArea();
		break;

	case BCFILL_YELLOW:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = YELLOW;
		pOut->ClearStatusBar();
		pOut->ClearDrawArea();
		break;

	case BCFILL_PURPLE:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = PURPLE;
		pOut->ClearStatusBar();
		pOut->ClearDrawArea();
		break;

	case BCFILL_ORANGE:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = ORANGE;
		pOut->ClearStatusBar();
		pOut->ClearDrawArea();
		break;
	
	////////////////////////////////////////////////////////////////////////////////////////

	case SELECT:		//Select an item
		pAct = new SelectAction(this);
		break;

	case MOVE:			//Move a figure(s)
		pAct = new MoveAction(this);
		break;

	case RESIZE:		//Resize a figure(s)
		pAct = new ResizeAction(this);
		break;

	case DEL:			//Delete a figure(s)
		pOut->ClearStatusBar();
		deleteFig();
		pOut->ClearDrawArea();
		break;

	case COPY:           //Copy an item to Clipboard
		//ClearClipboard();
		pAct = new CopyAction(this);
		break;

	case PASTE:         //Paste an item from Clipboard
		pAct = new PasteAction(this);
		break;

	case CUT:            //Cut an item and have it in Clipboard
		//ClearClipboard();
		pAct = new CutAction(this);
		break;

	case SAVE:			//Save the whole graph to a file
		pAct = new SaveAction(this);
		break;

	case LOAD:			//Load a graph from a file
		pAct = new LoadAction(this);
		break;

	case ZOOM_IN:        //Zooming the whole graph in
		pAct = new ZoomInAction(this);
		break;

	case ZOOM_OUT:       //Zooming the whole graph out
		pAct = new ZoomOutAction(this);
		break;

	case TO_ADDITEM:
		pOut->CreateDrawItemsToolbar();
		break;

	case EXIT:			//Exit the application
		//pAct = new EXITAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;

	case DRAWING_AREA:    //a click on the drawing area ==> no action   
		break;

	case EMPTY:    //a click on an empty area in the designed tool bar ==> no action
		break;

	case TO_PLAY:    //Switch to Play Mode, creating Play tool bar
		pOut->CreatePlayToolBar();
		break;

	case TO_DRAW:    //Switch to Draw Mode, creating Draw tool bar
		pOut->CreateDrawToolBar();
		break;

	case BY_TYPE:    //Pick figures by Type, for play mode
		pAct = new PickByTypeAction(this);
		break;

	case BY_COLOR:    //Pick figures by Color, for play mode
		break;

	case BY_BOTH:    //Pick figures by both Type and Color, for play mode
		break;

	case BY_AREA:    //Pick figures by Area, for play mode
		break;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}

//////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::printinfo(CFigure* pI)
{
	for (int i = 0; i < SelecFigCount; i++)
	{
		if (SelecFigCount == 1)
		{
			SelectedFigList[i]->print(pOut);
		}
		else if (SelecFigCount > 1)
		{
			pOut->PrintMessage("Number of selected figure: ");
			pOut->PrintInteger(SelecFigCount);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////
// Add a selected figure to an array 
void ApplicationManager::AddSelectedFigure(CFigure* s)
{
	if (SelecFigCount < MaxSelecCount)
		SelectedFigList[SelecFigCount++] = s;
}

////////////////////////////////////////////////////////////////////////////////////

CFigure* *ApplicationManager::GetSelectedFigs()
{
	return SelectedFigList;
}

int ApplicationManager::GetSelectedCount()
{
	return SelecFigCount;
}

int ApplicationManager::GetFigCount()
{
	return FigCount;
}
void ApplicationManager::UNSelectFigure(CFigure* s)
{
	for (int i = 0; i < SelecFigCount; i++)
	{
		if (SelectedFigList[i] == s) //[1 2 3 ]4 ] 
		{
			SelectedFigList[i] = SelectedFigList[SelecFigCount - 1];
			SelectedFigList[SelecFigCount - 1] = NULL;
			SelecFigCount--;
			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////

CFigure* ApplicationManager::GetFigure(int x, int y) const // ll select
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount - 1; i >= 0; i--)
	{
		CFigure* C = dynamic_cast<CRectangle*>(FigList[i]); //dynamic casting checking 
		if (C != NULL)
		{
			if (FigList[i]->checkLoc(x, y))
				return FigList[i];
		}

		C = dynamic_cast<CCircle*>(FigList[i]);
		if (C != NULL)
		{
			if (FigList[i]->checkLoc(x, y))
				return FigList[i];
		}

		C = dynamic_cast<CTriangle*>(FigList[i]);
		if (C != NULL)
		{
			if (FigList[i]->checkLoc(x, y))
				return FigList[i];
		}

		C = dynamic_cast<CLine*>(FigList[i]);
		if (C != NULL)
		{
			if (FigList[i]->checkLoc(x, y))
				return FigList[i];
		}
	}
	return NULL;
}

CFigure** ApplicationManager::GetDrawnFigs()
{
	return FigList;
}
int ApplicationManager::GetFigCount()
{
	return FigCount;
}
void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	clearselcFig();

	void ApplicationManager::deleteFig()
	{
		int k = 0;
		if (SelecFigCount == 0)
		{
			pOut->PrintMessage("please select figure first");
			return;
		}
		for (int i = 0; i < MaxFigCount; i++)
		{
			if (!FigList[i - k])
			{
				break;
			}
			else if (FigList[i - k]->IsSelected())
			{
				clearselcFig();
				delete FigList[i - k];
				FigList[i - k] = FigList[FigCount - 1];
				FigList[FigCount - 1] = NULL;
				FigCount--;
				k++;
				pOut->PrintMessage("Figure(s) deleted successfully");
			}
		}
	}

//==================================================================================//
//								Save Related Functions								//
//==================================================================================//

void ApplicationManager::SaveAll(ofstream& Outfile)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(Outfile); //Call Save Function
	}
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}

//////////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::clearselcFig()
{
	for (int i = 0; i < SelecFigCount; i++)
	{
		SelectedFigList[i] = NULL;
	}
	SelecFigCount = 0;
}

void ApplicationManager::OnlyclearselcFig()  //Only clears selected figure without selected figure count
{
	for (int i = 0; i < SelecFigCount; i++)
	{
		SelectedFigList[i] = NULL;
	}

void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i] = NULL;
	}
	FigCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < SelecFigCount; i++)
		delete SelectedFigList[i];
	delete pIn;
	delete pOut;
}

//Draw all figures on the user interface in the play mode specifically
void ApplicationManager::UpdateInterface_PlayMode() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->figStatus() == false)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}

//=================================================================================//
//                 Clipboard used for Copy, Cut & Paste Functions                  //
//=================================================================================//
void ApplicationManager::SetClipboard(CFigure** fig)
{
	IsInClipboard = true;
	/*for (int i = 0; i < SelecFigCount; i++)
	{
		Clipboard[ClipboardCount++] = fig[i];
	}*/
	Clipboard = fig;
}
CFigure** ApplicationManager::GetClipboard()
{
	if (IsInClipboard)
		return Clipboard;
	else
		return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetIsFigCut(bool b)
{
	IsFigCut = b;
}
////////////////////////////////////////////////////////////////////
bool ApplicationManager::GetIsFigCut()
{
	return IsFigCut;
}
void ApplicationManager::ClearClipboard()
{
	for (int i = 0; i < ClipboardCount; i++)
	{
		Clipboard[i] = NULL;
	}
}
void ApplicationManager::SetCount(int x)
{
	TempCount = x;
}
int ApplicationManager::GetCount()
{
	return TempCount;
}