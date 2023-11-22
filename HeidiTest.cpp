///** ***************************************************************************
// * @file
// *****************************************************************************/
//#include "thpe02.h"
//#include "../catch_amalgamated.hpp"
//
//using namespace Catch;
//TEST_CASE("srtList::size - size of 0")
//{
//    srtList list;   // list to hold frames
//
//    REQUIRE(list.size() == 0);  // nothing was inserted, size returns 0
//}
//
//TEST_CASE("srtList::size - size of 1")
//{
//    srtList list;   // list to hold frame
//    frame aFrame;   // frame    
//
//    aFrame.startTime = "start";     // initialize startTime
//    aFrame.endTime = "end";         // initialize endTime
//    aFrame.caption = "caption";     // initialize caption
//
//    list.insert(aFrame);            // insert frame into list
//    int size = list.size();         // get size of list
//
//    REQUIRE(size == 1);             // require size() return one
//}
//
//TEST_CASE("srtList::empty - true")
//{
//    srtList list;   // list to hold frames
//
//    REQUIRE(list.empty() == true); // nothing was inserted, empty returns true
//}
//
//TEST_CASE("srtList::empty - false")
//{
//    srtList list;   // list to hold frame
//    frame aFrame;   // frame
//
//    aFrame.startTime = "start";     // initialize startTime
//    aFrame.endTime = "end";         // initialize endTime
//    aFrame.caption = "caption";     // initialize caption
//
//    list.insert(aFrame);            // insert frame into list
//    
//    REQUIRE(list.empty() == false); // require list to not be empty
//}
//TEST_CASE("removeRangeTime")
//{
//    string startTime = "00:32:05,600";  // frame 5, first to be removed
//    string endTime = "00:54:09,259";    // frame 22, last to be removed
//    ifstream fin;                       // input file
//    srtList list1;                      // list to hold frames
//    frame aFrame;                       // frame
//
//    fin.open("test1.srt");      // open input file
//    REQUIRE(fin.is_open());     // check that file is open
//
//    list1.readIn(fin, aFrame);  // read into list
//    fin.close();                // close input file
//
//    int size = list1.size();    // get beginning list size
//
//    REQUIRE(size == 28);
//    list1.removeRangeTime(startTime, endTime);  // should remove 18 frames
//    REQUIRE(list1.size() == 10);                // ending size
//
//}
//
//TEST_CASE("srtList::removeRangeFrames")
//{
//    int startFrame = 5; // first frame to be removed
//    int endFrame = 22;  // last frame to be removed
//    ifstream fin;       // input file
//    srtList list;       // list to hold frames
//    frame aFrame;       // frame
//
//    fin.open("test1.srt");      // open input file
//    REQUIRE(fin.is_open());     // check that file is open
//
//    list.readIn(fin, aFrame);   // read into list
//    fin.close();                // close input file
//    
//    REQUIRE(list.size() == 28); // beginning size
//
//    list.removeRangeFrames(startFrame, endFrame);   // should remove 18 frames
//
//    REQUIRE(list.size() == 10); // ending size
//}
