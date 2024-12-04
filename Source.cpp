#include <iostream>
#include <Windows.h>
#define ����� return 0;
#include<string>
#include<iomanip>

//���
const int userCount = 2;
bool isadmin = false;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passArr = new std::string[userCount]{ "admin", "user" };


//�����
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

void Start();
bool password();
bool IsNumber(std::string string);
void CreateStaticStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
int Getid();
void RefillProduct();
void RemoveProduct();
void ChangePrice();
void ChangeStorage();
void Getline(std::string& stringName);

void AddNewProduct();
void EditProduct();
void DeleteProduct();

void ChangeEmployee();
void AddNewEmployee();
void EditEmployee();
void DeleteEmployee();



//���� ������� ������
template<typename Arr>
void FillStorege(Arr staticArr[], Arr dynamicArr[], int staticSize);



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Start();
	delete[]loginArr;
	delete[]passArr;
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;

	�����;
}

void Start()
{
	std::cout << "\t\tPoint\n\n";


	if (password() == true)
	{
		if (isadmin == true)
		{
			std::string choose;
			while (true)
			{
				std::cout << "1 - ������������ ������� �����\n2 - ������� �����\n����: ";
				Getline(choose);
				if (choose == "1")
				{
					CreateStaticStorage();
					break;
				}
				else if (choose == "2")
				{
					//������������ �����
					break;
				}
				else
				{
					std::cout << "\n\n������ �����\n\n";
				}
			}
			//�������� ���������� ����
			ShowAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShowUserMenu();

		}
	}
	else
	{
		std::cerr << "LoginErr\n";
	}
}

bool password()
{
	std::string login, parol;

	while (true)
	{
		std::cout << "������� �����: ";
		std::getline(std::cin, login, '\n');

		std::cout << "������� ������: ";
		std::getline(std::cin, parol, '\n');

		if (login == loginArr[0] && parol == passArr[0])
		{
			std::cout << "����������� ������������: " << loginArr[0] << "\n\n";
			isadmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[i] && parol == passArr[i])
			{
				std::cout << "����������� ������������: " << loginArr[i] << "\n\n";
				isadmin = true;
				return true;
			}
		}
	}

	system("cls");
	std::cout << "�������� ����� ��� ������.\n\n";
}

bool IsNumber(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
	}
	return true;
}

void CreateStaticStorage()
{
	const int tempSize = 10;
	int tempid[tempSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string tempName[tempSize]
	{
		"Nike Air force 1",
		"Dunk sb",
		"Nike Air Jordan 1",
		"Nike Air Jordan 3",
		"Nike Air Jordan 4",
		"Nike Air Jordan 5",
		"Asics Gel",
		"Adidas campus",
		"Nike Air Max 97",
		"Nike Air Max 90"
	};
	int tempCount[tempSize]{ 10,8,30,2,23,7,4,15,13,8 };
	double tempPrice[tempSize]{ 10000.0, 13000.0, 15000.0, 14000.0, 20000.0, 25000.0, 8000.0, 9000.0, 19000.0, 11000.0 };
	FillStorege(tempid, idArr, tempSize);
	FillStorege(tempName, nameArr, tempSize);
	FillStorege(tempCount, countArr, tempSize);
	FillStorege(tempPrice, priceArr, tempSize);
}

template<typename Arr>
void FillStorege(Arr staticArr[], Arr dynamicArr[], int staticSize)
{
	for (int i = 0; i < staticSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������ �������\n";
		std::cout << "2 - �������� �����\n";
		std::cout << "3 - ��������� �����\n";
		std::cout << "4 - ������� �� ������\n";
		std::cout << "5 - �������� ����\n";
		std::cout << "6 - ��������� ������\n";
		std::cout << "7 - ��������� �����������\n";
		std::cout << "8 - ����� � �������\n";
		std::cout << "0 - ������� �����\n\n";
		std::cout << "����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillProduct();
		}
		else if (choose == "4")
		{
			RemoveProduct();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������\n";
			Sleep(100);
		}
	}
}

