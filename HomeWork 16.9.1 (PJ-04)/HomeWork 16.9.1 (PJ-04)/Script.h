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
	Message message_001("В чат добавлен Lev Gladkov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_001);
	Message message_002("В чат добавлен Maxim Lvov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_002);
	Message message_003("В чат добавлен Andrey Orlov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_003);
	Message message_004("В чат добавлен Eugene Kaspersky.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_004);
	Message message_005("В чат добавлен Yaroslav Semenov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_005);
	Message message_006("В чат добавлен Rodion Braun.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_006);
	Message message_007("Привет парни! Сегодня погода просто ужасна!", 1, 0, false);
	chatRef.get_boxMessages().push_back(message_007);
	Message message_008("И не говори", 2, 0, false);
	chatRef.get_boxMessages().push_back(message_008);
	Message message_009("Из-за этого ливня, я проснулся в 4 часа утра", 4, 0, false);
	chatRef.get_boxMessages().push_back(message_009);
	Message message_010("Та же ситуация", 5, 0, false);
	chatRef.get_boxMessages().push_back(message_010);
	Message message_011("Народ, я тут посмотрел погоду на эту неделю. Будет вся неделя дождь", 6, 0, false);
	chatRef.get_boxMessages().push_back(message_011);
	Message message_012("Черт!", 5, 0, false);
	chatRef.get_boxMessages().push_back(message_012);
	Message message_013("Макс ты сегодня будешь смотреть футбол?", 1, 2, true);
	chatRef.get_boxMessages().push_back(message_013);
	Message message_014("Нет, у меня сегодня ночная смена.", 2, 1, true);
	chatRef.get_boxMessages().push_back(message_014);
	Message message_015("Ярик скинь 200 р. на карту.", 4, 5, true);
	chatRef.get_boxMessages().push_back(message_015);
	Message message_016("Сейчас скину.", 5, 4, true);
	chatRef.get_boxMessages().push_back(message_016);
	Message message_017("Родя, что делаешь?", 1, 6, true);
	chatRef.get_boxMessages().push_back(message_017);
	Message message_018("Пишу чат на котором, ты мне сейчас пишешь", 6, 1, true);
	chatRef.get_boxMessages().push_back(message_018);
	Message message_019("А ну ладно не буду тебе мишать. У тебя все получится!", 1, 6, true);
	chatRef.get_boxMessages().push_back(message_019);
	Message message_020("У тебя все получится!", 6, 1, true);
	chatRef.get_boxMessages().push_back(message_020);
}