#include "SerialClass.h"
#include <string>


void Serialize()
{
	printf("Welcome to the serial test app\n");

	Serial* sp = new Serial("\\\\.\\COM3"); // �ø��� ��Ʈ ��ȣ �� ���� �ٲ������ 
	if (sp->IsConnected())
		printf("We're conneted");


	char incomingData[256] = "";
	int dataLength = 255;
	int readResult = 0;

	while (sp->IsConnected()) // ���߿� �� �κ� ���� ����� ���� ����ϴ°� �ְ�ʹ�. 
	{
		readResult = sp->ReadData(incomingData, dataLength);
		incomingData[readResult] = 0;
		printf("%s", incomingData);


	}
	return;
}