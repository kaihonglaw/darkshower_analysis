//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 30 21:38:50 2023 by ROOT version 6.24/06
// from TTree Friends/Friend tree for Events
// found on file: /vols/cms/khl216/nano_out/nanotron_v3_bdt_0p95_fixed/bparkProductionAll_V1p0/HiddenValley_vector_m_2_ctau_10_xiO_1_xiL_1_privateMC_11X_NANOAODSIM_v1p0_generationSync/output_10_Friend.root
//////////////////////////////////////////////////////////

#ifndef Friends_hh
#define Friends_hh

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Friends {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           nLooseMuons;
   Float_t         LooseMuons_pt[9];   //[nLooseMuons]
   Float_t         LooseMuons_eta[9];   //[nLooseMuons]
   Float_t         LooseMuons_phi[9];   //[nLooseMuons]
   Float_t         LooseMuons_sip3d[9];   //[nLooseMuons]
   Float_t         LooseMuons_ip3d[9];   //[nLooseMuons]
   Float_t         LooseMuons_dxy[9];   //[nLooseMuons]
   Float_t         LooseMuons_dxyErr[9];   //[nLooseMuons]
   Int_t           nTriggeringMuons;
   Float_t         TriggeringMuons_pt[5];   //[nTriggeringMuons]
   Float_t         TriggeringMuons_eta[5];   //[nTriggeringMuons]
   Float_t         TriggeringMuons_phi[5];   //[nTriggeringMuons]
   Float_t         TriggeringMuons_sip3d[5];   //[nTriggeringMuons]
   Float_t         TriggeringMuons_ip3d[5];   //[nTriggeringMuons]
   Float_t         TriggeringMuons_dxy[5];   //[nTriggeringMuons]
   Float_t         TriggeringMuons_dxyErr[5];   //[nTriggeringMuons]
   Int_t           nMuonsWithEtaAndPtReq;
   Float_t         MuonsWithEtaAndPtReq_pt[8];   //[nMuonsWithEtaAndPtReq]
   Float_t         MuonsWithEtaAndPtReq_eta[8];   //[nMuonsWithEtaAndPtReq]
   Float_t         MuonsWithEtaAndPtReq_phi[8];   //[nMuonsWithEtaAndPtReq]
   Float_t         MuonsWithEtaAndPtReq_sip3d[8];   //[nMuonsWithEtaAndPtReq]
   Float_t         MuonsWithEtaAndPtReq_ip3d[8];   //[nMuonsWithEtaAndPtReq]
   Float_t         MuonsWithEtaAndPtReq_dxy[8];   //[nMuonsWithEtaAndPtReq]
   Float_t         MuonsWithEtaAndPtReq_dxyErr[8];   //[nMuonsWithEtaAndPtReq]
   Int_t           DisplacedMuonTrigger_flag;
   Int_t           nleadingLeptons;
   Int_t           nsubleadingLeptons;
   Int_t           Leptons_muonmuon;
   Int_t           Leptons_electronelectron;
   Int_t           Leptons_muonelectron;
   Int_t           Leptons_electronmuon;
   Int_t           Leptons_muonjets;
   Int_t           Leptons_electronjets;
   Int_t           Leptons_subLeptonTightId;
   Float_t         Leptons_subLeptonPtErr;
   Float_t         leadingLeptons_pt[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_eta[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_phi[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_charge[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_isMuon[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_isElectron[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_relIso[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_dxy[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_dz[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_dxysig[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_dzsig[1];   //[nleadingLeptons]
   Float_t         leadingLeptons_isTriggerMatched[1];   //[nleadingLeptons]
   Float_t         subleadingLeptons_pt[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_eta[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_phi[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_charge[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_isMuon[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_isElectron[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_relIso[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_dxy[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_dz[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_dxysig[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_dzsig[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_looseId[9];   //[nsubleadingLeptons]
   Float_t         subleadingLeptons_tightId[9];   //[nsubleadingLeptons]
   Int_t           nTriggeringMuons_triggermatched;
   Float_t         TriggeringMuons_triggermatched_pt[4];   //[nTriggeringMuons_triggermatched]
   Float_t         TriggeringMuons_triggermatched_eta[4];   //[nTriggeringMuons_triggermatched]
   Float_t         TriggeringMuons_triggermatched_phi[4];   //[nTriggeringMuons_triggermatched]
   Float_t         TriggeringMuons_triggermatched_sip3d[4];   //[nTriggeringMuons_triggermatched]
   Float_t         TriggeringMuons_triggermatched_ip3d[4];   //[nTriggeringMuons_triggermatched]
   Float_t         TriggeringMuons_triggermatched_dxy[4];   //[nTriggeringMuons_triggermatched]
   Float_t         TriggeringMuons_triggermatched_dxyErr[4];   //[nTriggeringMuons_triggermatched]
   Int_t           nMuonsWithTighterEtaAndPtReq;
   Float_t         MuonsWithTighterEtaAndPtReq_pt[4];   //[nMuonsWithTighterEtaAndPtReq]
   Float_t         MuonsWithTighterEtaAndPtReq_eta[4];   //[nMuonsWithTighterEtaAndPtReq]
   Float_t         MuonsWithTighterEtaAndPtReq_phi[4];   //[nMuonsWithTighterEtaAndPtReq]
   Float_t         MuonsWithTighterEtaAndPtReq_sip3d[4];   //[nMuonsWithTighterEtaAndPtReq]
   Float_t         MuonsWithTighterEtaAndPtReq_ip3d[4];   //[nMuonsWithTighterEtaAndPtReq]
   Float_t         MuonsWithTighterEtaAndPtReq_dxy[4];   //[nMuonsWithTighterEtaAndPtReq]
   Float_t         MuonsWithTighterEtaAndPtReq_dxyErr[4];   //[nMuonsWithTighterEtaAndPtReq]
   Int_t           nselectedJets_nominal;
   Float_t         selectedJets_nominal_pt[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_eta[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_phi[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_minDeltaRSubtraction[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_ptLepton[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_ptOriginal[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_ptSubtracted[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_rawFactor[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_ptRaw[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_numberCpf[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_numberMuon[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_numberElectron[11];   //[nselectedJets_nominal]
   Int_t           nSV;
   Float_t         SV_mass[7];   //[nSV]
   Float_t         SV_dxy[7];   //[nSV]
   Float_t         SV_dxySig[7];   //[nSV]
   Int_t           nsv;
   Float_t         sv_mass[7];   //[nsv]
   Float_t         sv_dxy[7];   //[nsv]
   Float_t         sv_dxysig[7];   //[nsv]
   Float_t         sv_ntracks[7];   //[nsv]
   Int_t           nsvAdapted;
   Float_t         svAdapted_mass[9];   //[nsvAdapted]
   Float_t         svAdapted_dxy[9];   //[nsvAdapted]
   Float_t         svAdapted_dxysig[9];   //[nsvAdapted]
   Float_t         svAdapted_ntracks[9];   //[nsvAdapted]
   Int_t           nMuon;
   Float_t         Muon_sip3d[11];   //[nMuon]
   Float_t         Muon_ip3d[11];   //[nMuon]
   Float_t         Muon_dxy[11];   //[nMuon]
   Float_t         Muon_dz[11];   //[nMuon]
   Float_t         Muon_pt[11];   //[nMuon]
   Float_t         Muon_dzErr[11];   //[nMuon]
   Float_t         Muon_dxyErr[11];   //[nMuon]
   Float_t         Muon_eta[11];   //[nMuon]
   Float_t         Muon_phi[11];   //[nMuon]
   Int_t           Muon_charge[11];   //[nMuon]
   Int_t           nJet;
   Float_t         Jet_muEF[17];   //[nJet]
   Float_t         Jet_muonSubtrFactor[17];   //[nJet]
   Float_t         Jet_pt[17];   //[nJet]
   Float_t         Leading_Jet_pt;
   Int_t           nmuonSV;
   Float_t         muonSV_dlen[27];   //[nmuonSV]
   Float_t         muonSV_dlenSig[27];   //[nmuonSV]
   Float_t         muonSV_dxy[27];   //[nmuonSV]
   Float_t         muonSV_dxySig[27];   //[nmuonSV]
   Float_t         muonSV_x[27];   //[nmuonSV]
   Float_t         muonSV_y[27];   //[nmuonSV]
   Float_t         muonSV_z[27];   //[nmuonSV]
   Float_t         muonSV_ndof[27];   //[nmuonSV]
   Float_t         muonSV_chi2[27];   //[nmuonSV]
   Float_t         muonSV_pAngle[27];   //[nmuonSV]
   Float_t         muonSV_origMass[27];   //[nmuonSV]
   Float_t         muonSV_mass[27];   //[nmuonSV]
   Float_t         muonSV_mu1pt[27];   //[nmuonSV]
   Float_t         muonSV_mu2pt[27];   //[nmuonSV]
   Float_t         muonSV_mu1phi[27];   //[nmuonSV]
   Float_t         muonSV_mu2phi[27];   //[nmuonSV]
   Float_t         muonSV_mu1eta[27];   //[nmuonSV]
   Float_t         muonSV_mu2eta[27];   //[nmuonSV]
   Float_t         muonSV_mu1index[27];   //[nmuonSV]
   Float_t         muonSV_mu2index[27];   //[nmuonSV]
   Float_t         qcdShatWeight;

   // List of branches
   TBranch        *b_nLooseMuons;   //!
   TBranch        *b_LooseMuons_pt;   //!
   TBranch        *b_LooseMuons_eta;   //!
   TBranch        *b_LooseMuons_phi;   //!
   TBranch        *b_LooseMuons_sip3d;   //!
   TBranch        *b_LooseMuons_ip3d;   //!
   TBranch        *b_LooseMuons_dxy;   //!
   TBranch        *b_LooseMuons_dxyErr;   //!
   TBranch        *b_nTriggeringMuons;   //!
   TBranch        *b_TriggeringMuons_pt;   //!
   TBranch        *b_TriggeringMuons_eta;   //!
   TBranch        *b_TriggeringMuons_phi;   //!
   TBranch        *b_TriggeringMuons_sip3d;   //!
   TBranch        *b_TriggeringMuons_ip3d;   //!
   TBranch        *b_TriggeringMuons_dxy;   //!
   TBranch        *b_TriggeringMuons_dxyErr;   //!
   TBranch        *b_nMuonsWithEtaAndPtReq;   //!
   TBranch        *b_MuonsWithEtaAndPtReq_pt;   //!
   TBranch        *b_MuonsWithEtaAndPtReq_eta;   //!
   TBranch        *b_MuonsWithEtaAndPtReq_phi;   //!
   TBranch        *b_MuonsWithEtaAndPtReq_sip3d;   //!
   TBranch        *b_MuonsWithEtaAndPtReq_ip3d;   //!
   TBranch        *b_MuonsWithEtaAndPtReq_dxy;   //!
   TBranch        *b_MuonsWithEtaAndPtReq_dxyErr;   //!
   TBranch        *b_DisplacedMuonTrigger_flag;   //!
   TBranch        *b_nleadingLeptons;   //!
   TBranch        *b_nsubleadingLeptons;   //!
   TBranch        *b_Leptons_muonmuon;   //!
   TBranch        *b_Leptons_electronelectron;   //!
   TBranch        *b_Leptons_muonelectron;   //!
   TBranch        *b_Leptons_electronmuon;   //!
   TBranch        *b_Leptons_muonjets;   //!
   TBranch        *b_Leptons_electronjets;   //!
   TBranch        *b_Leptons_subLeptonTightId;   //!
   TBranch        *b_Leptons_subLeptonPtErr;   //!
   TBranch        *b_leadingLeptons_pt;   //!
   TBranch        *b_leadingLeptons_eta;   //!
   TBranch        *b_leadingLeptons_phi;   //!
   TBranch        *b_leadingLeptons_charge;   //!
   TBranch        *b_leadingLeptons_isMuon;   //!
   TBranch        *b_leadingLeptons_isElectron;   //!
   TBranch        *b_leadingLeptons_relIso;   //!
   TBranch        *b_leadingLeptons_dxy;   //!
   TBranch        *b_leadingLeptons_dz;   //!
   TBranch        *b_leadingLeptons_dxysig;   //!
   TBranch        *b_leadingLeptons_dzsig;   //!
   TBranch        *b_leadingLeptons_isTriggerMatched;   //!
   TBranch        *b_subleadingLeptons_pt;   //!
   TBranch        *b_subleadingLeptons_eta;   //!
   TBranch        *b_subleadingLeptons_phi;   //!
   TBranch        *b_subleadingLeptons_charge;   //!
   TBranch        *b_subleadingLeptons_isMuon;   //!
   TBranch        *b_subleadingLeptons_isElectron;   //!
   TBranch        *b_subleadingLeptons_relIso;   //!
   TBranch        *b_subleadingLeptons_dxy;   //!
   TBranch        *b_subleadingLeptons_dz;   //!
   TBranch        *b_subleadingLeptons_dxysig;   //!
   TBranch        *b_subleadingLeptons_dzsig;   //!
   TBranch        *b_subleadingLeptons_looseId;   //!
   TBranch        *b_subleadingLeptons_tightId;   //!
   TBranch        *b_nTriggeringMuons_triggermatched;   //!
   TBranch        *b_TriggeringMuons_triggermatched_pt;   //!
   TBranch        *b_TriggeringMuons_triggermatched_eta;   //!
   TBranch        *b_TriggeringMuons_triggermatched_phi;   //!
   TBranch        *b_TriggeringMuons_triggermatched_sip3d;   //!
   TBranch        *b_TriggeringMuons_triggermatched_ip3d;   //!
   TBranch        *b_TriggeringMuons_triggermatched_dxy;   //!
   TBranch        *b_TriggeringMuons_triggermatched_dxyErr;   //!
   TBranch        *b_nMuonsWithTighterEtaAndPtReq;   //!
   TBranch        *b_MuonsWithTighterEtaAndPtReq_pt;   //!
   TBranch        *b_MuonsWithTighterEtaAndPtReq_eta;   //!
   TBranch        *b_MuonsWithTighterEtaAndPtReq_phi;   //!
   TBranch        *b_MuonsWithTighterEtaAndPtReq_sip3d;   //!
   TBranch        *b_MuonsWithTighterEtaAndPtReq_ip3d;   //!
   TBranch        *b_MuonsWithTighterEtaAndPtReq_dxy;   //!
   TBranch        *b_MuonsWithTighterEtaAndPtReq_dxyErr;   //!
   TBranch        *b_nselectedJets_nominal;   //!
   TBranch        *b_selectedJets_nominal_pt;   //!
   TBranch        *b_selectedJets_nominal_eta;   //!
   TBranch        *b_selectedJets_nominal_phi;   //!
   TBranch        *b_selectedJets_nominal_minDeltaRSubtraction;   //!
   TBranch        *b_selectedJets_nominal_ptLepton;   //!
   TBranch        *b_selectedJets_nominal_ptOriginal;   //!
   TBranch        *b_selectedJets_nominal_ptSubtracted;   //!
   TBranch        *b_selectedJets_nominal_rawFactor;   //!
   TBranch        *b_selectedJets_nominal_ptRaw;   //!
   TBranch        *b_selectedJets_nominal_numberCpf;   //!
   TBranch        *b_selectedJets_nominal_numberMuon;   //!
   TBranch        *b_selectedJets_nominal_numberElectron;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_dxy;   //!
   TBranch        *b_SV_dxySig;   //!
   TBranch        *b_nsv;   //!
   TBranch        *b_sv_mass;   //!
   TBranch        *b_sv_dxy;   //!
   TBranch        *b_sv_dxysig;   //!
   TBranch        *b_sv_ntracks;   //!
   TBranch        *b_nsvAdapted;   //!
   TBranch        *b_svAdapted_mass;   //!
   TBranch        *b_svAdapted_dxy;   //!
   TBranch        *b_svAdapted_dxysig;   //!
   TBranch        *b_svAdapted_ntracks;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_sip3d;   //!
   TBranch        *b_Muon_ip3d;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_muEF;   //!
   TBranch        *b_Jet_muonSubtrFactor;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Leading_Jet_pt;   //!
   TBranch        *b_nmuonSV;   //!
   TBranch        *b_muonSV_dlen;   //!
   TBranch        *b_muonSV_dlenSig;   //!
   TBranch        *b_muonSV_dxy;   //!
   TBranch        *b_muonSV_dxySig;   //!
   TBranch        *b_muonSV_x;   //!
   TBranch        *b_muonSV_y;   //!
   TBranch        *b_muonSV_z;   //!
   TBranch        *b_muonSV_ndof;   //!
   TBranch        *b_muonSV_chi2;   //!
   TBranch        *b_muonSV_pAngle;   //!
   TBranch        *b_muonSV_origMass;   //!
   TBranch        *b_muonSV_mass;   //!
   TBranch        *b_muonSV_mu1pt;   //!
   TBranch        *b_muonSV_mu2pt;   //!
   TBranch        *b_muonSV_mu1phi;   //!
   TBranch        *b_muonSV_mu2phi;   //!
   TBranch        *b_muonSV_mu1eta;   //!
   TBranch        *b_muonSV_mu2eta;   //!
   TBranch        *b_muonSV_mu1index;   //!
   TBranch        *b_muonSV_mu2index;   //!
   TBranch        *b_qcdShatWeight;   //!

   Friends(TTree *tree=0);
   virtual ~Friends();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Friends_cxx
Friends::Friends(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/vols/cms/khl216/nano_out/nanotron_v3_bdt_0p95_fixed/bparkProductionAll_V1p0/HiddenValley_vector_m_2_ctau_10_xiO_1_xiL_1_privateMC_11X_NANOAODSIM_v1p0_generationSync/output_10_Friend.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/vols/cms/khl216/nano_out/nanotron_v3_bdt_0p95_fixed/bparkProductionAll_V1p0/HiddenValley_vector_m_2_ctau_10_xiO_1_xiL_1_privateMC_11X_NANOAODSIM_v1p0_generationSync/output_10_Friend.root");
      }
      f->GetObject("Friends",tree);

   }
   Init(tree);
}

Friends::~Friends()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Friends::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Friends::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Friends::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nLooseMuons", &nLooseMuons, &b_nLooseMuons);
   fChain->SetBranchAddress("LooseMuons_pt", LooseMuons_pt, &b_LooseMuons_pt);
   fChain->SetBranchAddress("LooseMuons_eta", LooseMuons_eta, &b_LooseMuons_eta);
   fChain->SetBranchAddress("LooseMuons_phi", LooseMuons_phi, &b_LooseMuons_phi);
   fChain->SetBranchAddress("LooseMuons_sip3d", LooseMuons_sip3d, &b_LooseMuons_sip3d);
   fChain->SetBranchAddress("LooseMuons_ip3d", LooseMuons_ip3d, &b_LooseMuons_ip3d);
   fChain->SetBranchAddress("LooseMuons_dxy", LooseMuons_dxy, &b_LooseMuons_dxy);
   fChain->SetBranchAddress("LooseMuons_dxyErr", LooseMuons_dxyErr, &b_LooseMuons_dxyErr);
   fChain->SetBranchAddress("nTriggeringMuons", &nTriggeringMuons, &b_nTriggeringMuons);
   fChain->SetBranchAddress("TriggeringMuons_pt", TriggeringMuons_pt, &b_TriggeringMuons_pt);
   fChain->SetBranchAddress("TriggeringMuons_eta", TriggeringMuons_eta, &b_TriggeringMuons_eta);
   fChain->SetBranchAddress("TriggeringMuons_phi", TriggeringMuons_phi, &b_TriggeringMuons_phi);
   fChain->SetBranchAddress("TriggeringMuons_sip3d", TriggeringMuons_sip3d, &b_TriggeringMuons_sip3d);
   fChain->SetBranchAddress("TriggeringMuons_ip3d", TriggeringMuons_ip3d, &b_TriggeringMuons_ip3d);
   fChain->SetBranchAddress("TriggeringMuons_dxy", TriggeringMuons_dxy, &b_TriggeringMuons_dxy);
   fChain->SetBranchAddress("TriggeringMuons_dxyErr", TriggeringMuons_dxyErr, &b_TriggeringMuons_dxyErr);
   fChain->SetBranchAddress("nMuonsWithEtaAndPtReq", &nMuonsWithEtaAndPtReq, &b_nMuonsWithEtaAndPtReq);
   fChain->SetBranchAddress("MuonsWithEtaAndPtReq_pt", MuonsWithEtaAndPtReq_pt, &b_MuonsWithEtaAndPtReq_pt);
   fChain->SetBranchAddress("MuonsWithEtaAndPtReq_eta", MuonsWithEtaAndPtReq_eta, &b_MuonsWithEtaAndPtReq_eta);
   fChain->SetBranchAddress("MuonsWithEtaAndPtReq_phi", MuonsWithEtaAndPtReq_phi, &b_MuonsWithEtaAndPtReq_phi);
   fChain->SetBranchAddress("MuonsWithEtaAndPtReq_sip3d", MuonsWithEtaAndPtReq_sip3d, &b_MuonsWithEtaAndPtReq_sip3d);
   fChain->SetBranchAddress("MuonsWithEtaAndPtReq_ip3d", MuonsWithEtaAndPtReq_ip3d, &b_MuonsWithEtaAndPtReq_ip3d);
   fChain->SetBranchAddress("MuonsWithEtaAndPtReq_dxy", MuonsWithEtaAndPtReq_dxy, &b_MuonsWithEtaAndPtReq_dxy);
   fChain->SetBranchAddress("MuonsWithEtaAndPtReq_dxyErr", MuonsWithEtaAndPtReq_dxyErr, &b_MuonsWithEtaAndPtReq_dxyErr);
   fChain->SetBranchAddress("DisplacedMuonTrigger_flag", &DisplacedMuonTrigger_flag, &b_DisplacedMuonTrigger_flag);
   fChain->SetBranchAddress("nleadingLeptons", &nleadingLeptons, &b_nleadingLeptons);
   fChain->SetBranchAddress("nsubleadingLeptons", &nsubleadingLeptons, &b_nsubleadingLeptons);
   fChain->SetBranchAddress("Leptons_muonmuon", &Leptons_muonmuon, &b_Leptons_muonmuon);
   fChain->SetBranchAddress("Leptons_electronelectron", &Leptons_electronelectron, &b_Leptons_electronelectron);
   fChain->SetBranchAddress("Leptons_muonelectron", &Leptons_muonelectron, &b_Leptons_muonelectron);
   fChain->SetBranchAddress("Leptons_electronmuon", &Leptons_electronmuon, &b_Leptons_electronmuon);
   fChain->SetBranchAddress("Leptons_muonjets", &Leptons_muonjets, &b_Leptons_muonjets);
   fChain->SetBranchAddress("Leptons_electronjets", &Leptons_electronjets, &b_Leptons_electronjets);
   fChain->SetBranchAddress("Leptons_subLeptonTightId", &Leptons_subLeptonTightId, &b_Leptons_subLeptonTightId);
   fChain->SetBranchAddress("Leptons_subLeptonPtErr", &Leptons_subLeptonPtErr, &b_Leptons_subLeptonPtErr);
   fChain->SetBranchAddress("leadingLeptons_pt", &leadingLeptons_pt, &b_leadingLeptons_pt);
   fChain->SetBranchAddress("leadingLeptons_eta", &leadingLeptons_eta, &b_leadingLeptons_eta);
   fChain->SetBranchAddress("leadingLeptons_phi", &leadingLeptons_phi, &b_leadingLeptons_phi);
   fChain->SetBranchAddress("leadingLeptons_charge", &leadingLeptons_charge, &b_leadingLeptons_charge);
   fChain->SetBranchAddress("leadingLeptons_isMuon", &leadingLeptons_isMuon, &b_leadingLeptons_isMuon);
   fChain->SetBranchAddress("leadingLeptons_isElectron", &leadingLeptons_isElectron, &b_leadingLeptons_isElectron);
   fChain->SetBranchAddress("leadingLeptons_relIso", &leadingLeptons_relIso, &b_leadingLeptons_relIso);
   fChain->SetBranchAddress("leadingLeptons_dxy", &leadingLeptons_dxy, &b_leadingLeptons_dxy);
   fChain->SetBranchAddress("leadingLeptons_dz", &leadingLeptons_dz, &b_leadingLeptons_dz);
   fChain->SetBranchAddress("leadingLeptons_dxysig", &leadingLeptons_dxysig, &b_leadingLeptons_dxysig);
   fChain->SetBranchAddress("leadingLeptons_dzsig", &leadingLeptons_dzsig, &b_leadingLeptons_dzsig);
   fChain->SetBranchAddress("leadingLeptons_isTriggerMatched", &leadingLeptons_isTriggerMatched, &b_leadingLeptons_isTriggerMatched);
   fChain->SetBranchAddress("subleadingLeptons_pt", subleadingLeptons_pt, &b_subleadingLeptons_pt);
   fChain->SetBranchAddress("subleadingLeptons_eta", subleadingLeptons_eta, &b_subleadingLeptons_eta);
   fChain->SetBranchAddress("subleadingLeptons_phi", subleadingLeptons_phi, &b_subleadingLeptons_phi);
   fChain->SetBranchAddress("subleadingLeptons_charge", subleadingLeptons_charge, &b_subleadingLeptons_charge);
   fChain->SetBranchAddress("subleadingLeptons_isMuon", subleadingLeptons_isMuon, &b_subleadingLeptons_isMuon);
   fChain->SetBranchAddress("subleadingLeptons_isElectron", subleadingLeptons_isElectron, &b_subleadingLeptons_isElectron);
   fChain->SetBranchAddress("subleadingLeptons_relIso", subleadingLeptons_relIso, &b_subleadingLeptons_relIso);
   fChain->SetBranchAddress("subleadingLeptons_dxy", subleadingLeptons_dxy, &b_subleadingLeptons_dxy);
   fChain->SetBranchAddress("subleadingLeptons_dz", subleadingLeptons_dz, &b_subleadingLeptons_dz);
   fChain->SetBranchAddress("subleadingLeptons_dxysig", subleadingLeptons_dxysig, &b_subleadingLeptons_dxysig);
   fChain->SetBranchAddress("subleadingLeptons_dzsig", subleadingLeptons_dzsig, &b_subleadingLeptons_dzsig);
   fChain->SetBranchAddress("subleadingLeptons_looseId", subleadingLeptons_looseId, &b_subleadingLeptons_looseId);
   fChain->SetBranchAddress("subleadingLeptons_tightId", subleadingLeptons_tightId, &b_subleadingLeptons_tightId);
   fChain->SetBranchAddress("nTriggeringMuons_triggermatched", &nTriggeringMuons_triggermatched, &b_nTriggeringMuons_triggermatched);
   fChain->SetBranchAddress("TriggeringMuons_triggermatched_pt", TriggeringMuons_triggermatched_pt, &b_TriggeringMuons_triggermatched_pt);
   fChain->SetBranchAddress("TriggeringMuons_triggermatched_eta", TriggeringMuons_triggermatched_eta, &b_TriggeringMuons_triggermatched_eta);
   fChain->SetBranchAddress("TriggeringMuons_triggermatched_phi", TriggeringMuons_triggermatched_phi, &b_TriggeringMuons_triggermatched_phi);
   fChain->SetBranchAddress("TriggeringMuons_triggermatched_sip3d", TriggeringMuons_triggermatched_sip3d, &b_TriggeringMuons_triggermatched_sip3d);
   fChain->SetBranchAddress("TriggeringMuons_triggermatched_ip3d", TriggeringMuons_triggermatched_ip3d, &b_TriggeringMuons_triggermatched_ip3d);
   fChain->SetBranchAddress("TriggeringMuons_triggermatched_dxy", TriggeringMuons_triggermatched_dxy, &b_TriggeringMuons_triggermatched_dxy);
   fChain->SetBranchAddress("TriggeringMuons_triggermatched_dxyErr", TriggeringMuons_triggermatched_dxyErr, &b_TriggeringMuons_triggermatched_dxyErr);
   fChain->SetBranchAddress("nMuonsWithTighterEtaAndPtReq", &nMuonsWithTighterEtaAndPtReq, &b_nMuonsWithTighterEtaAndPtReq);
   fChain->SetBranchAddress("MuonsWithTighterEtaAndPtReq_pt", MuonsWithTighterEtaAndPtReq_pt, &b_MuonsWithTighterEtaAndPtReq_pt);
   fChain->SetBranchAddress("MuonsWithTighterEtaAndPtReq_eta", MuonsWithTighterEtaAndPtReq_eta, &b_MuonsWithTighterEtaAndPtReq_eta);
   fChain->SetBranchAddress("MuonsWithTighterEtaAndPtReq_phi", MuonsWithTighterEtaAndPtReq_phi, &b_MuonsWithTighterEtaAndPtReq_phi);
   fChain->SetBranchAddress("MuonsWithTighterEtaAndPtReq_sip3d", MuonsWithTighterEtaAndPtReq_sip3d, &b_MuonsWithTighterEtaAndPtReq_sip3d);
   fChain->SetBranchAddress("MuonsWithTighterEtaAndPtReq_ip3d", MuonsWithTighterEtaAndPtReq_ip3d, &b_MuonsWithTighterEtaAndPtReq_ip3d);
   fChain->SetBranchAddress("MuonsWithTighterEtaAndPtReq_dxy", MuonsWithTighterEtaAndPtReq_dxy, &b_MuonsWithTighterEtaAndPtReq_dxy);
   fChain->SetBranchAddress("MuonsWithTighterEtaAndPtReq_dxyErr", MuonsWithTighterEtaAndPtReq_dxyErr, &b_MuonsWithTighterEtaAndPtReq_dxyErr);
   fChain->SetBranchAddress("nselectedJets_nominal", &nselectedJets_nominal, &b_nselectedJets_nominal);
   fChain->SetBranchAddress("selectedJets_nominal_pt", selectedJets_nominal_pt, &b_selectedJets_nominal_pt);
   fChain->SetBranchAddress("selectedJets_nominal_eta", selectedJets_nominal_eta, &b_selectedJets_nominal_eta);
   fChain->SetBranchAddress("selectedJets_nominal_phi", selectedJets_nominal_phi, &b_selectedJets_nominal_phi);
   fChain->SetBranchAddress("selectedJets_nominal_minDeltaRSubtraction", selectedJets_nominal_minDeltaRSubtraction, &b_selectedJets_nominal_minDeltaRSubtraction);
   fChain->SetBranchAddress("selectedJets_nominal_ptLepton", selectedJets_nominal_ptLepton, &b_selectedJets_nominal_ptLepton);
   fChain->SetBranchAddress("selectedJets_nominal_ptOriginal", selectedJets_nominal_ptOriginal, &b_selectedJets_nominal_ptOriginal);
   fChain->SetBranchAddress("selectedJets_nominal_ptSubtracted", selectedJets_nominal_ptSubtracted, &b_selectedJets_nominal_ptSubtracted);
   fChain->SetBranchAddress("selectedJets_nominal_rawFactor", selectedJets_nominal_rawFactor, &b_selectedJets_nominal_rawFactor);
   fChain->SetBranchAddress("selectedJets_nominal_ptRaw", selectedJets_nominal_ptRaw, &b_selectedJets_nominal_ptRaw);
   fChain->SetBranchAddress("selectedJets_nominal_numberCpf", selectedJets_nominal_numberCpf, &b_selectedJets_nominal_numberCpf);
   fChain->SetBranchAddress("selectedJets_nominal_numberMuon", selectedJets_nominal_numberMuon, &b_selectedJets_nominal_numberMuon);
   fChain->SetBranchAddress("selectedJets_nominal_numberElectron", selectedJets_nominal_numberElectron, &b_selectedJets_nominal_numberElectron);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_dxy", SV_dxy, &b_SV_dxy);
   fChain->SetBranchAddress("SV_dxySig", SV_dxySig, &b_SV_dxySig);
   fChain->SetBranchAddress("nsv", &nsv, &b_nsv);
   fChain->SetBranchAddress("sv_mass", sv_mass, &b_sv_mass);
   fChain->SetBranchAddress("sv_dxy", sv_dxy, &b_sv_dxy);
   fChain->SetBranchAddress("sv_dxysig", sv_dxysig, &b_sv_dxysig);
   fChain->SetBranchAddress("sv_ntracks", sv_ntracks, &b_sv_ntracks);
   fChain->SetBranchAddress("nsvAdapted", &nsvAdapted, &b_nsvAdapted);
   fChain->SetBranchAddress("svAdapted_mass", svAdapted_mass, &b_svAdapted_mass);
   fChain->SetBranchAddress("svAdapted_dxy", svAdapted_dxy, &b_svAdapted_dxy);
   fChain->SetBranchAddress("svAdapted_dxysig", svAdapted_dxysig, &b_svAdapted_dxysig);
   fChain->SetBranchAddress("svAdapted_ntracks", svAdapted_ntracks, &b_svAdapted_ntracks);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_sip3d", Muon_sip3d, &b_Muon_sip3d);
   fChain->SetBranchAddress("Muon_ip3d", Muon_ip3d, &b_Muon_ip3d);
   fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
   fChain->SetBranchAddress("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_muEF", Jet_muEF, &b_Jet_muEF);
   fChain->SetBranchAddress("Jet_muonSubtrFactor", Jet_muonSubtrFactor, &b_Jet_muonSubtrFactor);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Leading_Jet_pt", &Leading_Jet_pt, &b_Leading_Jet_pt);
   fChain->SetBranchAddress("nmuonSV", &nmuonSV, &b_nmuonSV);
   fChain->SetBranchAddress("muonSV_dlen", muonSV_dlen, &b_muonSV_dlen);
   fChain->SetBranchAddress("muonSV_dlenSig", muonSV_dlenSig, &b_muonSV_dlenSig);
   fChain->SetBranchAddress("muonSV_dxy", muonSV_dxy, &b_muonSV_dxy);
   fChain->SetBranchAddress("muonSV_dxySig", muonSV_dxySig, &b_muonSV_dxySig);
   fChain->SetBranchAddress("muonSV_x", muonSV_x, &b_muonSV_x);
   fChain->SetBranchAddress("muonSV_y", muonSV_y, &b_muonSV_y);
   fChain->SetBranchAddress("muonSV_z", muonSV_z, &b_muonSV_z);
   fChain->SetBranchAddress("muonSV_ndof", muonSV_ndof, &b_muonSV_ndof);
   fChain->SetBranchAddress("muonSV_chi2", muonSV_chi2, &b_muonSV_chi2);
   fChain->SetBranchAddress("muonSV_pAngle", muonSV_pAngle, &b_muonSV_pAngle);
   fChain->SetBranchAddress("muonSV_origMass", muonSV_origMass, &b_muonSV_origMass);
   fChain->SetBranchAddress("muonSV_mass", muonSV_mass, &b_muonSV_mass);
   fChain->SetBranchAddress("muonSV_mu1pt", muonSV_mu1pt, &b_muonSV_mu1pt);
   fChain->SetBranchAddress("muonSV_mu2pt", muonSV_mu2pt, &b_muonSV_mu2pt);
   fChain->SetBranchAddress("muonSV_mu1phi", muonSV_mu1phi, &b_muonSV_mu1phi);
   fChain->SetBranchAddress("muonSV_mu2phi", muonSV_mu2phi, &b_muonSV_mu2phi);
   fChain->SetBranchAddress("muonSV_mu1eta", muonSV_mu1eta, &b_muonSV_mu1eta);
   fChain->SetBranchAddress("muonSV_mu2eta", muonSV_mu2eta, &b_muonSV_mu2eta);
   fChain->SetBranchAddress("muonSV_mu1index", muonSV_mu1index, &b_muonSV_mu1index);
   fChain->SetBranchAddress("muonSV_mu2index", muonSV_mu2index, &b_muonSV_mu2index);
   fChain->SetBranchAddress("qcdShatWeight", &qcdShatWeight, &b_qcdShatWeight);
   Notify();
}

Bool_t Friends::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Friends::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Friends::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Friends_cxx
