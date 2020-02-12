// sale_management.cpp : Defines the entry point for the console application.
//

#include "order.h"

using namespace std;

int main()
{
	Order orders[10];
	int n;
	do
	{
		 
		cout << "So hoa don: ";
		cin >> n;

	} while (n < 1 || n > 10);

	cout << "\nNhap thong tin cac hoa don:" << endl;
	 
	Order::GenerateOrders(orders, n);

	cout << "\nDanh sach hoa don sau khi sap xep tien lai giam dan" << endl;
	 
	SortOrderByProfit(orders, n);
	Order::PrintOrders(orders, n);

	cout << "\nTong tien cac hoa don: " << setw(47) << "" << setw(15) << GetSumSubTotal(orders, n) << endl;
	cout << "\nCac hoa don co tien thue cao nhat " << endl;
	 
	PrintOrdersWithMaxTAX(orders, n);

	cout << "\nCac san pham co so luong ban nhieu nhat " << endl;
	PrintOrdersQuantityMax(orders, n);
	system("pause");
	return 0;
}

