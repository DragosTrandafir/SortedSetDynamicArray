#include "SortedSet.h"
#include "SortedSetIterator.h"

void SortedSet::resize() {
	//BC:0(1)     WC:0(n)    Overall:O(n)
	// allocate a new array with double capacity somewhere in the computer's memory
	TElem* eNew = new int[2 * cp];

	//copy all the elements from the old array into the new array
	for (int i = 0; i < n; i++)
		eNew[i] = e[i];

	// double the capacity
	cp = 2 * cp;

	//release the memory space occupied by the old array
	delete[] e;

	// make the field e to refer the new array (with double capacity)
	e = eNew;
}

SortedSet::SortedSet(Relation r) {
	//BC:0(1)     WC:0(1)    Overall:O(1)
	
	
	//initialize the capacity
	this->cp = 1;
	//allocate memory space for an array with at most cp TElems
	e = new TElem[cp];

	//initialize the number of elements
	this->n = 0;

	//initialise the relation
	this->rel = r;

}


bool SortedSet::add(TComp elem) {
	//BC:0(1)     WC:0(n^2)    Overall:O(n^2)
	
	if (search(elem))
		return false;
	if (n == cp)
		resize();
	int i = 0;
	bool added = false;
	while (i < this->n && !added) {
		if (!rel(this->e[i], elem))//opposite relation 
		{
			added = true;
			for (int j = n - 1; j >= i; j--)
				this->e[j + 1] = this->e[j];

			this->e[i] = elem;
			this->n++;
		}
		else i++;

	}
	if (!added && n < cp)
		{
			this->e[n] = elem;
			this->n++;
		}
	return true;
	
}





bool SortedSet::remove(TComp elem) {
	
	//BC:0(1)     WC:0(n)    Overall:O(n)
	bool found = false;
	int i = 0;
	while (i < this->n && !found) {
		if (this->e[i] == elem) {
			found = true;
			for (int j = i; j < n - 1; j++)
				this->e[j] = this->e[j + 1];
			this->n--;
		}
		else i++;
	}
	return found;
}



	//BC:0(1)     WC:0(n)    Overall:O(n)
	for (int i = 0; i < n && (rel(this->e[i],elem) || this->e[i] == elem); i++)
		if (this->e[i] == elem)
			return true;
	return false;
}





int SortedSet::size() const {
	
	//BC:0(1)     WC:0(1)    Overall:O(1)
	return this->n;
}



bool SortedSet::isEmpty() const {
	
	//BC:0(1)     WC:0(1)    Overall:O(1)
	return (n==0);
}

SortedSetIterator SortedSet::iterator() const {
	//BC:0(1)     WC:0(1)    Overall:O(1)
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	
	//BC:0(1)     WC:0(1)    Overall:O(1)
	delete[] e;
}


