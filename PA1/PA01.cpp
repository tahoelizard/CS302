// Program Information ////////////////////////////////////////////////////////
/*
     File Name:    PA01.cpp

     Description:  Program runs driver to test linked list class
*/

// Version/Revision Information ///////////////////////////////////////////////
/*
     1.00 (08/21/2015) - Michael Leverington
          program developed for first programming assignment
          materials loosely based on linked list exercise in Brandle, et. al.
          in C++ Data Structures: A Laboratory Course, (c) 2009
*/

// Program description/support ////////////////////////////////////////////////
/*
     Program requires ListNode.h, ListNode.cpp, LinkedList.h, LinkedList.cpp
     to be appropriately linked with this file
*/

// Precompiler directives /////////////////////////////////////////////////////

   // none

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "LinkedList.h"

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const int SMALL_STR_LEN = 25;

enum CONTROL_CODES { HLP_CODE, ATB_CODE, IBC_CODE, IAC_CODE, RBC_CODE, 
                       R_AT_C_CODE, RAC_CODE, D_AT_C_CODE, CNC_CODE,
                         CTB_CODE, CTE_CODE, CFE_CODE, CFF_CODE, G_AT_C_CODE, 
                           MCL_CODE, MCR_CODE, CLT_CODE, ETP_CODE, NOP_CODE };

const bool VERBOSE = false;

const char ENDLINE_CHAR = '\n';

// Free function prototypes  //////////////////////////////////////////////////

void ShowMenu();
void GetCommandInput( char inputString[] );
int GetDataInput( const char inputString[] );
CONTROL_CODES ProcessInput( const char inStr[] );

// Main function implementation  //////////////////////////////////////////////

int  main()
   {
    LinkedList testListA, testListB, testListC;    // Test lists
    int testData;          // List data item
    char commandString[ SMALL_STR_LEN ];
    CONTROL_CODES command;
    bool tempBool, testListC_Constructed = false;

    ShowMenu();

    do
       {
        cout << endl << "Command: ";                  // Read command
        
        GetCommandInput( commandString );

        testData = GetDataInput( commandString );

        command = ProcessInput( commandString );

        if( !VERBOSE )
           {
            cout << commandString << testData << endl;
           }

        switch ( command )
           {
            case HLP_CODE:  // Help
               ShowMenu();
               break;

            case ATB_CODE:  // assign to b list

               testListB = testListA;

               if( VERBOSE )
                  {
                   cout << "  Test list \'A\' has been assigned to test list \'B\'." 
                        << endl;
                  }
               break;

            case CNC_CODE:  // construct c test list

               // tempTestList constructed in code block to control scope
                  { 
                   LinkedList tempTestList( testListA );

                   testListC = tempTestList;

                   testListC_Constructed = true;

                   tempTestList.~LinkedList();
                  }

               if( VERBOSE )
                  {
                   cout << "  Test list \'C\' has been constructed with test list \'A\'." 
                        << endl;
                  }
               break;

            case IBC_CODE:  // insert before cursor

               tempBool = testListA.insertBeforeCursor( testData );

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Value: " << testData 
                            << " inserted before cursor." << endl;
                      }
                   else
                      {
                       cout << "  Insert before cursor process failed." << endl;
                      }
                  }
               break;

            case IAC_CODE:  // insert after cursor

               tempBool = testListA.insertAfterCursor( testData );

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Value: " << testData 
                            << " inserted after cursor." << endl;
                      }
                   else
                      {
                       cout << "  Insert after cursor process failed." << endl;
                      }
                  }
               break;

            case RBC_CODE:  // replace before cursor

               tempBool = testListA.replaceBeforeCursor( testData );

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Value: " << testData 
                            << " replaced before cursor." << endl;
                      }
                   else
                      {
                       cout << "  Replace before cursor process failed." << endl;
                      }
                  }
               break;

            case R_AT_C_CODE:  // replace at cursor

               tempBool = testListA.replaceAtCursor( testData );

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Value: " << testData 
                            << " replaced after cursor." << endl;
                      }
                   else
                      {
                       cout << "  Replace after cursor process failed." << endl;
                      }
                  }
               break;

            case RAC_CODE:  // replace after cursor

               tempBool = testListA.replaceAfterCursor( testData );

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Value: " << testData 
                            << " replaced after cursor." << endl;
                      }
                   else
                      {
                       cout << "  Replace after cursor process failed." << endl;
                      }
                  }
               break;

            case D_AT_C_CODE:  // remove at cursor

               tempBool = testListA.removeAtCursor( testData );

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Value: " << testData 
                            << " removed at cursor." << endl;
                      }
                   else
                      {
                       cout << "  Remove at cursor process failed." << endl;
                      }
                  }
               break;

            case G_AT_C_CODE:  // get value at cursor

               tempBool = testListA.getDataAtCursor( testData );

               if( tempBool )
                  {
                   cout << "  Value: " << testData 
                        << " found at cursor." << endl;
                  }

               else if( VERBOSE )
                  {
                   cout << "  Data access at cursor process failed." << endl;
                  }
               break;

            case CTB_CODE:  // set cursor at beginning

               tempBool = testListA.goToBeginning();

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Cursor set at beginning of list." << endl;
                      }
                   else
                      {
                       cout << "  Cursor set to beginning process failed." << endl;
                      }
                  }
               break;

            case CTE_CODE:  // set cursor at end

               tempBool = testListA.goToEnd();

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Cursor set at end of list." << endl;
                      }
                   else
                      {
                       cout << "  Cursor set to end process failed." << endl;
                      }
                  }
               break;

            case MCL_CODE:  // move cursor left

               tempBool = testListA.goToPrior();

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Cursor moved left." << endl;
                      }
                   else
                      {
                       cout << "  Cursor move left process failed." << endl;
                      }
                  }
               break;

            case MCR_CODE:  // move cursor right

               tempBool = testListA.goToNext();

               if( VERBOSE )
                  {
                   if( tempBool )
                      {
                       cout << "  Cursor moved right." << endl;
                      }
                   else
                      {
                       cout << "  Cursor move right process failed." << endl;
                      }
                  }
               break;

            case CFE_CODE:  // check for empty

               if( testListA.isEmpty() )
                  {
                   cout << "  List is empty." << endl;
                  }
               else
                  {
                   cout << "  List is not empty." << endl;
                  }
               break;

            case CFF_CODE:  // check for full

               if( testListA.isFull() )
                  {
                    cout << "  List is full." << endl;
                  }
               else
                  {
                   cout << "  List is not full." << endl;
                  }
               break;

            case CLT_CODE:  // clear the list

               testListA.clear();

               if( VERBOSE )
                  {
                   cout << "  List has been cleared." << endl;
                  }
               break;

            case ETP_CODE:  // clear the list

               if( VERBOSE )
                  {
                   cout << "  End Program Requested" << endl;
                  }

               break;

            default :            // Invalid command

               // clear to end of line in case further data input
               cin.ignore( SMALL_STR_LEN, ENDLINE_CHAR );

               if( VERBOSE )
                  {
                   cout << "  Inactive or invalid command" << endl;
                  }
           }

        testListA.showStructure( 'A' );
        testListB.showStructure( 'B' );

        if( testListC_Constructed )
           {
            testListC.showStructure( 'C' );
           }
       }
    while ( command != ETP_CODE );

    return 0;
   }

