#include "Chat.h"
#include "Script.h"

int main()
{
	setlocale(0, "");

	Chat chat{ "Chat version 2.0" };

	test_Chat(chat); //test script (generated content)

	chat.strart_menu();

	return 0;
}