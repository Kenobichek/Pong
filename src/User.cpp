#include "User.h"

void User::changePosition()
{
	if (checkTopBorder())
	{
		posY = 0;
	}

	if (checkBottomBorder())
	{
		posY = windowHeight - platformHeight;
	}
}