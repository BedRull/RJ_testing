#include "Backpack.h"
#include <fstream>


Backpack::Backpack() :
	m_filePath(nullptr)
{
}


Backpack::Backpack(const char* path) :
	m_filePath(path)
{
}


Backpack::~Backpack()
{
}


void Backpack::add(Fruit* FruitToAdd)
{
	auto it = find(m_vecFruit.begin(), m_vecFruit.end(), *FruitToAdd);
	if(it != m_vecFruit.end())
		(*it).m_Count += FruitToAdd->m_Count;
	else
		m_vecFruit.push_back(*FruitToAdd);
}


bool Backpack::remove(Fruit* FruitToRemove)
{
	auto it = find(m_vecFruit.begin(), m_vecFruit.end(), *FruitToRemove);
	if(it != m_vecFruit.end())
	{
		if((*it).m_Count == FruitToRemove->m_Count)
		{
			m_vecFruit.erase(find(m_vecFruit.begin(), m_vecFruit.end(), *FruitToRemove));
			return true;
		}
		else if((*it).m_Count > FruitToRemove->m_Count)
		{
			(*it).m_Count -= FruitToRemove->m_Count;
			return true;
		}
	}

	return false;
}


void Backpack::printFruit(const Fruit* FruitToPrint) const
{
	cout << "Name: " << FruitToPrint->m_Name.c_str() << ". Weight: " << FruitToPrint->m_Weight << ". Price: " << FruitToPrint->m_Price << ". Count: " << FruitToPrint->m_Count << endl;
}


void Backpack::printAll() const
{
	for(auto itCur = m_vecFruit.begin(), itEnd = m_vecFruit.end(); itCur != itEnd; ++itCur)
		printFruit(&(*itCur));
}


bool Backpack::readFile()
{
	ifstream file;

	file.open(m_filePath);

	if(!file.is_open())
	{
		cout << "Unable to open file." << endl;
		return false;
	}

	while(file.peek() != EOF)
	{
		string Name;
		int Weight;
		int Price;

		file >> Name >> Weight >> Price;

		if(!file.good() && file.peek() != EOF)	// check if any errors occurred
		{
			cout << "Error while reading file. Invalid data format." << endl;
			return false;
		}

		add(&Fruit(Name, Weight, Price, 1));
	}

	file.close();
	return true;
}


void Backpack::clear()
{
	m_vecFruit.clear();
}


Backpack::VecFruits* Backpack::getFruits()
{
	return &m_vecFruit;
}