// Free function implementation  //////////////////////////////////////////////

/******************************************************************************
Function Specifications: ShowMenu
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - menu is displayed as shown
Algorithm: 
  - console output
Exceptional/Error Conditions:
  - none expected or treated
*/
void ShowMenu()
   {
    cout << endl << "Commands:" << endl << endl;
    cout << "  hlp    : Show this list of commands" << endl << endl;

    cout << "  atb    : Assign to \'B\' test list" << endl;
    cout << "  cnc    : Construct \'C\' test list with test list \'A\'" << endl;
    cout << "  cte    : Set cursor at end" << endl << endl;

    cout << "  ibc x  : Insert x before the cursor" << endl;
    cout << "  iac x  : Insert x after the cursor" << endl;
    cout << "  rbc x  : Replace with x before the cursor" << endl;
    cout << "  r@c x  : Replace with x at the cursor" << endl;
    cout << "  rac x  : Replace with x after the cursor" << endl << endl;

    cout << "  d@c    : Delete value at the cursor" << endl;
    cout << "  g@c    : Get value at the cursor" << endl << endl;

    cout << "  ctb    : Set cursor at beginning" << endl;
    cout << "  cte    : Set cursor at end" << endl << endl;
    cout << "  mcl    : Move cursor left" << endl;
    cout << "  mcr    : Move cursor right" << endl << endl;

    cout << "  cfe    : Check list for empty" << endl;
    cout << "  cff    : Check list for full" << endl;
    cout << "  clt    : Clear the list" << endl << endl;

    cout << "  etp    : End the test program" << endl;
    cout << endl;
   }

