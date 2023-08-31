import ROOT
from ROOT import *


def makedatacardSimple(mass, lifetime):

    nbins = 50.0
    nsigma = 10.0
    sigmaperbin = nsigma/nbins
    print("sigmaperbin = ", sigmaperbin)

    sideband1_binx1 = 1.0
    sideband1_binx2 = 3.0/sigmaperbin
    sideband2_binx1 = 7.0/sigmaperbin + 1
    sideband2_binx2 = nbins


    sideband1_binx1 = int(sideband1_binx1)
    sideband1_binx2 = int(sideband1_binx2)
    sideband2_binx1 = int(sideband2_binx1)
    sideband2_binx2 = int(sideband2_binx2)

    print("sideband1_binx1 = ", sideband1_binx1)
    print("sideband1_binx2 = ", sideband1_binx2)
    print("sideband2_binx1 = ", sideband2_binx1)
    print("sideband2_binx2 = ", sideband2_binx2)

    f  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat1/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h2 = f.Get("background") 
    h3 = f.Get("signal")

    ns = h3.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns =", ns)

    nB = (h2.Integral(sideband1_binx1, sideband1_binx2) + h2.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB =", nB)

    nobs = h2.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs =", nobs)

    f2  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat2/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h4 = f2.Get("background")
    h5 = f2.Get("signal")

    ns2 = h5.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns2 =", ns2)

    nB2 = (h4.Integral(sideband1_binx1, sideband1_binx2) + h4.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB2 =", nB2)

    nobs2 = h4.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs2 =", nobs2)

    f3  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat3/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h6 = f3.Get("background")
    h7 = f3.Get("signal")

    ns3 = h7.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns3 =", ns3)

    nB3 = (h6.Integral(sideband1_binx1, sideband1_binx2) + h6.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB3 =", nB3) 

    nobs3 = h6.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs3 =", nobs3)

    f4  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat4/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h8 = f4.Get("background")
    h9 = f4.Get("signal")

    ns4 = h9.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns4 =", ns4)

    nB4 = (h8.Integral(sideband1_binx1, sideband1_binx2) + h8.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB4 =", nB4)

    nobs4 = h8.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs4 =", nobs4)

    f5  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat5/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h10 = f5.Get("background")
    h11 = f5.Get("signal")

    ns5 = h11.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns5 =", ns5)
    
    nB5 = (h10.Integral(sideband1_binx1, sideband1_binx2) + h10.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB5 =", nB5)

    nobs5 = h10.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs5 =", nobs5)

    f6  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/single_vertex_cat6/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h12 = f6.Get("background")
    h13 = f6.Get("signal")

    ns6 = h13.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns6 =", ns6)
    
    nB6 = (h12.Integral(sideband1_binx1, sideband1_binx2) + h12.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB6 =", nB6)

    nobs6 = h12.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs6 =", nobs6)

    f7  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat1/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h14 = f7.Get("background")
    h15 = f7.Get("signal")

    ns7 = h15.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns7 =", ns7)

    nB7 = (h14.Integral(sideband1_binx1, sideband1_binx2) + h14.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB7 =", nB7)

    nobs7 = h14.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs7 =", nobs7)

    f8  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat2/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h16 = f8.Get("background")
    h17 = f8.Get("signal")

    ns8 = h17.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns8 =", ns8)

    nB8 = (h16.Integral(sideband1_binx1, sideband1_binx2) + h16.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB8 =", nB8)

    nobs8 = h16.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs8 =", nobs8)

    f9  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat3/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h18 = f9.Get("background")
    h19 = f9.Get("signal")

    ns9 = h19.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns9 =", ns9)
    
    nB9 = (h18.Integral(sideband1_binx1, sideband1_binx2) + h18.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB9 =", nB9)

    nobs9 = h18.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs9 =", nobs9)

    f10  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat4/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h20 = f10.Get("background")
    h21 = f10.Get("signal")

    ns10 = h21.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns10 =", ns10)
    
    nB10 = (h20.Integral(sideband1_binx1, sideband1_binx2) + h20.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB10 =", nB10)

    nobs10 = h20.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs10 =", nobs10)

    f11  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat5/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h22 = f11.Get("background")
    h23 = f11.Get("signal")

    ns11 = h23.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns11 =", ns11)

    nB11 = (h22.Integral(sideband1_binx1, sideband1_binx2) + h22.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB11 =", nB11)

    nobs11 = h22.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs11 =", nobs11)

    f12  = TFile("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_single_multi_data/multi_vertex_cat6/vector_m_{}/output_vector_{}_{}_1_1.root".format(mass, mass, lifetime))
    h24 = f12.Get("background")
    h25 = f12.Get("signal")

    ns12 = h25.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("ns12 =", ns12)

    nB12 = (h24.Integral(sideband1_binx1, sideband1_binx2) + h24.Integral(sideband2_binx1, sideband2_binx2))*4/6
    print("nB12 =", nB12)

    nobs12 = h24.Integral(sideband1_binx2 + 1, sideband2_binx1 - 1)
    print("nobs12 =", nobs12)
   
    if nB == 0.0:
        nB = 0.1
    if nB2 == 0.0:
        nB2 = 0.1
    if nB3 == 0.0:
        nB3 = 0.1
    if nB4 == 0.0:
        nB4 = 0.1
    if nB5 == 0.0:
        nB5 = 0.1
    if nB6 == 0.0:
        nB6 = 0.1
    if nB7 == 0.0:
        nB7 = 0.1
    if nB8 == 0.0:
        nB8 = 0.1
    if nB9 == 0.0:
        nB9 = 0.1
    if nB10 == 0.0:
        nB10 = 0.1
    if nB11 == 0.0:
        nB11 = 0.1
    if nB12 == 0.0:
        nB12 = 0.1

    
    if nobs == 0.0:
        nobs = 0.1
    if nobs2 == 0.0:
        nobs2 = 0.1
    if nobs3 == 0.0:
        nobs3 = 0.1
    if nobs4 == 0.0:
        nobs4 = 0.1
    if nobs5 == 0.0:
        nobs5 = 0.1
    if nobs6 == 0.0:
        nobs6 = 0.1
    if nobs7 == 0.0:
        nobs7 = 0.1
    if nobs8 == 0.0:
        nobs8 = 0.1
    if nobs9 == 0.0:
        nobs9 = 0.1
    if nobs10 == 0.0:
        nobs10 = 0.1
    if nobs11 == 0.0:
        nobs11 = 0.1
    if nobs12 == 0.0:
        nobs12 = 0.1




    datacard = open('/home/hep/khl216/CMSSW_10_2_13/src/datacard/dqcd/muonSV/categories_single_multi_data/m_{}/shape_count_mass{}_ctau{}.txt'.format(mass, mass,lifetime), "w")
    datacard.write("imax *  number of channels\n")
    datacard.write("jmax *  number of backgrounds\n")
    datacard.write("kmax *  number of nuisance parameters (sources of systematical uncertainties)\n")
    datacard.write("------------------------------------\n")
    datacard.write("\n") 
    datacard.write("------------------------------------\n")
    datacard.write("bin cat1 cat2 cat3 cat4 cat5 cat6 cat7 cat8 cat9 cat10 cat11 cat12\n")
    datacard.write("observation {} {} {} {} {} {} {} {} {} {} {} {} \n".format(nobs, nobs2, nobs3, nobs4, nobs5, nobs6, nobs7, nobs8, nobs9, nobs10 ,nobs11, nobs12))
    datacard.write("------------------------------------\n")
    datacard.write("bin cat1 cat1 cat2 cat2 cat3 cat3 cat4 cat4 cat5 cat5 cat6 cat6 cat7 cat7 cat8 cat8 cat9 cat9 cat10 cat10 cat11 cat11 cat12 cat12\n")
    datacard.write("process signal background signal background signal background signal background signal background signal background signal background signal background signal background signal background signal background signal background\n")
    datacard.write("process 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1\n")
    #datacard.write("rate {} {}\n".format(nS, 1))                                                         
    datacard.write("rate {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} \n".format(ns, nB, ns2, nB2, ns3, nB3, ns4, nB4, ns5, nB5, ns6, nB6, ns7, nB7, ns8, nB8, ns9, nB9, ns10, nB10, ns11, nB11, ns12, nB12))
    datacard.write("------------------------------------\n")
    datacard.write("lumi lnN 1.10 1.0 1.10 1.0 1.10 1.0 1.10 1.0 1.10 1.0 1.10 1.0 1.10 1.0 1.10 1.0 1.10 1.0 1.10 1.0 1.10 1.0 1.10 1.0\n")
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

if __name__ == "__main__":
   mass_points = [2]
   lifetime_points = [1, 10, 50, 100, 500] 
   for m in mass_points:
       for t in lifetime_points:
           makedatacardSimple(m, t)
