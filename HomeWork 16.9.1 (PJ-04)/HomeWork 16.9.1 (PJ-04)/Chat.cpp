#include "Chat.h"

std::string Chat::get_name_for_id(const long long id)
{
	if (id == 0) return ""; //NO NAME

	for (auto& element : _boxUsers)
	{
		if (element.get_idUser() == id)
		{
			return element.get_name();
		}
	}
	return ""; //NO NAME
}
const long long Chat::get_id_for_name(const std::string name)
{
	if (name == "0") return 0; //NO NAME

	for (auto& element : _boxUsers)
	{
		if (element.get_name() == name)
		{
			return element.get_idUser();
		}
	}
	return 0; //NO NAME
}
const std::string Chat::enter_login()
{
	std::cout << "����������, ������� ����� ��� �����������: ";
	std::string buferLogin;
	std::cin.ignore();
	getline(std::cin, buferLogin);

	if (buferLogin == "0") //0 breaks the program logic
	{
		std::cout << "0 not available \n";
		throw Login_creature();
	}

	if (check_login(buferLogin))
	{
		throw Login_creature(); //invalid login
	}

	std::cout << "Login heck! \n";
	return buferLogin;
}
const std::string Chat::enter_password()
{
	std::cout << "���������� ������: ";
	std::string buferPassword;
	std::cin >> buferPassword;

	if (check_password(buferPassword))
	{
		throw Password_creature(); //invalid password
	}
	std::cout
		<< "Password heck! \n"
		<< "   *   *   *   *   *   *\n";
	return buferPassword;
}
const bool Chat::check_login(const std::string& loginForCheck)
{
	for (auto& element : _boxUsers)
	{
		if (element.get_login() == loginForCheck)
		{
			return true;
		}
	}
	return false;
}
const bool Chat::check_password(const std::string& passwordForCheck)
{
	return false;
}
const bool Chat::check_name(const std::string& nameForCheck)
{
	for (auto& element : _boxUsers)
	{
		if (element.get_name() == nameForCheck)
		{
			return true;
		}
	}
	return false;
}
void Chat::creat_user(std::string login, std::string password)
{
	User newUser(login, password);
	_boxUsers.push_back(newUser);
	_currentUser = std::make_shared<User>(newUser);
}
void Chat::set_currentUser(const User& authorizer) //for authorization
{
	_currentUser = std::make_shared<User>(authorizer);
	std::cout << "����������� �������� \n";
}
auto Chat::verification() //authorization
{
	std::string login;
	std::string password;
	std::cout
		<< "������� � ���� ������� \n"
		<< "�����: ";
	std::cin.ignore();
	getline(std::cin, login);
	std::cout
		<< "������: ";
	std::cin >> password;

	for (auto& element : _boxUsers)
	{
		if (login == element.get_login() && password == element.get_password())
		{
			set_currentUser(element);
			return true;
		}
	}
	std::cout << "������: �����/������ ��������������. \n";
	return false;
}
const long long Chat::counter_new_message()
{
	long long counter{};
	for (auto& element : _boxMessages)
	{	//we don't count the old ones
		if (element.get_idMessage() <= _boxUsers.at(_currentUser->get_idUser() - 1).get_indicatorMessage())
		{
			continue;
		}
		//we do not consider private strangers
		if (element.get_flagPrivacy() && (element.get_recipient() != _currentUser->get_idUser()))
		{
			continue;
		}
		++counter;
	}
	return counter;
}
void Chat::view_messages()
{
	for (auto element : _boxMessages)
	{
		if (element.get_idMessage() < _boxUsers.at(_currentUser->get_idUser() - 1).get_indicatorMessage()) // view only new messages (+ always last)
		{
			continue;
		}

		//_boxUsers.at(_currentUser->get_idUser()-1).set_indicatorMessage(element.get_idMessage()); // for view only new messages

		if (element.get_flagPrivacy()) // check private
		{
			if (element.get_recipient() != _currentUser->get_idUser())
			{
				continue;
			}
		}

		std::string separator = element.get_flagPrivacy() ? "(Private): \n" : ": \n";

		std::cout
			<< get_name_for_id(element.get_sender())
			<< separator
			<< element.get_text() << "\n";
		std::cout << "__________________________________________________\n";

		if (element.get_flagPrivacy()) //reply to a private message
		{
			std::cout << "�������� �� ������ ���������? \n 0: ��� \n 1: �� \n";
			bool answer{ false };
			std::cin >> answer;
			if (answer)
			{
				new_privat_message(element.get_sender());
			}
		}
		//_boxUsers.at(_currentUser->get_idUser()-1).set_indicatorMessage(element.get_idMessage());// ��� ����� ����������� ���������
	}
	_boxUsers.at(_currentUser->get_idUser() - 1).set_indicatorMessage(idMessage); // for view only new messages
}
void Chat::sending_public_message()
{
	std::cout << "������� ��������� \n";
	std::string textMessage;
	std::cin.ignore();
	getline(std::cin, textMessage);
	Message newMessage{ textMessage, _currentUser->get_idUser() };
	_boxMessages.push_back(newMessage);
}
void Chat::new_privat_message(long long addressee) /////////////////////////����� �� �������
{
	if (addressee == 0)
	{
		bool off{ true };
		std::string recipientMessage; //addressee
		do
		{
			std::cout << "������� ��� ����������: \n";
			std::cin >> recipientMessage;

			if (recipientMessage == "0") {
				off = false; break;
			}

			if (!check_name(recipientMessage)) {
				std::cout << "������������ � ������ " << recipientMessage << " �� ������ \n ��� ������ ������� ��� ����������: 0 \n";
				continue;
			}
			else {
				off = false;
			}

		} while (off);
	}

	std::string textMessage;
	std::cout << "������� ����� ���������� ���������: \n";
	std::cin >> textMessage;

	Message newMessage{ textMessage, _currentUser->get_idUser(), addressee, true };
	//Message newMessage{ textMessage, _currentUser->get_id(), get_id_for_name(recipientMessage), true };

	_boxMessages.push_back(newMessage);
}
void Chat::strart_menu()
{
	std::cout << "����� ���������� � ���! \n";
	bool offChat{ true };
	do
	{
		std::cout
			<< "1 - ������� � ���� ������� \n"
			<< "2 - ����������� \n"
			<< "0 - ����� (�� ������� ����) \n"
			<< "��������: \n";
		char mode{};
		std::cin >> mode;
		system("cls");

		switch (mode)
		{
		case '1':
		{
			if (verification())
			{
				system("cls");
				working_session();
			}
			break;
		}

		case '2':
			try
			{
				registration();
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << "\n";
			}
			break;

		case '0':
			offChat = false;
			std::cout << "����� �� ���������, �������� �����! \n";
			break;

		default:
			std::cout << "������ �����. \n";
			break;
		}
	} while (offChat);
}
void Chat::registration()
{
	std::string buferLogin = enter_login();
	std::string buferPassword = enter_password();
	creat_user(buferLogin, buferPassword);
}
void Chat::working_session()
{
	if (_currentUser == nullptr) //erorr
	{
		std::cout << "������ �����������, ��������� � ������������� \n";
		return;
	}

	std::cout << "�����������: " << _currentUser->get_login() << "\n";
	bool offWorkingSession{ true };
	char action{};
	do
	{
		std::cout
			<< "1 �������� ������� ("
			<< counter_new_message()
			<< ") ��������� \n"
			<< "2 �������� ��� ��������� (�������) \n"
			<< "3 ����� ��������� \n"
			<< "4 ����� ������ ��������� \n"
			<< "0 ����� � ������� ���� \n";
		std::cin >> action;

		switch (action)
		{
		case '1':
			view_messages();
			break;

		case '2':
			_boxUsers.at(_currentUser->get_idUser() - 1).set_indicatorMessage(0);
			view_messages();
			break;

		case '3':
			sending_public_message();
			break;

		case '4':
			new_privat_message();
			break;

		case '0':
			system("cls");
			offWorkingSession = false;
			break;

		default:
			break;
		}
	} while (offWorkingSession);
}