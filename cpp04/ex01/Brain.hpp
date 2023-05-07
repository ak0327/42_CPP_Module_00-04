#pragma once
#include <iostream>
#include <string>

#define IDEAS_SIZE 100


class Brain {
public:
	Brain();
	Brain(const Brain &brain);
	~Brain();
	Brain &operator=(const Brain &brain);

	const std::string &getIdeaElem(size_t idx_0_to_99) const;
	void setIdeaElem(size_t idx_0_to_99, const std::string &elem);

private:
	std::string ideas_[IDEAS_SIZE];

	void assertIdeasIdx(size_t idx) const;

};