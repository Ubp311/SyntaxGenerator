#include	<iostream>
#include	<fstream>
#include	<random>
#include	<string>
#include	<cmath>


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

string	uitous(unsigned int	val)
{
	string	resultStr;

	unsigned int	tempVal = val;
	unsigned int	mul = 1U;

	if(val == 0U)
		return "0";
	tempVal /= 10U;
	while(tempVal != 0U)
	{
		tempVal /= 10U;
		mul *= 10U;
	}
	while(mul != 0U)
	{
		resultStr += val / mul + '0';
		val -= val / mul * mul;
		mul /= 10U;
	}

	return	resultStr;
};

int flag(const string& str, bool flags[])
{
	const string	flagStrs[4] = {"-v", "-sl", "-u", "-r"};

	for(int i = 0; i < 4; i++)
	{
		if(!str.compare(flagStrs[i]) && !flags[i])
		{
			flags[i] = true;
			return	1;
		}
		else
			return	0;
	}

	return	0;
};

bool	flagError(const string& str)
{
	if(!str.compare("-v") || !str.compare("-sl") || !str.compare("-u") || !str.compare("-r"))
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

/*const string	bigIntDivisionStr = "def bigIntDivision(val1, val2):\n"
	"\tremainder = 0\n"
	"\ttempRemainder = 0\n"
    "\tvalStr1Length = len(str(val1))\n"
    "\tvalStr2Length = len(str(val2))\n"
    "\tresultStr = ''\n"
	"\tif valStr1Length > 1 or valStr2Length > 1:\n"
    "\t\tif valStr1Length < valStr2Length:\n"
    "\t\t\treturn  0\n"
    "\t\telse:\n"
	"\t\t\tqEst = 5\n"
	"\t\t\ttempQEst = 5\n"
    "\t\t\ttempRemainder = remainder = int(str(val1)[0: valStr2Length])\n"
    "\t\t\tfor i in range(valStr2Length, valStr1Length):\n"
    "\t\t\t\tqEst = 0\n"
    "\t\t\t\ttempQEst = 5\n"
    "\t\t\t\twhile tempRemainder >= val2 or tempRemainder < 0:\n"
    "\t\t\t\t\tif tempRemainder < 0:\n"
	"\t\t\t\t\t\tqEst -= tempQEst\n"
    "\t\t\t\t\telif tempRemainder >= val2:\n"
    "\t\t\t\t\t\tqEst += tempQEst\n"
    "\t\t\t\t\ttempRemainder = remainder - val2 * qEst\n"
    "\t\t\t\t\tif tempQEst != 1:\n"
    "\t\t\t\t\t\ttempQEst = int(tempQEst / 2)\n"
    "\t\t\t\tresultStr += str(qEst)\n"
    "\t\t\t\ttempRemainder *= 10\n"
    "\t\t\t\ttempRemainder += int(str(val1)[i])\n"
	"\t\t\t\tremainder = tempRemainder\n"
	"\t\t\tqEst = 0\n"
	"\t\t\ttempQEst = 5\n"
    "\t\t\twhile tempRemainder >= val2 or tempRemainder < 0:\n"
    "\t\t\t\tif tempRemainder < 0:\n"
    "\t\t\t\t\tqEst -= tempQEst\n"
    "\t\t\t\telif tempRemainder >= val2:\n"
    "\t\t\t\t\tqEst += tempQEst\n"
    "\t\t\t\ttempRemainder = remainder - val2 * qEst\n"
    "\t\t\t\tif tempQEst != 1:\n"
    "\t\t\t\t\ttempQEst = int(tempQEst / 2)\n"
	"\t\t\tresultStr += str(qEst)\n"
	"\t\t\treturn  int(resultStr)\n"
	"\treturn	int(val1 / val2)\n\n";*/
const string	bigIntMultiplyStr = "def bigIntMultiply(val1, val2):\n"
	"\tqEst = bigIntDivision(val1, val2)\n"
	"\tif val1 > val2 * qEst and val1 < val2 * (qEst + 1) or val1 == val2 * qEst:\n"
	"\t\treturn	True\n"
	"\treturn	False\n\n";
const string	encodeStr = "def encode(val):\n"
	"\tvals = []\n"
	"\twhile val >= 2 ** 32:\n"
	"\t\tvals.append(val % 2 ** 32)\n"
	"\t\tval //= 2 ** 32\n"
	"\tvals.append(val)\n"
	"\treturn	vals\n\n";
const string	randomIndicesDecodeStr = "def randomIndicesDecode(vals, s, e):\n"
	"\tresult = 0\n"
	"\tif s < len(vals) and e >= len(vals):\n"
	"\t\te = len(vals) - 1\n"
	"\telif s >= len(vals) and e >= len(vals):\n"
	"\t\treturn 0\n"
	"\tfor i in range(s, e + 1):\n"
	"\t\tresult += (2 ** 32) ** (i - s) * vals[i]\n"
	"\treturn	result\n\n";

int main(int argc, char* argv[])
{
	int	syntaxNum = 100;
	int	operand1MinDigitNum = 8, operand1MaxDigitNum = 100;
	int operand2MinDigitNum = 8, operand2MaxDigitNum = 100;
	char	opChar = '+';
	bool	flags[4] = {false, false, false, false}; // array by value, sameLength, unsigned, random indices
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
			return	1;
		}
		cout << "Array by array or Array by variable? (a/v) : ";
		cin >> flagChar;
		flags[0] = (flagChar == 'a') ? true : false;
		if(flags[0])
		{
			cout << "Make the first and second value the same length? (y/n) : ";
			cin >> flagChar;
			flags[1] = (flagChar == 'y') ? true : false;
		}
		cout << "Signed value? (y/n) : ";
		cin >> flagChar;
		flags[2] = (flagChar == 'y') ? true : false;
		cout << "Random range? (y/n) : ";
		cin >> flagChar;
		flags[3] = (flagChar == 'y') ? true : false;
		if(flags[0])
		{
			cout << "Input the first minimum digit : ";
			cin >> operand1MinDigitNum;
			cout << "Input the first maximum digit : ";
			cin >> operand1MaxDigitNum;
			if (!flags[1])
			{
				cout << "Input the second minimum digit : ";
				cin >> operand2MinDigitNum;
				cout << "Input the second maximum digit : ";
				cin >> operand2MaxDigitNum;
			}
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
		cout << "Usage : ./main {SyntaxNum} {-sl : Both value length are same.} {-u : unsigned value.}" << endl;
		cout << "{opChar} {operand1MinDigitNum} {operand1MaxDigitNum} {operand2MinDigitNum} {operand2MaxDigitNum}" << endl;
		return	1;
	}
	else if (argc >= 7)
	{
		int	i = 1;
		
		if(flagError(argv[i]))
			return	1;
		i += flag(argv[i], flags);
		if(flagError(argv[i]))
			return	1;
		i += flag(argv[i], flags);
		syntaxNum = atoi(argv[i++]);
		if(flagError(argv[i]) || charError(argv[i][0]))
			return	1;
		i += flag(argv[i], flags);
		if(flagError(argv[i]))
			return	1;
		i += flag(argv[i], flags);
		opChar = argv[i++][0];
		if(flagError(argv[i]))
			return	1;
		i += flag(argv[i], flags);
		if(flagError(argv[i]))
			return	1;
		i += flag(argv[i], flags);
		operand1MinDigitNum = atoi(argv[i++]);
		i += flag(argv[i], flags);
		if(flagError(argv[i]))
			return	1;
		i += flag(argv[i], flags);
		if(flagError(argv[i]))
			return	1;
		operand1MaxDigitNum = atoi(argv[i++]);
		i += flag(argv[i], flags);
		if(flagError(argv[i]))
			return	1;
		i += flag(argv[i], flags);
		if(flagError(argv[i]))
			return	1;
		operand2MinDigitNum = atoi(argv[i++]);
		i += flag(argv[i], flags);
		if(flagError(argv[i]))
			return	1;
		i += flag(argv[i], flags);
		if(flagError(argv[i]))
			return	1;
		operand2MaxDigitNum = atoi(argv[i++]);
		if(i < argc)
		{
			if(flagError(argv[i]))
				return	1;
			i += flag(argv[i], flags);
		}
		if(i < argc)
		{
			if(flagError(argv[i]))
				return	1;
			i += flag(argv[i], flags);
		}
	}

	ifstream iFilePy;
	ifstream iFileTxt;
	ofstream oFilePy;
	ofstream oFileTxt;
	string	fileAddr = "./"; // At Windows Using ".\\"

	int	index = 1;

	random_device	rd1, rd2, rd3, rd4;
	mt19937	gen1(rd1()), gen2(rd2()), gen3(rd3());
	uniform_int_distribution<int>	disRange1(operand1MinDigitNum, operand1MaxDigitNum), disRange2(operand2MinDigitNum, operand2MaxDigitNum);
	uniform_int_distribution<int> disVal(0, 9), disSign(0, 1);
	uniform_int_distribution<unsigned int>	disIndex(0U, -1);

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
		return	2;
	}
	oFilePy.open(fileAddr + ".py", ios_base::out);
	oFileTxt.open(fileAddr + ".txt", ios_base::out);
	if (!oFilePy.fail() && !oFileTxt.fail())
	{
		oFilePy.write(encodeStr.c_str(), encodeStr.size());
		oFilePy.write(randomIndicesDecodeStr.c_str(), randomIndicesDecodeStr.size());
		if(!flags[0])
			oFileTxt.write("v\n", 2);
		for (int i = 0; i < syntaxNum; i++)
		{
			string	pyStr = "print(";
			string	syntaxStr;
			string	tempStr;
			int	maxJ = disRange1(gen1);
			int	tempVal = disVal(gen2);
			bool	isNegative = false;

			if(flags[2])
				isNegative = disSign(gen3);
			if(opChar == '-')
				pyStr += "abs(";
			if (isNegative)
			{
				pyStr += '-';
				syntaxStr += '-';
			}
			if(flags[3])
			{
				pyStr += "randomIndicesDecode(encode(";
				syntaxStr += '(';
			}
			while (tempVal == 0)
				tempVal = disVal(gen2);
			for (int j = 0; j < maxJ; j++)
			{
				tempStr += tempVal + '0';
				tempVal = disVal(gen2);
			}
			pyStr += tempStr;
			syntaxStr += tempStr;
			if(flags[3])
			{
				pyStr += ')';
				size_t maxIndex = (unsigned long long)(log2(10.0) * tempStr.size() + 2) >> 5;

				uniform_int_distribution<unsigned int>	disIndex(0, maxIndex);
				size_t	s, e;

				s = disIndex(rd4);
				e = disIndex(rd4);
				if(s > e)
					swap(s, e);
				pyStr += ", " + uitous(s) + ", " + uitous(e) + ')';
				syntaxStr += ", " + uitous(s) + ", " + uitous(e) + ')';
			}
			pyStr += ' ';
			if (opChar == '/')
				pyStr += opChar;
			pyStr += opChar;
			pyStr += ' ';
			syntaxStr += ' ';
			syntaxStr += opChar; // * / % + -
			syntaxStr += ' ';
			if (flags[2])
				isNegative = disSign(gen3);
			if (flags[0])
			{
				tempStr.clear();				
				if (!flags[1])
					maxJ = disRange2(gen1);
				if (isNegative)
				{
					pyStr += '-';
					syntaxStr += '-';
				}
				if(flags[3])
				{
					pyStr += "randomIndicesDecode(encode(";
					syntaxStr += '(';
				}
				while (tempVal == 0)
					tempVal = disVal(gen2);
				for (int j = 0; j < maxJ; j++)
				{
					tempStr += tempVal + '0';
					tempVal = disVal(gen2);
				}
				pyStr += tempStr;
				syntaxStr += tempStr;
				if(flags[3])
				{
					pyStr += ')';

					size_t maxIndex = (unsigned long long)(log2(10.0) * tempStr.size() + 2) >> 5;

					uniform_int_distribution<unsigned int> disIndex(0, maxIndex);
					size_t s, e;

					s = disIndex(rd4);
					e = disIndex(rd4);
					if (s > e)
						swap(s, e);
					pyStr += ", " + uitous(s) + ", " + uitous(e) + ')';
					syntaxStr += ", " + uitous(s) + ", " + uitous(e) + ')';
				}
			}
			else
			{
				tempStr = uitous(disIndex(rd4));
				pyStr += tempStr;
				syntaxStr += tempStr;
			}
			if(flags[2])
				pyStr += ')';
			if(opChar == '-')
				pyStr += ')';
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