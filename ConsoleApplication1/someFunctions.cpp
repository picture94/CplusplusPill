#include "pch.h"
#include "someFunctions.h"
#include "class_Human.h"
caca

#define Matrix(current_height, current_width)  arr[ (current_width)+(current_height)*(width) ]

/********************************************************
*
* types and their spaces 
*
*********************************************************/
void typeNotes() {
	const double PI = 3.141592;
	bool b_Married = false;
	char c_MyGrade = 'A';
	unsigned short int usi_Age = 24;
	short int si_Weight = 70;
	int i_Days = 28;
	long l_BigNum = 99999999;
	float f_Pi = 3.1415;
	double d_BigFloat = 9.999999999;
	long double ld_Pi = 3.141592;
	auto a_Whatever = true;

	std::cout << "Min bool " << (std::numeric_limits<unsigned short int>::max)() << std::endl;
	std::cout << "Min bool " << sizeof(unsigned short int) << std::endl;
	std::string s_Question("I'm going to cast strings to ints");
	std::cout << (std::stoi("4a2e")) << std::endl; //String to int -> 4
	std::cout << (std::stod("4.55555558")) << std::endl; //String to int -> 4
	std::string s_Age = "";
	getline(std::cin, s_Age);
	printf("You age is: %c \n", s_Age);
}














/********************************************************
*
* Call a function by reference
*
*********************************************************/
void infinitySum(int &value) {
	std::cout << "Hello, please enter two integers: " << std::endl;
	int firstNumber, secondNumber;
	// This loops breaks when reads not an integer
	while (std::cin >> firstNumber >> secondNumber) {
		std::cout << "The sum is:  " << firstNumber + secondNumber << std::endl;
		// Short if: (condition) ? (if_true) : (if_false)
	}
	//The reference is used as an alias
	value = 999;
	return void();
}











