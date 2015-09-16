#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int genRand(int min, int max){

	int range = max - min + 1;
	return( rand() % range + min);

}


void storeWords(fstream& myFile, int num,int min, int max, string& alphabet){
	int ranNum;
	string word = "";
	for(int i = 0; i < num; ++i){
		ranNum = genRand(min,max);
		for(int x = 0; x < ranNum; ++x){
			word += alphabet[rand() % 62];
		}
		myFile << (word + "\n");
		word = "";
	}
}

void characterFill(string& holder){
	for(char i = 'a'; i <= 'z'; ++i){
		holder += i;
	}
	for(char i = 'A'; i <= 'Z'; ++i){
		holder += i;
	}
	for(int x = 0; x < 10; ++x){
		holder += to_string(x);
	}
}
int main(){
	string text;
	fstream myfile;

	//does the rest of this program work? I don't see it getting called in the main so im not sure.
	//does this file have anything in it?
	myfile.open("GenWords.txt", fstream::out | fstream::app);

	while(!myfile.eof()){
	myfile >> text;
	cout << text << endl;
	}



	myfile.close();
	system("pause");
}