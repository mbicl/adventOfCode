#include "../../utils/aoc_utils.h"
#include <bits/stdc++.h>

using namespace std;

class Machine {
private:
	int a_register, b_register, c_register;
	vector<int> program, output;
	int instruction_pointer;

	void increment_pointer() {
		this->instruction_pointer += 2;
	}

	int get_combo_operand_value(int operand) {
		if (0 <= operand && operand <= 3) return operand;

		if (operand == 4) return this->a_register;
		if (operand == 5) return this->b_register;
		if (operand == 6) return this->c_register;

		throw runtime_error("program is not valid: operand " + to_string(operand));
	}

	void adv(int operand) {
		int numerator = this->a_register;
		int denominator = 1 << this->get_combo_operand_value(operand);
		this->a_register = numerator / denominator;
		this->increment_pointer();
	}

	void bxl(int operand) {
		this->b_register = this->b_register ^ operand;
		this->increment_pointer();
	}

	void bst(int operand) {
		this->b_register = this->get_combo_operand_value(operand) % 8;
		this->increment_pointer();
	}

	void jnz(int operand) {
		if (this->a_register == 0) {
            this->increment_pointer();
            return;
        }
		this->instruction_pointer = operand + 1;
	}

	void bxc(int operand) {
		this->b_register = this->b_register ^ this->c_register;
		this->increment_pointer();
	}

	void out(int operand) {
        int val = this->get_combo_operand_value(operand) % 8;
		this->output.push_back(val);
		this->increment_pointer();
	}

	void bdv(int operand) {
		int numerator = this->a_register;
		int denominator = 1 << this->get_combo_operand_value(operand);
		this->b_register = numerator / denominator;
		this->increment_pointer();
	}

	void cdv(int operand) {
		int numerator = this->a_register;
		int denominator = 1 << this->get_combo_operand_value(operand);
		this->c_register = numerator / denominator;
		this->increment_pointer();
	}

    void run_instruction(int opcode, int operand) {
		switch (opcode) {
		case 0: this->adv(operand); break;
		case 1: this->bxl(operand); break;
		case 2: this->bst(operand); break;
		case 3: this->jnz(operand); break;
		case 4: this->bxc(operand); break;
		case 5: this->out(operand); break;
		case 6: this->bdv(operand); break;
		case 7: this->cdv(operand); break;

		default:
			throw runtime_error("program is not valid: opcode " + to_string(opcode));
		}
	}

	void print() {
		cout << aoc::str::join(this->output, ",") << endl;
	}

public:
	Machine(int a, int b, int c, string p) {
		this->a_register = a;
		this->b_register = b;
		this->c_register = c;
		for (string i : aoc::str::split(p, ',')) {
			this->program.push_back(stoi(i));
		}
		this->instruction_pointer = 1;
	}

	void run_program() {
		while (true) {
			int opcode = this->program[this->instruction_pointer - 1];
			int operand = this->program[this->instruction_pointer];
			this->run_instruction(opcode, operand);
			if (this->instruction_pointer >= this->program.size())
				break;
		}

		this->print();
	}
};

signed main() {
	int a, b, c;
	string s;

	cin >> s >> s >> a;
	cin >> s >> s >> b;
	cin >> s >> s >> c;
	cin >> s >> s;

	Machine m(a, b, c, s);

	m.run_program();
}
