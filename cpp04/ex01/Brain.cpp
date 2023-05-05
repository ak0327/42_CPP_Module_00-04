#include "Brain.hpp"

Brain::Brain() {
	cout << "Brain constructor called" << endl;
	for (int i=0; i<IDEAS_SIZE; i++) {
		ideas_[i] = "Brain";
	}
}

Brain::Brain(const Brain &brain) {
	*this = brain;
	cout << "Brain copy constructor called" << endl;
}

Brain::~Brain() {
	cout << "Brain destructor called" << endl;
}

Brain &Brain::operator=(const Brain &brain) {
	if (this != &brain) {
		for (int i=0; i<IDEAS_SIZE; i++) {
			ideas_[i] = brain.ideas_[i];
		}
	}
	cout << "Brain copy assignment operator called" << endl;
	return *this;
}