/******************************************************************************
Function Specifications: GetCommandInput
===============================================================================
Preconditions:
  - none expected
Postconditions:
  - string is cleared and first three letters are input from data stream
Algorithm: 
  - console input of three characters
Exceptional/Error Conditions:
  - none expected or treated
*/
void GetCommandInput
  ( 
   char inputString[] // output: string to be returned
  )
   {
    strcpy( inputString, "     " );

    cin >> inputString[ 0 ] >> inputString[ 1 ] >> inputString[ 2 ];
   }

/******************************************************************************
Function Specifications: GetDataInput
===============================================================================
Preconditions:
  - input string holds three character string command
Postconditions:
  - for any string command beginning with 'i/I' or 'r/R',
    integer data is expected and input
Algorithm: 
  - console input, if selected
Exceptional/Error Conditions:
  - returned data value is set to zero in case it is not found in data stream
*/
int GetDataInput
  ( 
   const char inputString[] // input: string used to decide to input
  )
   {
    char inChar = inputString[ 0 ];
    int dataVal = 0;

    if( inChar == 'i' || inChar == 'I' || inChar == 'r' || inChar == 'R' )
       {
        cin >> dataVal;
       }

    return dataVal;
   }

/******************************************************************************
Function Specifications: ProcessInput
===============================================================================
Preconditions:
  - input string holds three character string command
Postconditions:
  - an integer constant is returned for each string command provided
Algorithm: 
  - selection of command from string
Exceptional/Error Conditions:
  - function returns a "no-op" constant if command string is not found
  - function adapts to any variation of letter case
*/
CONTROL_CODES ProcessInput
  ( 
   const char inStr[] // input: string used to translate commands
  )
   {
    char ltr1 = inStr[ 0 ], ltr2 = inStr[ 1 ], ltr3 = inStr[ 2 ];

    switch( ltr1 )
       {
        case 'a': case 'A':

           if( ltr2 == 't' || ltr2 == 'T' )
              {
               if( ltr3 == 'b' || ltr3 == 'B' )
                  {
                   return ATB_CODE;
                  }
              }
           break;

        case 'c': case 'C':

           if( ltr2 == 'f' || ltr2 == 'F' )
              {
               if( ltr3 == 'e' || ltr3 == 'E' )
                  {
                   return CFE_CODE;
                  }
               else if( ltr3 == 'f' || ltr3 == 'F' )
                  {
                   return CFF_CODE;
                  }
              }

           else if( ltr2 == 'l' || ltr2 == 'L' )
              {
               if( ltr3 == 't' || ltr3 == 'T' )
                  {
                   return CLT_CODE;
                  }
              }

           else if( ltr2 == 'n' || ltr2 == 'N' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return CNC_CODE;
                  }
              }

           else if( ltr2 == 't' || ltr2 == 'T' )
              {
               if( ltr3 == 'b' || ltr3 == 'B' )
                  {
                   return CTB_CODE;
                  }
               else if( ltr3 == 'e' || ltr3 == 'E' )
                  {
                   return CTE_CODE;
                  }
              }

           break;

        case 'd': case 'D':

           if( ltr2 == '@' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return D_AT_C_CODE;
                  }
              }

           break;

        case 'e': case 'E':

           if( ltr2 == 't' || ltr2 == 'T' )
              {
               if( ltr3 == 'p' || ltr3 == 'P' )
                  {
                   return ETP_CODE;
                  }
              }

           break;

        case 'g': case 'G':

           if( ltr2 == '@' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return G_AT_C_CODE;
                  }
              }

           break;

        case 'h': case 'H':

           if( ltr2 == 'l' || ltr2 == 'L' )
              {
               if( ltr3 == 'p' || ltr3 == 'P' )
                  {
                   return HLP_CODE;
                  }
              }

           break;

        case 'i': case 'I':

           if( ltr2 == 'b' || ltr2 == 'B' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return IBC_CODE;
                  }
              }

           else if( ltr2 == 'a' || ltr2 == 'A' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return IAC_CODE;
                  }
              }

           break;

        case 'm': case 'M':

           if( ltr2 == 'c' || ltr2 == 'C' )
              {
               if( ltr3 == 'l' || ltr3 == 'L' )
                  {
                   return MCL_CODE;
                  }

               else if( ltr3 == 'r' || ltr3 == 'R' )
                  {
                   return MCR_CODE;
                  }
              }

           break;

        case 'r': case 'R':

           if( ltr2 == 'b' || ltr2 == 'B' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return RBC_CODE;
                  }
              }

           else if( ltr2 == '@' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return R_AT_C_CODE;
                  }
              }

           if( ltr2 == 'a' || ltr2 == 'A' )
              {
               if( ltr3 == 'c' || ltr3 == 'C' )
                  {
                   return RAC_CODE;
                  }
              }

           break;
       }

    return NOP_CODE;
   }















