#include"allheaders.h"
vector<bikes> b;
vector<cars> c;
vector<trucks> t;
class vehicles
{
private:
	string name, color;
	int stock, horsepower;
	string description;
	double price;
public:
	void set_price(double x)
	{
		price = x;
	}
	void set_color(string c) {
		color = c;
	}
	void set_name(string n) {
		name = n;
	}
	void set_stock(int s) {
		stock = s;
	}
	void set_horsepower(int h) {
		horsepower = h;
	}
	void set_description(string d) {
		description = d;
	}
	double get_price()
	{
		return price;
	}
	string get_color() {
		return color;
	}
	string get_name() {
		return name;
	}
	int get_stock() {
		return stock;
	}
	int get_horsepower() {
		return horsepower;
	}
	string get_description() {
		return description;
	}
	virtual void getdata() = 0;
};
class bikes :public vehicles
{
public:
	void getdata()
	{
		string x;
		int y;
		double z;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\t\t\tEnter the Name of Bike: ";
		getline(cin, x);
		set_name(x);
		cout << "\n\t\t\tEnter the Color of Bike: ";
		cin >> x;
		set_color(x);
		cout << "\n\t\t\tEnter the availble units: ";
		cin >> y;
		set_stock(y);
		cout << "\n\t\t\tEnter the price: ";
		cin >> z;
		set_price(z);
		cout << "\n\t\t\tEnter the horespower of the engine: ";
		cin >> y;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		set_horsepower(y);
		cout << "\n\t\t\tEnter the Bike's Description: ";
		getline(cin, x);
		set_description(x);
	}
	static void read()
	{
		bikes arr;
		fstream file;
		file.open("bikes.txt", ios::in);
		while (file >> arr)
			b.push_back(arr);
		file.close();
	}
	static void write()
	{
		fstream file;
		file.open("bikes.txt", ios::out);
		for (int i = 0; i < b.size(); ++i)
		{
			file << b[i];
		}
		file.close();
	}
	static void list()
	{
		cout << "\t\t\t\nS.No" << "\t" << "Name of Bikes" << "\t" << "Price of Bikes" << "\n\n";
		for (int i = 0; i < b.size(); i++)
		{
			cout << i + 1 << "\t" << b[i].get_name() <<"\t$"<<b[i].get_price()<< "\n";
		}
	}
};
fstream& operator<<(fstream& file, bikes& obj)
{
	file << ' ' << obj.get_name() << ';' << obj.get_color() << ' ' << obj.get_stock() << ' ' << obj.get_price() << ' ' << obj.get_horsepower() << ' ' << obj.get_description() << ';' << ' ';
	return file;
}
fstream& operator>>(fstream& file, bikes& obj)
{
	string x;
	int y;
	double z;
	file.get();
	getline(file, x, ';');
	obj.set_name(x);
	file >> x;
	obj.set_color(x);
	file.get();
	file >> y;
	obj.set_stock(y);
	file.get();
	file >> z;
	obj.set_price(z);
	file.get();
	file >> y;
	obj.set_horsepower(y);
	file.get();
	getline(file, x, ';');
	obj.set_description(x);
	file.get();
	return file;
}
class cars :public vehicles
{
	string transmission;
public:
	void getdata()
	{
		string x;
		int y;
		double z;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\t\t\tEnter the Name of Car: ";
		getline(cin, x);
		set_name(x);
		cout << "\n\t\t\tEnter the Color of Car: ";
		cin >> x;
		set_color(x);
		cout << "\n\t\t\tEnter the availble units: ";
		cin >> y;
		set_stock(y);
		cout << "\n\t\t\tEnter the price: ";
		cin >> z;
		set_price(z);
		cout << "\n\t\t\tEnter the horespower of the engine: ";
		cin >> y;
		set_horsepower(y);
		cout << "\n\t\t\tEnter the Transmission of the Car: ";
		cin >> x;
		set_transmission(x);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\t\t\tEnter the Car's Description: ";
		getline(cin, x);
		set_description(x);
	}
	void set_transmission(string& x)
	{
		transmission = x;
	}
	string get_transmission()
	{
		return transmission;
	}
	static void read()
	{
		cars arr;
		fstream file;
		file.open("cars.txt", ios::in);
		while (file >> arr)
		{
			c.push_back(arr);
		}
		file.close();
	}
	static void write()
	{
		fstream file;
		file.open("cars.txt", ios::out);
		for (int i = 0; i < c.size(); ++i)
		{
			file << c[i];
		}
		file.close();
	}
	static void list()
	{
		cout << "\t\t\t\nS.No" << "\t" << "Name of Cars" <<"\t"<<"Price of Car"<< "\n\n";
		for (int i = 0; i < c.size(); i++)
		{
			cout << i + 1 << ": " << c[i].get_name() <<"                 "<<"$"<<c[i].get_price()<< "\n";
		}
	}
};
fstream& operator<<(fstream& file, cars& obj)
{
	file << ' ' << obj.get_name() << ';' << obj.get_color() << ' ' << obj.get_stock() << ' ' << obj.get_price() << ' ' << obj.get_horsepower() << ' ' << obj.get_description() << ';' << obj.get_transmission() << ' ';
	return file;
}
fstream& operator>>(fstream& file, cars& obj)
{
	string x;
	int y;
	double z;
	file.get();
	getline(file, x, ';');
	obj.set_name(x);
	file >> x;
	obj.set_color(x);
	file.get();
	file >> y;
	obj.set_stock(y);
	file.get();
	file >> z;
	obj.set_price(z);
	file.get();
	file >> y;
	obj.set_horsepower(y);
	file.get();
	getline(file, x, ';');
	obj.set_description(x);
	file >> x;
	obj.set_transmission(x);
	file.get();
	return file;
}
class trucks : public vehicles
{
	int loading_capacity;
public:
	void getdata()
	{
		string x;
		int y;
		double z;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\t\t\tEnter the Name of Truck: ";
		getline(cin, x);
		set_name(x);
		cout << "\n\t\t\tEnter the Color of Truck: ";
		cin >> x;
		set_color(x);
		cout << "\n\t\t\tEnter the availble units: ";
		cin >> y;
		set_stock(y);
		cout << "\n\t\t\tEnter the price: ";
		cin >> z;
		set_price(z);
		cout << "\n\t\t\tEnter the Loading Capapcity of the truck: ";
		cin >> y;
		set_loading_capacity(y);
		cout << "\n\t\t\tEnter the horespower of the engine: ";
		cin >> y;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		set_horsepower(y);
		cout << "\n\t\t\tEnter the Truck's Description: ";
		getline(cin, x);
		set_description(x);
	}
	void set_loading_capacity(int& x)
	{
		loading_capacity = x;
	}
	int get_loading_capacity()
	{
		return loading_capacity;
	}
	static void write()
	{
		fstream file;
		file.open("trucks.txt", ios::out);
		for (int i = 0; i < t.size(); ++i)
		{
			file << t[i];
		}
		file.close();
	}
	static void read()
	{
		trucks arr;
		fstream file;
		file.open("trucks.txt", ios::in);
		while (file >> arr)
		{
			t.push_back(arr);
		}
		file.close();
	}
	static void list()
	{
		cout << "\t\t\t\nS.No" << "\t" << "Name of Trucks" << "\t" << "Price of Trucks" << "\n\n";
		for (int i = 0; i < t.size(); i++)
		{
			cout << i + 1 << "\t" << t[i].get_name() <<"\t$"<<t[i].get_price()<< "\n";
		}
	}
};
fstream& operator<<(fstream& file, trucks& obj)
{
	file << ' ' << obj.get_name() << ';' << obj.get_color() << ' ' << obj.get_stock() << ' ' << obj.get_price() << ' ' << obj.get_horsepower() << ' ' << obj.get_description() << ';' << obj.get_loading_capacity() << ' ';
	return file;
}
fstream& operator>>(fstream& file, trucks& obj)
{
	string x;
	int y;
	double z;
	file.get();
	getline(file, x, ';');
	obj.set_name(x);
	file >> x;
	obj.set_color(x);
	file.get();
	file >> y;
	obj.set_stock(y);
	file.get();
	file >> z;
	obj.set_price(z);
	file.get();
	file >> y;
	obj.set_horsepower(y);
	file.get();
	getline(file, x, ';');
	obj.set_description(x);
	file >> y;
	obj.set_loading_capacity(y);
	file.get();
	return file;
}
class customer {
	string name;
	long int num, CNIC, credit_card;
	bool Filer;
	int pin;
	double bill;
	vector<string> cart;
public:
	friend ostream& operator<<(ostream& dout, customer& obj);
	~customer()
	{
		bikes::write();
		cars::write();
		trucks::write();
	}
	customer()
	{
		
		b.clear();
		c.clear();
		t.clear();
		bikes::read();
		cars::read();
		trucks::read();
	}
	void write()
	{
		fstream file("customer.txt", ios::app);
		file << *this;
	}
	void menu()
	{
		system("cls");
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                       CUSTOMER PORTAL                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\tSelect the Vehicle you want to add to cart: \n\n";
		cout << "\t\t\t1. Bikes." << endl;
		cout << "\t\t\t2. Cars." << endl;
		cout << "\t\t\t3. Trucks." << endl;
		cout << "\t\t\t4.proceed to checkout" << endl;
		int s;
		cin >> s;
		switch (s)
		{
		case 1:
			bike_menu();
			break;
		case 2:
			car_menu();
			break;
		case 3:
			truck_menu();
			break;
		case 4:
			checkout();
		}

	}
	void bike_menu()
	{
		system("cls");
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                       CUSTOMER PORTAL                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		bikes::list();
		cout << "\n\t\t\tEnter the S.No of the Bike you want to add to cart: ";
		int n;
		cin >> n;
		n--;
		cart.push_back(b[n].get_name());
		bill += b[n].get_price();
		b[n].set_stock(b[n].get_stock() - 1);
		menu();
	}
	void car_menu()
	{
		system("cls");
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                       CUSTOMER PORTAL                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		cars::list();
		cout << "\n\t\t\tEnter the S.No of the Car you want to add to cart: ";
		int n;
		cin >> n;
		n--;
		cart.push_back(c[n].get_name());
		system("CLS");
		bill += c[n].get_price();
		c[n].set_stock(c[n].get_stock() - 1);
		menu();
	}
	void truck_menu()
	{
		system("cls");
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                       CUSTOMER PORTAL                                               |" << endl;
		Sleep(50);
		cout << "\t\t|                      ******************                                             |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		trucks::list();
		cout << "\n\t\t\tEnter the S.No of the Truck you want to add to cart: ";
		int n;
		cin >> n;
		n--;
		cart.push_back(t[n].get_name());
		bill += t[n].get_price();
		t[n].set_stock(t[n].get_stock() - 1);
		menu();
	}
	void set_customerNmae(string c) {
		name = c;
	}
	void set_contact(long int con) {
		num = con;
	}
	void set_CNIC(long int n) {
		CNIC = n;
	}
	void set_CREDIT_card(long int r) {
		credit_card = r;
	}
	void set_Filer(bool f) {
		Filer = f;
	}
	void set_pin(int p) {
		pin = p;
	}
	string get_customerName() {
		return name;
	}
	long int get_contact() {
		return num;
	}
	long int get_CNIC() {
		return CNIC;
	}
	long int get_CREDIT_card() {
		return credit_card;
	}
	bool get_Filer() {
		return Filer;
	}
	int get_pin() {
		return pin;
	}
	double get_bill()
	{
		return bill;
	}
	void checkout()
	{
		system("CLS");
		string a;
		cout << "\n\n\t\t\tYour Due Amount is $" << bill;
		cout << "\n\n\n\n\t\t\tPlease enter your name" << endl;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, a);
		set_customerNmae(a);
		cout << endl << "\t\t\tPlease enter your contact number" << endl;
		long int b;
		cin >> b;
		set_contact(b);
		cout << endl << "\t\t\tPlease enter your CNIC number" << endl;
		string c;
		cin.clear();
		cin.ignore();
		getline(cin, c);
	here0:
		cout << endl << "\t\t\tPlease enter your 16 digit long debit card number" << endl;
		string cnumber;
		int ch;
		while ((ch = _getch()) != '\r') {
			if (ch == '\b') {
				if (cnumber.size() > 0) {
					cnumber.erase(cnumber.size() - 1, 1);
					cout << "\b \b";
				}
			}
			else {
				cnumber.push_back(ch);
				cout.put('*');
			}
		}
		auto z = cnumber.length();
		try
		{
			if (z != 16)
				throw 1;
		}
		catch (int)
		{
			cout << endl <<  "\t\t\tCARD NUMBER MUST BE 16 DIGITS LONG! " << endl;
			goto here0;
		}
		std::cout.put('\n');
		cout << endl << "\t\t\tAre you filer?" << endl;
		cout << endl << "\t\t\t1.Yes" << endl;
		cout << endl << "\t\t\t2.No" << endl;
		string e;
		cin >> e;
		here1:
		cout << endl << "\t\t\tPlease enter your CVV code " << endl;
		string code;
		int ch1;
		while ((ch1 = _getch()) != '\r') {
			if (ch1 == '\b') {
				if (code.size() > 0) {
					code.erase(code.size() - 1, 1);
					cout << "\b \b";
				}
			}
			else {
				code.push_back(ch);
				cout.put('*');
			}
		}
		auto we = code.length();
		try
		{
			if (we != 3)
				throw 1;
		}
		catch (int)
		{
			cout << endl <<  "\t\t\tCARD PIN MUST BE 3 DIGITS LONG! " << endl;
			goto here1;
		}

