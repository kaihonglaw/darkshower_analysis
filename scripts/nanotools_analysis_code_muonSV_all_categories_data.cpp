#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "TCanvas.h"
#include "TH1D.h"
#include "TLatex.h"
#include "TStyle.h"
#include <iostream>
#include <cmath>

using namespace ROOT::VecOps;

TH1D* background_weighting(TH1D* hist1, TH1D* hist2, TH1D* hist3, TH1D* hist4, TH1D* hist5, TH1D* hist6, TH1D* hist7, TH1D* hist8, TH1D* hist9, TH1D* hist10, TH1D* hist11, TH1D* hist12) {
   Double_t no_of_entries_original = 80000.0;
   Double_t no_of_entries1_original = 4159734.0;
   Double_t no_of_entries2_original = 30100864.0;
   Double_t no_of_entries3_original = 29327371.0;
   Double_t no_of_entries4_original = 19814379.0;
   Double_t no_of_entries5_original = 24759617.0;
   Double_t no_of_entries6_original = 20454047.0;
   Double_t no_of_entries7_original = 35664362.0;
   Double_t no_of_entries8_original = 28899863.0;
   Double_t no_of_entries9_original = 19939641.0;
   Double_t no_of_entries10_original = 16125220.0;
   Double_t no_of_entries11_original = 16464596.0;
   Double_t no_of_entries12_original = 10377764.0;

   Double_t branching_ratio = 0.01;
   Double_t xs = 43.9;

   Double_t xs1 = 2799000.0;
   Double_t xs2 = 2526000.0;
   Double_t xs3 = 1362000.0;
   Double_t xs4 = 376600.0;
   Double_t xs5 = 88930.0;
   Double_t xs6 = 21230.0;

   Double_t xs7 = 7055.0;
   Double_t xs8 = 619.3;
   Double_t xs9 = 59.24;
   Double_t xs10 = 18.21;
   Double_t xs11 = 3.275;
   Double_t xs12 = 1.078;

   //Double_t lumi = 33.6*1000;
   Double_t lumi = 0.96*1000;

   hist1->Scale(lumi*xs1/no_of_entries1_original);
   hist2->Scale(lumi*xs2/no_of_entries2_original);
   hist3->Scale(lumi*xs3/no_of_entries3_original);
   hist4->Scale(lumi*xs4/no_of_entries4_original);
   hist5->Scale(lumi*xs5/no_of_entries5_original);
   hist6->Scale(lumi*xs6/no_of_entries6_original);
   hist7->Scale(lumi*xs7/no_of_entries7_original);
   hist8->Scale(lumi*xs8/no_of_entries8_original);
   hist9->Scale(lumi*xs9/no_of_entries9_original);
   hist10->Scale(lumi*xs10/no_of_entries10_original);
   hist11->Scale(lumi*xs11/no_of_entries11_original);
   hist12->Scale(lumi*xs12/no_of_entries12_original);
 
   hist1->Add(hist2);
   hist1->Add(hist3);
   hist1->Add(hist4);
   hist1->Add(hist5);
   hist1->Add(hist6);
   hist1->Add(hist7);
   hist1->Add(hist8);
   hist1->Add(hist9);
   hist1->Add(hist10);
   hist1->Add(hist11);
   hist1->Add(hist12);
 

   return hist1;

}


