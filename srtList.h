/** ***************************************************************************
*  @file
*  @brief  Header file for srtList
*
*  @author Donald Weigel, Heidi Anderson, Ashleigh Kirkpatrick
*****************************************************************************/
#ifndef __SRTLIST__H__
#define __SRTLIST__H__

#include <string>  
#include <iostream>
#include <fstream>
#include <list>

using namespace std;


/**
 * @brief Holds data about the frames
 */
struct frame
{
    string startTime;   /**< Start Time of frame */
    string endTime;     /**< End Time of frame */
    string caption;     /**< caption */
};



/**
 * @brief Hold the data for an SRT list.
 */
class srtList
{
public:
    srtList();
    ~srtList();

    bool insert( frame aFrame );
    bool remove( int frameNumber );
    bool empty( );
    bool find( int frameNumber );
    bool removeRangeTime( string startTime, string endTime );
    void print( ofstream& fout ) const;
    void readIn( ifstream& in, frame& aFrame );
    void readSrtFile( ifstream& in, frame& aFrame );
    int size( );
    bool removeRangeFrames( int startFrame, int endFrame );
    bool validFrame( frame aFrame );

private:
/**
 * @brief Holds data for linked list
 */
    struct node
    {
        frame theFrame; /**< node for framae  */
        node* next;     /**< next node in the list */
    };
    node* headptr;      /**< first node in the list */


};

#endif