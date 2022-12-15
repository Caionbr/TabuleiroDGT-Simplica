#include "Serialport.h"

Serialport::Serialport(char* portname)
{
	errors = 0;
	status = { 0 };
	connected = false;

	handleToCOM = CreateFileA(static_cast<LPCSTR>(portname), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	DWORD errMsg = GetLastError();
	if (errMsg == 2) {
		printf("Nenhum dispositivo serial conectado na porta especificada\n");
	}
	else if (errMsg == 5) {
		printf("Existe outro app usando a porta especificada\n");
	}
	else if (errMsg == 0) {
		DCB dcbSerialParameters = { 0 };
		if (!GetCommState(handleToCOM, &dcbSerialParameters)) {
			printf("Nao foi possivel obter os parametros\n");
		}
		else {
			dcbSerialParameters.BaudRate = CBR_9600;
			dcbSerialParameters.ByteSize = 8;
			dcbSerialParameters.StopBits = ONESTOPBIT;
			dcbSerialParameters.Parity = NOPARITY;
			dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;
			
			if (!SetCommState(handleToCOM, &dcbSerialParameters)) {
				printf("Nao foi possivel settar os parametros\n");
			}
			else {
				connected = true;
				PurgeComm(handleToCOM, PURGE_RXCLEAR | PURGE_TXCLEAR);
				Sleep(STM_WAIT);
			}
		}
	}
}

Serialport::~Serialport()
{
	if (connected = true) {
		connected = false;
		CloseHandle(handleToCOM);
	}
}

int Serialport::ReadSerialport(char* buffer, unsigned int buf_size)
{
	DWORD bytesread;
	unsigned int toread = 0;

	ClearCommError(handleToCOM, &errors, &status);

	if (status.cbInQue > 0) {
		if (status.cbInQue > buf_size) {
			toread = buf_size;
		}
		else toread = status.cbInQue;
	}

	if (ReadFile(handleToCOM, buffer, toread, &bytesread, NULL)) {
		return bytesread;
	}

	return 0;
}

bool Serialport::Isconnected()
{
	return connected;
}