/********************************************************
*
* Matrices and POINTERS Notes
*
*********************************************************/
void printMatrices_int(int* arr, int height, int width) {
	std::cout << std::endl << "{ ";
	for (int i = 0; i < height; i++) {
		for (int ii = 0; ii < width; ii++) {
			// std::cout << arr[i*height + ii] << ", ";
			std::cout << Matrix(i, ii) << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << " }" << std::endl;

	// Actually it does not have sense print tensors of more than 3 dim
	// Func: (int* arr, int* arr_descrip, int arr_descrip_size)
	// arr_descrip_size has to be a passed variable. 
	// It can't be calculated inside the function because of pointers
	//for (int i = 0; i < arr_descrip_size; i++) { // dimensions
	//	for (int ii = 0; ii < *(arr_descrip+i); ii++) { // dimension size
	//		std::cout << *(arr + ii) << ", ";
	//	}
	//	std::cout << std::endl;
	//}
}
void matricesNotes( int* arr ) { // *arr == arr[SIZE] == arr[]
	int Age = 24;
	int *pAge;
	pAge = &Age; // now pAge has the direction of Age
	std::cout << pAge << std::endl; // address
	std::cout << *pAge << std::endl; // variable

	// Value of the firts element 
	std::cout << *arr << std::endl; // 0x008EEF64
	// Memory dir. of the first element
	std::cout << arr << std::endl; // or arr[] // 4
	// Value of the second/following element
	std::cout << *(arr + 1) << std::endl; //5		*(arr + 1) == arr[1]							
	// Memory dir. of the second/following element
	std::cout << arr + 1 << std::endl; // 0x008EEF68
	// Edit array, so in main would change too
	arr[1] = 777;

	// MULTI-DIMENSIONAL
	// Iteration order: down-right
	int arr3D[2][3][4] = {
							{
								{1,2,3,4},
								{5,6,7,8},
								{1,2,3,4}
							},
							{
								{1,2,3,4},
								{5,6,7,8},
								{1,2,3,4}
							}
	};
	// Get the size of each dimension
	static const unsigned int arr3D_ndim = 3; // 'static const' is necessary
	unsigned int arr3D_size_dim[arr3D_ndim];
	float divisor = 1;
	for (int i = 0; i < arr3D_ndim; i++) {
		arr3D_size_dim[i] = (sizeof(arr3D[0][0]) / sizeof(arr3D[0][0][0])) / divisor; // **arr3D == arr3D[0][0]
		divisor = arr3D_size_dim[i] / divisor;
		std::cout << "Dimension " << i << " has size: " << arr3D_size_dim[i] << std::endl;
		//// What it would be
		//arr3D_size_dim[i] = ( sizeof(**arr3D) / sizeof(arr3D[0][0][0]) ) / divisor;
		//arr3D_size_dim[i] = ( sizeof(*arr3D) / sizeof(arr3D[0][0][0]) ) / divisor;
		//arr3D_size_dim[i] = ( sizeof(arr3D) / sizeof(arr3D[0][0][0]) ) / divisor;
	}
	// To print it it's necessary iterate over it
	for (int i = 0; i < 2; i++) {
		for (int ii = 0; ii < 3; ii++) {
			for (int iii = 0; iii < 4; iii++) {
				std::cout << arr3D[i][ii][iii];
			} std::cout << std::endl;
		} std::cout << std::endl;
	}

	// To sum up, better use pseudo-multidimensional arrays
	// Multi-dim. arrays are just an abstraction for programmers
	#define HEIGHT 7	
	#define WIDTH 2
	int arr_sequential[HEIGHT * WIDTH] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	printMatrices_int(arr_sequential, HEIGHT, WIDTH);
	return void();
}









/********************************************************
*
* Struct Notes
*
*********************************************************/
// enum needs to be defined out of the struct because of the scope
enum type { mamal, insect, plant };
struct Creature {
	//struct is identical to a class except for inheritance, etc...
	type e_type;
	char c_name[50];
	int i_age;
	Creature() : i_age(3), x(5) {}   
	Creature(int age, int j) : i_age(age), x(j) {
		strcpy_s(c_name, "Noa"); e_type = mamal;
	}
	~Creature() { std::cout << "Creature dead\n"; } // Lambda function constructor
	void printMe() {
		std::cout << i_age << std::endl;
		std::cout << e_type << std::endl;
		std::cout << c_name << std::endl;
		std::cout << x << std::endl;
	}
	// All variables are public by default
	private: 
		int x; // must be here, the last line idk"
};
// It can inherit from a struct
struct Dog : Creature {
	// Override the constructor
	// You also use this with structs
	Dog( const char _name[]) {
		strcpy_s(c_name, _name);
		i_age = 3;
		e_type = mamal;
	}
	~Dog() { std::cout << "Dog dead\n"; } 

	// Override 
	void printMe() {
		std::cout << i_age << std::endl;
		std::cout << e_type << std::endl;
		std::cout << c_name << std::endl;
	}
};
void printStruct(Creature *s_creature) {
	// (*moneyWasted_func).euros == moneyWasted_func->euros
	std::cout << (*s_creature).i_age << std::endl;
	std::cout << s_creature->e_type << std::endl;
	std::cout << s_creature->c_name << std::endl;
	// std::cout << s_creature->x << std::endl; // X is inaccesible, It's necessary a 'getter' func
}
void structNotes() {
	Creature s_creature;
	strcpy_s(s_creature.c_name, "Yako");
	s_creature.i_age = 15;
	s_creature.e_type = mamal;

	// 2 different way for doing the same
	s_creature.printMe();
	printStruct( &s_creature);

	Creature s_creature2(55, 77);
	s_creature2.printMe();

	Dog myDog("Chispi");
	myDog.printMe();
}









/********************************************************
*
* Vector
*
*********************************************************/
void vectorNotes() {
	std::vector<int> vec_RandNums(1);
	vec_RandNums[0] = 42;
	vec_RandNums.push_back(7);
	std::cout << "Last index number: " << vec_RandNums[vec_RandNums.size() - 1] << std::endl;
	std::vector<int> vec_myVec(9);
	//std::iota(std::begin(vec_myVec), std::end(vec_myVec), 0);
	std::srand(time(NULL)); //seed to give rand() randomness
	std::generate(vec_myVec.begin(), vec_myVec.end(), []() { return std::rand() % 100; } );
	std::random_shuffle(vec_myVec.begin(), vec_myVec.end(), [](int max) { return std::rand() % max; });
	std::sort(vec_myVec.begin(), vec_myVec.end(), [](int x, int y) { return (x < y); });
	// There are: copy_if, for_each

	// To iterate over a vector, 2 ways...
	//for (int i = 0; i < vec_myvec.size(); i++)
	//	std::cout << vec_myvec[i] << std::endl;
	for (auto y : vec_myVec) std::cout << y << std::endl;
}








/********************************************************
*
* Deduction Types. Templates & auto type
*
*********************************************************/
// https://davidcapello.com/blog/cpp/lambda-en-cpp/
// Function template prototype
template<typename T, typename U>
int whatever(T t, U u);

void deductionNotes() {
	int pipi, caca;
	pipi = caca = 45;
	auto copy = caca;
	whatever<int>(copy, pipi); // or whatever(copy, pipi);
	
	// template specialization
	// template <> 
	// class mycontainer <char> { ... };
	// 'class' & 'typename' are equivalent
}

template<typename T, typename U>
int whatever(T t, U u) {
	std::cout << t +  u << std::endl;
	return 0;
};









/********************************************************
*
* Classes
*
*********************************************************/
void classesNotes() {
	// Could be understood as a struct
	class Box {
		public:
			double volume;
	} box1;

	Person p1;
	// Functions of the father can be used in sons
	std::cout << p1 << std::endl;
	std::cout << p1.getNumCreatures() << std::endl;
	p1.speak();

	Human h1; // We can instantiate fathers if not abstract
	h1.speak(); // Polimorphism
}








/********************************************************
*
* Write & read files
*
*********************************************************/
void ioFilesNotes() {
	std::ofstream writeToFile;
	std::ifstream readFromFile;
	std::string txtToWrite = "";
	std::string txtFromFile = "";

	// We open the file by providing a name and then either
	// ios::app : Append to the end of the file
	// ios::trunc : If the exists delete content
	// ios::in : Open file for reading
	// ios::out : Open file for writing
	// ios::ate : Open writing and move to the end of the file
	writeToFile.open("test.txt", std::ios_base::out |
		std::ios_base::trunc);

	if (writeToFile.is_open()) {
		// You can write with the stream insertion operator
		writeToFile << "Beginning of File\n";

		// You can write data in a string
		std::cout << "Enter data to write : ";
		getline(std::cin, txtToWrite);
		writeToFile << txtToWrite;

		// Close the file 
		writeToFile.close();
	}
	// Open the file for reading
	readFromFile.open("test.txt", std::ios_base::in);

	if (readFromFile.is_open()) {

		// Read text from file
		while (readFromFile.good()) {
			getline(readFromFile, txtFromFile);

			// Print text from file
			std::cout << txtFromFile << "\n";
		}
		readFromFile.close();
	}
}













/********************************************************
*
* Functions as modules (advanced)
*
*********************************************************/
// An ordinary function, just to manage it
int multx2( int num ) {
	return (num*2);
}
// A function as a parameter
int multx4( std::function<int(int)> funcx2, int num ) { // std::function<returType(parametersType)> name
	return ( funcx2(num) * 2 );
}
void functionNotes() {
	// A function ca be stored in a 'auto' variable
	auto function1 = multx2;
	std::cout << function1(5) << std::endl;
	// A function can be used without parameters
	std::cout << multx4(function1, 5) << std::endl;
	// Could exist an aggregations of functions
	std::vector< std::function<int(int)> > vec_functions(2);
	vec_functions[0] = multx2;
	std::cout << vec_functions[0](5) << std::endl;
	//vec_functions[1] = multx4; // err: vec_functions espects only this(function<int(int)>) func-type

	// So, Could exist a function that returns a function and needs as param
	// a vector of functions and a function... and so on
}