#include <iostream>
using namespace std;

template <typename T>
class Array {

	friend void arrayFill();
	friend void arrayInfo();
	
	private:
		T *arr;
		int sizeArray;
		
	public:
		Array(int size) {
			sizeArray = size;
			arr = new T[sizeArray];
		}
		
		~Array(){
			cout << "\ndestructor worked!" << endl;
		}
		
		void arrayFill(){
			int variable;
			cout << "Введите данные для заполнения массива:" << endl;
			for(int i=0;i<this->sizeArray;i++){
				cout << i << " : ";
				cin >> variable;
				if(i != 0)
					this->arr[i] = this->arr[i-1] + variable;
				else
					this->arr[i] = variable;
			}
		}
		
		void arrayInfo(){
			for(int j=0;j<this->sizeArray;j++) 
				cout << "arr[" << j << "]=" << this->arr[j] << " ";
		}
};

int main()
{
	Array<int> *arr = new Array<int>(5);
	arr->arrayFill();
	arr->arrayInfo();
	delete arr;
	return 0;
}