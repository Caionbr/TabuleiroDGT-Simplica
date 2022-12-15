#pragma once

#define STM_WAIT 6400
#define EXPECTED_BYTES 64

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

class Serialport {
private:
	HANDLE handleToCOM;
	bool connected;
	COMSTAT status;
	DWORD errors;
public:
	Serialport(char* portname);
	~Serialport();
	int ReadSerialport(char* buffer, unsigned int buf_size);
	bool Isconnected();
};