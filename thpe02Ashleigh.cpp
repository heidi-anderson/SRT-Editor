#include "thpe02.h"

/************************************************************************
 *  @author Ashleigh Kirkpatrick
 *
 *  @par Description
    Given a string that holds the frame, checks that everything that needs
    to be is a digit is a digit. This also checks there is colons between
    hours, mintues, and seconds and a comma between seconds and milliseconds.
 *
 *  @param[in] time - string that holds either the start or end time of structure
 *
 *  @par Example
 *  @verbatim
    string time = "00:00:00,000";
    bool result;

    result = validateTime( time ); //would return true

    time = "00:0a:00,00b";

    result = validateTime( time ); //would return false

    @endverbatim
 ************************************************************************/
bool validateTime( string time )
{
    string firstPair;
    string secondPair;
    string thirdPair;
    string trio;
    string firstCol;
    string secondCol;
    string comma;

    firstPair = time.substr( 0, 2 );
    firstCol = time.substr( 2, 1 );
    secondPair = time.substr( 3, 2 );
    secondCol = time.substr( 5, 1 );
    thirdPair = time.substr( 6, 2) ;
    comma = time.substr( 8, 1 );
    trio = time.substr( 9, 3 );

    if( isdigit( firstPair[0] ) && isdigit( firstPair[1] ) ) 
    {
        if( isdigit( secondPair[0] ) && isdigit(secondPair[1] ) )
        {
            if( isdigit( thirdPair[0] ) && isdigit( thirdPair[1] ) )
            {
                if( isdigit( trio[0] ) && isdigit( trio[1] ) && isdigit( trio[2] ) )
                {
                    if( firstCol == ":" )
                    {
                        if( secondCol == ":" )
                        {
                            if( comma == "," )
                                return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}


/************************************************************************
 *  @author Ashleigh Kirkpatrick
 *
 *  @par Description
    Given a string that holds both the frame times, this function will
    check that the string has the correct seperators.
 *
 *  @param[in] frameTime - string that holds either the start or end time of structure
 *
 *  @par Example
 *  @verbatim
    string time = "00:01:00,001 --> 00:02:00,002";
    bool result;

    result = validateSeperator( time ); //would return true

    time = "00:03:00,001 <-- 00:04:00,001"

    result = validateSeperator( time ); //would return false

    @endverbatim
 ************************************************************************/
bool validateSeperator( string frameTime )
{
    string spaceOne;
    string spaceTwo;
    string dashOne;
    string dashTwo;
    string arrow;

    spaceOne = frameTime.substr( 12, 1 );
    spaceTwo = frameTime.substr( 15, 1 );
    dashOne = frameTime.substr( 13, 1 );
    dashTwo = frameTime.substr( 14, 1 );
    arrow = frameTime.substr( 15, 1 );

    if( spaceOne == " " )
    {
        if( spaceTwo == " " )
        {
            if( dashOne == "-" )
            {
                if( dashTwo == "-" )
                {
                    if( arrow == ">" )
                        return true;
                }
            }
        }
    } 

    return false;
}


/************************************************************************
 *  @author Ashleigh Kirkpatrick
 *
 *  @par Description
    Given a input file and output file, reads insturctions from the
    instructional file, calling the apporitate functions.
 *
 *  @param[in] in - input file
 *  @param[in] out - ouputfile
 *
 *  @par Example
 *  @verbatim
 *  ifstream in;
 *  ofstream out;
 *
 *

    @endverbatim
 ************************************************************************/
void readInstructions( ifstream& in, ofstream& fout, srtList list )
{
    string temp;
    frame aFrame;
    int num;
    string startTime, endTime;
    int firstFrame, lastFrame;
    string fileName;

    while( getline( in, temp ) )
    {
         if( temp == "--add" )
        {
            list.readIn(in, aFrame);
        }

        if( temp == "--remove" )
        {
            in >> num;

            if( !list.remove( num ) )
            {
                cout << "Unable to remove frame number: " << num << endl;
            }
        }

        if( temp == "--print" )
        {
            getline( in, fileName );
            openOutput( fout, fileName );
            list.print( fout );
        }

        if( temp == "--removeTime" )
        {
            cout << "Enter starting time: ";
            cin >> startTime;
            cout << "Enter ending time: ";
            cin >> endTime;

            list.removeRangeTime( startTime, endTime );
        }

        if( temp == "--removeFrameRange" )
        {
            cout << "Enter first frame to be removed: ";
            cin >> firstFrame;
            cout << "Enter last frame to be removed: ";
            cin >> lastFrame;

            list.removeRangeFrames( firstFrame, lastFrame );
        }
    }
}