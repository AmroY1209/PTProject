#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x, y;
	//Create Input and Output objects to test
	Output* pOut = new Output();;
	Input* pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constructor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2, P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 4;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.FillClr = CORNFLOWERBLUE;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Line Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Line, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.2.1 - Drawing normal line
	pOut->PrintMessage("Drawing a Line ==> normal,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	
	pOut->DrawLine(P1, P2, gfxInfo, false);

	// 2.2.2 - Drawing highlighted line
	pOut->PrintMessage("Drawing a Line ==> Highlighted , Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawLine(P1, P2, gfxInfo, true);

	pOut->PrintMessage("Drawing a Line Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.3.1 - Drawing non-filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);

	// 2.3.2 - Drawing highlighted non-filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);


	// 2.3.3 - Drawing a filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 4;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.FillClr = CORNFLOWERBLUE;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);


	// 2.3.4 - Drawing a highlighted filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Circle in all possible states

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 2.4.1 - Drawing non-filled Circle
	pOut->PrintMessage("Drawing a Circle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawCirc(P1, P2, gfxInfo, false);
	// 2.4.2 - Drawing highlighted non-filled Circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCirc(P1, P2, gfxInfo, true);

	// 2.4.3 - Drawing a filled Circle
	pOut->PrintMessage("Drawing a Circle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 4;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.FillClr = CORNFLOWERBLUE;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawCirc(P1, P2, gfxInfo, false);

	// 2.4.4 - Drawing a highlighted filled Circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCirc(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the stirng clear the status bar
	// 3- print on the status bar "You Entered" then print the string
	string m = pIn->GetSrting(pOut);
	pOut->PrintMessage("You Entered: "+m);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
			pOut->PrintMessage("Action: Draw a Rectangle, Click anywhere");
			break;

		case DRAW_LINE:
			pOut->PrintMessage("Action: Draw a Line, Click anywhere");
			break;

		case DRAW_CIRC:
			pOut->PrintMessage("Action: Draw a Circle, Click anywhere");
			break;

		case DRAW_TRI:
			pOut->PrintMessage("Action: Draw a Triangle, Click anywhere");
			break;

		case COPY:
			pOut->PrintMessage("Action: Copy the selected figures, Click anywhere");
			break;

		case PASTE:
			pOut->PrintMessage("Action: Paste the last copied/cut figures, Click anywhere");
			break;

		case SELECT:
			pOut->PrintMessage("Action: Select a figure, Click anywhere");
			break;

		case CUT:
			pOut->PrintMessage("Action: Cut the selected figures, Click anywhere");
			break;

		case CHNG_DRAW_CLR:
			pOut->PrintMessage("Action: Change the drawing color, Click anywhere");
			break;

		case CHNG_FILL_CLR:
			pOut->PrintMessage("Action: Change the fill color, Click anywhere");
			break;

		case CHNG_BK_CLR:
			pOut->PrintMessage("Action: Change the background color, Click anywhere");
			break;

		case MOVE:
			pOut->PrintMessage("Action: Move the selected object to a selected position, Click anywhere");
			break;

		case RESIZE:
			pOut->PrintMessage("Action: Change size of a selected object, Click anywhere");
			break;

		case SAVE:
			pOut->PrintMessage("Action: Save to a file, Click anywhere");
			break;

		case DEL:
			pOut->PrintMessage("Action: Delete the selected object, Click anywhere");
			break;

		case STATUS:
			pOut->PrintMessage("Action: A click on the Status Bar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: A click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: A click on an empty area in the Designed Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating Draw tool bar");
			pOut->CreateDrawToolBar();
			break;

		case TO_ADDITEM:
			pOut->PrintMessage("Action: Switch to add item menu, choose one of the figures: ");
			pOut->CreateDrawItemsToolbar();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Play tool bar");
			pOut->CreatePlayToolBar();
			break;

		case BY_COLOR:
			pOut->PrintMessage("Action: Pick figures by Color, Click anywhere");
			break;

		case BY_TYPE:
			pOut->PrintMessage("Action: Pick figures by Type, Click anywhere");
			break;

		case BY_BOTH:
			pOut->PrintMessage("Action: Pick figures by both Type and Color, Click anywhere");
			break;

		case BY_AREA:
			pOut->PrintMessage("Action: Pick figures by Area, Click anywhere");
			break;

		case ZOOM_IN:
			pOut->PrintMessage("Action: Zoom in, Click anywhere");
			break;

		case ZOOM_OUT:
			pOut->PrintMessage("Action: Zoom out, Click anywhere");
			break;

		case LOAD:
			pOut->PrintMessage("Action: Load a saved graph from a file, Click anywhere");
			break;

		case EXIT:
			break;
		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
	return 0;
}