		std::cout.put('\n');

		this->write();
		delete this;

		system("cls");
		cout << "\n\n\n\t\t\tThank You for Using Our Software.\n\nPress Any key to exit.";
		cin.ignore();
		cin.get();
		exit(0);
	}
	friend fstream& operator<<(fstream& file, customer& obj);
	friend fstream& operator>>(fstream& file, customer& obj);
};
ostream& operator<<(ostream& dout, customer& obj)
{
	int static i = 1;
	cout << "\n" << i << ")" << "\t" << obj.name << "\t$" << obj.bill << "\n";
	for (int f = 0; f < obj.cart.size(); f++)
	{
		cout << "\t\t\t\t\t" << obj.cart[f] << "\n";
	}
	i++;
	return dout;
}
fstream& operator<<(fstream& file, customer& obj)
{
	file << obj.get_customerName() << ';' << obj.get_CNIC() << ' ' << obj.get_contact() << ' ' << obj.get_bill() << ' ';
	for (int i = 0; i < obj.cart.size(); i++)
	{
		if (i == (obj.cart.size() - 1))
		{
			file << obj.cart[i] << ';' << '*';
		}
		else
			file << obj.cart[i] << ';' << ' ';
	}
	return file;
}
fstream& operator>>(fstream& file, customer& obj)
{
	string x;
	getline(file, obj.name, ';');
	file >> obj.CNIC;
	file.get();
	file >> obj.num;
	file.get();
	file >> obj.bill;
	file.get();
	obj.cart.clear();
	do
	{
		getline(file, x, ';');
		obj.cart.push_back(x);
	} while (file.get() == ' ');
	
	return file;
}
class admin
{
public:
	void car();
	void truck();
	void bike();
	admin()
	{
		trucks::read();
		cars::read();
		bikes::read();
	}
	void password()
	{
		system("CLS");
		cout << "\t\t\tPlease Enter the password." << endl;
		string password;
		int ch;

		while ((ch = _getch()) != '\r') 
		{
			if (ch == '\b') {
				if (password.size() > 0) {
					password.erase(password.size() - 1, 1);
					std::cout << "\b \b";
				}
			}
			else {
				password.push_back(ch);
				std::cout.put('*');
			}
			}
		if (password == "tryhard")
		{
			menu();

		}
		else
		{
			cout << "\n\t\tWrong password.\n";
			cout << "\n\t\t1: Retry\n\t\t2: Exit";
			int x;
			cin >> x;
			switch (x)
			{
			case 1:
				this->password();
			case 2:
				delete this;
				exit(0);
			}
		}
std::cout.put('\n');
		
		}
	void menu()
	{

		{
			system("CLS");
			cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
			Sleep(50);
			cout << "\t\t|                       WELCOME BACK ADMIN                                            |" << endl;
			Sleep(50);
			cout << "\t\t|                      ********************                                           |" << endl;
			Sleep(50);
			cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
			Sleep(50);
			cout << "\t\t\t1. Modification in Vehicles." << endl;
			cout << "\t\t\t2. Add a vehicles." << endl;
			cout << "\t\t\t3. View All Vehicles.\n";
			cout << "\t\t\t4. Delete a Vehicle.\n";
			cout << "\t\t\t5. View purchase history" << endl;
			cout << "\t\t\t6. Return to main menu." << endl;
			cout << "\t\t\t7. Exit.\n";
			int a;
			cin >> a;
			system("CLS");
			switch (a)
			{
			case 1:
			{
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t|                       MODIFICATION IN VEHICLE                                       |" << endl;
				Sleep(50);
				cout << "\t\t|                      *************************                                      |" << endl;
				Sleep(50);
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t\t1. Modification in cars inventory." << endl;
				cout << "\t\t\t2. Modification in trucks inventory." << endl;
				cout << "\t\t\t3. Modification in Bikes inventory." << endl;
				int a;
				cin >> a;
				system("CLS");
				switch (a)
				{
				case 1:
				{
					car();
				}
				case 2:
				{
					truck();
				}
				case 3:
				{
					bike();
				}
				}

			}
			case 2:
			{
				{
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                       CHANGE IN VEHICLE                                            |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t\t1. Addition in cars inventory." << endl;
					cout << "\t\t\t2. Addition in trucks inventory." << endl;
					cout << "\t\t\t3. Addition in Bikes inventory." << endl;
					int s;
					cin >> s;
					system("CLS");
					switch (s)
					{
					case 1:
					{
						cars obj1;
						obj1.getdata();
						c.push_back(obj1);
						break;
					}
					case 2:
					{
						trucks obj2;
						obj2.getdata();
						t.push_back(obj2);
						break;
					}
					case 3:
					{
						bikes obj3;
						obj3.getdata();
						b.push_back(obj3);
						break;
					}
					case 4:
						menu();

					}

				}
				cout << "\n\t\tPress Any key to return to the main menu.";
				cin.ignore();
				cin.get();
				menu();
				break;
			}
			case 3:
			{
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t|                       WELCOME BACK ADMIN                                            |" << endl;
				Sleep(50);
				cout << "\t\t|                      ********************                                           |" << endl;
				Sleep(50);
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t\t1. View All Bikes" << endl;
				cout << "\t\t\t2. View All Cars" << endl;
				cout << "\t\t\t3. View All Trucks\n";
				cout << "\t\t\t4. Exit" << endl;
				int a;
				cin >> a;
				switch (a)
				{
				case 1:
					system("cls");
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                       WELCOME BACK ADMIN                                            |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\nS.No\tName\t\t\tStock\n\n";
					for (int i = 0; i < b.size(); i++)
					{
						cout << i + 1 << b[i];
					}
					break;
				case 2:
					system("cls");
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                       WELCOME BACK ADMIN                                            |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\nS.No\tName\t\t\tStock\n\n";
					for (int i = 0; i < c.size(); i++)
					{
						cout << i + 1 << c[i];
					}
					break;
				case 3:
					system("cls");
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                       WELCOME BACK ADMIN                                            |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\nS.No\tName\t\t\tStock\n\n";
					for (int i = 0; i < t.size(); i++)
					{
						cout << i + 1 << t[i];
					}
					break;
				default:
					cout << "\n\t\tYou Entered and Invalid choice\n\nPress any key to Exit.";
					cin.ignore();
					cin.get();
					delete this;
					exit(0);
					break;
				}
				cout << "\n\n\t\tPress any key to return to main menu.";
				cin.ignore();
				cin.get();
				menu();
			}
			case 4:
				
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t|                       WELCOME BACK ADMIN                                            |" << endl;
				Sleep(50);
				cout << "\t\t|                      ********************                                           |" << endl;
				Sleep(50);
				cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
				Sleep(50);
				cout << "\t\t\t1. Delete a Bike" << endl;
				cout << "\t\t\t2. Delete a Car" << endl;
				cout << "\t\t\t3. Delete a Truck\n";
				cout << "\t\t\t4. Exit" << endl;
				int a;
				cin >> a;
				switch (a)
				{
				case 1:
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                       WELCOME BACK ADMIN                                            |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					bikes::list();
					c3:
					cout << "\n\n\t\tEnter the S.No of the bike you want to delete: ";
					cin >> a;
					try
					{
						if (a > b.size())
						{
							throw 1;
						}
					}
					catch (int)
					{
						cout << "\n\n\t\t\tYou entred wrong option.Press any key to rety.";
						cin.ignore();
						cin.get();
						goto c3;
					}
					a--;
					b.erase(b.begin() + a);
					break;
				case 2:
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                       WELCOME BACK ADMIN                                            |" << endl;
					Sleep(50);
					cout << "\t\t|                      ********************                                           |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cars::list();
					c1:
					cout << "\n\n\t\tEnter the S.No of the Car you want to delete: ";
					cin >> a;
					try
					{
						if (a > c.size())
						{
							throw 1;
						}
					}
					catch (int)
					{
						cout << "\n\n\t\t\tYou entred wrong option.Press any key to rety.";
						cin.ignore();
						cin.get();
						goto c1;
					}
					a--;
					c.erase(c.begin() + a);
					break;
				case 3:
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					cout << "\t\t|                       WELCOME BACK ADMIN                                              |" << endl;
					Sleep(50);
					cout << "\t\t|                      ******************                                             |" << endl;
					Sleep(50);
					cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
					Sleep(50);
					trucks::list();
					c2:
					cout << "\n\n\t\t\tEnter the S.No of the Truck you want to delete: ";
					cin >> a;
					a--;
					try
					{
						if (a > t.size())
						{
							throw 1;
						}
					}
					catch (int)
					{
						cout << "\n\n\t\t\tYou entred wrong option.Press any key to rety.";
						cin.ignore();
						cin.get();
						goto c2;
					}
					t.erase(t.begin() + a);
					break;
				}
				cout << "\n\n\t\t\tPress Any key to return to main menu.\n";
				cin.ignore();
				cin.get();
				menu();
				break;
			case 6:
			{
				main();
			}
			case 5:
			{
				fstream file("customer.txt", ios::in);
				customer obj;
				cout << "\nS.No\tCustomer Name\tBill Amount\tVehicle's bought";
				cout << "\n===\t=============\t==========\t=================\n\n";
				while (file >> obj)
				{
					cout << obj;
				}
				cout << "\n\n\n\t\t\tPress Any key to return to main menu.";
				cin.ignore();
				cin.get();
				menu();
				break;
			}

			case 7:
				delete this;
				exit(0);
			}

		}

	}
	~admin()
	{
		trucks::write();
		cars::write();
		bikes::write();
	}
};

