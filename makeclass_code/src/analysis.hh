#include "TGraphAsymmErrors.h"
#include "TEfficiency.h"
#include "TLatex.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TROOT.h"
#include "THStack.h"
#include "TString.h"
#include "TH1.h"
#include "TH2F.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "RooRealVar.h"
#include "RooExponential.h"
#include "RooPlot.h"
#include "RooGaussian.h"
#include "RooPolynomial.h"
#include "RooAddPdf.h"
#include "RooAbsData.h"
#include "RooAbsRealLValue.h"
#include "RooAbsPdf.h"
#include "RooMinuit.h"
#include "RooCategory.h"
#include "RooDataSet.h"
#include "RooArgSet.h"
#include "RooDataHist.h"
#include "RooNLLVar.h"
#include "RooSimultaneous.h"
#include "RooExponential.h"
#include "RooGlobalFunc.h"
#include "RooCBShape.h"
#include "RooFormula.h"
#include "RooRandom.h"
#include "RooFitResult.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "vector"
#include "../aux/Friends.hh"
#include "header.hh"
#include <cmath>
using namespace std;
using namespace RooFit;
using std::vector;
#include <sys/stat.h>

Friends *p;

auto mass = 2;
auto mass_window_down = mass*0.95;
auto mass_window_up = mass*1.05;

