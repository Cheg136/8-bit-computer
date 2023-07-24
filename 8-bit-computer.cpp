#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <vector>

class FileArray {
public:
	int size, over;
	int* data;
	std::string filename;

	FileArray(int arraySize, const std::string& inputFilename) : size(arraySize), filename(inputFilename) {
		data = new int[size];
	}

	~FileArray() {
		delete[] data;
	}

	bool read() {
		std::ifstream infile(filename);
		if (!infile) {
			std::cout << "Error opening file: " << filename << std::endl;
			return false;
		}

		for (int i = 0; i < size; ++i) {
			if (!(infile >> data[i])) {
				std::cout << "Error reading data from file." << std::endl;
				return false;
			}
		}

		infile.close();
		return true;
	}

	bool write() {
		std::ofstream outfile(filename);
		if (!outfile) {
			std::cout << "Error opening file: " << filename << std::endl;
			return false;
		}

		for (int i = 0; i < size; ++i) {
			outfile << data[i] << " ";
			if ((i + 1) % over == 0) { 
				outfile << std::endl << std::endl; 
			}
		}

		outfile.close();
		return true;
	}

	void setover(int dat) {
		over = dat;
	}
};

void itb4(int busData, bool data[]) {
	if (busData >= 8) { data[3] = 1; busData -= 8; } else { data[3] = 0; }
	if (busData >= 4) { data[2] = 1; busData -= 4; } else { data[2] = 0; }
	if (busData >= 2) { data[1] = 1; busData -= 2; } else { data[1] = 0; }
	if (busData >= 1) { data[0] = 1; busData -= 1; } else { data[0] = 0; }
}

void bti4(int& busData, bool data[]) {
	busData = 0;
	if (data[3]) { busData += 8; }
	if (data[2]) { busData += 4; }
	if (data[1]) { busData += 2; }
	if (data[0]) { busData += 1; }
}

void itb8(int busData, bool data[]) {
	if (busData >= 128) { data[7] = 1; busData -= 128; } else { data[7] = 0; }
	if (busData >= 64) { data[6] = 1; busData -= 64; } else { data[6] = 0; }
	if (busData >= 32) { data[5] = 1; busData -= 32; } else { data[5] = 0; }
	if (busData >= 16) { data[4] = 1; busData -= 16; } else { data[4] = 0; }
	if (busData >= 8) { data[3] = 1; busData -= 8; } else { data[3] = 0; }
	if (busData >= 4) { data[2] = 1; busData -= 4; } else { data[2] = 0; }
	if (busData >= 2) { data[1] = 1; busData -= 2; } else { data[1] = 0; }
	if (busData >= 1) { data[0] = 1; busData -= 1; } else { data[0] = 0; }
}

void bti8(int& busData, bool data[]) {
	busData = 0;
	if (data[7]) { busData += 128; }
	if (data[6]) { busData += 64; }
	if (data[5]) { busData += 32; }
	if (data[4]) { busData += 16; }
	if (data[3]) { busData += 8; }
	if (data[2]) { busData += 4; }
	if (data[1]) { busData += 2; }
	if (data[0]) { busData += 1; }
}

void itb16(int busData, bool data[]) {
	if (busData >= 32768) { data[7] = 1; busData -= 128; } else { data[7] = 0; }
	if (busData >= 16384) { data[6] = 1; busData -= 64; } else { data[6] = 0; }
	if (busData >= 8192) { data[5] = 1; busData -= 32; } else { data[5] = 0; }
	if (busData >= 4096) { data[4] = 1; busData -= 16; } else { data[4] = 0; }
	if (busData >= 2048) { data[3] = 1; busData -= 8; } else { data[3] = 0; }
	if (busData >= 1024) { data[2] = 1; busData -= 4; } else { data[2] = 0; }
	if (busData >= 512) { data[1] = 1; busData -= 2; } else { data[1] = 0; }
	if (busData >= 256) { data[0] = 1; busData -= 1; } else { data[0] = 0; }
	if (busData >= 128) { data[7] = 1; busData -= 128; } else { data[7] = 0; }
	if (busData >= 64) { data[6] = 1; busData -= 64; } else { data[6] = 0; }
	if (busData >= 32) { data[5] = 1; busData -= 32; } else { data[5] = 0; }
	if (busData >= 16) { data[4] = 1; busData -= 16; } else { data[4] = 0; }
	if (busData >= 8) { data[3] = 1; busData -= 8; } else { data[3] = 0; }
	if (busData >= 4) { data[2] = 1; busData -= 4; } else { data[2] = 0; }
	if (busData >= 2) { data[1] = 1; busData -= 2; } else { data[1] = 0; }
	if (busData >= 1) { data[0] = 1; busData -= 1; } else { data[0] = 0; }
}

