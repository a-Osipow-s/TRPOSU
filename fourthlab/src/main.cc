#include <iostream>
#include <string.h>
using namespace std;

class String{

	friend void set();
	friend void print();
	friend void deletePointInLine();

	public:
		String(string str){
			strLine = str;	
		}
		~String(){
			cout << "destructor"<< endl;
		}
		void set();
		void print();
		void deletePointInLine();
		
	private:
		string strLine;
		
	String& operator += (String s2)
    {
        strLine += s2.strLine;
        return *this;
    }
};

void String::set() {
	cout << "Input string: " << endl;
	cin >> this->strLine;
}

void String::print() {
	cout << this->strLine << endl;
}

void String::deletePointInLine() {
	if(this->strLine.size()>=5)
		for(int i = 0;i<this->strLine.size();i++)
			if(this->strLine[i] == '.')
				this->strLine.erase(i,1);
}

int main()
{
	String *str = new String("Anton123.2wqe.trt");
	str->print();
	str->deletePointInLine();
	str->print();
	delete str;
	return 0;
}