TH1D* muonSV_mass_cat1 = new TH1D("muonSV_mass_cat1","muonSV_mass_cat1",50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_cat2 = new TH1D("muonSV_mass_cat2","muonSV_mass_cat2",50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_cat3 = new TH1D("muonSV_mass_cat3","muonSV_mass_cat3",50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_cat4 = new TH1D("muonSV_mass_cat4","muonSV_mass_cat4",50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_cat5 = new TH1D("muonSV_mass_cat5","muonSV_mass_cat5",50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_cat6 = new TH1D("muonSV_mass_cat6","muonSV_mass_cat6",50, mass_window_down, mass_window_up);
TH1D* muonSV_gen_matched_mass_cat1 = new TH1D("muonSV_gen_matched_mass_cat1","muonSV_gen_matched_mass_cat1",50, mass_window_down, mass_window_up);
TH1D* muonSV_gen_matched_mass_cat2 = new TH1D("muonSV_gen_matched_mass_cat2","muonSV_gen_matched_mass_cat2",50, mass_window_down, mass_window_up);
TH1D* muonSV_gen_matched_mass_cat3 = new TH1D("muonSV_gen_matched_mass_cat3","muonSV_gen_matched_mass_cat3",50, mass_window_down, mass_window_up);
TH1D* muonSV_gen_matched_mass_cat4 = new TH1D("muonSV_gen_matched_mass_cat4","muonSV_gen_matched_mass_cat4",50, mass_window_down, mass_window_up);
TH1D* muonSV_gen_matched_mass_cat5 = new TH1D("muonSV_gen_matched_mass_cat5","muonSV_gen_matched_mass_cat5",50, mass_window_down, mass_window_up);
TH1D* muonSV_gen_matched_mass_cat6 = new TH1D("muonSV_gen_matched_mass_cat6","muonSV_gen_matched_mass_cat6",50, mass_window_down, mass_window_up);

TH1D* muonSV_mass_min_chi2_categorised = new TH1D("muonSV_mass_min_chi2_categorised", "muonSV_mass_min_chi2_categorised", 100, 0, 22);
TH1D* muonSV_mass_min_chi2 = new TH1D("muonSV_mass_min_chi2", "muonSV_mass_min_chi2", 100, 0, 22);
TH1D* nmuonSV_plot = new TH1D("nmuonSV_plot", "nmuonSV_plot", 11, -0.5, 10.5);
TH1D* nmuonSV_multivertices_plot = new TH1D("nmuonSV_multivertices_plot", "nmuonSV_multivertices_plot", 11, -0.5, 10.5);

TH1D* muonSV_mass_min_chi2_multivertices_cat = new TH1D("muonSV_mass_min_chi2_multivertices_cat", "muonSV_mass_min_chi2_multivertices_cat", 100, 0, 22);
TH1D* muonSV_mass_min_chi2_singlevertex_cat = new TH1D("muonSV_mass_min_chi2_singlevertex_cat", "muonSV_mass_min_chi2_singlevertex_cat", 100, 0, 22);

TH1D* muonSV_mass_multivertices_cat1 = new TH1D("muonSV_mass_multivertices_cat1", "muonSV_mass_multivertices_cat1", 100, 0, 22);
TH1D* muonSV_mass_multivertices_mass_window_cat1 = new TH1D("muonSV_mass_multivertices_mass_window_cat1", "muonSV_mass_multivertices_mass_window_cat1", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_multivertices_cat2 = new TH1D("muonSV_mass_multivertices_cat2", "muonSV_mass_multivertices_cat2", 100, 0, 22);
TH1D* muonSV_mass_multivertices_mass_window_cat2 = new TH1D("muonSV_mass_multivertices_mass_window_cat2", "muonSV_mass_multivertices_mass_window_cat2", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_multivertices_cat3 = new TH1D("muonSV_mass_multivertices_cat3", "muonSV_mass_multivertices_cat3", 100, 0, 22);
TH1D* muonSV_mass_multivertices_mass_window_cat3 = new TH1D("muonSV_mass_multivertices_mass_window_cat3", "muonSV_mass_multivertices_mass_window_cat3", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_multivertices_cat4 = new TH1D("muonSV_mass_multivertices_cat4", "muonSV_mass_multivertices_cat4", 100, 0, 22);
TH1D* muonSV_mass_multivertices_mass_window_cat4 = new TH1D("muonSV_mass_multivertices_mass_window_cat4", "muonSV_mass_multivertices_mass_window_cat4", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_multivertices_cat5 = new TH1D("muonSV_mass_multivertices_cat5", "muonSV_mass_multivertices_cat5", 100, 0, 22);
TH1D* muonSV_mass_multivertices_mass_window_cat5 = new TH1D("muonSV_mass_multivertices_mass_window_cat5", "muonSV_mass_multivertices_mass_window_cat5", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_multivertices_cat6 = new TH1D("muonSV_mass_multivertices_cat6", "muonSV_mass_multivertices_cat6", 100, 0, 22);
TH1D* muonSV_mass_multivertices_mass_window_cat6 = new TH1D("muonSV_mass_multivertices_mass_window_cat6", "muonSV_mass_multivertices_mass_window_cat6", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_multivertices_cat1_new = new TH1D("muonSV_mass_multivertices_cat1_new", "muonSV_mass_multivertices_cat1_new", 100, 0, 22);
TH1D* muonSV_mass_multivertices_mass_window_cat1_new = new TH1D("muonSV_mass_multivertices_mass_window_cat1_new", "muonSV_mass_multivertices_mass_window_cat1_new", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_multivertices_cat2_new = new TH1D("muonSV_mass_multivertices_cat2_new", "muonSV_mass_multivertices_cat2_new", 100, 0, 22);
TH1D* muonSV_mass_multivertices_mass_window_cat2_new = new TH1D("muonSV_mass_multivertices_mass_window_cat2_new", "muonSV_mass_multivertices_mass_window_cat2_new", 50, mass_window_down, mass_window_up);

TH1D* muonSV_mass_singlevertex_cat1 = new TH1D("muonSV_mass_singlevertex_cat1", "muonSV_mass_singlevertex_cat1", 100, 0, 22);
TH1D* muonSV_mass_singlevertex_mass_window_cat1 = new TH1D("muonSV_mass_singlevertex_mass_window_cat1", "muonSV_mass_singlevertex_mass_window_cat1", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_singlevertex_cat2 = new TH1D("muonSV_mass_singlevertex_cat2", "muonSV_mass_singlevertex_cat2", 100, 0, 22);
TH1D* muonSV_mass_singlevertex_mass_window_cat2 = new TH1D("muonSV_mass_singlevertex_mass_window_cat2", "muonSV_mass_singlevertex_mass_window_cat2", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_singlevertex_cat3 = new TH1D("muonSV_mass_singlevertex_cat3", "muonSV_mass_singlevertex_cat3", 100, 0, 22);
TH1D* muonSV_mass_singlevertex_mass_window_cat3 = new TH1D("muonSV_mass_singlevertex_mass_window_cat3", "muonSV_mass_singlevertex_mass_window_cat3", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_singlevertex_cat4 = new TH1D("muonSV_mass_singlevertex_cat4", "muonSV_mass_singlevertex_cat4", 100, 0, 22);
TH1D* muonSV_mass_singlevertex_mass_window_cat4 = new TH1D("muonSV_mass_singlevertex_mass_window_cat4", "muonSV_mass_singlevertex_mass_window_cat4", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_singlevertex_cat5 = new TH1D("muonSV_mass_singlevertex_cat5", "muonSV_mass_singlevertex_cat5", 100, 0, 22);
TH1D* muonSV_mass_singlevertex_mass_window_cat5 = new TH1D("muonSV_mass_singlevertex_mass_window_cat5", "muonSV_mass_singlevertex_mass_window_cat5", 50, mass_window_down, mass_window_up);
TH1D* muonSV_mass_singlevertex_cat6 = new TH1D("muonSV_mass_singlevertex_cat6", "muonSV_mass_singlevertex_cat6", 100, 0, 22);
TH1D* muonSV_mass_singlevertex_mass_window_cat6 = new TH1D("muonSV_mass_singlevertex_mass_window_cat6", "muonSV_mass_singlevertex_mass_window_cat6", 50, mass_window_down, mass_window_up);




void get_event(int i) {
  if ( p->LoadTree(i) < 0) { 
    cout<<"\nProblem in LoadTree."
        <<"\nEntry: "<<i<<endl;
    exit(0);
  }
  p->fChain->GetEntry(i);
}

double del_phi(Double_t phi1, Double_t phi2) {
	Double_t pi = TMath::Pi();
	Double_t d_phi = phi1 - phi2;
	while (d_phi >= pi) d_phi -= 2 * pi;
	while (d_phi < -pi) d_phi += 2 * pi;
	return d_phi;
}


