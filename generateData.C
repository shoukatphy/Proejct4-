/////////////////////
//data simulation////
/////////////////////
#include<iostream>
using namespace std;

int nmEvents=1000;

void generateData(int nmEvents){
	
         //creat a file to save data
	 ofstream dataFile;
         dataFile.open("myFile.txt");

	//for random num generation
	   TTimeStamp timeStamp; 
	 double seed = timeStamp.GetNanoSec();//get nanoSec as seed.

	TRandom3 GenerateRndm(seed);//randomnumber generator 
	double ms = 0.8;//upper limit on neutrino mass
	double sigma = 1.5;
	double data;
	
	for(int i=0; i<nmEvents;  i++){
         data = GenerateRndm.Gaus(ms, sigma);    
	cout<<data<<endl;
	dataFile<<data<<endl;
	}

    dataFile.close();

 
 cout<<"All is well"<<endl;
}
