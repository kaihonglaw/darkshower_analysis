# import ROOT in batch mode                                                                                                          
import os
import sys
#import PyFunctions
#from PyFunctions import *
import math
from array import array
import re
import json
import types

#import sys                                                                                                                          
oldargv = sys.argv[:]
sys.argv = [ '-b-' ]
import ROOT
ROOT.gROOT.SetBatch(True)
sys.argv = oldargv

import numpy as np
from array import array
import pandas as pd
import scipy.stats

# from ROOT import TH1F, TH1D, TH2D, TFile, TLorentzVector, TVector3, TChain, TProfile, TTree, TGraph
from ROOT import *

# load FWLite C++ libraries                                                                                                          
ROOT.gSystem.Load("libFWCoreFWLite.so");
ROOT.gSystem.Load("libDataFormatsFWLite.so");
ROOT.FWLiteEnabler.enable()
def makedatacardSimple(mass, lifetime):
    mu = mass
    ctau = lifetime
    sig = 0.00190827951434
    gam = 0.0183813166745
    category = 4

    binwidth = sig/5
    ndecimal = num_after_point(binwidth) + 1

    xsigup = mu + 2*sig
    xsigdown = mu - 2*sig

    ''' 
    sig_for_background_fit = 0.0145295860772 
    gam_for_background_fit = 0.00908020946671
    G = 2*sig_for_background_fit*np.sqrt(2*np.log(2))
    L = 2*gam_for_background_fit
 
    HWHM = (0.5346*L + np.sqrt(0.2166*L**2 + G**2))/2
    '''

    HWHM = 0.01*mu
   
    xfitup = mu + 5*HWHM
    xfitdown = mu - 5*HWHM

    bins = 50

    binwidth = (xfitup - xfitdown)/bins


    f  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat{}/vector_m_{}/output_vector_{}_{}_1_1.root".format(category, mass, mass, lifetime))
    h2 = f.Get("background")
    
    f1 = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat{}/vector_m_{}/output_vector_{}_{}_1_1.root".format(category, mass, mass, lifetime))  
    h3 = f1.Get("signal") 
    '''
    #Dummy data
    function = ROOT.TF1("expF","100.*exp(-(x-{}))".format(mass));
    random = ROOT.TRandom2(1);
    for i in range(h2.GetNbinsX()):
        value = random.Poisson(function.Eval(h2.GetBinCenter(i+1)))
        print(i,h2.GetBinCenter(i+1),value)
        h2.SetBinContent(i+1,value)
        h2.SetBinError(i+1,value**0.5)
    '''
    # tree_mudata.Draw('mass>>h2',"lxy > {} && lxy < {} && dimuon_pt > {} && dimuon_pt < {} && pass_all_iso_both == {} && pass_all_iso_one == {} && pass_all_iso_none == {} && mass > {} && mass < {}".format(lxybins[j,0], lxybins[j,1], ptbins[j1,0], ptbins[j1,1], isobins[j2,0], isobins[j2,1], isobins[j2,2], xfitdown, xfitup),'')

    print(float(xfitdown), float(xfitup))

    x_unmasked = []
    y_unmasked = []
    print(h2.GetNbinsX())
    for i in range(h2.GetNbinsX()):
        if(h2.GetBinCenter(i+1)>float(xfitdown)): 
	    #print h2.GetBinCenter(i+1)
            x_unmasked.append(round(h2.GetBinCenter(i+1),ndecimal))
            y_unmasked.append(h2.GetBinContent(i+1))

    # print "x_unmasked", x_unmasked
    # print "y_unmasked", y_unmasked
    # print "y_unmasked_error", np.sqrt(y_unmasked)

    data = ROOT.TH1F("data1","Histogram of data_obs__x", int(bins), float(xfitdown), float(xfitup))
    for i in range(h2.GetNbinsX()):
	# print i, x_unmasked[i],y_unmasked[i]
        data.SetBinContent(i+1,y_unmasked[i])
        data.SetBinError(i+1, h2.GetBinError(i+1))

    h1 = h2.Clone("h2");#ROOT.TH1F("h1","h1", int(bins), float(xfitdown), float(xfitup))

    # tree_mudata.Draw('mass>>h1',"lxy > {} && lxy < {} && dimuon_pt > {} && dimuon_pt < {} && pass_all_iso_both == {} && pass_all_iso_one == {} && pass_all_iso_none == {} && mass > {} && mass < {} && (mass < {} || mass > {})".format(lxybins[j,0], lxybins[j,1], ptbins[j1,0], ptbins[j1,1], isobins[j2,0], isobins[j2,1], isobins[j2,2], xfitdown, xfitup, xsigdown, xsigup),'')

    x_masked = []
    y_masked = []
    print(h1.GetNbinsX())
    for i in range(h1.GetNbinsX()):
	# if(h1.GetBinCenter(i+1)>float(xfitdown) and h1.GetBinContent(i+1)>0):
	#         x_masked.append(round(h1.GetBinCenter(i+1),3))
	#         y_masked.append(h1.GetBinContent(i+1))

        if(h1.GetBinCenter(i+1)>float(xfitdown) and h1.GetBinCenter(i+1)<float(xsigdown)):
            x_masked.append(round(h1.GetBinCenter(i+1),ndecimal))
            y_masked.append(h1.GetBinContent(i+1))

	# if(h1.GetBinCenter(i+1)>=float(xsigdown) and h1.GetBinCenter(i+1)<=float(xsigup) and h1.GetBinContent(i+1)>0):
	#         x_masked.append(round(h1.GetBinCenter(i+1),3))
	#         y_masked.append(h1.GetBinContent(i+1))

        if(h1.GetBinCenter(i+1)>float(xsigup) and h1.GetBinCenter(i+1)<float(xfitup)):
            x_masked.append(round(h1.GetBinCenter(i+1),ndecimal))
            y_masked.append(h1.GetBinContent(i+1))

    # print "x_masked", x_masked
    # print "y_masked", y_masked
    # print "y_masked_error", np.sqrt(y_masked)

    x_sigdata = [] 
    y_sigdata = []
    for i in range(h2.GetNbinsX()):
        if(h2.GetBinCenter(i+1)>float(xsigdown) and h2.GetBinCenter(i+1)<float(xsigup)):
            x_sigdata.append(round(h2.GetBinCenter(i+1),ndecimal))
            y_sigdata.append(h2.GetBinContent(i+1))


    numbins = len(x_unmasked) 
    numdata = sum(y_unmasked)
    numsideband = sum(y_masked)
    
    ###MAKE DATACARD

    x = ROOT.RooRealVar("x","x",float(xfitdown),float(xfitup))

    l = ROOT.RooArgList(x)

    x.setRange("loSB", mu-5*HWHM, mu-2*HWHM)
    x.setRange("hiSB", mu+2*HWHM, mu+5*HWHM)
    x.setRange("full", mu-5*HWHM, mu+5*HWHM)
    fit_range = "loSB,hiSB"


    data_obs = ROOT.RooDataHist("data_obs", "data_obs", l, data)
    # mean = ROOT.RooRealVar('mean', 'Mean of DoubleCB', float(mass- (25*binwidth)), float(mass + (25*binwidth)))                    
    mean = ROOT.RooRealVar('mean', 'Mean of Voigtian', mu)
    sigma = ROOT.RooRealVar('sigma', 'Sigma of Voigitan', sig)
    gamma = ROOT.RooRealVar('gamma', 'Gamma of Voigitan', gam)
    '''
    alpha_1 = ROOT.RooRealVar('alpha_1', 'alpha1 of DoubleCB',  1)
    alpha_2 = ROOT.RooRealVar('alpha_2', 'alpha2 of DoubleCB',  -1.25)
    n_1 = ROOT.RooRealVar('n_1', 'n1 of DoubleCB', 5)
    n_2 = ROOT.RooRealVar('n_2', 'n2 of DoubleCB', 5)
    '''
    #cbs_1 = ROOT.RooCBShape("CrystallBall_1", "CrystallBall_1", x, mean, sigma, alpha_1, n_1)
    #cbs_2 = ROOT.RooCBShape("CrystallBall_2", "CrystallBall_2", x, mean, sigma, alpha_2, n_2)
    #mc_frac = ROOT.RooRealVar("mc_frac", "mc_frac", 0.5)
    #signal = ROOT.RooAddPdf('signal', 'signal', ROOT.RooArgList(cbs_1,cbs_2), ROOT.RooArgList(mc_frac))
    #signal = ROOT.RooGaussian("signal", "signal", x, mean, sigma)
    signal = ROOT.RooVoigtian("signal", "signal", x, mean, gamma, sigma)

    ns = h3.Integral()
    print("ns =", ns)
    nS = ns
    sig_norm = ROOT.RooRealVar("sig_norm","sig_norm",nS,0,10*nS)
    
    orderbern=3
    pbern = [0]*(orderbern+1)
    parbern = ROOT.RooArgList()
    for i in range(orderbern+1): 
        pbern[i] = ROOT.RooRealVar("pbern{}".format(i),"pbern{}".format(i),0,100)
        parbern.add(pbern[i])
    
    # backgroundbern = ROOT.RooBernsteinFast(1)("backgroundbern","backgroundbern", x, parbern)
    backgroundbern = ROOT.RooBernsteinFast(orderbern)("backgroundbern","backgroundbern", x, parbern)
    # backgroundbern = ROOT.RooBernsteinFast(orderbern)("backgroundbern","backgroundbern", x, parbern)

    #Polynomial
    polynomial_c1 = ROOT.RooRealVar("poly_c1", "poly_c1", 0, -100, 100, "GeV^-1")
    polynomial_c2 = ROOT.RooRealVar("poly_c2", "poly_c2", 0, -100, 100, "GeV^-2")
    polynomial_c3 = ROOT.RooRealVar("poly_c3", "poly_c3", 0, -100, 100, "GeV^-3")
    #backgroundpoly = ROOT.RooPolynomial("backgroundpoly", "backgroundpoly", x, ROOT.RooArgList(polynomial_c1, polynomial_c2, polynomial_c3)) 
    backgroundpoly = ROOT.RooPolynomial("backgroundpoly", "backgroundpoly", x, ROOT.RooArgList(polynomial_c1))

    nB = data.Integral()
    print("nB =", nB)
    background_norm = ROOT.RooRealVar("roomultipdf_norm","Number of background events",nB,0.9*nB,1.1*nB)

    '''
    backgroundbern.fitTo(data_obs,ROOT.RooFit.Minimizer("Minuit2","Migrad"))
    backgroundbern.fitTo(data_obs,ROOT.RooFit.Minimizer("Minuit2","Migrad"))
    resultbern = ROOT.RooFitResult(backgroundbern.fitTo(data_obs, ROOT.RooFit.Save(ROOT.kTRUE), ROOT.RooFit.Minimizer("Minuit2","Migrad")))
    '''
   
    backgroundpoly.fitTo(data_obs, ROOT.RooFit.Range(fit_range), ROOT.RooFit.Minimizer("Minuit2","Migrad"))
    #backgroundpoly.fitTo(data_obs,ROOT.RooFit.Minimizer("Minuit2","Migrad"))

    #Exponential
    alpha = ROOT.RooRealVar("alpha", "alpha", 0, -10, 10 )
    backgroundexp = ROOT.RooExponential("backgroundexp", "backgroundexp", x, alpha )
    backgroundexp.fitTo(data_obs,ROOT.RooFit.Range(fit_range), ROOT.RooFit.Minimizer("Minuit2","Migrad"))

    # # Power law function: using RooGenericPdf functionality
    pow_1 = ROOT.RooRealVar("pow_1","pow_1", 0, -10, 10)
    backgroundpow_1 = ROOT.RooGenericPdf("backgroundpow_1", "TMath::Power(@0,@1)", ROOT.RooArgList(x,pow_1) )
    backgroundpow_1.fitTo(data_obs,ROOT.RooFit.Range(fit_range), ROOT.RooFit.Minimizer("Minuit2","Migrad"))


    #resultpoly= ROOT.RooFitResult(backgroundpoly.fitTo(data_obs, ROOT.RooFit.Save(ROOT.kTRUE), ROOT.RooFit.Minimizer("Minuit2","Migrad")))

    # # Make a RooCategory object: this will control which PDF is "active"
    cat = ROOT.RooCategory("pdfindex_cat{}".format(category), "Index of Pdf which is active for cat{}".format(category))
    # 
    # # Make a RooArgList of the models
    models = ROOT.RooArgList()
    models.add(backgroundpoly)
    models.add(backgroundexp)
    models.add(backgroundpow_1)
    # 
    # # Build the RooMultiPdf object
    multipdf = ROOT.RooMultiPdf("multipdf_cat{}".format(category), "MultiPdf for cat{}".format(category), cat, models)

    c1 = ROOT.TCanvas("c1","c1")
    c1.cd()
    xframe1 = x.frame(ROOT.RooFit.Title("mass {} GeV".format(mass)))
    data_obs.plotOn(xframe1, ROOT.RooFit.MarkerColor(0), ROOT.RooFit.LineColor(0))  #invisible plot of the full data set
    backgroundpoly.plotOn(xframe1, ROOT.RooFit.NormRange(fit_range), ROOT.RooFit.Range("full"), ROOT.RooFit.LineColor(2),ROOT.RooFit.Name("bkg_poly"), ROOT.RooFit.LineStyle(2))

    npar2 = backgroundpoly.getParameters(data_obs).selectByAttrib("Constant",False).getSize()
    print("background chi^2 = ", xframe1.chiSquare())
    print("background npar = ", npar2)
    print("background chi^2/ndf = ", xframe1.chiSquare(npar2))

    backgroundexp.plotOn(xframe1,ROOT.RooFit.NormRange(fit_range), ROOT.RooFit.Range("full"), ROOT.RooFit.LineColor(3),ROOT.RooFit.Name("bkg_exp"), ROOT.RooFit.LineStyle(2))
    backgroundpow_1.plotOn(xframe1, ROOT.RooFit.NormRange(fit_range), ROOT.RooFit.Range("full"), ROOT.RooFit.LineColor(4),ROOT.RooFit.Name("bkg_pow"), ROOT.RooFit.LineStyle(2))
    data_obs.plotOn(xframe1, ROOT.RooFit.CutRange(fit_range), ROOT.RooFit.Name("data"))
	 
 
    xframe1.Draw()
    # leg = ROOT.TLegend(0.6,0.1,0.9,0.4)                                                   

    xframe1.GetYaxis().SetTitle("Events/ {} GeV".format(binwidth))
    # xframe1.GetYaxis().SetTitleSize(0.05)
    # xframe1.GetYaxis().SetLabelSize(0.045)
    xframe1.GetYaxis().SetTitleOffset(1.35)

    # xframe1.GetXaxis().SetLabelSize(0.17)
    # xframe1.GetXaxis().SetTitleSize(0.21)
    # xframe1.GetXaxis().SetTitleOffset(0.85)
    xframe1.GetXaxis().SetTitle("Mass [GeV]")
				       
    leg1 = ROOT.TLegend(0.35,0.7,0.78,0.9)
    leg1.SetLineColor(0)
    leg1.SetFillColor(0)
    leg1.SetFillStyle(0)
    leg1.AddEntry(xframe1.findObject("data"), "Data", "pe")
    leg1.AddEntry(xframe1.findObject("bkg_poly"), "#color[2]{%s fit}" %("Polynomial (first order)"), "l")
    leg1.AddEntry(xframe1.findObject("bkg_exp"), "#color[3]{%s fit}" %("Exponential"), "l")
    leg1.AddEntry(xframe1.findObject("bkg_pow"), "#color[4]{%s fit}" %("Power law"), "l")

    
    leg1.SetTextFont(42)
    leg1.SetBorderSize(0)
    leg1.Draw()

    c1.Draw()
    c1.SaveAs("/home/hep/khl216/CMSSW_10_2_13/src/datacard/dqcd/muonSV/categories_single_multi_data/m_{}/multipdffits_mass{}_cat{}.png".format(mass, mass, category))
    # cat = ROOT.RooCategory("pdf_index","Index of Pdf which is active")
    # mypdfs = ROOT.RooArgList()
    # mypdfs.add(backgroundbern)
    # multipdf = ROOT.RooMultiPdf("roomultipdf","All Pdfs",cat,mypdfs)

    mybkgs = ROOT.RooWorkspace("mybkgs", "workspace")
    getattr(mybkgs,'import')(cat)
    getattr(mybkgs,'import')(background_norm)
    #getattr(mybkgs,'import')(backgroundpoly)
    getattr(mybkgs,'import')(multipdf)
    getattr(mybkgs,'import')(data_obs)
    getattr(mybkgs,'import')(signal)

    mybkgs.writeToFile('/home/hep/khl216/CMSSW_10_2_13/src/datacard/dqcd/muonSV/categories_single_multi_data/m_{}/envelope-shapes-TH1_mass{}_ctau{}_cat{}.root'.format(mass, mass, lifetime, category))
    mybkgs.Print()

    print("Multipdf RooWorkspace made")
    ROOT.gDirectory.Add(mybkgs)
    
    ''' 
    datacard = open('/home/hep/khl216/CMSSW_10_2_13/src/datacard/dqcd/muonSV/categories/m_{}/simple-shapes-TH1_mass{}_ctau{}.txt'.format(mass, mass,lifetime), "w")
    datacard.write("imax 1  number of channels\n")
    datacard.write("jmax 1  number of backgrounds\n")
    datacard.write("kmax *  number of nuisance parameters (sources of systematical uncertainties)\n")
    datacard.write("------------------------------------\n")
    datacard.write("shapes data_obs * simple-shapes-TH1_mass{}_ctau{}.root mybkgs:data_obs\n".format(mass,lifetime))
    datacard.write("shapes signal * simple-shapes-TH1_mass{}_ctau{}.root mybkgs:signal\n".format(mass, lifetime))
    datacard.write("shapes background * simple-shapes-TH1_mass{}_ctau{}.root mybkgs:backgroundpoly\n".format(mass, lifetime))
    # datacard.write("shapes background * simple-shapes-TH1_mass{}_order{}.root mybkgs:roomultipdf\n".format(mass, orderbern))
    
    datacard.write("------------------------------------\n")
    datacard.write("bin bin1\n")
    datacard.write("observation -1\n")
    datacard.write("------------------------------------\n")
    datacard.write("bin bin1 bin1\n")
    datacard.write("process signal background\n")
    datacard.write("process 0 1\n")
    #datacard.write("rate {} {}\n".format(nS, 1))                                                         
    datacard.write("rate {} {}\n".format(nS, nB))
    datacard.write("------------------------------------\n")
    datacard.write("lumi lnN 1.10 1.0\n")
    #datacard.write("bgnorm lnN - 1.05\n")                                                                   
    #datacard.write("signorm lnN 1.05 -\n")   
    #datacard.write("trigsf_unc lnN {} -\n".format(1))
    #datacard.write("oneminuseff lnN {} -\n".format(1))
    #datacard.write("mcstat_unc lnN {} -\n".format(1))
    #datacard.write("sigma param {} {}\n".format(sig,sig/2))
    #datacard.write("mean param {} {}\n".format(mu,sig))
    # datacard.write("mean1 param {} {}\n".format(mu,sig))
    # datacard.write("pdf_index discrete\n".format())
    
    datacard.close()
    '''


def num_after_point(x):
    s = str(x)
    if not '.' in s:
        return 0
    return len(s) - s.index('.') - 1
if __name__ == "__main__":
    makedatacardSimple(2, 500)

