#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	//BC:?(1)     WC:?(1)    Overall:O(1)
	//TODO - Implementation
	this->current = 0;

}


void SortedSetIterator::first() {
	//BC:?(1)     WC:Tita(1)    Overall:O(1)
	//TODO - Implementation
	this->current = 0;
}


void SortedSetIterator::next() {
	//BC:?(1)     WC:?(1)    Overall:O(1)
	//TODO - Implementation
	if (!valid()) {
		throw exception();
	}
	else {
		this->current++;
	}
}


TElem SortedSetIterator::getCurrent()
{
	//BC:?(1)     WC:?(1)    Overall:O(1)
	//TODO - Implementation
	if (!valid()) {
		throw exception();
	}
	else {
		return this->multime.e[this->current];
	}
}

bool SortedSetIterator::valid() const {
	//BC:?(1)     WC:?(1)    Overall:O(1)
	//TODO - Implementation
	return  (this->current < this->multime.n);
}

