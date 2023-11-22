/** ***************************************************************************
*  @file
*  @brief  Header file. All prototypes and includes are here.
* 
*  @author Donald Weigel, Heidi Anderson, Ashleigh Kirkpatrick
*****************************************************************************/
#ifndef __THPE02__H__
#define __THPE02__H__

#include <string>  
#include <iostream>
#include <fstream>
#include <list>
#include "srtList.h"

using namespace std;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

bool validateTime( string time );
void readInstructions( ifstream& in, ofstream& fout, srtList list );
void usageState( );
bool openInput( ifstream& file, string fileName );
bool openOutput( ofstream& file, string fileName );


#endif