#include	<iostream>
#include	<fstream>
#include	<random>
#include	<string>


using namespace std;

string	itos(int val)
{
	string	resultStr;

	int	tempVal = val;
	int	mul = 1;
	
	if (val < 0)
	{
		val *= -1;
		resultStr += '-';
	}
	if (val == 0)
		return	"0";
	while (tempVal != 0)
	{
		tempVal /= 10;
		mul *= 10;
	}
	mul /= 10;
	while (mul != 0)
	{
		resultStr += val / mul + '0';
		val -= val / mul * mul;
		mul /= 10;
	}

	return	resultStr;
};

int main(int argc, char* argv[])
{
	int	syntaxNum = 100;
	int	operand1MinDigitNum = 8, operand1MaxDigitNum = 100;
	int operand2MinDigitNum = 8, operand2MaxDigitNum = 100;

	if (argc == 1)
	{
		cout << "Input the number of syntax : ";
		cin >> syntaxNum;
		cout << "Input the first minimum digit : ";
		cin >> operand1MinDigitNum;
		cout << "Input the first maximum digit : ";
		cin >> operand1MaxDigitNum;
		cout << "Input the second minimum digit : ";
		cin >> operand2MinDigitNum;
		cout << "Input the second maximum digit : ";
		cin >> operand2MaxDigitNum;
	}
	else if (argc < 6)
	{
		cout << "Error : Lack of parameters." << endl;
		return	0;
	}
	else if (argc == 6)
	{
		syntaxNum = atoi(argv[1]);
		operand1MinDigitNum = atoi(argv[2]);
		operand1MaxDigitNum = atoi(argv[3]);
		operand2MinDigitNum = atoi(argv[4]);
		operand2MaxDigitNum = atoi(argv[5]);
	}

	ifstream iFile;
	ofstream oFile;
	string	fileAddr = ".\\";
	string	fileName;

	int	index = 1;

	random_device	rd1, rd2, rd3;
	mt19937	gen1(rd1()), gen2(rd2()), gen3(rd3());
	uniform_int_distribution<int>	disRange1(operand1MinDigitNum, operand1MaxDigitNum), disRange2(operand2MinDigitNum, operand2MaxDigitNum);
	uniform_int_distribution<int> disVal(0, 9), disSign(0, 1);

	fileName += itos(index);
	fileAddr += itos(index++);
	fileName += ".py";
	fileAddr += ".py";
	iFile.open(fileAddr, ios_base::in);

	cout << iFile.is_open();
	while (iFile.is_open() && index != 2147483648)
	{
		fileAddr.clear();
		fileName.clear();
		fileAddr += '.\\';
		fileName += itos(index);
		fileAddr += itos(index++);
		fileAddr += ".py";
		fileName += ".py";
	}
	oFile.open(fileName, ios_base::out);
	if (oFile.is_open())
	{
		for (int i = 0; i < syntaxNum; i++)
		{
			string	valStr = "print(";
			bool	isNegative = disSign(gen3);

			int	maxJ = disRange1(gen1);
			int	tempVal = disVal(gen2);
			if (isNegative)
				valStr += '-';
			while (tempVal == 0)
				tempVal = disVal(gen2);
			for (int j = 0; j < maxJ; j++)
			{
				valStr += tempVal + '0';
				tempVal = disVal(gen2);
			}
			valStr += " * "; // * / % + -
			maxJ = disRange2(gen1);
			isNegative = disSign(gen3);
			if (isNegative)
				valStr += '-';
			while (tempVal == 0)
				tempVal = disVal(gen2);
			for (int j = 0; j < maxJ; j++)
			{
				valStr += tempVal + '0';
				tempVal = disVal(gen2);
			}
			valStr += ")\n";
			oFile.write(valStr.c_str(), valStr.size());

			cout << "Making : " << i + 1 << " / " << syntaxNum << endl;
		}

		oFile.close();
	}
	else
		cout << "Error : Can't open file!" << endl;
	

	iFile.close();

	return	0;
}