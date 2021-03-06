#pragma once
#include <Windows.h>

class PlayerData
{
public:
	UINT8 R;
	UINT8 G;
	UINT8 B;
	int X;
	int Y;
	SOCKET ClientSocket;

	//proto buffer, flat buffer
	//0	  1 	2	3	4	5	6	7	8	9	10	11	        12	13	14
	//R   G	    B	X				Y				ClientNumber
	void MakeData(char* Data) //Deserialze(?????????????), json -> Data
	{
		//R = (UINT8)Data[0];
		//G = (UINT8)Data[1];
		//B = (UINT8)Data[2];
		memcpy(&R, &Data[0], 1);
		memcpy(&G, &Data[1], 1);
		memcpy(&B, &Data[2], 1);
		memcpy(&X, &Data[3], 4);
		memcpy(&Y, &Data[7], 4);
		memcpy(&ClientSocket, &Data[11], 4);
	}

	void MakePacket(char* Packet) //Serialize(?????????), Data -> json
	{
		//Packet[0] = (UINT8)R;
		//Packet[1] = (UINT8)G;
		//Packet[2] = (UINT8)B;
		memcpy(&Packet[0], &R, 1);
		memcpy(&Packet[1], &G, 1);
		memcpy(&Packet[2], &B, 1);
		memcpy(&Packet[3], &(X), 4);
		memcpy(&Packet[7], &(Y), 4);
		memcpy(&Packet[11], &(ClientSocket), 4);
	}
};