#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	//BC:0(1)     WC:0(1)    Overall:O(1)
	
	this->current = 0;

}


void SortedSetIterator::first() {
	//BC:0(1)     WC:0(1)    Overall:O(1)

	this->current = 0;
}


void SortedSetIterator::next() {
	//BC:0(1)     WC:0(1)    Overall:O(1)
	
	if (!valid()) {
		throw exception();
	}
	else {
		this->current++;
	}
}


TElem SortedSetIterator::getCurrent()
{
	//BC:0(1)     WC:0(1)    Overall:O(1)

	if (!valid()) {
		throw exception();
	}
	else {
		return this->multime.e[this->current];
	}
}

bool SortedSetIterator::valid() const {
	//BC:0(1)     WC:0(1)    Overall:O(1)
	//TODO - Implementation
	return  (this->current < this->multime.n);
}

