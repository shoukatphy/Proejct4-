/////////////////////////////
//Estmating the upper limit//
// of e-neutrino mass////////
/////////////////////////////

#include "TKDE.h"
#include<iostream>
using namespace std;

int NeuMass(const int nmEvents){

	//open data file
        ifstream dataFile("myFile.txt");

	if(!dataFile.is_open()){
	cout<<"Error opening the data file"<<endl;
	}
      
	//store data in a vector
	vector<double>data(nmEvents);

	for(int r=0; r<nmEvents; r++){
	
	dataFile>>data[r];

	}
       //dataFile.close();
   
	//plot the distribution of the data
	
	auto *hs = new TH1D("hs","e-Neu Mass Upper Limit (data)",5000, -8., 10.);

	for(int i=0; i<nmEvents; i++){
	
		hs->Fill(data[i]);
	}
    
	//creat canvas 
	auto *c = new TCanvas();


	//scale histogram and plot the data
	 // scale histogram
         hs->Scale(0.3/hs->Integral(),"width" );
         hs->SetStats(false);
         //hs->SetTitle("e-Neutrino Mass (data) and a fit; Mass(eV) ; Events(Probability)");
         hs->SetMarkerStyle(20);
         hs->SetMarkerColor(3);
	 hs->SetMarkerSize(1);
         hs->Draw();
	        
	// create TKDE class
	double rho = 1.0; //default value
        TKDE * kde = new TKDE(nmEvents, &data[0], -8., 10., "", rho);
        hs->GetXaxis()->SetTitle("Mass(eV)");
        hs->GetYaxis()->SetTitle("Events(Normalized)");
        kde->Draw("same");   
        //as fit is  gaussian, so the maximization of it will give x=mean. Therefore, withouting applying a minimizer, I just get the mean value of x 

        double mass_estimated = kde->GetMean();

cout<<"The estimated upper limit of the election neutrino mass is: "<<mass_estimated<<endl;
         TLegend * leg = new TLegend(0.1 ,0.7,0.4, 0.9);
         
          leg->AddEntry(kde->GetDrawnFunction(),"TKDE fit Func");
          leg->AddEntry(hs, "Data points");
          leg->Draw();
        c->Update();

	c->SaveAs("NeuMass.pdf");
	return 0;
}//end
