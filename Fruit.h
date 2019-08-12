#pragma once
#include "Helper.h"

// Data type
struct Fruit
{
	string m_Name;
	int m_Weight;
	int m_Price;
	int m_Count;

	Fruit(string Name, int Weight, int Price, int Count) :
		m_Name(Name),
		m_Weight(Weight),
		m_Price(Price),
		m_Count(Count)
	{
	}

	friend bool operator== (const Fruit& f1, const Fruit& f2)
	{
		return (f1.m_Name == f2.m_Name && f1.m_Weight == f2.m_Weight && f1.m_Price == f2.m_Price);			// compare all except count
	}
};