void ShowUserMenu()
{
	std::string choose;

	while (true)
	{
		system("cls");
		std::cout << "1 - ������ �������\n";
		std::cout << "2 - �������� �����\n";
		std::cout << "3 - ��������� �����\n";
		std::cout << "4 - ������� �� ������\n";
		std::cout << "5 - ����� � �������\n";
		std::cout << "0 - ������� �����\n\n";
		std::cout << "����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillProduct();
		}
		else if (choose == "4")
		{
			RemoveProduct();
		}
		else if (choose == "5")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������\n";
			Sleep(100);
		}
	}
}

void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID\t" << "��������\t\t\t" << "���-��\t" << "����\n";

		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		}
		system("pause");
	}
	else if (mode == 1)//����� ��� ����
	{
		std::cout << "ID\t" << "��������\t\t\t" << "���-��\n";

		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 2)//����� ��� ���-�� 
	{
		std::cout << "ID\t" << "��������\t\t\t" << "����\n";

		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << priceArr[i] << "\n";
		}
	}
	else if (mode == 3)//����� ��������
	{
		std::cout << "ID\t" << "��������\n";

		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\n";
		}
	}
	else
	{
		std::cerr << "\nMenuModeError\n";
	}
}

int Getid()
{
	std::string stringID;
	int result{};
	while (true)
	{
		std::cout << "������� ID ������: ";
		Getline(stringID);
		if (IsNumber(stringID))
		{
			result = std::stoi(stringID);
			if (result > 0 && result <= size)
			{
				return result;
			}
			else
			{
				std::cout << "\n������������ ID\n";
			}
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void RefillProduct()
{
	std::string choose, chooseCount;
	int id = 0, count;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n������: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = Getid();
			while (true)
			{
				std::cout << "������� ���-�� ������ ��� ����������: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count >= 0 && count <= 1000)
					{
						countArr[id - 1] += count;
						std::cout << "\n\n����� ������� ��������\n\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void RemoveProduct()
{
	std::string choose, chooseCount;
	int id = 0, count;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n������: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = Getid();
			while (true)
			{
				std::cout << "������� ���-�� ������ ��� ��������: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count >= 0 && count <= countArr[id - 1])
					{
						countArr[id - 1] -= count;
						std::cout << "\n\n����� ������� ��������\n\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}

}

void ChangePrice()
{
	std::string choose, choosePrice;
	int id = 0;
	double price{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n������: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(2);
			id = Getid();
			while (true)
			{
				std::cout << "������� ����� ����: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price >= 0 && price <= 1000000.0)
					{
						priceArr[id - 1] = price;
						std::cout << "\n\n����� ������� ��������\n\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}

}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ���������� ������ ������\n2 - �������������� ���������\n3 - �������� ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewProduct();
		}
		else if (choose == "2")
		{
			EditProduct();
		}
		else if (choose == "3")
		{
			DeleteProduct();
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void Getline(std::string& stringName)
{
	std::getline(std::cin, stringName, '\n');
}

void AddNewProduct()
{
	std::string choose, nameStr, priceStr, countStr;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);

		if (choose == "1")
		{
			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]nameArr;
			delete[]countArr;
			delete[]priceArr;

			size++;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempId[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			while (true)
			{
				std::cout << "������� �������� ������ ������:";
				Getline(nameStr);
				if (nameStr.size() <= 60 && nameStr.size() > 1)
				{
					nameArr[size - 1] = nameStr;
					break;
				}
				std::cout << "\n������ �����. �� 2 �� 60 ��������\n";
			}

			while (true)
			{
				std::cout << "������� ���-�� ������ ������:";
				Getline(countStr);
				if (IsNumber(countStr))
				{
					if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000)
					{
						countArr[size - 1] = std::stoi(countStr);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}

			while (true)
			{
				std::cout << "������� ���� ������ ������:";
				Getline(priceStr);
				if (IsNumber(priceStr))
				{
					if (std::stod(priceStr) >= 0 && std::stod(priceStr) <= 1000000.0)
					{
						priceArr[size - 1] = std::stod(priceStr);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}

			idArr[size - 1] = size;

			std::cout << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1]
				<< "\t" << countArr[size - 1] << "\t" << priceArr[size - 1] << "\n\n";
			std::cout << "����� ����� ������� ��������\n";

			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;

			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void EditProduct()
{
	std::string choose, newName;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(3);
			id = Getid();
			while (true)
			{
				std::cout << "������� ����� �������� ������";
				Getline(newName);
				if (newName.size() <= 60 && newName.size() > 1)
				{
					nameArr[id - 1] = newName;
					break;
				}
				std::cout << "\n������ �����. �� 2 �� 60 ��������\n";
			}
			std::cout << "�������� ��������\n";
			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}

void DeleteProduct()
{
	std::string choose;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);

		if (choose == "1")
		{
			ShowStorage(3);
			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]nameArr;
			delete[]countArr;
			delete[]priceArr;

			size--;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			id = Getid();

			for (int i = 0, j = 0; i < size, j < size + 1; i++, j++)
			{
				if (j == id - 1)
				{
					j++;
					idArr[i] = tempId[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}
				else
				{
					idArr[i] = tempId[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}

			}
			std::cout << "����� ������� ������\n";

			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;

			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}

void ChangeEmployee()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ���������� ������ ����������\n2 - �������������� ������, ������\n3 - �������� ����������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewEmployee();
		}
		else if (choose == "2")
		{
			EditEmployee();
		}
		else if (choose == "3")
		{
			DeleteEmployee();
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}

void AddNewEmployee()
{
	std::string choose, newLogin, newPass;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);

		if (choose == "1")
		{
			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];


			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passArr[i];
			}

			delete[]tempPass;
			delete[]tempLogin;


			userCount++;

			loginArr = new std::string[userCount];
			passArr = new std::string[userCount];

			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passArr[i];
			}

			while (true)
			{
				std::cout << "������� �������� ������ ������:";
				Getline(nameStr);
				if (nameStr.size() <= 60 && nameStr.size() > 1)
				{
					nameArr[size - 1] = nameStr;
					break;
				}
				std::cout << "\n������ �����. �� 2 �� 60 ��������\n";
			}

			while (true)
			{
				std::cout << "������� ���-�� ������ ������:";
				Getline(countStr);
				if (IsNumber(countStr))
				{
					if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000)
					{
						countArr[size - 1] = std::stoi(countStr);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}

			while (true)
			{
				std::cout << "������� ���� ������ ������:";
				Getline(priceStr);
				if (IsNumber(priceStr))
				{
					if (std::stod(priceStr) >= 0 && std::stod(priceStr) <= 1000000.0)
					{
						priceArr[size - 1] = std::stod(priceStr);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}

			idArr[size - 1] = size;

			std::cout << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1]
				<< "\t" << countArr[size - 1] << "\t" << priceArr[size - 1] << "\n\n";
			std::cout << "����� ����� ������� ��������\n";

			delete[]tempPass;
			delete[]tempLogin;

			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void EditProduct()
{
	std::string choose, newName;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(3);
			id = Getid();
			while (true)
			{
				std::cout << "������� ����� �������� ������";
				Getline(newName);
				if (newName.size() <= 60 && newName.size() > 1)
				{
					nameArr[id - 1] = newName;
					break;
				}
				std::cout << "\n������ �����. �� 2 �� 60 ��������\n";
			}
			std::cout << "�������� ��������\n";
			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}

void DeleteProduct()
{
	std::string choose;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);

		if (choose == "1")
		{
			ShowStorage(3);
			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]nameArr;
			delete[]countArr;
			delete[]priceArr;

			size--;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			id = Getid();

			for (int i = 0, j = 0; i < size, j < size + 1; i++, j++)
			{
				if (j == id - 1)
				{
					j++;
					idArr[i] = tempId[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}
				else
				{
					idArr[i] = tempId[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}

			}
			std::cout << "����� ������� ������\n";

			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;

			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}

void EditEmployee()
{
}

void DeleteEmployee()
{
}
