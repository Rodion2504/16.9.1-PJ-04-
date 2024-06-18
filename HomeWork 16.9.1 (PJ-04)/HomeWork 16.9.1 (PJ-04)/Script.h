#include "Chat.h"
#pragma once
void test_Chat(Chat& chatRef)
{
	//generated content
	User Gladkov{ "1",	"1" };		//01 
	User Lvov{ "Maxim Lvov",			"123" };		//02
	User Mitrofanov{ "Makar Mitrofanov",			"123" };		//03
	User Orlov{ "Andrey Orlov",	"J@#ua_0Rx" };	//04
	User Semenov{ "Yaroslav Semenov",			"123" };		//05
	User Braun{ "Rodion Braun",		"123" };		//06 Rodion Braun
	chatRef.get_boxUsers().push_back(Gladkov);
	chatRef.get_boxUsers().push_back(Lvov);
	chatRef.get_boxUsers().push_back(Mitrofanov);
	chatRef.get_boxUsers().push_back(Orlov);
	chatRef.get_boxUsers().push_back(Semenov);
	chatRef.get_boxUsers().push_back(Braun);
	Message message_001("� ��� �������� Lev Gladkov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_001);
	Message message_002("� ��� �������� Maxim Lvov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_002);
	Message message_003("� ��� �������� Andrey Orlov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_003);
	Message message_004("� ��� �������� Eugene Kaspersky.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_004);
	Message message_005("� ��� �������� Yaroslav Semenov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_005);
	Message message_006("� ��� �������� Rodion Braun.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_006);
	Message message_007("������ �����! ������� ������ ������ ������!", 1, 0, false);
	chatRef.get_boxMessages().push_back(message_007);
	Message message_008("� �� ������", 2, 0, false);
	chatRef.get_boxMessages().push_back(message_008);
	Message message_009("��-�� ����� �����, � ��������� � 4 ���� ����", 4, 0, false);
	chatRef.get_boxMessages().push_back(message_009);
	Message message_010("�� �� ��������", 5, 0, false);
	chatRef.get_boxMessages().push_back(message_010);
	Message message_011("�����, � ��� ��������� ������ �� ��� ������. ����� ��� ������ �����", 6, 0, false);
	chatRef.get_boxMessages().push_back(message_011);
	Message message_012("����!", 5, 0, false);
	chatRef.get_boxMessages().push_back(message_012);
	Message message_013("���� �� ������� ������ �������� ������?", 1, 2, true);
	chatRef.get_boxMessages().push_back(message_013);
	Message message_014("���, � ���� ������� ������ �����.", 2, 1, true);
	chatRef.get_boxMessages().push_back(message_014);
	Message message_015("���� ����� 200 �. �� �����.", 4, 5, true);
	chatRef.get_boxMessages().push_back(message_015);
	Message message_016("������ �����.", 5, 4, true);
	chatRef.get_boxMessages().push_back(message_016);
	Message message_017("����, ��� �������?", 1, 6, true);
	chatRef.get_boxMessages().push_back(message_017);
	Message message_018("���� ��� �� �������, �� ��� ������ ������", 6, 1, true);
	chatRef.get_boxMessages().push_back(message_018);
	Message message_019("� �� ����� �� ���� ���� ������. � ���� ��� ���������!", 1, 6, true);
	chatRef.get_boxMessages().push_back(message_019);
	Message message_020("� ���� ��� ���������!", 6, 1, true);
	chatRef.get_boxMessages().push_back(message_020);
}