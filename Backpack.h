#pragma once

#include "Fruit.h"
#include <vector>
#include <iostream>

class Backpack
{
public:
	// data type
	using VecFruits = vector<Fruit>;

	// cons`s
	Backpack();
	Backpack(const char* path);
	~Backpack();

	// console commands
	void add(Fruit* FruitToAdd);
	bool remove(Fruit* FruitToRemove);
	void printFruit(const Fruit* FruitToPrint) const;
	void printAll() const;
	
	// methods
	bool readFile();
	void clear();
	VecFruits* getFruits();

private:
	// members
	const char* m_filePath;
	VecFruits m_vecFruit;
};