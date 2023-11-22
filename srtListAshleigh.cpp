//Functions Ashleigh builds will be here
#include "thpe02.h"
/************************************************************************
 *  @author Ashleigh Kirkpatrick
 *
 *  @par Description
    Reads an srt file and stores the information into a frame
 *
 *  @param[in] in - ifstream for input file
 *  @param[aFrame] - frame structure variable that stores fram info
 *
 *  @par Example
 *  @verbatim
    list.readSrtFile(file, aFrame);

    @endverbatim
 *
 ************************************************************************/
void srtList::readSrtFile( ifstream& in, frame& aFrame )
{
    string num;
    string tempCapt;
    string temp;
    string holder;
    bool result = true;

    //reads in caption
    while( getline( in, num, '\n' ) )
    {
       
        getline( in, temp );

        aFrame.caption = "";

        while( getline( in, tempCapt, '\n' ) && !tempCapt.empty( ) )
        {
            if( !aFrame.caption.empty( ) )
            {
                aFrame.caption += "\n";
            }
            aFrame.caption += tempCapt;
        }

        //reads in frame captions
        aFrame.startTime = temp.substr( 0, 12 );
        aFrame.endTime = temp.substr( 17, 12 );

        result = validateTime( aFrame.startTime );

        if( result == false )
        {
            //error message
            return;
        }

        result = validateTime( aFrame.endTime );

        if( result == false )
        {
            //error message
            return;
        }

        if( !insert( aFrame) )
        {
            cout << "Unable to insert frame:" << endl;
            cout << temp << endl;
            cout << aFrame.caption << endl;
        }
    }

    return;

}

/************************************************************************
 *  @author Ashleigh Kirkpatrick
 *
 *  @par Description
    Reads in the start time, end time, and caption into a structure.
 *
 *  @param[in] in - the file to read from
 *  @param[in] aFrame - the structure to read into
 *
 *  @par Example
 *  @verbatim
    string name = "Hi.txt";
    ifstream in;
    frame aFrame;

    in.open( name );

    readIn( in, aFrame );

    CHECK( aFrame.startTime == "00:01:00,001" ); //would be true
    CHECK( aFrame.endTime == "00:02:00,002" ); //would be true
    CHECK( aFrame.caption == "Hi!" ); //would be true

    @endverbatim
 ************************************************************************/
void srtList::readIn( ifstream& in, frame& aFrame )
{
    string tempCapt;
    string temp;
    string holder;
    bool result = true;
    int frameNum = 0;

    getline( in, temp );
    aFrame.caption = "";
    //reads in caption
    while( getline( in, tempCapt, '\n') && !tempCapt.empty( ) )
    {
        if ( !aFrame.caption.empty( ) )
        {
            aFrame.caption += "\n";
        }
        aFrame.caption += tempCapt;
    }

    //reads in frame captions
    aFrame.startTime = temp.substr( 0, 12 );
    aFrame.endTime = temp.substr( 17, 27 );

    result = validateTime( aFrame.startTime );

    if( result == false )
    {
        //error message
        return;
    }

    result = validateTime( aFrame.endTime );

    if( result == false )
    {
        //error message
        return;
    }

    if( !insert( aFrame) )
    {
        cout << "Unable to insert frame:" << endl;
        cout << temp << endl;
        cout << aFrame.caption << endl;
        
    }

    return;
}


/************************************************************************
 *  @author Ashleigh Kirkpatrick
 *
 *  @par Description
    Based of the start time of a certain structure, inserts structures into lists.
 *
 *  @param[in] aFrame - the structure to put in the list
 *
 *  @par Example
 *  @verbatim
    srtList list;
    frame frameOne, frameTwo, frameThree;
    bool result;

    frameOne.startTime = "00:01:00,010";
    frameOne.endTime = "00:02:00,004";
    frameOne.caption = "Hello Ash!";

    result = list.insert( frameOne ); //would be true

    @endverbatim
 ************************************************************************/
bool srtList::insert( frame aFrame )
{
    node* temp = new ( nothrow ) node;
    node* curr = headptr;
    node* prev = nullptr;

    if( temp == nullptr )
    {
        delete temp;
        return false;
    }

    temp->theFrame = aFrame;
    temp->next = nullptr;

    if( !validFrame( aFrame ) )
    {
        delete temp;
        return false;
    }

    if( empty( ) || aFrame.endTime.compare( curr->theFrame.startTime ) < 0 )
    {
        // insert to front
        temp->next = headptr;
        headptr = temp;
        return true;
    }

    while( curr != nullptr && aFrame.endTime.compare( curr->theFrame.startTime ) > 0 )
    {
        // traverse to the right spot
        prev = curr;
        curr = curr->next;
    }

    if( ( prev != nullptr && aFrame.startTime.compare( prev->theFrame.endTime ) >= 0 ) ||
        ( curr != nullptr && aFrame.endTime.compare( curr->theFrame.startTime ) <= 0 ) )
    {
        //insert in middle
        temp->next = curr;
        prev->next = temp;
        return true;
    }

    if( curr == nullptr && aFrame.startTime.compare( prev->theFrame.endTime ) > 0 )
    {
        // insert to end
        temp->next = curr;
        prev->next = temp;
        return true;
    }

    return false;
}

