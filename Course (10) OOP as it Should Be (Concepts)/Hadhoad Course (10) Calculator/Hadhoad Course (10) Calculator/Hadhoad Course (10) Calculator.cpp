#include <iostream>
#include <string>
#include <format>

using namespace std;

class clsCalculator
{
private: 
	float _value = 0;
	string _textForFinalOperation = "";


	void SetFinalOperationText(std::string Operation, float number = 0)
	{
		if (Operation == "Clear")
			_textForFinalOperation = "Result after clear is : 0";
		else
			// {:.2f} تعني رقمين بعد العلامة العشرية تماماً مثل %.2f
			_textForFinalOperation = std::format("Result after {} {:.2f} is : {:.2f}",
				Operation, number, _value);
	}
public:
	void Add(float number)
	{
		_value += number;
		SetFinalOperationText("adding", number);
	}

	void Subtract(float number)
	{
		_value -= number;
		SetFinalOperationText("subtracting", number);
	}

	void Divide(float number)
	{
		if(number == 0)
		{
			cout << "You can't divide by zero" << endl;
			return;
		}
		_value /= number;
		SetFinalOperationText("dividing", number);

	}

	void Multiply(float number)
	{
		_value *= number;
		SetFinalOperationText("Multipling", number);
	}

	void Clear()
	{
		_value = 0;
		SetFinalOperationText("Clear");

	}

	float GetFinalResult()
	{
		return _value;
	}

	void PrintResult()
	{
		cout << _textForFinalOperation << endl;
	}

};

class clsCalculatorDoctor
{
private:
	float _Result = 0;
	float _LastNumber = 0;
	string _LastOperation = "Clear";
	float _PreviousResult = 0;
	bool _IsZero(float Number)
	{
		return (Number == 0);
	}

public:
	void Add(float Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Adding";
		_Result += Number;
	}

	void Subtract(float Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Subtracting";
		_Result -= Number;
	}

	void Divide(float Number)
	{
		_LastNumber = Number;

		if (_IsZero(Number))
		{
			Number = 1;
		}

		_PreviousResult = _Result;
		_LastOperation = "Dividing";
		_Result /= Number;
	}

	void Multiply(float Number)
	{
		_LastNumber = Number;
		_LastOperation = "Multiplying";
		_PreviousResult = _Result;
		_Result *= Number;
	}

	float GetFinalResults()
	{
		return _Result;
	}

	void Clear()
	{
		_LastNumber = 0;
		_PreviousResult = 0;
		_LastOperation = "Clear";
		_Result = 0;
	}

	void CancelLastOperation()
	{
		_LastNumber = 0;
		_LastOperation = "Cancelling Last Operation";
		_Result = _PreviousResult;
	}

	void PrintResult()
	{
		cout << "Result ";
		cout << "After " << _LastOperation << " " <<
		_LastNumber << " is: " << _Result << "\n";
	}
};

void MyCalculatorCall()
{
	clsCalculator Calculator;
	Calculator.Clear();

	Calculator.Add(10);
	Calculator.PrintResult();

	Calculator.Add(100);
	Calculator.PrintResult();

	Calculator.Subtract(100);
	Calculator.PrintResult();

	Calculator.Clear();
	Calculator.PrintResult();
}

void DoctorCalculatorCall()
{
	clsCalculatorDoctor Calculator;
	Calculator.Clear();

	Calculator.Add(10);
	Calculator.PrintResult();

	Calculator.Add(100);
	Calculator.PrintResult();

	Calculator.Subtract(20);
	Calculator.PrintResult();

	Calculator.Divide(0);
	Calculator.PrintResult();

	Calculator.Divide(2);
	Calculator.PrintResult();

	Calculator.Multiply(3);
	Calculator.PrintResult();

	Calculator.CancelLastOperation();
	Calculator.PrintResult();

	Calculator.Clear();
	Calculator.PrintResult();

	system("pause>0");
}

int main()
{
	MyCalculatorCall();

	DoctorCalculatorCall();
}

