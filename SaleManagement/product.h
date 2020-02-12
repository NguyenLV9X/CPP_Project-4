#pragma once
#include <string>
#include <iomanip>
#include <iostream>

class Product
{
private:
	std::string name_; // Ten san pham
	int production_year_; // Nam san xuat
	long original_price_; // Gia goc (chinh la gia nhap)

public:
	void Input();
	void Output();
	std::string GetName();
	int GetProductionYear();
	long GetOriginalPrice();
};
