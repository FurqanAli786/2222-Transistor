#include <iostream>
#include <conio.h>

using namespace std;

void main(void)
{
	char Opt;
	float Av, B, Vbe, Vb, Vcc, Vce, R1, R2, Rc, Re, RL, C, Ic, Ie, re, Xc, F;
	cout << "\t\t*****************************************************" << endl;
	cout << "\t\t   ***********************************************   " << endl;
	cout << "\t\tWelcome to program of 2222 Transistor as an amplifier" << endl;
abc:
	cout << "\nChoose, \n1: Analysis \n2: Designing\n3:exit" << endl;
	cin >> Opt;
	if (Opt == '1')
	{
		cout << "Welcome to Analysis" << endl;
		cout << "Enter Values of:\n Voltage source Vcc:";
		cin >> Vcc;
		cout << "Resistor R1:";
		cin >> R1;
		cout << "Resistor R2:";
		cin >> R2;
		cout << "Resistor Rc:";
		cin >> Rc;
		cout << "Resistor Re:";
		cin >> Re;
		Vce = Vcc / 2;
		RL = Rc;
		Ic = (Vcc - Vce) / (Rc + Re);
		Ie = Ic;
		re = (.025 / Ie);
		Vb = (R2*Vcc) / (R1 + R2);
		Av = (Rc / (2 * re));
		B = (10 * R2 / Re);
		cout << "\tFor maximum power:\nVoltage gain Av=" << Av << "\nCurrent gain B=" << B << endl;
		cout << "Vb=" << Vb << "volts\nIc=" << Ic << "Amps\nIe=" << Ie << "Amps\nre=" << re << "ohms\nRL=" << RL << "ohms" << endl;
		goto abc;
	}
	else if (Opt == '2')
	{
		cout << "Welcome to Designing" << endl;
		cout << "Enter Values of:\n Voltage source Vcc:";
		cin >> Vcc;
		cout << "Required Voltage gain Av:";
		cin >> Av;
		cout << "Load resistance RL:";
		cin >> RL;
	IF:
		cout << "Input Frequency(20-20000) F:";
		cin >> F;
		if (F<20 || F>20000)
		{
			cout << "Frequency is out of range, re enter frequency\n";
			goto IF;
		}
		Vbe = 0.7;
		B = 180;
		Vce = Vcc / 2;
		Rc = RL;
		re = Rc / (2 * Av);
		Ie = (0.025) / re;
		Ic = Ie;
		Re = ((Vcc - Vce) / Ic) - Rc;
		Vb = Vbe + (Ie*Re);
		R2 = (B*Re) / 10;
		R1 = (Vcc*R2 / Vb) - R2;
		Xc = Re / 10;
		C = 1 / (2 * 3.1415*F*Xc);
		cout << "\tThe required values are:" << endl;
		cout << "R1=" << R1 << "ohms\nR2=" << R2 << "ohms\nRc=" << Rc << "ohms\nRe=" << Re << "ohms\nCapacitors=" << C << "farads" << endl;
		goto abc;
	}
	else if (Opt == '3')
	{
		cout << "thanks for using this programme";
	}
	else
	{
		cout << "Invalid input,try again";
		goto abc;
	}
	_getch();
}