void admin::car()
{
	cars::list();
	cout << endl;
	int a;
	cout << "\t\t\tEnter the serial number of car you want to modify?" << endl;
	cin >> a;
	system("CLS");
	while (a)
	{
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                       MODIFICATION IN CARS                                          |" << endl;
		Sleep(50);
		cout << "\t\t|                      ***********************                                        |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t\t1. Modify price" << endl;
		cout << "\t\t\t2. Modify color" << endl;
		cout << "\t\t\t3. Modify stock" << endl;
		cout << "\t\t\t4. Modify horsepower" << endl;
		cout << "\t\t\t5. Modify description" << endl;
		cout << "\t\t\t6. Modify name" << endl;
		int d;
		cin >> d;
		system("CLS");
		switch (d)
		{
		case 1:
		{
			cout << "\t\t\tPlease Enter new price?";
			float b;
			cin >> b;
			system("CLS");
			try
			{
				if (b < 0)
					throw 1;
			}
			catch (int)
			{
				cout << "\t\t\tYou entered wrong price" << endl;
				cout << "\t\t\treturn to main menu?" << endl;
				cout << "\t\t\t1.Yes" << endl;
				cout << "\t\t\t2.No" << endl;
				int k;
				cin >> k;
				if (k == 1)
				{
					system("CLS");
					menu();
				}
				else
				{
					delete this;
					exit(0);
				}
			}

			for (int i = a - 1; i < a; i++)
			{
				c[i].set_price(b);
			}
			system("CLS");
			menu();
		}
		case 2:
		{
			cout << "\t\t\tPlease Enter new color?";
			string b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_color(b);
			}
			system("CLS");
			menu();
		}
		case 3:
		{
			cout << "\t\t\tPlease Enter new stock?";
			int b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_stock(b);
			}
			system("CLS");
			menu();
		}
		case 4:
		{
			cout << "\t\t\tPlease Enter new horse power?";
			int b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_horsepower(b);
			}
			system("CLS");
			menu();
		}
		case 5:
		{
			cout << "\t\t\tPlease Enter new description?";
			string b;
			cin.ignore();
			getline(cin, b);
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_description(b);
			}
			system("CLS");
			menu();
		}
		case 6:
		{
			cout << "\t\t\tPlease Enter new name?";
			string b;
			cin.ignore();
			getline(cin, b);
			for (int i = a - 1; i < a; i++)
			{
				c[i].set_name(b);
			}
			system("CLS");
			menu();
		}
		case 7:
		{
			menu();
		}
		}
	}
}
void admin::truck()
{
	trucks::list();
	cout << endl;
	int a;
	cout << "\t\t\tEnter the serial number of car you want to modify?" << endl;
	cin >> a;
	system("CLS");
	while (a)
	{
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                       MODIFICATION IN TRUCK                                         |" << endl;
		Sleep(50);
		cout << "\t\t|                      ************************                                        |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t\t1. Modify price" << endl;
		cout << "\t\t\t2. Modify color" << endl;
		cout << "\t\t\t3. Modify stock" << endl;
		cout << "\t\t\t4. Modify horsepower" << endl;
		cout << "\t\t\t5. Modify description" << endl;
		cout << "\t\t\t6. Modify name" << endl;
		int d;
		cin >> d;
		system("CLS");
		switch (d)
		{
		case 1:
		{
			cout << "\t\t\tPlease Enter new price?";
			float b;
			cin >> b;
			system("CLS");
			try
			{
				if (b < 0)
					throw 1;
			}
			catch (int)
			{
				cout << "\t\t\tYou entered wrong price" << endl;
				cout << "\t\t\treturn to main menu?" << endl;
				cout << "\t\t\t1.Yes" << endl;
				cout << "\t\t\t2.No" << endl;
				int k;
				cin >> k;
				if (k == 1)
				{
					system("CLS");
					menu();

				}
				else
				{
					delete this;
					exit(0);
				}

			}
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_price(b);
			}
			system("CLS");
			menu();
		}
		case 2:
		{
			cout << "\t\t\tPlease Enter new color?";
			string b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_color(b);
			}
			system("CLS");
			menu();
		}
		case 3:
		{
			cout << "\t\t\tPlease Enter new stock?";
			int b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_stock(b);
			}
			system("CLS");
			menu();
		}
		case 4:
		{
			cout << "\t\t\tPlease Enter new horse power?";
			int b;
			cin >> b;
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_horsepower(b);
			}
			system("CLS");
			menu();
		}
		case 5:
		{
			cout << "\t\t\tPlease Enter new description?";
			string b;
			cin.ignore();
			getline(cin, b);
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_description(b);
			}
			system("CLS");
			menu();
		}
		case 6:
		{
			cout << "\t\t\tPlease Enter new name?";
			string b;
			cin.ignore();
			getline(cin, b);
			for (int i = a - 1; i < a; i++)
			{
				t[i].set_name(b);
			}
			system("CLS");
			menu();
		}
		case 7:
		{
			menu();
		}
		}
	}
}
void admin::bike()
{
	bikes::list();
	cout << endl;
	int a;
	cout << "\t\t\tEnter the serial number of car you want to modify?" << endl;
	cin >> a;
	system("CLS");
	while (a)
	{
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t|                       MODIFICATION IN BIKES                                         |" << endl;
		Sleep(50);
		cout << "\t\t|                      ***********************                                        |" << endl;
		Sleep(50);
		cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
		Sleep(50);
		cout << "\t\t\t1. Modify price" << endl;
		cout << "\t\t\t 2. Modify color" << endl;
		cout << "\t\t\t 3. Modify stock" << endl;
		cout << "\t\t\t 4. Modify horsepower" << endl;
		cout << "\t\t\t 5. Modify description" << endl;
		cout << "\t\t\t 6. Modify name" << endl;
		int d;
		cin >> d;
		system("CLS");
		switch (d)
		{
		case 1:
		{
			cout << "\t\t\tPlease Enter new price?";
			float x;
			cin >> x;
			system("CLS");
			try
			{
				if (x < 0)
					throw 1;
			}
			catch (int)
			{
				cout << "\t\t\tYou entered wrong price" << endl;
				cout << "\t\t\treturn to main menu?" << endl;
				cout << "\t\t\t1.Yes" << endl;
				cout << "\t\t\t2.No" << endl;
				int k;
				cin >> k;
				if (k == 1)
				{
					system("CLS");
					menu();
				}
				else
				{
					delete this;
					exit(0);
				}

			}
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_price(x);
			}
			system("CLS");
			menu();
		}
		case 2:
		{
			cout << "\t\t\t\n\nPlease Enter new color?";
			string x;
			cin >> x;
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_color(x);
			}
			system("CLS");
			menu();
		}
		case 3:
		{
			cout << "\t\t\t\n\nPlease Enter new stock?";
			int x;
			cin >> x;
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_stock(x);
			}
			system("CLS");
			menu();
		}
		case 4:
		{
			cout << "\t\t\t\n\nPlease Enter new horse power?";
			int x;
			cin >> x;
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_horsepower(x);
			}
			system("CLS");
			menu();
		}
		case 5:
		{
			cout << "\t\t\t\n\nPlease Enter new description?";
			string x;
			cin.ignore();
			getline(cin, x);
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_description(x);
			}
			system("CLS");
			menu();
		}
		case 6:
		{
			cout << "\t\t\t\n\nPlease Enter new name?";
			string x;
			cin.ignore();
			getline(cin, x);
			for (int i = a - 1; i < a; i++)
			{
				b[i].set_name(x);
			}
			system("CLS");
			menu();
		}
		case 7:
		{
			menu();
		}
		}
	}
}
ostream& operator<<(ostream& dout, vehicles& obj)
{
	cout << "\t" << obj.get_name() << "\t\t\t" << obj.get_stock() << "\n";
	return dout;
}
int main()
{
	
	system("color 0A");
	menu_screen();
}
void menu_screen() {
	admin* obj = new admin();
	Sleep(50);
	cout << "\n\n\n\n";
	Sleep(50);
	cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
	Sleep(50);
	cout << "\t\t|                       CAR DEALERSHIP MANAGEMENT SYSTEM                              |" << endl;
	Sleep(50);
	cout << "\t\t|                       *********************************                             |" << endl;
	Sleep(50);
	cout << "\t\t|                               SASUKE GARAGE                                         |" << endl;
	Sleep(50);
	cout << "\t\t|                             ****************                                        |" << endl;
	Sleep(50);
	cout << "\t\t|                                                                                     |" << endl;
	Sleep(50);
	cout << "\t\t|-------------------------------------------------------------------------------------|" << endl;
	Sleep(50);
	cout << "\n\n\n\n";
	cout << "\t\t\tPlease Choose any one:" << endl;
	cout << "\t\t\t1.Customer." << endl;
	cout << "\t\t\t2.Admin." << endl;
	cout << "\t\t\t3.Exit." << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 1:
	{
		customer* obj1 = new customer();
		obj1->menu();
		break;
	}
	case 2:
	{
		obj->password();
		break;
	}
	case 3:
	{
		delete obj;
		exit(0);
	}
	}
}