void bti16(int& busData, bool data[]) {
	busData = 0;
	if (data[15]) { busData += 32768; }
	if (data[14]) { busData += 16384; }
	if (data[13]) { busData += 8192; }
	if (data[12]) { busData += 4096; }
	if (data[11]) { busData += 2048; }
	if (data[10]) { busData += 1024; }
	if (data[9]) { busData += 512; }
	if (data[8]) { busData += 256; }
	if (data[7]) { busData += 128; }
	if (data[6]) { busData += 64; }
	if (data[5]) { busData += 32; }
	if (data[4]) { busData += 16; }
	if (data[3]) { busData += 8; }
	if (data[2]) { busData += 4; }
	if (data[1]) { busData += 2; }
	if (data[0]) { busData += 1; }
}

bool registerA_in = false;
bool registerA_out = false;
bool registerB_in = false;
bool registerB_out = false;
bool registerC_in = false;
bool registerC_out = false;
bool registerD_in = false;
bool registerD_out = false;
bool registerE_in = false;
bool registerE_out = false;
bool registerF_in = false;
bool registerF_out = false;
bool registerI_in = false;
bool registerI_out = false;
bool registerR_in = false;
bool registerR_out = false;
bool clock_off = false;
bool ALU_out = false;
bool carry = false;
bool zero = false;
bool RAM_in = false;
bool RAM_out = false;
bool counter_on = false;
bool counter_out = false;
bool counter_in = false;

int registerA_data = 0;
int registerB_data = 0;
int registerC_data = 0;
int registerD_data = 0;
int registerE_data = 0;
int registerF_data = 0;
int registerI_data = 0;
int registerR_data = 0;
int ALU_type = 0;
int counterdata = 0;
int RAM_data[65536] = {0};

void registerA(int& data) {
	if (registerA_in) { registerA_data = data; }
	if (registerA_out) { data = registerA_data; }
}

void registerB(int& data) {
	if (registerB_in) { registerB_data = data; }
	if (registerB_out) { data = registerB_data; }
}

void registerC(int& data) {
	if (registerC_in) { registerC_data = data; }
	if (registerC_out) { data = registerC_data; }
}

void registerD(int& data) {
	if (registerD_in) { registerD_data = data; }
	if (registerD_out) { data = registerD_data; }
}

void registerE(int& data) {
	if (registerE_in) { registerE_data = data; }
	if (registerE_out) { data = registerE_data; }
}

void registerF(int& data) {
	if (registerF_in) { registerF_data = data; }
	if (registerF_out) { data = registerF_data; }
}

void registerI(int& data) {
	if (registerI_in) { registerI_data = data; }
	if (registerI_out) { data = registerI_data; }
}

void registerR(int& data) {
	if (registerR_in) { registerR_data = data; }
	if (registerR_out) { data = registerR_data; }
}

void clock(int& on) {
	if (clock_off) { on = 0; }
}