void nano_analysis() {

   string mass = "2";
   string lifetime = "500";


   TFile *f = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_single_multi_vertex_categorisation/darkshower_analysis/makeclass_code/output/m_%s/HiddenValley_vector_m_%s_ctau_%s_xiO_1_xiL_1_privateMC_11X_NANOAODSIM_v1p0_generationSync_m%s_ctau%s.root", mass.c_str(), mass.c_str(), lifetime.c_str(), mass.c_str(), lifetime.c_str()));
   TFile *f1 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-15to20_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f2 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-20to30_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v4_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f3 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-30to50_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f4 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-50to80_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f5 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-80to120_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f5_ext = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-80to120_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f6 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-120to170_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f6_ext = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-120to170_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f7 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f8 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f8_ext = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext3-v1_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f9 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f9_ext = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f10 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f11 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-800to1000_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext3-v2_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f12 = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_%s/QCD_Pt-1000toInf_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));

   
   TFile *f_dataB = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_single_multi_vertex_categorisation/darkshower_analysis/makeclass_code/output/m_%s/ParkingBPH1_Run2018B-05May2019-v2_MINIAOD_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));
   TFile *f_dataC = new TFile(Form("/vols/cms/khl216/darkshower_analysis_muonSV_single_multi_vertex_categorisation/darkshower_analysis/makeclass_code/output/m_%s/ParkingBPH1_Run2018C-05May2019-v1_MINIAOD_v1p0_generationSync_m%s_ctau10.root", mass.c_str(), mass.c_str()));  


   TH1D *h_muonSV_mass_min_chi2_categorised_dataB = (TH1D*) f_dataB->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi2_dataB = (TH1D*) f_dataB->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV_dataB = (TH1D*) f_dataB->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices_dataB = (TH1D*) f_dataB->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices_dataB = (TH1D*) f_dataB->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex_dataB = (TH1D*) f_dataB->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new_dataB = (TH1D*) f_dataB->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new_dataB = (TH1D*) f_dataB->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat1_dataB = (TH1D*) f_dataB->Get("muonSV_mass_multivertices_mass_window_cat1");
   TH1D *h_muonSV_mass_multivertices_cat2_dataB = (TH1D*) f_dataB->Get("muonSV_mass_multivertices_mass_window_cat2");
   TH1D *h_muonSV_mass_multivertices_cat3_dataB = (TH1D*) f_dataB->Get("muonSV_mass_multivertices_mass_window_cat3");
   TH1D *h_muonSV_mass_multivertices_cat4_dataB = (TH1D*) f_dataB->Get("muonSV_mass_multivertices_mass_window_cat4");
   TH1D *h_muonSV_mass_multivertices_cat5_dataB = (TH1D*) f_dataB->Get("muonSV_mass_multivertices_mass_window_cat5");
   TH1D *h_muonSV_mass_multivertices_cat6_dataB = (TH1D*) f_dataB->Get("muonSV_mass_multivertices_mass_window_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat1_dataB = (TH1D*) f_dataB->Get("muonSV_mass_singlevertex_mass_window_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat2_dataB = (TH1D*) f_dataB->Get("muonSV_mass_singlevertex_mass_window_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat3_dataB = (TH1D*) f_dataB->Get("muonSV_mass_singlevertex_mass_window_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat4_dataB = (TH1D*) f_dataB->Get("muonSV_mass_singlevertex_mass_window_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat5_dataB = (TH1D*) f_dataB->Get("muonSV_mass_singlevertex_mass_window_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat6_dataB = (TH1D*) f_dataB->Get("muonSV_mass_singlevertex_mass_window_cat6");

   TH1D *h_muonSV_mass_min_chi2_categorised_dataC = (TH1D*) f_dataC->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi2_dataC = (TH1D*) f_dataC->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV_dataC = (TH1D*) f_dataC->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices_dataC = (TH1D*) f_dataC->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices_dataC = (TH1D*) f_dataC->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex_dataC = (TH1D*) f_dataC->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new_dataC = (TH1D*) f_dataC->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new_dataC = (TH1D*) f_dataC->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat1_dataC = (TH1D*) f_dataC->Get("muonSV_mass_multivertices_mass_window_cat1");
   TH1D *h_muonSV_mass_multivertices_cat2_dataC = (TH1D*) f_dataC->Get("muonSV_mass_multivertices_mass_window_cat2");
   TH1D *h_muonSV_mass_multivertices_cat3_dataC = (TH1D*) f_dataC->Get("muonSV_mass_multivertices_mass_window_cat3");
   TH1D *h_muonSV_mass_multivertices_cat4_dataC = (TH1D*) f_dataC->Get("muonSV_mass_multivertices_mass_window_cat4");
   TH1D *h_muonSV_mass_multivertices_cat5_dataC = (TH1D*) f_dataC->Get("muonSV_mass_multivertices_mass_window_cat5");
   TH1D *h_muonSV_mass_multivertices_cat6_dataC = (TH1D*) f_dataC->Get("muonSV_mass_multivertices_mass_window_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat1_dataC = (TH1D*) f_dataC->Get("muonSV_mass_singlevertex_mass_window_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat2_dataC = (TH1D*) f_dataC->Get("muonSV_mass_singlevertex_mass_window_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat3_dataC = (TH1D*) f_dataC->Get("muonSV_mass_singlevertex_mass_window_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat4_dataC = (TH1D*) f_dataC->Get("muonSV_mass_singlevertex_mass_window_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat5_dataC = (TH1D*) f_dataC->Get("muonSV_mass_singlevertex_mass_window_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat6_dataC = (TH1D*) f_dataC->Get("muonSV_mass_singlevertex_mass_window_cat6");

   //Get total of era B and C
   
   h_muonSV_mass_min_chi2_categorised_dataB->Add(h_muonSV_mass_min_chi2_categorised_dataC);
   h_muonSV_mass_min_chi2_dataB->Add(h_muonSV_mass_min_chi2_dataC);
   h_nmuonSV_dataB->Add(h_nmuonSV_dataC);
   h_nmuonSV_multivertices_dataB->Add(h_nmuonSV_multivertices_dataC);
   h_muonSV_mass_min_chi2_multivertices_dataB->Add(h_muonSV_mass_min_chi2_multivertices_dataC);
   h_muonSV_mass_min_chi2_singlevertex_dataB->Add(h_muonSV_mass_min_chi2_singlevertex_dataC);
   h_muonSV_mass_multivertices_cat1_new_dataB->Add(h_muonSV_mass_multivertices_cat1_new_dataC);
   h_muonSV_mass_multivertices_cat2_new_dataB->Add(h_muonSV_mass_multivertices_cat2_new_dataC);
   h_muonSV_mass_multivertices_cat1_dataB->Add(h_muonSV_mass_multivertices_cat1_dataC);
   h_muonSV_mass_multivertices_cat2_dataB->Add(h_muonSV_mass_multivertices_cat2_dataC);
   h_muonSV_mass_multivertices_cat3_dataB->Add(h_muonSV_mass_multivertices_cat3_dataC);
   h_muonSV_mass_multivertices_cat4_dataB->Add(h_muonSV_mass_multivertices_cat4_dataC);
   h_muonSV_mass_multivertices_cat5_dataB->Add(h_muonSV_mass_multivertices_cat5_dataC);
   h_muonSV_mass_multivertices_cat6_dataB->Add(h_muonSV_mass_multivertices_cat6_dataC);
   h_muonSV_mass_singlevertex_cat1_dataB->Add(h_muonSV_mass_singlevertex_cat1_dataC);
   h_muonSV_mass_singlevertex_cat2_dataB->Add(h_muonSV_mass_singlevertex_cat2_dataC);
   h_muonSV_mass_singlevertex_cat3_dataB->Add(h_muonSV_mass_singlevertex_cat3_dataC);
   h_muonSV_mass_singlevertex_cat4_dataB->Add(h_muonSV_mass_singlevertex_cat4_dataC);
   h_muonSV_mass_singlevertex_cat5_dataB->Add(h_muonSV_mass_singlevertex_cat5_dataC);
   h_muonSV_mass_singlevertex_cat6_dataB->Add(h_muonSV_mass_singlevertex_cat6_dataC);  


   TH1D *h_muonSV_mass_min_chi2_categorised = (TH1D*) f->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi2 = (TH1D*) f->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV = (TH1D*) f->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices = (TH1D*) f->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices = (TH1D*) f->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex = (TH1D*) f->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new = (TH1D*) f->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new = (TH1D*) f->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat1 = (TH1D*) f->Get("muonSV_mass_multivertices_mass_window_cat1");
   TH1D *h_muonSV_mass_multivertices_cat2 = (TH1D*) f->Get("muonSV_mass_multivertices_mass_window_cat2");
   TH1D *h_muonSV_mass_multivertices_cat3 = (TH1D*) f->Get("muonSV_mass_multivertices_mass_window_cat3");
   TH1D *h_muonSV_mass_multivertices_cat4 = (TH1D*) f->Get("muonSV_mass_multivertices_mass_window_cat4");
   TH1D *h_muonSV_mass_multivertices_cat5 = (TH1D*) f->Get("muonSV_mass_multivertices_mass_window_cat5");
   TH1D *h_muonSV_mass_multivertices_cat6 = (TH1D*) f->Get("muonSV_mass_multivertices_mass_window_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat1 = (TH1D*) f->Get("muonSV_mass_singlevertex_mass_window_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat2 = (TH1D*) f->Get("muonSV_mass_singlevertex_mass_window_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat3 = (TH1D*) f->Get("muonSV_mass_singlevertex_mass_window_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat4 = (TH1D*) f->Get("muonSV_mass_singlevertex_mass_window_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat5 = (TH1D*) f->Get("muonSV_mass_singlevertex_mass_window_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat6 = (TH1D*) f->Get("muonSV_mass_singlevertex_mass_window_cat6");
   
 
   TH1D *h_muonSV_mass_min_chi2_categorised1 = (TH1D*) f1->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi21 = (TH1D*) f1->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV1 = (TH1D*) f1->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices1 = (TH1D*) f1->Get("nmuonSV_multivertices_plot"); 
   TH1D *h_muonSV_mass_min_chi2_multivertices1 = (TH1D*) f1->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex1 = (TH1D*) f1->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new1 = (TH1D*) f1->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new1 = (TH1D*) f1->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat11 = (TH1D*) f1->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat21 = (TH1D*) f1->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat31 = (TH1D*) f1->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat41 = (TH1D*) f1->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat51 = (TH1D*) f1->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat61 = (TH1D*) f1->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat11 = (TH1D*) f1->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat21 = (TH1D*) f1->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat31 = (TH1D*) f1->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat41 = (TH1D*) f1->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat51 = (TH1D*) f1->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat61 = (TH1D*) f1->Get("muonSV_mass_singlevertex_cat6");

 

   TH1D *h_muonSV_mass_min_chi2_categorised2 = (TH1D*) f2->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi22 = (TH1D*) f2->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV2 = (TH1D*) f2->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices2 = (TH1D*) f2->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices2 = (TH1D*) f2->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex2 = (TH1D*) f2->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new2 = (TH1D*) f2->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new2 = (TH1D*) f2->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat12 = (TH1D*) f2->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat22 = (TH1D*) f2->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat32 = (TH1D*) f2->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat42 = (TH1D*) f2->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat52 = (TH1D*) f2->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat62 = (TH1D*) f2->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat12 = (TH1D*) f2->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat22 = (TH1D*) f2->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat32 = (TH1D*) f2->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat42 = (TH1D*) f2->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat52 = (TH1D*) f2->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat62 = (TH1D*) f2->Get("muonSV_mass_singlevertex_cat6");


   TH1D *h_muonSV_mass_min_chi2_categorised3 = (TH1D*) f3->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi23 = (TH1D*) f3->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV3 = (TH1D*) f3->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices3 = (TH1D*) f3->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices3 = (TH1D*) f3->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex3 = (TH1D*) f3->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new3 = (TH1D*) f3->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new3 = (TH1D*) f3->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat13 = (TH1D*) f3->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat23 = (TH1D*) f3->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat33 = (TH1D*) f3->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat43 = (TH1D*) f3->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat53 = (TH1D*) f3->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat63 = (TH1D*) f3->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat13 = (TH1D*) f3->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat23 = (TH1D*) f3->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat33 = (TH1D*) f3->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat43 = (TH1D*) f3->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat53 = (TH1D*) f3->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat63 = (TH1D*) f3->Get("muonSV_mass_singlevertex_cat6");

   TH1D *h_muonSV_mass_min_chi2_categorised4 = (TH1D*) f4->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi24 = (TH1D*) f4->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV4 = (TH1D*) f4->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices4 = (TH1D*) f4->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices4 = (TH1D*) f4->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex4 = (TH1D*) f4->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new4 = (TH1D*) f4->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new4 = (TH1D*) f4->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat14 = (TH1D*) f4->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat24 = (TH1D*) f4->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat34 = (TH1D*) f4->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat44 = (TH1D*) f4->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat54 = (TH1D*) f4->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat64 = (TH1D*) f4->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat14 = (TH1D*) f4->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat24 = (TH1D*) f4->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat34 = (TH1D*) f4->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat44 = (TH1D*) f4->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat54 = (TH1D*) f4->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat64 = (TH1D*) f4->Get("muonSV_mass_singlevertex_cat6");

   TH1D *h_muonSV_mass_min_chi2_categorised5 = (TH1D*) f5->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi25 = (TH1D*) f5->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV5 = (TH1D*) f5->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices5 = (TH1D*) f5->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices5 = (TH1D*) f5->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex5 = (TH1D*) f5->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new5 = (TH1D*) f5->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new5 = (TH1D*) f5->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat15 = (TH1D*) f5->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat25 = (TH1D*) f5->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat35 = (TH1D*) f5->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat45 = (TH1D*) f5->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat55 = (TH1D*) f5->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat65 = (TH1D*) f5->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat15 = (TH1D*) f5->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat25 = (TH1D*) f5->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat35 = (TH1D*) f5->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat45 = (TH1D*) f5->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat55 = (TH1D*) f5->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat65 = (TH1D*) f5->Get("muonSV_mass_singlevertex_cat6");

   TH1D *h_muonSV_mass_min_chi2_categorised5_ext = (TH1D*) f5_ext->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi25_ext = (TH1D*) f5_ext->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV5_ext = (TH1D*) f5_ext->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices5_ext = (TH1D*) f5_ext->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices5_ext = (TH1D*) f5_ext->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex5_ext = (TH1D*) f5_ext->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new5_ext = (TH1D*) f5_ext->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new5_ext = (TH1D*) f5_ext->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat15_ext = (TH1D*) f5_ext->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat25_ext = (TH1D*) f5_ext->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat35_ext = (TH1D*) f5_ext->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat45_ext = (TH1D*) f5_ext->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat55_ext = (TH1D*) f5_ext->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat65_ext = (TH1D*) f5_ext->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat15_ext = (TH1D*) f5_ext->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat25_ext = (TH1D*) f5_ext->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat35_ext = (TH1D*) f5_ext->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat45_ext = (TH1D*) f5_ext->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat55_ext = (TH1D*) f5_ext->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat65_ext = (TH1D*) f5_ext->Get("muonSV_mass_singlevertex_cat6");



   TH1D *h_muonSV_mass_min_chi2_categorised6 = (TH1D*) f6->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi26 = (TH1D*) f6->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV6 = (TH1D*) f6->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices6 = (TH1D*) f6->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices6 = (TH1D*) f6->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex6 = (TH1D*) f6->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new6 = (TH1D*) f6->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new6 = (TH1D*) f6->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat16 = (TH1D*) f6->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat26 = (TH1D*) f6->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat36 = (TH1D*) f6->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat46 = (TH1D*) f6->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat56 = (TH1D*) f6->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat66 = (TH1D*) f6->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat16 = (TH1D*) f6->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat26 = (TH1D*) f6->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat36 = (TH1D*) f6->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat46 = (TH1D*) f6->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat56 = (TH1D*) f6->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat66 = (TH1D*) f6->Get("muonSV_mass_singlevertex_cat6");



   TH1D *h_muonSV_mass_min_chi2_categorised6_ext = (TH1D*) f6_ext->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi26_ext = (TH1D*) f6_ext->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV6_ext = (TH1D*) f6_ext->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices6_ext = (TH1D*) f6_ext->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices6_ext = (TH1D*) f6_ext->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex6_ext = (TH1D*) f6_ext->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new6_ext = (TH1D*) f6_ext->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new6_ext = (TH1D*) f6_ext->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat16_ext = (TH1D*) f6_ext->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat26_ext = (TH1D*) f6_ext->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat36_ext = (TH1D*) f6_ext->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat46_ext = (TH1D*) f6_ext->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat56_ext = (TH1D*) f6_ext->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat66_ext = (TH1D*) f6_ext->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat16_ext = (TH1D*) f6_ext->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat26_ext = (TH1D*) f6_ext->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat36_ext = (TH1D*) f6_ext->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat46_ext = (TH1D*) f6_ext->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat56_ext = (TH1D*) f6_ext->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat66_ext = (TH1D*) f6_ext->Get("muonSV_mass_singlevertex_cat6");



   TH1D *h_muonSV_mass_min_chi2_categorised7 = (TH1D*) f7->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi27 = (TH1D*) f7->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV7 = (TH1D*) f7->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices7 = (TH1D*) f7->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices7 = (TH1D*) f7->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex7 = (TH1D*) f7->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new7 = (TH1D*) f7->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new7 = (TH1D*) f7->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat17 = (TH1D*) f7->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat27 = (TH1D*) f7->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat37 = (TH1D*) f7->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat47 = (TH1D*) f7->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat57 = (TH1D*) f7->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat67 = (TH1D*) f7->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat17 = (TH1D*) f7->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat27 = (TH1D*) f7->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat37 = (TH1D*) f7->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat47 = (TH1D*) f7->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat57 = (TH1D*) f7->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat67 = (TH1D*) f7->Get("muonSV_mass_singlevertex_cat6");


   TH1D *h_muonSV_mass_min_chi2_categorised8 = (TH1D*) f8->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi28 = (TH1D*) f8->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV8 = (TH1D*) f8->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices8 = (TH1D*) f8->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices8 = (TH1D*) f8->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex8 = (TH1D*) f8->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new8 = (TH1D*) f8->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new8 = (TH1D*) f8->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat18 = (TH1D*) f8->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat28 = (TH1D*) f8->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat38 = (TH1D*) f8->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat48 = (TH1D*) f8->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat58 = (TH1D*) f8->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat68 = (TH1D*) f8->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat18 = (TH1D*) f8->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat28 = (TH1D*) f8->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat38 = (TH1D*) f8->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat48 = (TH1D*) f8->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat58 = (TH1D*) f8->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat68 = (TH1D*) f8->Get("muonSV_mass_singlevertex_cat6");



   TH1D *h_muonSV_mass_min_chi2_categorised8_ext = (TH1D*) f8_ext->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi28_ext = (TH1D*) f8_ext->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV8_ext = (TH1D*) f8_ext->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices8_ext = (TH1D*) f8_ext->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices8_ext = (TH1D*) f8_ext->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex8_ext = (TH1D*) f8_ext->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new8_ext = (TH1D*) f8_ext->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new8_ext = (TH1D*) f8_ext->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat18_ext = (TH1D*) f8_ext->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat28_ext = (TH1D*) f8_ext->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat38_ext = (TH1D*) f8_ext->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat48_ext = (TH1D*) f8_ext->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat58_ext = (TH1D*) f8_ext->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat68_ext = (TH1D*) f8_ext->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat18_ext = (TH1D*) f8_ext->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat28_ext = (TH1D*) f8_ext->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat38_ext = (TH1D*) f8_ext->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat48_ext = (TH1D*) f8_ext->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat58_ext = (TH1D*) f8_ext->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat68_ext = (TH1D*) f8_ext->Get("muonSV_mass_singlevertex_cat6");



   TH1D *h_muonSV_mass_min_chi2_categorised9 = (TH1D*) f9->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi29 = (TH1D*) f9->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV9 = (TH1D*) f9->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices9 = (TH1D*) f9->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices9 = (TH1D*) f9->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex9 = (TH1D*) f9->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new9 = (TH1D*) f9->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new9 = (TH1D*) f9->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat19 = (TH1D*) f9->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat29 = (TH1D*) f9->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat39 = (TH1D*) f9->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat49 = (TH1D*) f9->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat59 = (TH1D*) f9->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat69 = (TH1D*) f9->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat19 = (TH1D*) f9->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat29 = (TH1D*) f9->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat39 = (TH1D*) f9->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat49 = (TH1D*) f9->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat59 = (TH1D*) f9->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat69 = (TH1D*) f9->Get("muonSV_mass_singlevertex_cat6");

   TH1D *h_muonSV_mass_min_chi2_categorised9_ext = (TH1D*) f9_ext->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi29_ext = (TH1D*) f9_ext->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV9_ext = (TH1D*) f9_ext ->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices9_ext  = (TH1D*) f9_ext ->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices9_ext = (TH1D*) f9_ext->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex9_ext = (TH1D*) f9_ext->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new9_ext = (TH1D*) f9_ext->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new9_ext = (TH1D*) f9_ext->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat19_ext = (TH1D*) f9_ext->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat29_ext = (TH1D*) f9_ext->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat39_ext = (TH1D*) f9_ext->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat49_ext = (TH1D*) f9_ext->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat59_ext = (TH1D*) f9_ext->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat69_ext = (TH1D*) f9_ext->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat19_ext = (TH1D*) f9_ext->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat29_ext = (TH1D*) f9_ext->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat39_ext = (TH1D*) f9_ext->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat49_ext = (TH1D*) f9_ext->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat59_ext = (TH1D*) f9_ext->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat69_ext = (TH1D*) f9_ext->Get("muonSV_mass_singlevertex_cat6");


   TH1D *h_muonSV_mass_min_chi2_categorised10 = (TH1D*) f10->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi210 = (TH1D*) f10->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV10 = (TH1D*) f10->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices10 = (TH1D*) f10->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices10 = (TH1D*) f10->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex10 = (TH1D*) f10->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new10 = (TH1D*) f10->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new10 = (TH1D*) f10->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat110 = (TH1D*) f10->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat210 = (TH1D*) f10->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat310 = (TH1D*) f10->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat410 = (TH1D*) f10->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat510 = (TH1D*) f10->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat610 = (TH1D*) f10->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat110 = (TH1D*) f10->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat210 = (TH1D*) f10->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat310 = (TH1D*) f10->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat410 = (TH1D*) f10->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat510 = (TH1D*) f10->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat610 = (TH1D*) f10->Get("muonSV_mass_singlevertex_cat6");



   TH1D *h_muonSV_mass_min_chi2_categorised11 = (TH1D*) f11->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi211 = (TH1D*) f11->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV11 = (TH1D*) f11->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices11 = (TH1D*) f11->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices11 = (TH1D*) f11->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex11 = (TH1D*) f11->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new11 = (TH1D*) f11->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new11 = (TH1D*) f11->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat111 = (TH1D*) f11->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat211 = (TH1D*) f11->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat311 = (TH1D*) f11->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat411 = (TH1D*) f11->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat511 = (TH1D*) f11->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat611 = (TH1D*) f11->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat111 = (TH1D*) f11->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat211 = (TH1D*) f11->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat311 = (TH1D*) f11->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat411 = (TH1D*) f11->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat511 = (TH1D*) f11->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat611 = (TH1D*) f11->Get("muonSV_mass_singlevertex_cat6");    

   TH1D *h_muonSV_mass_min_chi2_categorised12 = (TH1D*) f12->Get("muonSV_mass_min_chi2_categorised");
   TH1D *h_muonSV_mass_min_chi212 = (TH1D*) f12->Get("muonSV_mass_min_chi2");
   TH1D *h_nmuonSV12 = (TH1D*) f12->Get("nmuonSV_plot");
   TH1D *h_nmuonSV_multivertices12 = (TH1D*) f12->Get("nmuonSV_multivertices_plot");
   TH1D *h_muonSV_mass_min_chi2_multivertices12 = (TH1D*) f12->Get("muonSV_mass_min_chi2_multivertices_cat");
   TH1D *h_muonSV_mass_min_chi2_singlevertex12 = (TH1D*) f12->Get("muonSV_mass_min_chi2_singlevertex_cat");
   TH1D *h_muonSV_mass_multivertices_cat1_new12 = (TH1D*) f12->Get("muonSV_mass_multivertices_cat1_new");
   TH1D *h_muonSV_mass_multivertices_cat2_new12 = (TH1D*) f12->Get("muonSV_mass_multivertices_cat2_new");
   TH1D *h_muonSV_mass_multivertices_cat112 = (TH1D*) f12->Get("muonSV_mass_multivertices_cat1");
   TH1D *h_muonSV_mass_multivertices_cat212 = (TH1D*) f12->Get("muonSV_mass_multivertices_cat2");
   TH1D *h_muonSV_mass_multivertices_cat312 = (TH1D*) f12->Get("muonSV_mass_multivertices_cat3");
   TH1D *h_muonSV_mass_multivertices_cat412 = (TH1D*) f12->Get("muonSV_mass_multivertices_cat4");
   TH1D *h_muonSV_mass_multivertices_cat512 = (TH1D*) f12->Get("muonSV_mass_multivertices_cat5");
   TH1D *h_muonSV_mass_multivertices_cat612 = (TH1D*) f12->Get("muonSV_mass_multivertices_cat6");
   TH1D *h_muonSV_mass_singlevertex_cat112 = (TH1D*) f12->Get("muonSV_mass_singlevertex_cat1");
   TH1D *h_muonSV_mass_singlevertex_cat212 = (TH1D*) f12->Get("muonSV_mass_singlevertex_cat2");
   TH1D *h_muonSV_mass_singlevertex_cat312 = (TH1D*) f12->Get("muonSV_mass_singlevertex_cat3");
   TH1D *h_muonSV_mass_singlevertex_cat412 = (TH1D*) f12->Get("muonSV_mass_singlevertex_cat4");
   TH1D *h_muonSV_mass_singlevertex_cat512 = (TH1D*) f12->Get("muonSV_mass_singlevertex_cat5");
   TH1D *h_muonSV_mass_singlevertex_cat612 = (TH1D*) f12->Get("muonSV_mass_singlevertex_cat6");


   h_muonSV_mass_min_chi2_categorised5->Add(h_muonSV_mass_min_chi2_categorised5_ext);
   h_muonSV_mass_min_chi25->Add(h_muonSV_mass_min_chi25_ext);
   h_nmuonSV5->Add(h_nmuonSV5_ext);
   h_nmuonSV_multivertices5->Add(h_nmuonSV_multivertices5_ext);
   h_muonSV_mass_min_chi2_multivertices5->Add(h_muonSV_mass_min_chi2_multivertices5_ext);
   h_muonSV_mass_min_chi2_singlevertex5->Add(h_muonSV_mass_min_chi2_singlevertex5_ext);
   h_muonSV_mass_multivertices_cat1_new5->Add(h_muonSV_mass_multivertices_cat1_new5_ext);
   h_muonSV_mass_multivertices_cat2_new5->Add(h_muonSV_mass_multivertices_cat2_new5_ext);
   h_muonSV_mass_multivertices_cat15->Add(h_muonSV_mass_multivertices_cat15_ext);
   h_muonSV_mass_multivertices_cat25->Add(h_muonSV_mass_multivertices_cat25_ext);
   h_muonSV_mass_multivertices_cat35->Add(h_muonSV_mass_multivertices_cat35_ext);
   h_muonSV_mass_multivertices_cat45->Add(h_muonSV_mass_multivertices_cat45_ext);
   h_muonSV_mass_multivertices_cat55->Add(h_muonSV_mass_multivertices_cat55_ext);
   h_muonSV_mass_multivertices_cat65->Add(h_muonSV_mass_multivertices_cat65_ext);
   h_muonSV_mass_singlevertex_cat15->Add(h_muonSV_mass_singlevertex_cat15_ext);
   h_muonSV_mass_singlevertex_cat25->Add(h_muonSV_mass_singlevertex_cat25_ext);
   h_muonSV_mass_singlevertex_cat35->Add(h_muonSV_mass_singlevertex_cat35_ext);
   h_muonSV_mass_singlevertex_cat45->Add(h_muonSV_mass_singlevertex_cat45_ext);
   h_muonSV_mass_singlevertex_cat55->Add(h_muonSV_mass_singlevertex_cat55_ext);
   h_muonSV_mass_singlevertex_cat65->Add(h_muonSV_mass_singlevertex_cat65_ext);
  


   h_muonSV_mass_min_chi2_categorised6->Add(h_muonSV_mass_min_chi2_categorised6_ext);
   h_muonSV_mass_min_chi26->Add(h_muonSV_mass_min_chi26_ext);
   h_nmuonSV6->Add(h_nmuonSV6_ext);
   h_nmuonSV_multivertices6->Add(h_nmuonSV_multivertices6_ext);
   h_muonSV_mass_min_chi2_multivertices6->Add(h_muonSV_mass_min_chi2_multivertices6_ext);
   h_muonSV_mass_min_chi2_singlevertex6->Add(h_muonSV_mass_min_chi2_singlevertex6_ext);
   h_muonSV_mass_multivertices_cat1_new6->Add(h_muonSV_mass_multivertices_cat1_new6_ext);
   h_muonSV_mass_multivertices_cat2_new6->Add(h_muonSV_mass_multivertices_cat2_new6_ext);
   h_muonSV_mass_multivertices_cat16->Add(h_muonSV_mass_multivertices_cat16_ext);
   h_muonSV_mass_multivertices_cat26->Add(h_muonSV_mass_multivertices_cat26_ext);
   h_muonSV_mass_multivertices_cat36->Add(h_muonSV_mass_multivertices_cat36_ext);
   h_muonSV_mass_multivertices_cat46->Add(h_muonSV_mass_multivertices_cat46_ext);
   h_muonSV_mass_multivertices_cat56->Add(h_muonSV_mass_multivertices_cat56_ext);
   h_muonSV_mass_multivertices_cat66->Add(h_muonSV_mass_multivertices_cat66_ext);
   h_muonSV_mass_singlevertex_cat16->Add(h_muonSV_mass_singlevertex_cat16_ext);
   h_muonSV_mass_singlevertex_cat26->Add(h_muonSV_mass_singlevertex_cat26_ext);
   h_muonSV_mass_singlevertex_cat36->Add(h_muonSV_mass_singlevertex_cat36_ext);
   h_muonSV_mass_singlevertex_cat46->Add(h_muonSV_mass_singlevertex_cat46_ext);
   h_muonSV_mass_singlevertex_cat56->Add(h_muonSV_mass_singlevertex_cat56_ext);
   h_muonSV_mass_singlevertex_cat66->Add(h_muonSV_mass_singlevertex_cat66_ext);


   h_muonSV_mass_min_chi2_categorised8->Add(h_muonSV_mass_min_chi2_categorised8_ext);
   h_muonSV_mass_min_chi28->Add(h_muonSV_mass_min_chi28_ext);
   h_nmuonSV8->Add(h_nmuonSV8_ext);
   h_nmuonSV_multivertices8->Add(h_nmuonSV_multivertices8_ext);
   h_muonSV_mass_min_chi2_multivertices8->Add(h_muonSV_mass_min_chi2_multivertices8_ext);
   h_muonSV_mass_min_chi2_singlevertex8->Add(h_muonSV_mass_min_chi2_singlevertex8_ext);
   h_muonSV_mass_multivertices_cat1_new8->Add(h_muonSV_mass_multivertices_cat1_new8_ext);
   h_muonSV_mass_multivertices_cat2_new8->Add(h_muonSV_mass_multivertices_cat2_new8_ext);
   h_muonSV_mass_multivertices_cat18->Add(h_muonSV_mass_multivertices_cat18_ext);
   h_muonSV_mass_multivertices_cat28->Add(h_muonSV_mass_multivertices_cat28_ext);
   h_muonSV_mass_multivertices_cat38->Add(h_muonSV_mass_multivertices_cat38_ext);
   h_muonSV_mass_multivertices_cat48->Add(h_muonSV_mass_multivertices_cat48_ext);
   h_muonSV_mass_multivertices_cat58->Add(h_muonSV_mass_multivertices_cat58_ext);
   h_muonSV_mass_multivertices_cat68->Add(h_muonSV_mass_multivertices_cat68_ext);
   h_muonSV_mass_singlevertex_cat18->Add(h_muonSV_mass_singlevertex_cat18_ext);
   h_muonSV_mass_singlevertex_cat28->Add(h_muonSV_mass_singlevertex_cat28_ext);
   h_muonSV_mass_singlevertex_cat38->Add(h_muonSV_mass_singlevertex_cat38_ext);
   h_muonSV_mass_singlevertex_cat48->Add(h_muonSV_mass_singlevertex_cat48_ext);
   h_muonSV_mass_singlevertex_cat58->Add(h_muonSV_mass_singlevertex_cat58_ext);
   h_muonSV_mass_singlevertex_cat68->Add(h_muonSV_mass_singlevertex_cat68_ext);

   h_muonSV_mass_min_chi2_categorised9->Add(h_muonSV_mass_min_chi2_categorised9_ext);
   h_muonSV_mass_min_chi29->Add(h_muonSV_mass_min_chi29_ext);
   h_nmuonSV9->Add(h_nmuonSV9_ext);
   h_nmuonSV_multivertices9->Add(h_nmuonSV_multivertices9_ext);
   h_muonSV_mass_min_chi2_multivertices9->Add(h_muonSV_mass_min_chi2_multivertices9_ext);
   h_muonSV_mass_min_chi2_singlevertex9->Add(h_muonSV_mass_min_chi2_singlevertex9_ext);
   h_muonSV_mass_multivertices_cat1_new9->Add(h_muonSV_mass_multivertices_cat1_new9_ext);
   h_muonSV_mass_multivertices_cat2_new9->Add(h_muonSV_mass_multivertices_cat2_new9_ext);
   h_muonSV_mass_multivertices_cat19->Add(h_muonSV_mass_multivertices_cat19_ext);
   h_muonSV_mass_multivertices_cat29->Add(h_muonSV_mass_multivertices_cat29_ext);
   h_muonSV_mass_multivertices_cat39->Add(h_muonSV_mass_multivertices_cat39_ext);
   h_muonSV_mass_multivertices_cat49->Add(h_muonSV_mass_multivertices_cat49_ext);
   h_muonSV_mass_multivertices_cat59->Add(h_muonSV_mass_multivertices_cat59_ext);
   h_muonSV_mass_multivertices_cat69->Add(h_muonSV_mass_multivertices_cat69_ext);
   h_muonSV_mass_singlevertex_cat19->Add(h_muonSV_mass_singlevertex_cat19_ext);
   h_muonSV_mass_singlevertex_cat29->Add(h_muonSV_mass_singlevertex_cat29_ext);
   h_muonSV_mass_singlevertex_cat39->Add(h_muonSV_mass_singlevertex_cat39_ext);
   h_muonSV_mass_singlevertex_cat49->Add(h_muonSV_mass_singlevertex_cat49_ext);
   h_muonSV_mass_singlevertex_cat59->Add(h_muonSV_mass_singlevertex_cat59_ext);
   h_muonSV_mass_singlevertex_cat69->Add(h_muonSV_mass_singlevertex_cat69_ext);

   Double_t no_of_entries_original = 80000.0;
   Double_t no_of_entries1_original = 4159734.0;
   Double_t no_of_entries2_original = 30100864.0;
   Double_t no_of_entries3_original = 29327371.0;
   Double_t no_of_entries4_original = 19814379.0;
   Double_t no_of_entries5_original = 24759617.0;
   Double_t no_of_entries6_original = 20454047.0;
   Double_t no_of_entries7_original = 35664362.0;
   Double_t no_of_entries8_original = 28899863.0;
   Double_t no_of_entries9_original = 19939641.0;
   Double_t no_of_entries10_original = 16125220.0;
   Double_t no_of_entries11_original = 16464596.0;
   Double_t no_of_entries12_original = 10377764.0;
 
   Double_t branching_ratio = 0.01;
   Double_t xs = 43.9;

   Double_t xs1 = 2799000.0;
   Double_t xs2 = 2526000.0;
   Double_t xs3 = 1362000.0;
   Double_t xs4 = 376600.0;
   Double_t xs5 = 88930.0;
   Double_t xs6 = 21230.0;

   Double_t xs7 = 7055.0;
   Double_t xs8 = 619.3;
   Double_t xs9 = 59.24;
   Double_t xs10 = 18.21;
   Double_t xs11 = 3.275;
   Double_t xs12 = 1.078;

   //Double_t lumi = 33.6*1000;
   Double_t lumi = 0.96*1000;

   h_muonSV_mass_min_chi2_categorised->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_min_chi2_categorised1->Scale(lumi*xs1/no_of_entries1_original);
   h_muonSV_mass_min_chi2_categorised2->Scale(lumi*xs2/no_of_entries2_original);
   h_muonSV_mass_min_chi2_categorised3->Scale(lumi*xs3/no_of_entries3_original);
   h_muonSV_mass_min_chi2_categorised4->Scale(lumi*xs4/no_of_entries4_original);
   h_muonSV_mass_min_chi2_categorised5->Scale(lumi*xs5/no_of_entries5_original);
   h_muonSV_mass_min_chi2_categorised6->Scale(lumi*xs6/no_of_entries6_original);
   h_muonSV_mass_min_chi2_categorised7->Scale(lumi*xs7/no_of_entries7_original);
   h_muonSV_mass_min_chi2_categorised8->Scale(lumi*xs8/no_of_entries8_original);
   h_muonSV_mass_min_chi2_categorised9->Scale(lumi*xs9/no_of_entries9_original);
   h_muonSV_mass_min_chi2_categorised10->Scale(lumi*xs10/no_of_entries10_original);
   h_muonSV_mass_min_chi2_categorised11->Scale(lumi*xs11/no_of_entries11_original);
   h_muonSV_mass_min_chi2_categorised12->Scale(lumi*xs12/no_of_entries12_original);

   h_muonSV_mass_min_chi2->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_min_chi21->Scale(lumi*xs1/no_of_entries1_original);
   h_muonSV_mass_min_chi22->Scale(lumi*xs2/no_of_entries2_original);
   h_muonSV_mass_min_chi23->Scale(lumi*xs3/no_of_entries3_original);
   h_muonSV_mass_min_chi24->Scale(lumi*xs4/no_of_entries4_original);
   h_muonSV_mass_min_chi25->Scale(lumi*xs5/no_of_entries5_original);
   h_muonSV_mass_min_chi26->Scale(lumi*xs6/no_of_entries6_original);
   h_muonSV_mass_min_chi27->Scale(lumi*xs7/no_of_entries7_original);
   h_muonSV_mass_min_chi28->Scale(lumi*xs8/no_of_entries8_original);
   h_muonSV_mass_min_chi29->Scale(lumi*xs9/no_of_entries9_original);
   h_muonSV_mass_min_chi210->Scale(lumi*xs10/no_of_entries10_original);
   h_muonSV_mass_min_chi211->Scale(lumi*xs11/no_of_entries11_original);
   h_muonSV_mass_min_chi212->Scale(lumi*xs12/no_of_entries12_original);
   
   h_nmuonSV->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_nmuonSV1->Scale(lumi*xs1/no_of_entries1_original);
   h_nmuonSV2->Scale(lumi*xs2/no_of_entries2_original);
   h_nmuonSV3->Scale(lumi*xs3/no_of_entries3_original);
   h_nmuonSV4->Scale(lumi*xs4/no_of_entries4_original);
   h_nmuonSV5->Scale(lumi*xs5/no_of_entries5_original);
   h_nmuonSV6->Scale(lumi*xs6/no_of_entries6_original);
   h_nmuonSV7->Scale(lumi*xs7/no_of_entries7_original);
   h_nmuonSV8->Scale(lumi*xs8/no_of_entries8_original);
   h_nmuonSV9->Scale(lumi*xs9/no_of_entries9_original);
   h_nmuonSV10->Scale(lumi*xs10/no_of_entries10_original);
   h_nmuonSV11->Scale(lumi*xs11/no_of_entries11_original);
   h_nmuonSV12->Scale(lumi*xs12/no_of_entries12_original);

   h_nmuonSV_multivertices->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_nmuonSV_multivertices1->Scale(lumi*xs1/no_of_entries1_original);
   h_nmuonSV_multivertices2->Scale(lumi*xs2/no_of_entries2_original);
   h_nmuonSV_multivertices3->Scale(lumi*xs3/no_of_entries3_original);
   h_nmuonSV_multivertices4->Scale(lumi*xs4/no_of_entries4_original);
   h_nmuonSV_multivertices5->Scale(lumi*xs5/no_of_entries5_original);
   h_nmuonSV_multivertices6->Scale(lumi*xs6/no_of_entries6_original);
   h_nmuonSV_multivertices7->Scale(lumi*xs7/no_of_entries7_original);
   h_nmuonSV_multivertices8->Scale(lumi*xs8/no_of_entries8_original);
   h_nmuonSV_multivertices9->Scale(lumi*xs9/no_of_entries9_original);
   h_nmuonSV_multivertices10->Scale(lumi*xs10/no_of_entries10_original);
   h_nmuonSV_multivertices11->Scale(lumi*xs11/no_of_entries11_original);
   h_nmuonSV_multivertices12->Scale(lumi*xs12/no_of_entries12_original);
  
   h_muonSV_mass_min_chi2_multivertices->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_min_chi2_multivertices1->Scale(lumi*xs1/no_of_entries1_original);
   h_muonSV_mass_min_chi2_multivertices2->Scale(lumi*xs2/no_of_entries2_original);
   h_muonSV_mass_min_chi2_multivertices3->Scale(lumi*xs3/no_of_entries3_original);
   h_muonSV_mass_min_chi2_multivertices4->Scale(lumi*xs4/no_of_entries4_original);
   h_muonSV_mass_min_chi2_multivertices5->Scale(lumi*xs5/no_of_entries5_original);
   h_muonSV_mass_min_chi2_multivertices6->Scale(lumi*xs6/no_of_entries6_original);
   h_muonSV_mass_min_chi2_multivertices7->Scale(lumi*xs7/no_of_entries7_original); 
   h_muonSV_mass_min_chi2_multivertices8->Scale(lumi*xs8/no_of_entries8_original);
   h_muonSV_mass_min_chi2_multivertices9->Scale(lumi*xs9/no_of_entries9_original);
   h_muonSV_mass_min_chi2_multivertices10->Scale(lumi*xs10/no_of_entries10_original);
   h_muonSV_mass_min_chi2_multivertices11->Scale(lumi*xs11/no_of_entries11_original);
   h_muonSV_mass_min_chi2_multivertices12->Scale(lumi*xs12/no_of_entries12_original);

   
   h_muonSV_mass_min_chi2_singlevertex->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   /*
   h_muonSV_mass_min_chi2_singlevertex1->Scale(lumi*xs1/no_of_entries1_original);
   h_muonSV_mass_min_chi2_singlevertex2->Scale(lumi*xs2/no_of_entries2_original);
   h_muonSV_mass_min_chi2_singlevertex3->Scale(lumi*xs3/no_of_entries3_original);
   h_muonSV_mass_min_chi2_singlevertex4->Scale(lumi*xs4/no_of_entries4_original);
   h_muonSV_mass_min_chi2_singlevertex5->Scale(lumi*xs5/no_of_entries5_original);
   h_muonSV_mass_min_chi2_singlevertex6->Scale(lumi*xs6/no_of_entries6_original);
   h_muonSV_mass_min_chi2_singlevertex7->Scale(lumi*xs7/no_of_entries7_original);
   h_muonSV_mass_min_chi2_singlevertex8->Scale(lumi*xs8/no_of_entries8_original);
   h_muonSV_mass_min_chi2_singlevertex9->Scale(lumi*xs9/no_of_entries9_original);
   h_muonSV_mass_min_chi2_singlevertex10->Scale(lumi*xs10/no_of_entries10_original);
   h_muonSV_mass_min_chi2_singlevertex11->Scale(lumi*xs11/no_of_entries11_original);
   h_muonSV_mass_min_chi2_singlevertex12->Scale(lumi*xs12/no_of_entries12_original);
   */
  
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised2);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised3);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised4);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised5);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised6);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised7);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised8);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised9);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised10);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised11);
   h_muonSV_mass_min_chi2_categorised1->Add(h_muonSV_mass_min_chi2_categorised12);
 
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi22);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi23);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi24);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi25);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi26);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi27);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi28);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi29);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi210);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi211);
   h_muonSV_mass_min_chi21->Add(h_muonSV_mass_min_chi212);

   h_nmuonSV1->Add(h_nmuonSV2);
   h_nmuonSV1->Add(h_nmuonSV3);
   h_nmuonSV1->Add(h_nmuonSV4);
   h_nmuonSV1->Add(h_nmuonSV5);
   h_nmuonSV1->Add(h_nmuonSV6);
   h_nmuonSV1->Add(h_nmuonSV7);
   h_nmuonSV1->Add(h_nmuonSV8);
   h_nmuonSV1->Add(h_nmuonSV9);
   h_nmuonSV1->Add(h_nmuonSV10);
   h_nmuonSV1->Add(h_nmuonSV11);
   h_nmuonSV1->Add(h_nmuonSV12);

   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices2);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices3);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices4);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices5);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices6);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices7);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices8);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices9);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices10);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices11);
   h_nmuonSV_multivertices1->Add(h_nmuonSV_multivertices12);

   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices2);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices3);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices4);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices5);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices6);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices7);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices8);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices9);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices10);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices11);
   h_muonSV_mass_min_chi2_multivertices1->Add(h_muonSV_mass_min_chi2_multivertices12);

   /*
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex2);
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex3);
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex4);  
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex5);
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex6);
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex7);
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex8);
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex9);
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex10);
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex11);
   h_muonSV_mass_min_chi2_singlevertex1->Add(h_muonSV_mass_min_chi2_singlevertex12);
   */

   background_weighting(h_muonSV_mass_min_chi2_singlevertex1, h_muonSV_mass_min_chi2_singlevertex2, h_muonSV_mass_min_chi2_singlevertex3, h_muonSV_mass_min_chi2_singlevertex4, h_muonSV_mass_min_chi2_singlevertex5, h_muonSV_mass_min_chi2_singlevertex6, h_muonSV_mass_min_chi2_singlevertex7, h_muonSV_mass_min_chi2_singlevertex8, h_muonSV_mass_min_chi2_singlevertex9, h_muonSV_mass_min_chi2_singlevertex10, h_muonSV_mass_min_chi2_singlevertex11, h_muonSV_mass_min_chi2_singlevertex12); 
   
   h_muonSV_mass_multivertices_cat1_new->Scale(lumi*xs*branching_ratio/no_of_entries_original);  
   h_muonSV_mass_multivertices_cat2_new->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_multivertices_cat1->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_multivertices_cat2->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_multivertices_cat3->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_multivertices_cat4->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_multivertices_cat5->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_multivertices_cat6->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_singlevertex_cat1->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_singlevertex_cat2->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_singlevertex_cat3->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_singlevertex_cat4->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_singlevertex_cat5->Scale(lumi*xs*branching_ratio/no_of_entries_original);
   h_muonSV_mass_singlevertex_cat6->Scale(lumi*xs*branching_ratio/no_of_entries_original);
  
   background_weighting(h_muonSV_mass_multivertices_cat1_new1, h_muonSV_mass_multivertices_cat1_new2, h_muonSV_mass_multivertices_cat1_new3, h_muonSV_mass_multivertices_cat1_new4, h_muonSV_mass_multivertices_cat1_new5, h_muonSV_mass_multivertices_cat1_new6, h_muonSV_mass_multivertices_cat1_new7, h_muonSV_mass_multivertices_cat1_new8, h_muonSV_mass_multivertices_cat1_new9, h_muonSV_mass_multivertices_cat1_new10, h_muonSV_mass_multivertices_cat1_new11, h_muonSV_mass_multivertices_cat1_new12); 

   background_weighting(h_muonSV_mass_multivertices_cat2_new1, h_muonSV_mass_multivertices_cat2_new2, h_muonSV_mass_multivertices_cat2_new3, h_muonSV_mass_multivertices_cat2_new4, h_muonSV_mass_multivertices_cat2_new5, h_muonSV_mass_multivertices_cat2_new6, h_muonSV_mass_multivertices_cat2_new7, h_muonSV_mass_multivertices_cat2_new8, h_muonSV_mass_multivertices_cat2_new9, h_muonSV_mass_multivertices_cat2_new10, h_muonSV_mass_multivertices_cat2_new11, h_muonSV_mass_multivertices_cat2_new12);

   background_weighting(h_muonSV_mass_multivertices_cat11, h_muonSV_mass_multivertices_cat12, h_muonSV_mass_multivertices_cat13, h_muonSV_mass_multivertices_cat14, h_muonSV_mass_multivertices_cat15, h_muonSV_mass_multivertices_cat16, h_muonSV_mass_multivertices_cat17, h_muonSV_mass_multivertices_cat18, h_muonSV_mass_multivertices_cat19, h_muonSV_mass_multivertices_cat110, h_muonSV_mass_multivertices_cat111, h_muonSV_mass_multivertices_cat112);

   background_weighting(h_muonSV_mass_multivertices_cat21, h_muonSV_mass_multivertices_cat22, h_muonSV_mass_multivertices_cat23, h_muonSV_mass_multivertices_cat24, h_muonSV_mass_multivertices_cat25, h_muonSV_mass_multivertices_cat26, h_muonSV_mass_multivertices_cat27, h_muonSV_mass_multivertices_cat28, h_muonSV_mass_multivertices_cat29, h_muonSV_mass_multivertices_cat210, h_muonSV_mass_multivertices_cat211, h_muonSV_mass_multivertices_cat212);

   background_weighting(h_muonSV_mass_multivertices_cat31, h_muonSV_mass_multivertices_cat32, h_muonSV_mass_multivertices_cat33, h_muonSV_mass_multivertices_cat34, h_muonSV_mass_multivertices_cat35, h_muonSV_mass_multivertices_cat36, h_muonSV_mass_multivertices_cat37, h_muonSV_mass_multivertices_cat38, h_muonSV_mass_multivertices_cat39, h_muonSV_mass_multivertices_cat310, h_muonSV_mass_multivertices_cat311, h_muonSV_mass_multivertices_cat312);
 
   background_weighting(h_muonSV_mass_multivertices_cat41, h_muonSV_mass_multivertices_cat42, h_muonSV_mass_multivertices_cat43, h_muonSV_mass_multivertices_cat44, h_muonSV_mass_multivertices_cat45, h_muonSV_mass_multivertices_cat46, h_muonSV_mass_multivertices_cat47, h_muonSV_mass_multivertices_cat48, h_muonSV_mass_multivertices_cat49, h_muonSV_mass_multivertices_cat410, h_muonSV_mass_multivertices_cat411, h_muonSV_mass_multivertices_cat412);

   background_weighting(h_muonSV_mass_multivertices_cat51, h_muonSV_mass_multivertices_cat52, h_muonSV_mass_multivertices_cat53, h_muonSV_mass_multivertices_cat54, h_muonSV_mass_multivertices_cat55, h_muonSV_mass_multivertices_cat56, h_muonSV_mass_multivertices_cat57, h_muonSV_mass_multivertices_cat58, h_muonSV_mass_multivertices_cat59, h_muonSV_mass_multivertices_cat510, h_muonSV_mass_multivertices_cat511, h_muonSV_mass_multivertices_cat512);

   background_weighting(h_muonSV_mass_multivertices_cat61, h_muonSV_mass_multivertices_cat62, h_muonSV_mass_multivertices_cat63, h_muonSV_mass_multivertices_cat64, h_muonSV_mass_multivertices_cat65, h_muonSV_mass_multivertices_cat66, h_muonSV_mass_multivertices_cat67, h_muonSV_mass_multivertices_cat68, h_muonSV_mass_multivertices_cat69, h_muonSV_mass_multivertices_cat610, h_muonSV_mass_multivertices_cat611, h_muonSV_mass_multivertices_cat612);

   background_weighting(h_muonSV_mass_singlevertex_cat11, h_muonSV_mass_singlevertex_cat12, h_muonSV_mass_singlevertex_cat13, h_muonSV_mass_singlevertex_cat14, h_muonSV_mass_singlevertex_cat15, h_muonSV_mass_singlevertex_cat16, h_muonSV_mass_singlevertex_cat17, h_muonSV_mass_singlevertex_cat18, h_muonSV_mass_singlevertex_cat19, h_muonSV_mass_singlevertex_cat110, h_muonSV_mass_singlevertex_cat111, h_muonSV_mass_singlevertex_cat112);

   background_weighting(h_muonSV_mass_singlevertex_cat21, h_muonSV_mass_singlevertex_cat22, h_muonSV_mass_singlevertex_cat23, h_muonSV_mass_singlevertex_cat24, h_muonSV_mass_singlevertex_cat25, h_muonSV_mass_singlevertex_cat26, h_muonSV_mass_singlevertex_cat27, h_muonSV_mass_singlevertex_cat28, h_muonSV_mass_singlevertex_cat29, h_muonSV_mass_singlevertex_cat210, h_muonSV_mass_singlevertex_cat211, h_muonSV_mass_singlevertex_cat212);

   background_weighting(h_muonSV_mass_singlevertex_cat31, h_muonSV_mass_singlevertex_cat32, h_muonSV_mass_singlevertex_cat33, h_muonSV_mass_singlevertex_cat34, h_muonSV_mass_singlevertex_cat35, h_muonSV_mass_singlevertex_cat36, h_muonSV_mass_singlevertex_cat37, h_muonSV_mass_singlevertex_cat38, h_muonSV_mass_singlevertex_cat39, h_muonSV_mass_singlevertex_cat310, h_muonSV_mass_singlevertex_cat311, h_muonSV_mass_singlevertex_cat312);
 
   background_weighting(h_muonSV_mass_singlevertex_cat41, h_muonSV_mass_singlevertex_cat42, h_muonSV_mass_singlevertex_cat43, h_muonSV_mass_singlevertex_cat44, h_muonSV_mass_singlevertex_cat45, h_muonSV_mass_singlevertex_cat46, h_muonSV_mass_singlevertex_cat47, h_muonSV_mass_singlevertex_cat48, h_muonSV_mass_singlevertex_cat49, h_muonSV_mass_singlevertex_cat410, h_muonSV_mass_singlevertex_cat411, h_muonSV_mass_singlevertex_cat412);

   background_weighting(h_muonSV_mass_singlevertex_cat51, h_muonSV_mass_singlevertex_cat52, h_muonSV_mass_singlevertex_cat53, h_muonSV_mass_singlevertex_cat54, h_muonSV_mass_singlevertex_cat55, h_muonSV_mass_singlevertex_cat56, h_muonSV_mass_singlevertex_cat57, h_muonSV_mass_singlevertex_cat58, h_muonSV_mass_singlevertex_cat59, h_muonSV_mass_singlevertex_cat510, h_muonSV_mass_singlevertex_cat511, h_muonSV_mass_singlevertex_cat512);

   background_weighting(h_muonSV_mass_singlevertex_cat61, h_muonSV_mass_singlevertex_cat62, h_muonSV_mass_singlevertex_cat63, h_muonSV_mass_singlevertex_cat64, h_muonSV_mass_singlevertex_cat65, h_muonSV_mass_singlevertex_cat66, h_muonSV_mass_singlevertex_cat67, h_muonSV_mass_singlevertex_cat68, h_muonSV_mass_singlevertex_cat69, h_muonSV_mass_singlevertex_cat610, h_muonSV_mass_singlevertex_cat611, h_muonSV_mass_singlevertex_cat612);


 
   TFile *f_original = new TFile("/vols/cms/khl216/muonSV_BDT_background_fixed_nmuonSV0.root");
   TH1D *bdt_0p95 = (TH1D*) f_original->Get("BDT > 0.95");
   //bdt_0p97 = f.Get("background_bdt_0p97_new_samples_added")
   //bdt_0p99 = f.Get("background_bdt_0p99_new_samples_added")
   //bdt_0p997 = f.Get("background_bdt_0p997_new_samples_added")
   TH1D *bdt_0p9994 = (TH1D*) f_original->Get("BDT > 0.9994");
   //bdt_0 = f.Get("background_bdt_0_new_samples_added")
   
   /*   
   h_muonSV_mass_min_chi2_categorised1->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_min_chi21->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_min_chi2_multivertices1->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_min_chi2_singlevertex1->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_multivertices_cat1_new1->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_multivertices_cat2_new1->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral()); 
   h_muonSV_mass_multivertices_cat11->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_multivertices_cat21->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_multivertices_cat31->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_multivertices_cat41->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_multivertices_cat51->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_multivertices_cat61->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_singlevertex_cat11->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_singlevertex_cat21->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_singlevertex_cat31->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_singlevertex_cat41->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_singlevertex_cat51->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   h_muonSV_mass_singlevertex_cat61->Scale(bdt_0p9994->Integral()/bdt_0p95->Integral());
   */   


   gStyle->SetOptStat(0); gStyle->SetTextFont(42);
      
   TFile *f_single_cat1 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat1/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout << "TFile created" << std::endl;
   f_single_cat1->WriteObject(h_muonSV_mass_singlevertex_cat1_dataB, "background");
   f_single_cat1->WriteObject(h_muonSV_mass_singlevertex_cat1, "signal");
   f_single_cat1->WriteObject(h_muonSV_mass_singlevertex_cat1_dataB, "data_obs"); 

   TFile *f_single_cat2 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat2/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout << "TFile created" << std::endl;
   f_single_cat2->WriteObject(h_muonSV_mass_singlevertex_cat2_dataB, "background");
   f_single_cat2->WriteObject(h_muonSV_mass_singlevertex_cat2, "signal");
   f_single_cat2->WriteObject(h_muonSV_mass_singlevertex_cat2_dataB, "data_obs");

   TFile *f_single_cat3 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat3/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout << "TFile created" << std::endl;
   f_single_cat3->WriteObject(h_muonSV_mass_singlevertex_cat3_dataB, "background");
   f_single_cat3->WriteObject(h_muonSV_mass_singlevertex_cat3, "signal");
   f_single_cat3->WriteObject(h_muonSV_mass_singlevertex_cat3_dataB, "data_obs"); 
   
   TFile *f_single_cat4 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat4/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout << "TFile created" << std::endl;
   f_single_cat4->WriteObject(h_muonSV_mass_singlevertex_cat4_dataB, "background");
   f_single_cat4->WriteObject(h_muonSV_mass_singlevertex_cat4, "signal");
   f_single_cat4->WriteObject(h_muonSV_mass_singlevertex_cat4_dataB, "data_obs");
 
   TFile *f_single_cat5 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat5/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout << "TFile created" << std::endl;
   f_single_cat5->WriteObject(h_muonSV_mass_singlevertex_cat5_dataB, "background");
   f_single_cat5->WriteObject(h_muonSV_mass_singlevertex_cat5, "signal");
   f_single_cat5->WriteObject(h_muonSV_mass_singlevertex_cat5_dataB, "data_obs");

   TFile *f_single_cat6 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat6/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout << "TFile created" << std::endl;
   f_single_cat6->WriteObject(h_muonSV_mass_singlevertex_cat6_dataB, "background");
   f_single_cat6->WriteObject(h_muonSV_mass_singlevertex_cat6, "signal");
   f_single_cat6->WriteObject(h_muonSV_mass_singlevertex_cat6_dataB, "data_obs");

   TFile *f_multi_cat1 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat1/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout<<"TFile created" << std::endl;
   f_multi_cat1->WriteObject(h_muonSV_mass_multivertices_cat1_dataB, "background");
   f_multi_cat1->WriteObject(h_muonSV_mass_multivertices_cat1, "signal");
   f_multi_cat1->WriteObject(h_muonSV_mass_multivertices_cat1_dataB, "data_obs");

   TFile *f_multi_cat2 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat2/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout<<"TFile created" << std::endl;
   f_multi_cat2->WriteObject(h_muonSV_mass_multivertices_cat2_dataB, "background");
   f_multi_cat2->WriteObject(h_muonSV_mass_multivertices_cat2, "signal");     
   f_multi_cat2->WriteObject(h_muonSV_mass_multivertices_cat2_dataB, "data_obs");  

   TFile *f_multi_cat3 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat3/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout<<"TFile created" << std::endl;
   f_multi_cat3->WriteObject(h_muonSV_mass_multivertices_cat3_dataB, "background");
   f_multi_cat3->WriteObject(h_muonSV_mass_multivertices_cat3, "signal");
   f_multi_cat3->WriteObject(h_muonSV_mass_multivertices_cat3_dataB, "data_obs");

   TFile *f_multi_cat4 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat4/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout<<"TFile created" << std::endl;
   f_multi_cat4->WriteObject(h_muonSV_mass_multivertices_cat4_dataB, "background");
   f_multi_cat4->WriteObject(h_muonSV_mass_multivertices_cat4, "signal");
   f_multi_cat4->WriteObject(h_muonSV_mass_multivertices_cat4_dataB, "data_obs");

   TFile *f_multi_cat5 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat5/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout<<"TFile created" << std::endl;
   f_multi_cat5->WriteObject(h_muonSV_mass_multivertices_cat5_dataB, "background");
   f_multi_cat5->WriteObject(h_muonSV_mass_multivertices_cat5, "signal");
   f_multi_cat5->WriteObject(h_muonSV_mass_multivertices_cat5_dataB, "data_obs");

   TFile *f_multi_cat6 = new TFile(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat6/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "RECREATE");
   std::cout<<"TFile created" << std::endl;
   f_multi_cat6->WriteObject(h_muonSV_mass_multivertices_cat6_dataB, "background");
   f_multi_cat6->WriteObject(h_muonSV_mass_multivertices_cat6, "signal");
   f_multi_cat6->WriteObject(h_muonSV_mass_multivertices_cat6_dataB, "data_obs");
   
   TCanvas* c2 = new TCanvas("", "", 800, 700);
   c2->SetLogy();
   h_muonSV_mass_min_chi2_categorised1->SetLineColor(kRed);
   h_muonSV_mass_min_chi2_categorised->SetLineColor(kBlue+1);

   h_muonSV_mass_min_chi2_categorised1->GetXaxis()->SetTitle("Mass (GeV)");
   h_muonSV_mass_min_chi2_categorised1->GetYaxis()->SetTitle("Number of events");
   

   h_muonSV_mass_min_chi2_categorised1->DrawClone("hist e1");
   h_muonSV_mass_min_chi2_categorised->DrawClone("hist e1 Same");

   TLegend* out_legend2 = new TLegend(0.78, 0.695, 0.98, 0.775);
   out_legend2->AddEntry(h_muonSV_mass_min_chi2_categorised1, "Background", "l");
   out_legend2->AddEntry(h_muonSV_mass_min_chi2_categorised, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend2->Draw("Same");

   TCanvas* c3 = new TCanvas("", "", 800, 700);
   c3->SetLogy();
   h_muonSV_mass_min_chi21->SetLineColor(kRed);
   h_muonSV_mass_min_chi2->SetLineColor(kBlue+1);

   h_muonSV_mass_min_chi21->GetXaxis()->SetTitle("Mass (GeV)");
   h_muonSV_mass_min_chi21->GetYaxis()->SetTitle("Number of events");

   h_muonSV_mass_min_chi21->DrawClone("hist e1");
   h_muonSV_mass_min_chi2->DrawClone("hist e1 Same");

   TLegend* out_legend3 = new TLegend(0.78, 0.695, 0.98, 0.775);
   out_legend3->AddEntry(h_muonSV_mass_min_chi21, "Background", "l");
   out_legend3->AddEntry(h_muonSV_mass_min_chi2, "Signal", "l");
   out_legend3->Draw("Same");

   TCanvas* c4 = new TCanvas("", "", 800, 700);
   c4->SetLogy();
   h_nmuonSV1->SetLineColor(kRed);
   h_nmuonSV->SetLineColor(kBlue+1);

   h_nmuonSV1->GetXaxis()->SetTitle("nmuonSV");
   h_nmuonSV1->GetYaxis()->SetTitle("Number of events");
 
   h_nmuonSV1->DrawClone("hist e1");
   h_nmuonSV->DrawClone("hist e1 Same");

   TLegend* out_legend4 = new TLegend(0.78, 0.695, 0.98, 0.775);
   out_legend4->AddEntry(h_nmuonSV1, "Background", "l");
   out_legend4->AddEntry(h_nmuonSV, "Signal", "l");
   out_legend4->Draw("Same");

   TCanvas* c5 = new TCanvas("", "", 800, 700);
   c5->SetLogy();
   h_nmuonSV_multivertices1->SetLineColor(kRed);
   h_nmuonSV_multivertices->SetLineColor(kBlue+1);

   h_nmuonSV_multivertices1->GetXaxis()->SetTitle("nmuonSV");
   h_nmuonSV_multivertices1->GetYaxis()->SetTitle("Number of events");

   h_nmuonSV_multivertices1->DrawClone("hist e1");
   h_nmuonSV_multivertices->DrawClone("hist e1 Same");

   TLegend* out_legend5 = new TLegend(0.78, 0.695, 0.98, 0.775);
   out_legend5->AddEntry(h_nmuonSV_multivertices1, "Background", "l");
   out_legend5->AddEntry(h_nmuonSV_multivertices, "Signal", "l");
   out_legend5->Draw("Same");
 
   TCanvas* c6 = new TCanvas("", "", 800, 700);
   c6->SetLogy();
   h_muonSV_mass_min_chi2_multivertices1->SetLineColor(kRed);
   h_muonSV_mass_min_chi2_multivertices->SetLineColor(kBlue+1);

   h_muonSV_mass_min_chi2_multivertices1->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_min_chi2_multivertices1->GetYaxis()->SetTitle("Number of events/0.22 GeV");
   h_muonSV_mass_min_chi2_multivertices1->SetTitle("Multi vertex events");
   h_muonSV_mass_min_chi2_multivertices1->SetMaximum(1E5);
   h_muonSV_mass_min_chi2_multivertices1->SetMinimum(1E-1);

   h_muonSV_mass_min_chi2_multivertices1->DrawClone("hist e1");
   h_muonSV_mass_min_chi2_multivertices->DrawClone("hist e1 Same");

   TLegend* out_legend6 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend6->AddEntry(h_muonSV_mass_min_chi2_multivertices1, "Background", "l");
   out_legend6->AddEntry(h_muonSV_mass_min_chi2_multivertices, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend6->Draw("Same");

   TCanvas* c7 = new TCanvas("", "", 800, 700);
   c7->SetLogy();
   h_muonSV_mass_min_chi2_singlevertex1->SetLineColor(kRed);
   h_muonSV_mass_min_chi2_singlevertex->SetLineColor(kBlue+1);

   h_muonSV_mass_min_chi2_singlevertex1->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_min_chi2_singlevertex1->GetYaxis()->SetTitle("Number of events/0.22 GeV");
   h_muonSV_mass_min_chi2_singlevertex1->SetTitle("Single vertex events");
   h_muonSV_mass_min_chi2_singlevertex1->SetMaximum(1E5);
   h_muonSV_mass_min_chi2_singlevertex1->SetMinimum(1E-1);

   h_muonSV_mass_min_chi2_singlevertex1->DrawClone("hist e1");
   h_muonSV_mass_min_chi2_singlevertex->DrawClone("hist e1 Same");

   TLegend* out_legend7 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend7->AddEntry(h_muonSV_mass_min_chi2_singlevertex1, "Background", "l");
   out_legend7->AddEntry(h_muonSV_mass_min_chi2_singlevertex, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend7->Draw("Same");
   
   TCanvas* c8 = new TCanvas("", "", 800, 700);
   c8->SetLogy();

   h_muonSV_mass_min_chi2_multivertices->GetXaxis()->SetTitle("Mass (GeV)");
   h_muonSV_mass_min_chi2_multivertices->GetYaxis()->SetTitle("Number of events");
   h_muonSV_mass_min_chi2_multivertices->SetTitle("muonSV_mass_min_chi2_multivertex_cat");

   h_muonSV_mass_min_chi2_multivertices->DrawClone("hist e1");

   TLegend* out_legend8 = new TLegend(0.78, 0.695, 0.98, 0.775);
   out_legend8->AddEntry(h_muonSV_mass_min_chi2_multivertices, "Signal", "l");
   out_legend8->Draw("Same");

   TCanvas* c9 = new TCanvas("", "", 800, 700);
   c9->SetLogy();

   h_muonSV_mass_min_chi2_singlevertex->GetXaxis()->SetTitle("Mass (GeV)");
   h_muonSV_mass_min_chi2_singlevertex->GetYaxis()->SetTitle("Number of events");

   h_muonSV_mass_min_chi2_singlevertex->DrawClone("hist e1");

   TLegend* out_legend9 = new TLegend(0.78, 0.695, 0.98, 0.775);
   out_legend9->AddEntry(h_muonSV_mass_min_chi2_singlevertex, "Signal", "l");
   out_legend9->Draw("Same");

   TCanvas* c10 = new TCanvas("", "", 800, 700);
   c10->SetLogy();

   h_muonSV_mass_multivertices_cat1_new1->SetLineColor(kRed);
   h_muonSV_mass_multivertices_cat1_new->SetLineColor(kBlue+1);

   h_muonSV_mass_multivertices_cat1_new1->GetXaxis()->SetTitle("Mass (GeV)");
   h_muonSV_mass_multivertices_cat1_new1->GetYaxis()->SetTitle("Number of events");

   h_muonSV_mass_multivertices_cat1_new1->DrawClone("hist e1");
   h_muonSV_mass_multivertices_cat1_new->DrawClone("hist e1 Same");

   TLegend* out_legend10 = new TLegend(0.78, 0.695, 0.98, 0.775);
   out_legend10->AddEntry(h_muonSV_mass_multivertices_cat1_new1, "Background", "l");
   out_legend10->AddEntry(h_muonSV_mass_multivertices_cat1_new, "Signal", "l");
   out_legend10->Draw("Same");
   
   TCanvas* c11 = new TCanvas("", "", 800, 700);
   c11->SetLogy();

   h_muonSV_mass_multivertices_cat2_new1->SetLineColor(kRed);
   h_muonSV_mass_multivertices_cat2_new->SetLineColor(kBlue+1);
 
   h_muonSV_mass_multivertices_cat2_new1->GetXaxis()->SetTitle("Mass (GeV)");
   h_muonSV_mass_multivertices_cat2_new1->GetYaxis()->SetTitle("Number of events");

   h_muonSV_mass_multivertices_cat2_new1->DrawClone("hist e1");
   h_muonSV_mass_multivertices_cat2_new->DrawClone("hist e1 Same");

   TLegend* out_legend11 = new TLegend(0.78, 0.695, 0.98, 0.775);
   out_legend11->AddEntry(h_muonSV_mass_multivertices_cat2_new1, "Background", "l");
   out_legend11->AddEntry(h_muonSV_mass_multivertices_cat2_new, "Signal", "l");
   out_legend11->Draw("Same");
   
   TCanvas* c12 = new TCanvas("", "", 800, 700);
   c12->SetLogy();

   h_muonSV_mass_multivertices_cat11->SetLineColor(kRed);
   h_muonSV_mass_multivertices_cat1->SetLineColor(kBlue+1);
   h_muonSV_mass_multivertices_cat1_dataB->SetLineColor(kBlack);

   h_muonSV_mass_multivertices_cat1_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_multivertices_cat1_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_multivertices_cat1_dataB->SetTitle("Multi vertex category 1");

   h_muonSV_mass_multivertices_cat1_dataB->SetMaximum(1E5);
   h_muonSV_mass_multivertices_cat1_dataB->SetMinimum(1E-1);

   h_muonSV_mass_multivertices_cat1_dataB->DrawClone("hist e1");
   h_muonSV_mass_multivertices_cat1->DrawClone("hist e1 Same");
   //h_muonSV_mass_multivertices_cat1_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend12 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend12->AddEntry(h_muonSV_mass_multivertices_cat1_dataB, "Data", "l");
   //out_legend12->AddEntry(h_muonSV_mass_multivertices_cat11, "Background", "l");
   out_legend12->AddEntry(h_muonSV_mass_multivertices_cat1, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend12->Draw("Same");

   c12->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat1/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));


   TCanvas* c13 = new TCanvas("", "", 800, 700);
   c13->SetLogy();

   h_muonSV_mass_multivertices_cat21->SetLineColor(kRed);
   h_muonSV_mass_multivertices_cat2->SetLineColor(kBlue+1);
   h_muonSV_mass_multivertices_cat2_dataB->SetLineColor(kBlack);

   h_muonSV_mass_multivertices_cat2_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_multivertices_cat2_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_multivertices_cat2_dataB->SetTitle("Multi vertex category 2");

   h_muonSV_mass_multivertices_cat2_dataB->SetMaximum(1E5);
   h_muonSV_mass_multivertices_cat2_dataB->SetMinimum(1E-1);

   h_muonSV_mass_multivertices_cat2_dataB->DrawClone("hist e1");
   h_muonSV_mass_multivertices_cat2->DrawClone("hist e1 Same");
   //h_muonSV_mass_multivertices_cat2_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend13 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend13->AddEntry(h_muonSV_mass_multivertices_cat2_dataB, "Data", "l");
   //out_legend13->AddEntry(h_muonSV_mass_multivertices_cat21, "Background", "l");
   out_legend13->AddEntry(h_muonSV_mass_multivertices_cat2, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend13->Draw("Same");

   c13->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat2/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));

   TCanvas* c14 = new TCanvas("", "", 800, 700);
   c14->SetLogy();

   h_muonSV_mass_multivertices_cat31->SetLineColor(kRed);
   h_muonSV_mass_multivertices_cat3->SetLineColor(kBlue+1);
   h_muonSV_mass_multivertices_cat3_dataB->SetLineColor(kBlack);

   h_muonSV_mass_multivertices_cat3_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_multivertices_cat3_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_multivertices_cat3_dataB->SetTitle("Multi vertex category 3");

   h_muonSV_mass_multivertices_cat3_dataB->SetMaximum(1E5);
   h_muonSV_mass_multivertices_cat3_dataB->SetMinimum(1E-1);

   h_muonSV_mass_multivertices_cat3_dataB->DrawClone("hist e1");
   h_muonSV_mass_multivertices_cat3->DrawClone("hist e1 Same");
   //h_muonSV_mass_multivertices_cat3_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend14 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend14->AddEntry(h_muonSV_mass_multivertices_cat3_dataB, "Data", "l");
   //out_legend14->AddEntry(h_muonSV_mass_multivertices_cat31, "Background", "l");
   out_legend14->AddEntry(h_muonSV_mass_multivertices_cat3, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend14->Draw("Same");

   c14->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat3/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));


   TCanvas* c15 = new TCanvas("", "", 800, 700);
   c15->SetLogy();

   h_muonSV_mass_multivertices_cat41->SetLineColor(kRed);
   h_muonSV_mass_multivertices_cat4->SetLineColor(kBlue+1);
   h_muonSV_mass_multivertices_cat4_dataB->SetLineColor(kBlack);

   h_muonSV_mass_multivertices_cat4_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_multivertices_cat4_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_multivertices_cat4_dataB->SetTitle("Multi vertex category 4");

   h_muonSV_mass_multivertices_cat4_dataB->SetMaximum(1E5);
   h_muonSV_mass_multivertices_cat4_dataB->SetMinimum(1E-1);

   h_muonSV_mass_multivertices_cat4_dataB->DrawClone("hist e1");
   h_muonSV_mass_multivertices_cat4->DrawClone("hist e1 Same");
   //h_muonSV_mass_multivertices_cat4_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend15 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend15->AddEntry(h_muonSV_mass_multivertices_cat4_dataB, "Data", "l");
   //out_legend15->AddEntry(h_muonSV_mass_multivertices_cat41, "Background", "l");
   out_legend15->AddEntry(h_muonSV_mass_multivertices_cat4, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend15->Draw("Same");

   c15->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat4/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));

   TCanvas* c16 = new TCanvas("", "", 800, 700);
   c16->SetLogy();

   h_muonSV_mass_multivertices_cat51->SetLineColor(kRed);
   h_muonSV_mass_multivertices_cat5->SetLineColor(kBlue+1);
   h_muonSV_mass_multivertices_cat5_dataB->SetLineColor(kBlack);

   h_muonSV_mass_multivertices_cat5_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_multivertices_cat5_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_multivertices_cat5_dataB->SetTitle("Multi vertex category 5");

   h_muonSV_mass_multivertices_cat5_dataB->SetMaximum(1E5);
   h_muonSV_mass_multivertices_cat5_dataB->SetMinimum(1E-1);

   h_muonSV_mass_multivertices_cat5_dataB->DrawClone("hist e1");
   h_muonSV_mass_multivertices_cat5->DrawClone("hist e1 Same");
   //h_muonSV_mass_multivertices_cat5_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend16 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend16->AddEntry(h_muonSV_mass_multivertices_cat5_dataB, "Data", "l");
   //out_legend16->AddEntry(h_muonSV_mass_multivertices_cat51, "Background", "l");
   out_legend16->AddEntry(h_muonSV_mass_multivertices_cat5, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend16->Draw("Same");

   c16->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat5/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));

   TCanvas* c17 = new TCanvas("", "", 800, 700);
   c17->SetLogy();

   h_muonSV_mass_multivertices_cat61->SetLineColor(kRed);
   h_muonSV_mass_multivertices_cat6->SetLineColor(kBlue+1);
   h_muonSV_mass_multivertices_cat6_dataB->SetLineColor(kBlack);

   h_muonSV_mass_multivertices_cat6_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_multivertices_cat6_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_multivertices_cat6_dataB->SetTitle("Multi vertex category 6");

   h_muonSV_mass_multivertices_cat6_dataB->SetMaximum(1E5);
   h_muonSV_mass_multivertices_cat6_dataB->SetMinimum(1E-1);

   h_muonSV_mass_multivertices_cat6_dataB->DrawClone("hist e1");
   h_muonSV_mass_multivertices_cat6->DrawClone("hist e1 Same");
   //h_muonSV_mass_multivertices_cat6_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend17 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend17->AddEntry(h_muonSV_mass_multivertices_cat6_dataB, "Data", "l");
   //out_legend17->AddEntry(h_muonSV_mass_multivertices_cat61, "Background", "l");
   out_legend17->AddEntry(h_muonSV_mass_multivertices_cat6, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend17->Draw("Same");

   c17->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat6/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));


   TCanvas* c18 = new TCanvas("", "", 800, 700);
   c18->SetLogy();

   h_muonSV_mass_singlevertex_cat11->SetLineColor(kRed);
   h_muonSV_mass_singlevertex_cat1->SetLineColor(kBlue+1);
   h_muonSV_mass_singlevertex_cat1_dataB->SetLineColor(kBlack);

   h_muonSV_mass_singlevertex_cat1_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_singlevertex_cat1_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_singlevertex_cat1_dataB->SetTitle("Single vertex category 1");

   h_muonSV_mass_singlevertex_cat1_dataB->SetMaximum(1E5);
   h_muonSV_mass_singlevertex_cat1_dataB->SetMinimum(1E-1);

   h_muonSV_mass_singlevertex_cat1_dataB->DrawClone("hist e1");
   h_muonSV_mass_singlevertex_cat1->DrawClone("hist e1 Same");
   //h_muonSV_mass_singlevertex_cat1_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend18 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend18->AddEntry(h_muonSV_mass_singlevertex_cat1_dataB, "Data", "l");
   //out_legend18->AddEntry(h_muonSV_mass_singlevertex_cat11, "Background", "l");
   out_legend18->AddEntry(h_muonSV_mass_singlevertex_cat1, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend18->Draw("Same");

   c18->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat1/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));

   TCanvas* c19 = new TCanvas("", "", 800, 700);
   c19->SetLogy();

   h_muonSV_mass_singlevertex_cat21->SetLineColor(kRed);
   h_muonSV_mass_singlevertex_cat2->SetLineColor(kBlue+1);
   h_muonSV_mass_singlevertex_cat2_dataB->SetLineColor(kBlack);

   h_muonSV_mass_singlevertex_cat2_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_singlevertex_cat2_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_singlevertex_cat2_dataB->SetTitle("Single vertex category 2");

   h_muonSV_mass_singlevertex_cat2_dataB->SetMaximum(1E5);
   h_muonSV_mass_singlevertex_cat2_dataB->SetMinimum(1E-1);

   h_muonSV_mass_singlevertex_cat2_dataB->DrawClone("hist e1");
   h_muonSV_mass_singlevertex_cat2->DrawClone("hist e1 Same");
   //h_muonSV_mass_singlevertex_cat2_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend19 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend19->AddEntry(h_muonSV_mass_singlevertex_cat2_dataB, "Data", "l");
   //out_legend19->AddEntry(h_muonSV_mass_singlevertex_cat21, "Background", "l");
   out_legend19->AddEntry(h_muonSV_mass_singlevertex_cat2, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend19->Draw("Same");

   c19->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat2/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));

   TCanvas* c20 = new TCanvas("", "", 800, 700);
   c20->SetLogy();

   h_muonSV_mass_singlevertex_cat31->SetLineColor(kRed);
   h_muonSV_mass_singlevertex_cat3->SetLineColor(kBlue+1);
   h_muonSV_mass_singlevertex_cat3_dataB->SetLineColor(kBlack);

   h_muonSV_mass_singlevertex_cat3_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_singlevertex_cat3_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_singlevertex_cat3_dataB->SetTitle("Single vertex category 3");

   h_muonSV_mass_singlevertex_cat3_dataB->SetMaximum(1E5);
   h_muonSV_mass_singlevertex_cat3_dataB->SetMinimum(1E-1);

   h_muonSV_mass_singlevertex_cat3_dataB->DrawClone("hist e1");
   h_muonSV_mass_singlevertex_cat3->DrawClone("hist e1 Same");
  //h_muonSV_mass_singlevertex_cat3_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend20 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend20->AddEntry(h_muonSV_mass_singlevertex_cat3_dataB, "Data", "l");
   //out_legend20->AddEntry(h_muonSV_mass_singlevertex_cat31, "Background", "l");
   out_legend20->AddEntry(h_muonSV_mass_singlevertex_cat3, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend20->Draw("Same");

   c20->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat3/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));

 
   TCanvas* c21 = new TCanvas("", "", 800, 700);
   c21->SetLogy();

   h_muonSV_mass_singlevertex_cat41->SetLineColor(kRed);
   h_muonSV_mass_singlevertex_cat4->SetLineColor(kBlue+1);
   h_muonSV_mass_singlevertex_cat4_dataB->SetLineColor(kBlack);

   h_muonSV_mass_singlevertex_cat4_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_singlevertex_cat4_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_singlevertex_cat4_dataB->SetTitle("Single vertex category 4");

   h_muonSV_mass_singlevertex_cat4_dataB->SetMaximum(1E5);
   h_muonSV_mass_singlevertex_cat4_dataB->SetMinimum(1E-1);

   h_muonSV_mass_singlevertex_cat4_dataB->DrawClone("hist e1");
   h_muonSV_mass_singlevertex_cat4->DrawClone("hist e1 Same");
   //h_muonSV_mass_singlevertex_cat4_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend21 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend21->AddEntry(h_muonSV_mass_singlevertex_cat4_dataB, "Data", "l");
   //out_legend21->AddEntry(h_muonSV_mass_singlevertex_cat41, "Background", "l");
   out_legend21->AddEntry(h_muonSV_mass_singlevertex_cat4, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend21->Draw("Same");

   c21->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat4/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));


   TCanvas* c22 = new TCanvas("", "", 800, 700);
   c22->SetLogy();
   
   h_muonSV_mass_singlevertex_cat51->SetLineColor(kRed);
   h_muonSV_mass_singlevertex_cat5->SetLineColor(kBlue+1);
   h_muonSV_mass_singlevertex_cat5_dataB->SetLineColor(kBlack);  

   h_muonSV_mass_singlevertex_cat5_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_singlevertex_cat5_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_singlevertex_cat5_dataB->SetTitle("Single vertex category 5");

   h_muonSV_mass_singlevertex_cat5_dataB->SetMaximum(1E5);
   h_muonSV_mass_singlevertex_cat5_dataB->SetMinimum(1E-1);

   h_muonSV_mass_singlevertex_cat5_dataB->DrawClone("hist e1");
   h_muonSV_mass_singlevertex_cat5->DrawClone("hist e1 Same");
   //h_muonSV_mass_singlevertex_cat5_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend22 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend22->AddEntry(h_muonSV_mass_singlevertex_cat5_dataB, "Data", "l");
   //out_legend22->AddEntry(h_muonSV_mass_singlevertex_cat51, "Background", "l");
   out_legend22->AddEntry(h_muonSV_mass_singlevertex_cat5, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend22->Draw("Same");

   c22->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat5/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));


   TCanvas* c23 = new TCanvas("", "", 800, 700);
   c23->SetLogy();

   h_muonSV_mass_singlevertex_cat61->SetLineColor(kRed);
   h_muonSV_mass_singlevertex_cat6->SetLineColor(kBlue+1);
   h_muonSV_mass_singlevertex_cat6_dataB->SetLineColor(kBlack);

   h_muonSV_mass_singlevertex_cat6_dataB->GetXaxis()->SetTitle("Dimuon mass (GeV)");
   h_muonSV_mass_singlevertex_cat6_dataB->GetYaxis()->SetTitle("Events/0.22 GeV");
   h_muonSV_mass_singlevertex_cat6_dataB->SetTitle("Single vertex category 6");

   h_muonSV_mass_singlevertex_cat6_dataB->SetMaximum(1E5);
   h_muonSV_mass_singlevertex_cat6_dataB->SetMinimum(1E-1);

   h_muonSV_mass_singlevertex_cat6_dataB->DrawClone("hist e1");
   h_muonSV_mass_singlevertex_cat6->DrawClone("hist e1 Same");
   //h_muonSV_mass_singlevertex_cat6_dataB->DrawClone("hist e1 Same");

   TLegend* out_legend23 = new TLegend(0.48, 0.795, 0.88, 0.875);
   out_legend23->AddEntry(h_muonSV_mass_singlevertex_cat6_dataB, "Data", "l");
   //out_legend23->AddEntry(h_muonSV_mass_singlevertex_cat61, "Background", "l");
   out_legend23->AddEntry(h_muonSV_mass_singlevertex_cat6, "Vector portal (m=2 GeV, c#tau=10 mm)", "l");
   out_legend23->Draw("Same");

   c23->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat6/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));
 
   /*
   Double_t binwidth = 22.0/50.0;
   Int_t sideband1_x1 = (Int_t) 1.9/binwidth;
   Int_t sideband1_x2 = (Int_t) 1.96/binwidth;
   Int_t sideband2_x1 = (Int_t) 2.04/binwidth;
   Int_t sideband2_x2 = (Int_t) 2.1/binwidth;

   std::cout << "sideband1_x1 = " << sideband1_x1 << std::endl;
   std::cout << "sideband1_x2 = " << sideband1_x2 << std::endl;  
   std::cout << "sideband2_x1 = " << sideband2_x1 << std::endl;
   std::cout << "sideband2_x2 = " << sideband2_x2 << std::endl;
   */
   /*
   Double_t single_vertex_cat_bkg = (h_muonSV_mass_min_chi2_singlevertex1->Integral(sideband1_x1, sideband1_x2) + h_muonSV_mass_min_chi2_singlevertex1->Integral(sideband2_x1, sideband2_x2))*4/6 ;

   Double_t single_vertex_cat_sig = h_muonSV_mass_min_chi2_singlevertex->Integral(sideband1_x2, sideband2_x1);

   Double_t multi_vertex_cat_bkg = (h_muonSV_mass_min_chi2_multivertices1->Integral(sideband1_x1, sideband1_x2) + h_muonSV_mass_min_chi2_multivertices1->Integral(sideband2_x1, sideband2_x2))*4/6;

   Double_t multi_vertex_cat_sig = h_muonSV_mass_min_chi2_multivertices->Integral(sideband1_x2, sideband2_x1);
   */
   /*
   Double_t single_vertex_cat_bkg = h_muonSV_mass_min_chi2_singlevertex1->Integral(83,100);
   Double_t single_vertex_cat_sig = h_muonSV_mass_min_chi2_singlevertex->Integral(83,100);
   Double_t multi_vertex_cat_bkg = h_muonSV_mass_min_chi2_multivertices1->Integral(83,100);
   Double_t multi_vertex_cat_sig = h_muonSV_mass_min_chi2_multivertices->Integral(83,100);

   Double_t single_vertex_cat1_bkg = h_muonSV_mass_singlevertex_cat11->Integral(83,100);
   Double_t single_vertex_cat1_sig = h_muonSV_mass_singlevertex_cat1->Integral(83,100);
   Double_t single_vertex_cat2_bkg = h_muonSV_mass_singlevertex_cat21->Integral(83,100);
   Double_t single_vertex_cat2_sig = h_muonSV_mass_singlevertex_cat2->Integral(83,100);
   Double_t single_vertex_cat3_bkg = h_muonSV_mass_singlevertex_cat31->Integral(83,100);
   Double_t single_vertex_cat3_sig = h_muonSV_mass_singlevertex_cat3->Integral(83,100);
   Double_t single_vertex_cat4_bkg = h_muonSV_mass_singlevertex_cat41->Integral(83,100);
   Double_t single_vertex_cat4_sig = h_muonSV_mass_singlevertex_cat4->Integral(83,100);
   Double_t single_vertex_cat5_bkg = h_muonSV_mass_singlevertex_cat51->Integral(83,100);
   Double_t single_vertex_cat5_sig = h_muonSV_mass_singlevertex_cat5->Integral(83,100);
   Double_t single_vertex_cat6_bkg = h_muonSV_mass_singlevertex_cat61->Integral(83,100);
   Double_t single_vertex_cat6_sig = h_muonSV_mass_singlevertex_cat6->Integral(83,100);

   Double_t multi_vertex_cat1_bkg = h_muonSV_mass_multivertices_cat11->Integral(83,100);
   Double_t multi_vertex_cat1_sig = h_muonSV_mass_multivertices_cat1->Integral(83,100);
   Double_t multi_vertex_cat2_bkg = h_muonSV_mass_multivertices_cat21->Integral(83,100);
   Double_t multi_vertex_cat2_sig = h_muonSV_mass_multivertices_cat2->Integral(83,100);
   Double_t multi_vertex_cat3_bkg = h_muonSV_mass_multivertices_cat31->Integral(83,100);
   Double_t multi_vertex_cat3_sig = h_muonSV_mass_multivertices_cat3->Integral(83,100);
   Double_t multi_vertex_cat4_bkg = h_muonSV_mass_multivertices_cat41->Integral(83,100);
   Double_t multi_vertex_cat4_sig = h_muonSV_mass_multivertices_cat4->Integral(83,100);
   Double_t multi_vertex_cat5_bkg = h_muonSV_mass_multivertices_cat51->Integral(83,100);
   Double_t multi_vertex_cat5_sig = h_muonSV_mass_multivertices_cat5->Integral(83,100);
   Double_t multi_vertex_cat6_bkg = h_muonSV_mass_multivertices_cat61->Integral(83,100);
   Double_t multi_vertex_cat6_sig = h_muonSV_mass_multivertices_cat6->Integral(83,100);


 
   std::cout << "single_vertex_cat_bkg norm = " << single_vertex_cat_bkg << std::endl;
   std::cout << "single_vertex_cat_sig norm = " << single_vertex_cat_sig << std::endl;
   std::cout << "multi_vertex_cat_bkg norm = " << multi_vertex_cat_bkg << std::endl;
   std::cout << "multi_vertex_cat_sig norm = " << multi_vertex_cat_sig << std::endl;

   std::cout << "single_vertex_cat1_bkg norm = " << single_vertex_cat1_bkg << std::endl;
   std::cout << "single_vertex_cat1_sig norm = " << single_vertex_cat1_sig << std::endl;
   std::cout << "single_vertex_cat2_bkg norm = " << single_vertex_cat2_bkg << std::endl;
   std::cout << "single_vertex_cat2_sig norm = " << single_vertex_cat2_sig << std::endl;
   std::cout << "single_vertex_cat3_bkg norm = " << single_vertex_cat3_bkg << std::endl;
   std::cout << "single_vertex_cat3_sig norm = " << single_vertex_cat3_sig << std::endl;
   std::cout << "single_vertex_cat4_bkg norm = " << single_vertex_cat4_bkg << std::endl;
   std::cout << "single_vertex_cat4_sig norm = " << single_vertex_cat4_sig << std::endl;
   std::cout << "single_vertex_cat5_bkg norm = " << single_vertex_cat5_bkg << std::endl;
   std::cout << "single_vertex_cat5_sig norm = " << single_vertex_cat5_sig << std::endl;
   std::cout << "single_vertex_cat6_bkg norm = " << single_vertex_cat6_bkg << std::endl;
   std::cout << "single_vertex_cat6_sig norm = " << single_vertex_cat6_sig << std::endl;

   std::cout << "multi_vertex_cat1_bkg_norm = " << multi_vertex_cat1_bkg << std::endl;
   std::cout << "multi_vertex_cat1_sig_norm = " << multi_vertex_cat1_sig << std::endl;   
   std::cout << "multi_vertex_cat2_bkg_norm = " << multi_vertex_cat2_bkg << std::endl;
   std::cout << "multi_vertex_cat2_sig_norm = " << multi_vertex_cat2_sig << std::endl; 
   std::cout << "multi_vertex_cat3_bkg_norm = " << multi_vertex_cat3_bkg << std::endl;
   std::cout << "multi_vertex_cat3_sig_norm = " << multi_vertex_cat3_sig << std::endl; 
   std::cout << "multi_vertex_cat4_bkg_norm = " << multi_vertex_cat4_bkg << std::endl;
   std::cout << "multi_vertex_cat4_sig_norm = " << multi_vertex_cat4_sig << std::endl;
   std::cout << "multi_vertex_cat5_bkg_norm = " << multi_vertex_cat5_bkg << std::endl;
   std::cout << "multi_vertex_cat5_sig_norm = " << multi_vertex_cat5_sig << std::endl;
   std::cout << "multi_vertex_cat6_bkg_norm = " << multi_vertex_cat6_bkg << std::endl;
   std::cout << "multi_vertex_cat6_sig_norm = " << multi_vertex_cat6_sig << std::endl;
   */
}
