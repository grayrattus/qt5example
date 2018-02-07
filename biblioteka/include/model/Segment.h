#ifndef SEGMENT_H
#define SEGMENT_H

#include <memory>
using namespace std;

class Segment {
		char letter;
		float value;
		public:
			Segment(char segmentLetter);
			float getValue();
			char getLetter();

};
#endif 

typedef unique_ptr<Segment> SegmentPtr;