void ALU(int& data) {
	if (ALU_out) {
		bool a[16] = {0}, b[16] = {0}, s[16] = {0};

		switch (ALU_type) {
			case 0: // ADD
				itb16(registerA_data, a);
				itb16(registerB_data, b);
				carry = 0;
				for (int i = 0; i < 16; i++) {
					if (a[i] + b[i] + carry == 0) { s[i] = 0; carry = 0; }
					else if (a[i] + b[i] + carry == 1) { s[i] = 1; carry = 0; }
					else if (a[i] + b[i] + carry == 2) { s[i] = 0; carry = 1; }
					else if (a[i] + b[i] + carry == 3) { s[i] = 1; carry = 1; }
				}
				bti16(data, s);
				break;

			case 1: // SUB
				itb16(registerA_data, a);
				itb16(registerB_data, b);
				carry = 1;
				for (int i = 0; i < 16; i++) { b[i] = (b[i]) ? 0 : 1; }
				for (int i = 0; i < 16; i++) {
					if (a[i] + b[i] + carry == 0) { s[i] = 0; carry = 0; }
					else if (a[i] + b[i] + carry == 1) { s[i] = 1; carry = 0; }
					else if (a[i] + b[i] + carry == 2) { s[i] = 0; carry = 1; }
					else if (a[i] + b[i] + carry == 3) { s[i] = 1; carry = 1; }
				}
				bti16(data, s);
				break;

			case 2: // ADD with carry
				itb16(registerA_data, a);
				itb16(registerB_data, b);
				for (int i = 0; i < 16; i++) {
					if (a[i] + b[i] + carry == 0) { s[i] = 0; carry = 0; }
					else if (a[i] + b[i] + carry == 1) { s[i] = 1; carry = 0; }
					else if (a[i] + b[i] + carry == 2) { s[i] = 0; carry = 1; }
					else if (a[i] + b[i] + carry == 3) { s[i] = 1; carry = 1; }
				}
				bti16(data, s);
				break;

			case 3: // SUB with carry
				itb16(registerA_data, a);
				itb16(registerB_data, b);
				for (int i = 0; i < 16; i++) { b[i] = (b[i]) ? 0 : 1; }
				for (int i = 0; i < 16; i++) {
					if (a[i] + b[i] + carry == 0) { s[i] = 0; carry = 0; }
					else if (a[i] + b[i] + carry == 1) { s[i] = 1; carry = 0; }
					else if (a[i] + b[i] + carry == 2) { s[i] = 0; carry = 1; }
					else if (a[i] + b[i] + carry == 3) { s[i] = 1; carry = 1; }
				}
				bti16(data, s);
				break;

			case 4: // increment
				registerA_data += 1;
				break;

			case 5: // decrement
				registerA_data -= 1;
				break;

			case 6: // AND
				if (registerA_data == registerB_data) { data = 1; }
				else { data = 0; }
				break;

			case 7: // OR
				if (registerA_data + registerB_data > 0) { data = 1; }
				else { data = 0; }
				break;

			case 8: // NOT
				if (registerA_data > 0) { data = 1; }
				else { data = 0; }
				break;

			case 9: // NAND
				if (registerA_data == registerB_data) { data = 0; }
				else { data = 1; }
				break;

			case 10: // XOR
				if ((registerA_data == 0 && 0 < registerB_data) || (registerA_data > 0 && 0 == registerB_data)) { data = 1; }
				else { data = 0; }
				break;

			case 11: // NOR
				if (registerA_data + registerB_data == 0) { data = 1; }
				else { data = 0; }
				break;

			case 12: // XNOR
				if ((registerA_data == 0 && 0 == registerB_data) || (registerA_data > 0 && 0 < registerB_data)) { data = 1; }
				else { data = 0; }
				break;

			case 13: // A>B
				if (registerA_data > registerB_data) { data = 1; }
				else { data = 0; }
				break;

			case 14: // A<B
				if (registerA_data < registerB_data) { data = 1; }
				else { data = 0; }
				break;
		}

		if (data == 0) { zero = true; }
		else { zero = false; }
	}
}

void RAM(int& data) {
	if (RAM_in) { data = RAM_data[registerR_data]; }
	if (RAM_out) { RAM_data[registerR_data] = data; }
}

void counter(int& data) {
	if (counter_on) { counterdata = (counterdata >= 65535) ? 0 : counterdata + 1; }
	if (counter_out) { data = counterdata; }
	if (counter_in) { counterdata = data; }
}

void reset() {
	registerA_in = false;
	registerA_out = false;
	registerB_in = false;
	registerB_out = false;
	registerC_in = false;
	registerC_out = false;
	registerD_in = false;
	registerD_out = false;
	registerE_in = false;
	registerE_out = false;
	registerF_in = false;
	registerF_out = false;
	registerI_in = false;
	registerI_out = false;
	registerR_in = false;
	registerR_out = false;
	clock_off = false;
	ALU_out = false;
	carry = false;
	zero = false;
	RAM_in = false;
	RAM_out = false;
	counter_on = false;
	counter_out = false;
	counter_in = false;

	registerA_data = 0;
	registerB_data = 0;
	registerC_data = 0;
	registerD_data = 0;
	registerE_data = 0;
	registerF_data = 0;
	registerI_data = 0;
	registerR_data = 0;
	ALU_type = 0;
	counterdata = 0;
	for (int i = 0; i < 65535; i++) { RAM_data[i] = 0; }
}

int main() {

	FileArray arr(1, "8_bit_computer_memory.txt");
	arr.setover(40);
	arr.read();
	arr.write();

	int on = 0;
	while (on != 2) {
		if (on == 0) {
			std::cin >> on;
		}
		if (on < 0 || on > 2) {
			on = 0;
		}
		if (on == 1) {
			reset();
			while (on == 1) {
				// Implementation logic here
			}
		}
	}

	return 0;
}
