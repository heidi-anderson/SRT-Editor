/** ***************************************************************************
 * @file
 *
 * @brief has all of Heidi Anderson's srtList functions.
 *****************************************************************************/

#include "thpe02.h"

 /** ***************************************************************************
  * @author Heidi Anderson
  *
  * @par Description
  * This function constucts an empty srtList
  *
  * @par Example
  * @verbatim
    headptr = nullptr;

    @endverbatim
  *****************************************************************************/
srtList::srtList( ) 
{
    headptr = nullptr;  // makes empty list
}



/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description
 * This function destructs an srtList
 *
 *****************************************************************************/
srtList::~srtList( )
{

}



/** ***************************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  Outputs entire list of nodes to an ofstream
 *
 *
 *  @param[in, out] out - an ofstream to output to
 *
 *  @par Example
 *  @verbatim

    list1; // assume contains frames 1, 2, and 3
    ofstream out;
    string fileName = "out.srt"
    out.open(fileName);
    list1.print( out );

    //a file containing frames 1, 2, and 3 names out.srt has been written

    @endverbatim
 *****************************************************************************/
void srtList::print( ofstream& out ) const
{
    node* ptr = headptr;    // node
    int frameNumber = 1;    // frame number

    if( headptr == nullptr ) // check if empty
        return;
    
    while( ptr != nullptr )
    {
        out << frameNumber << endl;                 // frame number
        out << ( ptr->theFrame.startTime );         // start time
        out << " --> ";                             // arrow thing
        out << ( ptr->theFrame.endTime ) << endl;   // endtime
        out << ( ptr->theFrame.caption ) << endl;   // caption
        if( ptr->next != nullptr )
            out << '\n';
        ptr = ptr->next;    // traverse
        frameNumber++;      // increment frame number
    }
}



/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description
 * This function determines the size of a linked list.
 *
 * @returns true if successful and false otherwise.
 *
 * @par Example
 * @verbatim
    TEST_CASE("size")
    {
        srtList list1;
        frame frame1, frame2, frame3;

        list1.insert(frame1);
        list1.insert(frame2);
        list1.insert(frame3);

        REQUIRE(list1.size() == 3);
    }
   @endverbatim
 *****************************************************************************/
int srtList::size( )
{
    int count = 0;          // iterator
    node* ptr = headptr;    // node

    while( ptr != nullptr )
    {
        count++;            // increment count
        ptr = ptr->next;    // traverse 
    }
    return count;

}



/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description
 * This function tests to see if the list is empty
 *
 * @returns bool, true if it is empty, false otherwise
 * 
 * @par Example
 * @verbatim
   if (headptr == nullptr)
        return true;
    return false;

   @endverbatim
 *
 *****************************************************************************/
bool srtList::empty( )
{
    if( headptr == nullptr ) // if headptr is nullptr, the list is clearly empty
        return true;
    return false;
}



/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description
 * this function removes a section of frames based on end time and start time
 *
 * @param[in] startTime - start of what needs to be removed
 * @param[in] endTime - end time of what needs to be removed.
 *
 * @returns true if successful, false otherwise.
 *
 * @par Example
 * @verbatim
    string startTime = "00:32:03,150";
    string endTime = "00:35:10,009";
    ifstream fin("sw1.srt");
    srtList list1;

    REQUIRE(fin.is_open());
    REQUIRE(list1.readSRTFile(fin) == true);
    fin.close();

    REQUIRE(list1.size() == 28);
    list1.removeRangeTime(startTime, endTime);
    REQUIRE(list1.size() == 23)

   @endverbatim
 *
 *****************************************************************************/
bool srtList::removeRangeTime( string startTime, string endTime )
{
    int frameNumber = 1;    // starting point for frame nums
    node* ptr = headptr;    // starting point for srtList

    while( ptr != nullptr )
    {
        if( startTime <= ptr->theFrame.startTime &&
            ptr->theFrame.endTime <= endTime )       // if frame is between args
        {
            ptr = ptr->next;                        // traverse
            
            if( !remove( frameNumber ) )               // remove frame
                return false;
        }
        else
        {
            frameNumber++;                          // increment frame number
            ptr = ptr->next;                        // traverse
        }
    }
    return true;
}



/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description
 * this function removes a section of frames based on end frame and start frame
 *
 * @param[in] startFrame - start frame of what needs to be removed
 * @param[in] endFrame - end frame of what needs to be removed.
 *
 * @returns true if successfull, false otherwise
 *
 * @par Example
 * @verbatim
    string startTime = "00:32:03,150";
    string endTime = "00:35:10,009";
    ifstream fin("sw1.srt");
    srtList list1;

    REQUIRE(fin.is_open());
    REQUIRE(list1.readSRTFile(fin) == true);
    fin.close();

    REQUIRE(list1.size() == 28);
    list1.removeRangeTime(startTime, endTime);
    REQUIRE(list1.size() == 23)

   @endverbatim
 *
 *****************************************************************************/
bool srtList::removeRangeFrames( int startFrame, int endFrame )
{
    int frameNumber = 1;    // starting point of frame numbers
    node* ptr = headptr;    // starting point of list

    while( ptr != nullptr )
    {
        ptr = ptr->next;    // traverse
        if( startFrame <= frameNumber &&  // if given start is <= current frame
            endFrame >= frameNumber )      // if given end is >= current frame  
        {                                                   
            if( !remove( frameNumber ) )     // remove frame
                return false;               
        }
            frameNumber++;  // increment frame number
    }

    return true;
}


/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description
 * checks that the times on the frames are valid.
 * 
 * @param[in] aFrame - struct variable holding frame information
 *
 * @returns true if successfull, false otherwise
 *
 * @par Example
 * @verbatim
    srtList list;   
    frame aFrame;   // assume frame holds information (time/caption/frame num)

    list.validFrame( aFrame );

    output would be true.

   @endverbatim
 *
 *****************************************************************************/
bool srtList::validFrame( frame aFrame )
{
    string startTime = aFrame.startTime;
    string endTime = aFrame.endTime;
    int i;

    if( startTime.length( ) != 12 )
        return false;

    if( startTime.at( 3 ) == ':' || startTime.at( 6 ) == ':' || startTime.at( 9 ) == ',' )
        return false;

    for( i = 0; i < 12; ++i )
    {
        if( i != 2 && i != 5 && i != 8 )
        {
            if( !isdigit( endTime[i] ) )
                return false;
        }
    }
    if( endTime < startTime )
        return false;
    return true;
}  