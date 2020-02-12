#include "order.h"
#include "product.h"

using namespace std;

void Order::Input() {
	Product::Input();
	 
	cout << "So luong:";
	cin >> quantity_;
	cout << "Gia ban:";
	cin >> sell_price_;
}

// In ra thong tin hoa don tren 1 dong theo dinh dang sau
// Do rong 25 ky tu cho ten san pham, can le phai
// Do rong 15 ky tu cho gia nhap, can le phai
// Do rong 10 ky tu so luong san pham, can le phai
// Do rong 15 ky tu cho gia ban, can le phai
// Do rong 15 ky tu cho tong tien hoa don, can le phai
// Do rong 10 ky tu thue VAT, can le phai
// Do rong 15 ky tu cho loi nhuan thu duoc tu hoa don, can le phai
void Order::Output() {
	cout << setw(25) << GetName() << setw(15) << GetOriginalPrice();
	 
	cout << setw(10) << quantity_ << setw(15) << sell_price_ << setw(15) << GetSubTotal() << setw(10) << GetVAT() << setw(15) << GetProfit() <<endl;
}

// Tra ve tong tien trong hoa don hien tai
// Tong tien = so luong san pham * gia ban 1 san pham
long Order::GetSubTotal() {
	 
	return quantity_*sell_price_;
}

// Tra ve thue VAT cho hoa don hien tai
// Thue VAT = (tong tien trong hoa don hien tai)/10, lam tron ve so nguyen
long Order::GetVAT() {
	 
	return GetSubTotal() / 10;
}

// Tra ve loi nhuan (tien lai) tu hoa don hien tai
// Loi nhuan cho 1 san pham la hieu cua gia ban va gia nhap
long Order::GetProfit() {
	 
	return GetSubTotal() - quantity_ * GetOriginalPrice();
}

// Nhap vao n hoa don, luu trong mang orders
void Order::GenerateOrders(Order orders[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin hoa don: " << i + 1 << endl;
		 
		orders[i].Input();

	}
}

// In ra thong tin tat ca cac hoa don trong mang dau vao - orders
void Order::PrintOrders(Order orders[], int n) {
	cout << endl;
	cout << setw(5) << "STT" << setw(25) << "Ten San Pham" << setw(15) << "Gia nhap";
	cout << setw(10) << "So Luong" << setw(15) << "Gia Ban" << setw(15) << "Thanh Tien";
	cout << setw(10) << "VAT" << setw(15) << "Tien Lai" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << i + 1;
		 
		orders[i].Output();
	}
}

// Tra ve gia tri VAT lon nhat cua hoa don trong mang orders cac hoa don dau vao
long GetMaxVAT(Order orders[], int n)
{
	long max = orders[0].GetVAT();
	for (int i = 1; i < n; i++)
	{
		 
		if (orders[i].GetVAT() > max)
			max = orders[i].GetVAT();
	}
	return max;
}

// Sap xep mang hoa don orders theo loi nhuan (tien lai) giam dan
void SortOrderByProfit(Order orders[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (orders[j].GetVAT() > orders[j - 1].GetVAT())
			{
				 
				Order orTemp = orders[j];
				orders[j] = orders[j - 1];
				orders[j - 1] = orTemp;	
			}
		}
	}
}

// In ra cac hoa don co thue VAT lon nhat trong mang orders cac hoa don dau vao
void PrintOrdersWithMaxTAX(Order orders[], int n)
{
	cout << endl;
	cout << setw(5) << "STT" << setw(25) << "Ten San Pham" << setw(15) << "Gia nhap";
	cout << setw(10) << "So Luong" << setw(15) << "Gia Ban" << setw(15) << "Thanh Tien";
	cout << setw(10) << "Thue" << setw(15) << "Tien Lai" << endl;
	for (int i = 0; i < n; i++)
	{
		if (orders[i].GetVAT() == GetMaxVAT(orders, n))
		{
			 
			cout << setw(5) << i + 1;
			orders[i].Output();
		}
	}
}

// Tra ve tong tien tat ca cac hoa don trong mang orders
long GetSumSubTotal(Order orders[], int n)
{
	long sum = 0;
	for (int i = 0; i < n; i++)
	{
		 
		sum += orders[i].GetSubTotal();
	}
	return sum;
}

//Phan Nang Cao
//Xuat ra cac san pham co so luong ban nhieu nhat
void PrintOrdersQuantityMax(Order orders[], int n)
{
	int inTemp = 1;
	cout << endl;
	cout << setw(5) << "STT" << setw(25) << "Ten San Pham" << setw(10) << "Nam SX" << setw(20) << "Gia nhap" << endl;;
	for (int i = 0; i < n; i++)
	{
		if (orders[i].quantity_ == GetMaxQuantity(orders, n))
		{
			cout << setw(5) << inTemp;
			Product prdTemp = orders[i];
			prdTemp.Output();
			inTemp++;
		}
	}
}

//Phan Nang Cao
// Tra ve so luong lon nhat cua hoa don trong mang orders cac hoa don dau vao
long GetMaxQuantity(Order orders[], int n)
{
	long max = orders[0].quantity_;
	for (int i = 1; i < n; i++)
	{
		if (orders[i].quantity_ > max)
			max = orders[i].quantity_;
	}
	return max;
}