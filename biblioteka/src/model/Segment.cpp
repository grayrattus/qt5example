#include "Segment.h"

Segment::Segment(char letter) {
	switch(letter) {
		case 'A':
			this->letter = 'A';
			this->value = 1.0;
			break;
		case 'B':
			this->letter = 'B';
			this->value = 1.1;
			break;
		case 'C':
			this->letter = 'C';
			this->value = 1.2;
			break;
		case 'D':
			this->letter = 'D';
			this->value = 1.3;
			break;
		case 'E':
			this->letter = 'E';
			this->value = 1.5;
			break;
		default:
			this->letter = 'E';
			this->value = 1.5;
			break;			
		}	
}

float Segment::getValue() {
	return this->value;
};
char Segment::getLetter() {
	return this->letter;
};

