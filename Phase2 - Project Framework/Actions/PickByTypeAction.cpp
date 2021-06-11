#include "PickByTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"

PickByTypeAction::PickByTypeAction(ApplicationManager* pApp) :Action(pApp)
{
	Cx = 0;
	Cy = 0;
	no_of_figs = 0;
	rightPick = 0;
	wrongPick = 0;
	num_of_each_fig[0] = 0;
	num_of_each_fig[1] = 0;
	num_of_each_fig[2] = 0;
	num_of_each_fig[3] = 0;
}

PickByTypeAction::~PickByTypeAction()
{
}

void PickByTypeAction::printScore(int score)
{
	string msg;
	if (score == 1)
	{
		rightPick++;
		msg = "Right, Keep Going!, Your score is: " + to_string(rightPick) + " Valid, and " + to_string(wrongPick) + " Invalid.";
	}
	else if (score == 2)
	{
		wrongPick++;
		msg = "Wrong, Look carfully!, Your score is: " + to_string(rightPick) + " Valid, and " + to_string(wrongPick) + " Invalid.";
	}
	else if (score == 3)
		msg = "YOU WIN!, Your score is: " + to_string(rightPick) + " Valid, and " + to_string(wrongPick) + " Invalid.";

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(msg);
}

void PickByTypeAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Game: Pick Figures by Type , Click on a figure to start playing ");

	fig = pManager->GetDrawnFigs();
	no_of_figs = pManager->GetFigCount();
	for (int i = 0; i < no_of_figs; i++)
	{
		if (dynamic_cast<CRectangle*>(fig[i]))
			num_of_each_fig[0]++;    //To get number of rectangles drawn
		else if (dynamic_cast<CLine*>(fig[i]))
			num_of_each_fig[1]++;    //To get number of lines drawn
		else if (dynamic_cast<CTriangle*>(fig[i]))
			num_of_each_fig[2]++;    //To get number of triangles drawn
		else 
			num_of_each_fig[3]++;    //To get number of circles drawn

		fig[i]->unHide();
	}

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void PickByTypeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (no_of_figs > 1)
	{
		CFigure* type = pManager->GetFigure(Cx, Cy);
		if (dynamic_cast<CRectangle*>(type))
		{
			no_to_pick = num_of_each_fig[0];
			pOut->PrintMessage("Pick all the rectangles!");
			r = 1;
		}
		else if (dynamic_cast<CLine*>(type))
		{
			no_to_pick = num_of_each_fig[1];
			pOut->PrintMessage("Pick all the lines!");
			l = 2;
		}
		else if (dynamic_cast<CTriangle*>(type))
		{
			no_to_pick = num_of_each_fig[2];
			pOut->PrintMessage("Pick all the triangles!");
			t = 3;
		}
		else
		{
			no_to_pick = num_of_each_fig[3];
			pOut->PrintMessage("Pick all the circles!");
			c = 4;
		}
		while (no_to_pick > 0)
		{
			pIn->GetPointClicked(Cx, Cy);
			if (Cy > UI.ToolBarHeight || Cx > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				CFigure* selectedFigure = pManager->GetFigure(Cx, Cy);
				if (selectedFigure != NULL)
				{
					if (dynamic_cast<CRectangle*>(selectedFigure) && r==1)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (dynamic_cast<CLine*>(selectedFigure) && l==2)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (dynamic_cast<CTriangle*>(selectedFigure) && t==3)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (dynamic_cast<CCircle*>(selectedFigure) && c==4)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else
					{
						printScore(2);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
					}
				}
			}
			else
			{
				pOut->PrintMessage("Toolbar clicked, you stopped the game");
				no_to_pick = -1;
			}
			if (no_to_pick == 0)
				printScore(3);
		}
	}
	else
		pOut->PrintMessage("You must draw at least two figures to play!");
	for (int i = 0; i < no_of_figs; i++)
	{
		fig[i]->unHide();
		pManager->UpdateInterface_PlayMode();
	}
}