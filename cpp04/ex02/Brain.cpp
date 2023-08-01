#include "Brain.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Brain::Brain() {
	for (size_t i=0; i<IDEAS_SIZE; i++) {
		if (i % 2 == 0) {
			setIdeaElem(i, "Hello, this is neuron!");
		} else {
			setIdeaElem(i, "...??");
		}
	}
	std::cout << COLOR_MAGENTA << "Brain constructor" << COLOR_RESET << std::endl;
}

Brain::Brain(const Brain &brain) {
	for (size_t i=0; i<IDEAS_SIZE; i++) {
		setIdeaElem(i, brain.getIdeaElem(i));
	}
	std::cout << COLOR_MAGENTA << "Brain copy constructor" << COLOR_RESET << std::endl;
}

Brain::~Brain() {
	std::cout << COLOR_MAGENTA << "Brain destructor" << COLOR_RESET << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
	if (this != &brain) {
		for (size_t i=0; i<IDEAS_SIZE; i++) {
			setIdeaElem(i, brain.getIdeaElem(i));
		}
	}
	std::cout << COLOR_MAGENTA << "Brain copy assignment operator" << COLOR_RESET << std::endl;
	return *this;
}

const std::string &Brain::getIdeaElem(size_t idx_0_to_99) const {
	assertIdeasIdx(idx_0_to_99);
	return ideas_[idx_0_to_99];
}

void Brain::setIdeaElem(size_t idx_0_to_99, const std::string &elem) {
	assertIdeasIdx(idx_0_to_99);
	ideas_[idx_0_to_99] = elem;
}

void Brain::assertIdeasIdx(size_t idx) const {
	if (IDEAS_SIZE <= idx) {
		throw std::out_of_range(COLOR_RED "[Error] index out of range, index:[0,100)" COLOR_RESET);
	}
}
