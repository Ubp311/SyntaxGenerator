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
	
	if (val == 0)
		return	"0";
	if (val < 0)
	{
		val *= -1;
		resultStr += '-';
	}
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

int flag(const string& str, bool& isSameLength, bool& isUnsigned)
{
	if(str == "-sl" && !isSameLength)
	{
		isSameLength = true;
		return	1;
	}
	else if(str == "-u" && !isUnsigned)
	{
		isUnsigned = true;
		return	1;
	}
	else
		return	0;
};

bool	flagError(const string& str)
{
	if(!str.compare("-sl") || !str.compare("-u"))
		return	false;
	else
	{
		for(int i = 0; i != '\0'; i++)
		{
			if(!isdigit(str[i]))
			{
				cout <<	"Error." << endl;
				return	true;
			}
		}
		return	false;
	}
};

bool	charError(const char& c)
{
	switch (c)
	{
	case '*':
		return	false;
	case '/':
		return	false;
	case '%':
		return	false;
	case '+':
		return	false;
	case '-':
		return	false; 
	default:
		cout << "Error : Unknown character." << endl;
		return	true;
	}
};

int main(int argc, char* argv[])
{
	int	syntaxNum = 100;
	int	operand1MinDigitNum = 8, operand1MaxDigitNum = 100;
	int operand2MinDigitNum = 8, operand2MaxDigitNum = 100;
	char	opChar = '+';
	bool	isSameLength = false;
	bool	isUnsigned = false;
	char	flagChar = 'n';

	if (argc == 1)
	{
		cout << "Input the number of syntax : ";
		cin >> syntaxNum;
		cout << "Input the operator('*','/','+','-') : ";
		cin >> opChar;
		if(charError(opChar))
		{
			cout << "Error : Unknown operator." << endl;
			return	0;
		}
		cout << "Make the first and second value the same length? (y/n) : ";
		cin >> flagChar;
		isSameLength = (flagChar == 'y') ? true : false;
		cout << "Signed value? (y/n) : ";
		cin >> flagChar;
		isUnsigned = (flagChar == 'y') ? false : true;
		if(!isSameLength)
		{
			cout << "Input the first minimum digit : ";
			cin >> operand1MinDigitNum;
			cout << "Input the first maximum digit : ";
			cin >> operand1MaxDigitNum;
			cout << "Input the second minimum digit : ";
			cin >> operand2MinDigitNum;
			cout << "Input the second maximum digit : ";
			cin >> operand2MaxDigitNum;
		}
		else
		{
			cout << "Input the minimum digit : ";
			cin >> operand1MinDigitNum;
			cout << "Input the maximum digit : ";
			cin >> operand1MaxDigitNum;
		}
	}
	else if (argc < 7)
	{
		cout << "Error : Lack of parameters." << endl;
		return	0;
	}
	else if (argc >= 7)
	{
		int	i = 1;
		
		if(flagError(argv[i]))
			return	0;
		i += flag(argv[i], isSameLength, isUnsigned);
		if(flagError(argv[i]))
			return	0;
		i += flag(argv[i], isSameLength, isUnsigned);
		syntaxNum = atoi(argv[i++]);
		if(flagError(argv[i]) || charError(argv[i][0]))
			return	0;
		i += flag(argv[i], isSameLength, isUnsigned);
		if(flagError(argv[i]))
			return	0;
		i += flag(argv[i], isSameLength, isUnsigned);
		opChar = argv[i++][0];
		if(flagError(argv[i]))
			return	0;
		i += flag(argv[i], isSameLength, isUnsigned);
		if(flagError(argv[i]))
			return	0;
		i += flag(argv[i], isSameLength, isUnsigned);
		operand1MinDigitNum = atoi(argv[i++]);
		i += flag(argv[i], isSameLength, isUnsigned);
		if(flagError(argv[i]))
			return	0;
		i += flag(argv[i], isSameLength, isUnsigned);
		if(flagError(argv[i]))
			return	0;
		operand1MaxDigitNum = atoi(argv[i++]);
		i += flag(argv[i], isSameLength, isUnsigned);
		if(flagError(argv[i]))
			return	0;
		i += flag(argv[i], isSameLength, isUnsigned);
		if(flagError(argv[i]))
			return	0;
		operand2MinDigitNum = atoi(argv[i++]);
		i += flag(argv[i], isSameLength, isUnsigned);
		if(flagError(argv[i]))
			return	0;
		i += flag(argv[i], isSameLength, isUnsigned);
		if(flagError(argv[i]))
			return	0;
		operand2MaxDigitNum = atoi(argv[i++]);
		if(i < argc)
		{
			if(flagError(argv[i]))
				return	0;
			i += flag(argv[i], isSameLength, isUnsigned);
		}
		if(i < argc)
		{
			if(flagError(argv[i]))
				return	0;
			i += flag(argv[i], isSameLength, isUnsigned);
		}
	}

	ifstream iFilePy;
	ifstream iFileTxt;
	ofstream oFilePy;
	ofstream oFileTxt;
	string	fileAddr = "./"; // At Windows Using ".\\"

	int	index = 1;

	random_device	rd1, rd2, rd3;
	mt19937	gen1(rd1()), gen2(rd2()), gen3(rd3());
	uniform_int_distribution<int>	disRange1(operand1MinDigitNum, operand1MaxDigitNum), disRange2(operand2MinDigitNum, operand2MaxDigitNum);
	uniform_int_distribution<int> disVal(0, 9), disSign(0, 1);

	fileAddr += itos(index++);

	iFilePy.open(fileAddr + ".py", ios_base::in);
	iFileTxt.open(fileAddr + ".txt", ios_base::in);

	while (iFilePy.is_open() || iFileTxt.is_open() && index != 2147483648)
	{
		iFilePy.close();
		iFileTxt.close();
		fileAddr.clear();
		fileAddr += "./"; // At Windows Using ".\\"
		fileAddr += itos(index++);
		iFilePy.open(fileAddr + ".py", ios_base::in);
		iFileTxt.open(fileAddr + ".txt", ios_base::in);
	}
	if(index == 2147483648)
	{
		cout << "Index full." << endl;
		iFilePy.close();
		iFileTxt.close();
		return	0;
	}
	oFilePy.open(fileAddr + ".py", ios_base::out);
	oFileTxt.open(fileAddr + ".txt", ios_base::out);
	if (!oFilePy.fail() && !oFileTxt.fail())
	{
		for (int i = 0; i < syntaxNum; i++)
		{
			string	pyStr = "print(";
			string	syntaxStr;
			bool	isNegative = false;
			if(!isUnsigned)
				isNegative = disSign(gen3);
			int	maxJ = disRange1(gen1);
			int	tempVal = disVal(gen2);
			if (isNegative)
			{
				pyStr += '-';
				syntaxStr += '-';
			}
			while (tempVal == 0)
				tempVal = disVal(gen2);
			for (int j = 0; j < maxJ; j++)
			{
				pyStr += tempVal + '0';
				syntaxStr += tempVal + '0';
				tempVal = disVal(gen2);
			}
			pyStr += ' '; // * / % + -
			pyStr += opChar;
			pyStr += ' ';
			syntaxStr += ' ';
			syntaxStr += opChar;
			syntaxStr += ' ';
			if(!isSameLength)
			{
				maxJ = disRange2(gen1);
				if(!isUnsigned)
					isNegative = disSign(gen3);
			}
			if (isNegative)
			{
				pyStr += '-';
				syntaxStr += '-';
			}
			while (tempVal == 0)
				tempVal = disVal(gen2);
			for (int j = 0; j < maxJ; j++)
			{
				pyStr += tempVal + '0';
				syntaxStr += tempVal + '0';
				tempVal = disVal(gen2);
			}
			pyStr += ")\n";
			if(i < syntaxNum - 1)
				syntaxStr += '\n';
			oFilePy.write(pyStr.c_str(), pyStr.size());
			oFileTxt.write(syntaxStr.c_str(), syntaxStr.size());

			cout << "Generating : " << i + 1 << " / " << syntaxNum << endl;
		}
	}
	else
		cout << "Error : Can't open file!" << endl;

	iFilePy.close();
	iFileTxt.close();
	oFilePy.close();
	oFileTxt.close();

	return	0;
}