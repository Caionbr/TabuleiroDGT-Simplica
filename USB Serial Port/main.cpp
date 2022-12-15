#include <iostream>
#include <iomanip>
#include <thread>
#include <string>
#include "Serialport.h"

char input[EXPECTED_BYTES];
double inputValDbl = 0;
std::string hey[8];
int zerocount=0;

char comport[] = "COM8"; //Valor a ser alterado dependendo da porta
char* port = comport;

int main() {
	Serialport STM(port);
	if (STM.Isconnected()) {
		std::cout << "Sucesso!\nConectado na porta " << port << std::endl;
	}
	else std::cin.get();

	while (STM.Isconnected()) {
		STM.ReadSerialport(input, EXPECTED_BYTES);
        for (int c = 0; c < 8; c++) {
            for (int i = 0; i < 8; i++) {
                if (input[(c * 8) + i] == '0' && i != 7) {
                    zerocount++;
                }
                else if (zerocount > 0) {
                    if (input[(c * 8) + i] == '0' && i == 7) {
                        zerocount++;
                    }
                    zerocount = zerocount + 0x30;
                    hey[c].push_back((char)zerocount);
                    zerocount = 0;
                    if (input[(c * 8) + i] != '0') {
                        hey[c].push_back(input[(c * 8) + i]);
                    }
                }
                else {
                    hey[c].push_back(input[(c * 8) + i]);
                }
            }
            printf("%s/", hey[c].c_str());
            hey[c].clear();
        }
		
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		printf("\n\n");
	}
}