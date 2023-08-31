#include "analysis.hh"

int main (int argc, char **argv)
{
  if (argc < 5)
    {
      printf("\nUsage: %s *.root\n\n",argv[0]);
      exit(0);
    }
  int const index = argc - 1;
  TString path[index];
  for ( int j = 0; j < argc-1; j++)
    {
      path[j] = (argv[j+1]);
      cout<<path[j]<<endl;
    }
  
  cout<<"File name = "<<path[0]<<endl;
  
  TString file_details= path[0];
  std::string str_input(file_details.Data());
  //str_input += "/*.root";
  std::string str(file_details.Data());
  std::replace(str.begin(), str.end(), '_', ' ');  // replace '_' by ' '

  vector<string> array;
  stringstream ss(str);
  string temp;
  while (ss >> temp)
    array.push_back(temp); 

  TChain *chain = new TChain("Friends");
  
  
  //Data
  //for (int k = 1; k < 395 ; k++){     //1% of era B
  for (int k = 1; k < 318 ; k++){      //1% of era C 
  //for (int k = 1; k < 1074 ; k++){      //5% of era D
      std::string str_input_file(str_input + "/output_"+ std::to_string(k)+"_Friend.root");
      if(gSystem->AccessPathName(str_input_file.c_str())==0){
          chain -> Add(str_input_file.c_str()); // Add the root file to the TChain chain
          cout << " adding " << str_input_file << endl;
          }
      }
  

  //MC
  /*  
  str_input += "/*.root";
  chain -> Add(str_input.c_str()); // Add the root file to the TChain chain
  cout << " adding " << str_input << endl;
  */
   

  p = new Friends(chain);

  int numev = p->fChain->GetEntries();
  cout << "Total number of events to be processed = " << numev << endl;

  get_event(0) ;

  string gen_mass_input(path[argc-3].Data());
  double gen_mass = stod(gen_mass_input);
  cout << "gen mass = " << gen_mass << endl;

  for( int i = 0 ; i < numev ; i ++ )

     {
       if(i>0 && i%50000==0) cout << "Processed " << i << " events..."<<endl;
   
       get_event(i);
     
       vector<double> chi2;
       vector<double> dR;
       vector<double> pAngle;
       vector<double> dxy;
       vector<double> vx;
       vector<double> vy;
       vector<double> vz;
       vector<double> mass;
       vector<double> mu1index;
       vector<double> mu2index;
       vector<double> mass_multivertices;
       vector<double> chi2_multivertices;

       chi2.clear();
       dR.clear();
       pAngle.clear();
       dxy.clear();
       vx.clear();
       vy.clear();
       vz.clear();
       mass.clear();
       mu1index.clear();
       mu2index.clear();
       mass_multivertices.clear();
       chi2_multivertices.clear();

       //nmuonSV cut
       if(p->nmuonSV ==0){
         continue;
         }

       int cat_index = 0;
       int nmuonSV_3sigma = 0;
       int count_multivertices = 0;
       
       double sigma = 0.01*gen_mass;
      
       for(int muonSV=0; muonSV<(int)p->nmuonSV; muonSV++){
          chi2.push_back(p->muonSV_chi2[muonSV]);
          dR.push_back(sqrt(pow(p->muonSV_mu1phi[muonSV] - p->muonSV_mu2phi[muonSV], 2) + pow(p->muonSV_mu1eta[muonSV] - p->muonSV_mu2eta[muonSV], 2)));
          pAngle.push_back(p->muonSV_pAngle[muonSV]);
          dxy.push_back(p->muonSV_dxy[muonSV]);
          vx.push_back(p->muonSV_x[muonSV]);
          vy.push_back(p->muonSV_y[muonSV]);
          vz.push_back(p->muonSV_z[muonSV]);
          mass.push_back(p->muonSV_mass[muonSV]);
          mu1index.push_back(p->muonSV_mu1index[muonSV]);
          mu2index.push_back(p->muonSV_mu2index[muonSV]);
          if (p->muonSV_mass[muonSV] > gen_mass - 3*sigma && p->muonSV_mass[muonSV] < gen_mass + 3*sigma){
             nmuonSV_3sigma += 1;
          } 

          for(int muonSV1=muonSV+1; muonSV1<(int)p->nmuonSV; muonSV1++){
             if (fabs(p->muonSV_mass[muonSV1] - p->muonSV_mass[muonSV])/p->muonSV_mass[muonSV] < 3*0.01*p->muonSV_mass[muonSV]){
                 if(p->muonSV_mu1index[muonSV] != p->muonSV_mu1index[muonSV1] && p->muonSV_mu1index[muonSV] != p->muonSV_mu2index[muonSV1] && p->muonSV_mu2index[muonSV] != p->muonSV_mu1index[muonSV1] && p->muonSV_mu2index[muonSV] != p->muonSV_mu2index[muonSV1] && p->muonSV_chi2[muonSV] < 10 && p->muonSV_chi2[muonSV1] < 10 && p->muonSV_mu1eta[muonSV] != 0 && p->muonSV_mu2eta[muonSV] != 0 && p->muonSV_mu1eta[muonSV1] != 0 && p->muonSV_mu2eta[muonSV1] != 0){
                   cat_index += 1;
                   mass_multivertices.push_back(p->muonSV_mass[muonSV1]);
                   mass_multivertices.push_back(p->muonSV_mass[muonSV]);
                   chi2_multivertices.push_back(p->muonSV_chi2[muonSV1]);
                   chi2_multivertices.push_back(p->muonSV_chi2[muonSV]);
                   /* 
                   if(p->muonSV_mass[muonSV] > 10 || p->muonSV_mass[muonSV1] > 10){
                     int min_chi2_index_check = 0;
                     if (p->muonSV_chi2[muonSV] > p->muonSV_chi2[muonSV1]) min_chi2_index_check = muonSV1;
                     if (p->muonSV_chi2[muonSV] < p->muonSV_chi2[muonSV1]) min_chi2_index_check = muonSV;
                       if (p->muonSV_mass[min_chi2_index_check] < 12 && p->muonSV_mass[min_chi2_index_check] > 10){
                       cout << "MuonSV dlen = " << p->muonSV_dlen[min_chi2_index_check] << endl;
                       cout << "MuonSV dlenSig = " << p->muonSV_dlenSig[min_chi2_index_check] << endl;
                       cout << "MuonSV dxy = " << p->muonSV_dxy[min_chi2_index_check] << endl;
                       cout << "MuonSV dxySig = " << p->muonSV_dxySig[min_chi2_index_check] << endl;
                       cout << "MuonSV ndof = " << p->muonSV_ndof[min_chi2_index_check] << endl;
                       cout << "MuonSV chi2 = " << p->muonSV_chi2[min_chi2_index_check] << endl; 
                       cout << "MuonSV pAngle = " << p->muonSV_pAngle[min_chi2_index_check] << endl;
                       cout << "MuonSV mass = " << p->muonSV_mass[min_chi2_index_check] << endl;
                       cout << "MuonSV mu1pt = " << p->muonSV_mu1pt[min_chi2_index_check] << endl;
                       cout << "MuonSV mu2pt = " << p->muonSV_mu2pt[min_chi2_index_check] << endl;
                       cout << "MuonSV mu1phi = " << p->muonSV_mu1phi[min_chi2_index_check] << endl;
                       cout << "MuonSV mu2phi = " << p->muonSV_mu2phi[min_chi2_index_check] << endl;
                       cout << "MuonSV mu1eta = " << p->muonSV_mu1eta[min_chi2_index_check] << endl;
                       cout << "MuonSV mu2eta = " << p->muonSV_mu2eta[min_chi2_index_check] << endl;
                       }
                   }
                   */
                 }
             }                
          }
       }

       
       auto min_chi2_multiverticies = min_element(begin(chi2_multivertices), end(chi2_multivertices));
       auto min_chi2_index_multivertices = distance(begin(chi2_multivertices), min_chi2_multiverticies);
        
       auto min_chi2 = min_element(begin(chi2), end(chi2));
       auto min_chi2_index = distance(begin(chi2), min_chi2);

       //dR cut
       if(dR[min_chi2_index] >= 1.2) continue;

       muonSV_mass_min_chi2->Fill(mass[min_chi2_index]);

       if(p->muonSV_mu1eta[min_chi2_index] == 0 || p->muonSV_mu2eta[min_chi2_index] == 0){
          cout << "Muon has eta = 0!" << endl;
       }

       nmuonSV_plot->Fill(nmuonSV_3sigma);

       //multi-vertex category
       if(cat_index != 0){
         muonSV_mass_min_chi2_categorised->Fill(mass_multivertices[min_chi2_index_multivertices]);
         muonSV_mass_min_chi2_multivertices_cat->Fill(mass_multivertices[min_chi2_index_multivertices]);
         //category 1
         if(dxy[min_chi2_index] < 1 && pAngle[min_chi2_index] < 0.2){
           muonSV_mass_multivertices_cat1->Fill(mass_multivertices[min_chi2_index_multivertices]);
           muonSV_mass_multivertices_mass_window_cat1->Fill(mass_multivertices[min_chi2_index_multivertices]);
         }
         //category 2
         if(dxy[min_chi2_index] < 1 && pAngle[min_chi2_index] > 0.2){
           muonSV_mass_multivertices_cat2->Fill(mass_multivertices[min_chi2_index_multivertices]);
           muonSV_mass_multivertices_mass_window_cat2->Fill(mass_multivertices[min_chi2_index_multivertices]);
         } 
         //category 3
         if(dxy[min_chi2_index] > 1 && dxy[min_chi2_index] < 10 && pAngle[min_chi2_index] < 0.2){
           muonSV_mass_multivertices_cat3->Fill(mass_multivertices[min_chi2_index_multivertices]);
           muonSV_mass_multivertices_mass_window_cat3->Fill(mass_multivertices[min_chi2_index_multivertices]);
         }
         //category 4
         if(dxy[min_chi2_index] > 1 && dxy[min_chi2_index] < 10 && pAngle[min_chi2_index] > 0.2){
           muonSV_mass_multivertices_cat4->Fill(mass_multivertices[min_chi2_index_multivertices]);
           muonSV_mass_multivertices_mass_window_cat4->Fill(mass_multivertices[min_chi2_index_multivertices]);
         }
         //category 5
         if(dxy[min_chi2_index] > 10 && pAngle[min_chi2_index] < 0.2){
           muonSV_mass_multivertices_cat5->Fill(mass_multivertices[min_chi2_index_multivertices]);
           muonSV_mass_multivertices_mass_window_cat5->Fill(mass_multivertices[min_chi2_index_multivertices]);
         }
         //category 6 
         if(dxy[min_chi2_index] > 10 && pAngle[min_chi2_index] > 0.2){
           muonSV_mass_multivertices_cat6->Fill(mass_multivertices[min_chi2_index_multivertices]);
           muonSV_mass_multivertices_mass_window_cat6->Fill(mass_multivertices[min_chi2_index_multivertices]);
         }

         //new category 1
         if(dxy[min_chi2_index] < 1){
           muonSV_mass_multivertices_cat1_new->Fill(mass_multivertices[min_chi2_index_multivertices]);
           muonSV_mass_multivertices_mass_window_cat1_new->Fill(mass_multivertices[min_chi2_index_multivertices]); 
         }

         //new category 2
         if(dxy[min_chi2_index] > 1){
           muonSV_mass_multivertices_cat2_new->Fill(mass_multivertices[min_chi2_index_multivertices]);
           muonSV_mass_multivertices_mass_window_cat2_new->Fill(mass_multivertices[min_chi2_index_multivertices]);
         }

 
         int i,j; 
         count_multivertices += 1;                                                          
         for (i =1; i < mass_multivertices.size(); i++){
             for(j =0; j<i; j++){
                if (mass_multivertices[i] == mass_multivertices[j]){
                   break;
                }
              }
              if (i==j) count_multivertices++;
          }
       }
  
       nmuonSV_multivertices_plot->Fill(count_multivertices);
   
       //check muon SV has no muons with eta == 0 for single vertex category
       if(p->muonSV_mu1eta[min_chi2_index] == 0 || p->muonSV_mu2eta[min_chi2_index] == 0){
          cout << "Muon has eta = 0!" << endl;
          continue; 
       }
   
       //single-vertex category
       if(cat_index == 0){
         muonSV_mass_min_chi2_categorised->Fill(mass[min_chi2_index]);
         muonSV_mass_min_chi2_singlevertex_cat->Fill(mass[min_chi2_index]);
         //category 1
         if(dxy[min_chi2_index] < 1 && pAngle[min_chi2_index] < 0.2){
           muonSV_mass_singlevertex_cat1->Fill(mass[min_chi2_index]);
           muonSV_mass_singlevertex_mass_window_cat1->Fill(mass[min_chi2_index]); 
         }
         //category 2
         if(dxy[min_chi2_index] < 1 && pAngle[min_chi2_index] > 0.2){
           muonSV_mass_singlevertex_cat2->Fill(mass[min_chi2_index]);
           muonSV_mass_singlevertex_mass_window_cat2->Fill(mass[min_chi2_index]); 
         } 
         //category 3
         if(dxy[min_chi2_index] > 1 && dxy[min_chi2_index] < 10 && pAngle[min_chi2_index] < 0.2){
           muonSV_mass_singlevertex_cat3->Fill(mass[min_chi2_index]);
           muonSV_mass_singlevertex_mass_window_cat3->Fill(mass[min_chi2_index]);
         }
         //category 4
         if(dxy[min_chi2_index] > 1 && dxy[min_chi2_index] < 10 && pAngle[min_chi2_index] > 0.2){
           muonSV_mass_singlevertex_cat4->Fill(mass[min_chi2_index]);
           muonSV_mass_singlevertex_mass_window_cat4->Fill(mass[min_chi2_index]);
         }
         //category 5
         if(dxy[min_chi2_index] > 10 && pAngle[min_chi2_index] < 0.2){
           muonSV_mass_singlevertex_cat5->Fill(mass[min_chi2_index]);
           muonSV_mass_singlevertex_mass_window_cat5->Fill(mass[min_chi2_index]);
         }
         //category 6  
         if(dxy[min_chi2_index] > 10 && pAngle[min_chi2_index] > 0.2){
           muonSV_mass_singlevertex_cat6->Fill(mass[min_chi2_index]);
           muonSV_mass_singlevertex_mass_window_cat6->Fill(mass[min_chi2_index]);
         }

        
 
       }

       //category 3
       if(dxy[min_chi2_index] > 1 && dxy[min_chi2_index] < 10 && pAngle[min_chi2_index] < 0.2){
         muonSV_mass_cat3->Fill(mass[min_chi2_index]); 
       }
       
       //categpry 4
       if(dxy[min_chi2_index] > 1 && dxy[min_chi2_index] < 10 && pAngle[min_chi2_index] > 0.2){
         muonSV_mass_cat4->Fill(mass[min_chi2_index]);
       }
       /*
       vector<TVector3> genpart_vertices0;
       vector<TVector3> genpart_vertices;
       vector<TVector3> genpart_vertices1;

       genpart_vertices0.clear();
       genpart_vertices.clear();
       genpart_vertices1.clear();
 
       for(int genpart0=0;genpart0<(int)p->nGenPart;genpart0++){  
        TVector3 genpart_vertex0; 
        genpart_vertex0.SetXYZ(p->GenPart_vertex_x[genpart0],p->GenPart_vertex_y[genpart0],p->GenPart_vertex_z[genpart0]);
        genpart_vertices0.push_back(genpart_vertex0);
       }
  
       for(int genpart=0;genpart<(int)p->nGenPart;genpart++){
	int leadingmupt_index=-1, lowestmupt_index=-1;
        int recomupt_index1=-1, recomupt_index2=-1;
        int leadingrecomupt_index=-1, lowestrecomupt_index=-1;
        int recomuplus_index = -1, recomuminus_index = -1;
        int muplus_index = -1, muminus_index = -1;    
        
        if(p->GenPart_status[genpart]!=1 || fabs(p->GenPart_pdgId[genpart])!=13 || fabs(p->GenPart_pt[genpart])<=3.0 || fabs(p->GenPart_eta[genpart])>=2.4) continue;
 
        int mu1_match = 0; int mu2_match = 0;

        TVector3 genpart_vertex;
	genpart_vertex.SetXYZ(p->GenPart_vertex_x[genpart],p->GenPart_vertex_y[genpart],p->GenPart_vertex_z[genpart]);

        for(int recomu=0;recomu<(int)p->nMuon;recomu++){
	  if(p->Muon_genPartIdx[recomu]==genpart){ 
            mu1_match++;
            recomupt_index1 = recomu;
            }
	}
        int match=0;
	for(int genpart1=genpart+1;genpart1<(int)p->nGenPart;genpart1++){
	  if(p->GenPart_status[genpart1]!=1 || fabs(p->GenPart_pdgId[genpart1])!=13 || fabs(p->GenPart_pt[genpart1])<=3.0 || fabs(p->GenPart_eta[genpart1])>=2.4) continue;
          TVector3 genpart_vertex1;
	  for(int recomu=0;recomu<(int)p->nMuon;recomu++){
	    if(p->Muon_genPartIdx[recomu]==genpart1){
              mu2_match++;
              recomupt_index2 = recomu;
              }
	  }
          genpart_vertex1.SetXYZ(p->GenPart_vertex_x[genpart1],p->GenPart_vertex_y[genpart1],p->GenPart_vertex_z[genpart1]);
          //int genpartidxmother = p->GenPart_genPartIdxMother[genpart];
          //int genpartidxmother1 = p->GenPart_genPartIdxMother[genpart1]; 
	  if(genpart_vertex==genpart_vertex1){
            //int genpart_mother_match = 0;
            //for(int genpart2=0;genpart2<(int)p->nGenPart;genpart2++){
              //if(p->GenPart_genPartIdxMother[genpart2]==p->GenPart_genPartIdxMother[genpart1]){genpart_mother_match++;}
            //}
            int check_vertex = 0;
            for(int index=0;index<genpart_vertices0.size(); index++){
              if(genpart_vertices0.at(index)==genpart_vertex1){check_vertex++;}
            }

            if(check_vertex==2){
	      match++;
              leadingmupt_index=genpart; lowestmupt_index=genpart1;
              leadingrecomupt_index = recomupt_index1; lowestrecomupt_index = recomupt_index2;
              
              if(p->GenPart_pt[genpart1]>p->GenPart_pt[genpart]){ leadingmupt_index=genpart1; lowestmupt_index=genpart; leadingrecomupt_index = recomupt_index2; lowestrecomupt_index = recomupt_index1;}

              recomuplus_index = recomupt_index1; recomuminus_index = recomupt_index2; muplus_index = genpart; muminus_index = genpart1;
              if(p->Muon_charge[recomupt_index2]== 1){recomuplus_index = recomupt_index2; recomuminus_index = recomupt_index1; muplus_index = genpart1; muminus_index = genpart;}
            } 
	  }

       }
      
       if(match>0){ 

	  int check_previous_vertex=0;
	  for(int index=0;index<genpart_vertices.size(); index++){
	    if(genpart_vertices.at(index)==genpart_vertex){
              check_previous_vertex++;
              }
          }
          if(check_previous_vertex!=0){cout << "check_previous_vertex= " << check_previous_vertex << endl;} 
	  if(check_previous_vertex==0){
	    genpart_vertices.push_back(genpart_vertex);
            if(mu1_match>0 && mu2_match>0 && leadingmupt_index != -1 && lowestmupt_index != -1 && leadingrecomupt_index != -1 && lowestrecomupt_index != -1){
	      //cout<<"Matched both reco muons for this event"<<endl;
	      genpart_vertices1.push_back(genpart_vertex);
	      }
            }
         }
     } //Gen particle loop ends
 
     //Check matching between generated SV and min chi2 SV
     for(int genpart=0;genpart<(int)genpart_vertices1.size();genpart++){
	int match_dR=0, match_dR_distance=0, match_dR_distance1=0;
      	int match_dR_distance_darkqcd=0;
      	TVector3 genpart_vertex = genpart_vertices1.at(genpart);
 
        
        TVector3 sv_vertex;
	sv_vertex.SetXYZ(p->muonSV_x[min_chi2_index],p->muonSV_y[min_chi2_index],p->muonSV_z[min_chi2_index]);
        double dR_distance = (genpart_vertex-sv_vertex).Perp();
        if(dR_distance<0.1){
         //category 1
         if(dxy[min_chi2_index] < 1 && pAngle[min_chi2_index] < 0.2){
         muonSV_gen_matched_mass_cat1->Fill(mass[min_chi2_index]);
         }
         
         //category 2 
         if(dxy[min_chi2_index] < 1 && pAngle[min_chi2_index] > 0.2){
         muonSV_gen_matched_mass_cat2->Fill(mass[min_chi2_index]);
         }

         //category 3
         if(dxy[min_chi2_index] > 1 && dxy[min_chi2_index] < 10 && pAngle[min_chi2_index] < 0.2){
         muonSV_gen_matched_mass_cat3->Fill(mass[min_chi2_index]);
         }

         //category 4
         if(dxy[min_chi2_index] > 1 && dxy[min_chi2_index] < 10 && pAngle[min_chi2_index] > 0.2){
         muonSV_gen_matched_mass_cat4->Fill(mass[min_chi2_index]);
         } 
      
         //category 5
         if(dxy[min_chi2_index] > 10 && pAngle[min_chi2_index] < 0.2){
         muonSV_gen_matched_mass_cat5->Fill(mass[min_chi2_index]);
         }
         
         //category 6 
         if(dxy[min_chi2_index] > 10 && pAngle[min_chi2_index] > 0.2){
         muonSV_gen_matched_mass_cat6->Fill(mass[min_chi2_index]);
         }         
 
        }
      } 
      */     
 

     } //Event loop ends 

    string mass(path[argc-3].Data());
    string lifetime(path[argc-2].Data());
    string output_name(path[argc-4].Data());

    cout << "Mass = " << mass << endl;
    cout << "Lifetime = " << lifetime << endl;
    cout << "output_name = " << output_name << endl;
  
    TChain *signal_bdt = new TChain(); 
    signal_bdt->Add(Form("/vols/cms/mmieskol/icenet/output/dqcd/deploy/modeltag__vector_all/vols/cms/mc3909/bparkProductionAll_V1p0/HiddenValley_vector_m_%s_ctau_%s_xiO_1_xiL_1_privateMC_11X_NANOAODSIM_v1p0_generationSync/*.root/Events", mass.c_str(), lifetime.c_str()));
   
    auto no_of_entries_original = signal_bdt->GetEntries();
    cout << "Number of entries original = " << no_of_entries_original << endl;
    auto lumi = 33.6*1000;
    auto xs = 43.9;
    auto branching_ratio = 0.01;
    
    /*
    muonSV_mass_cat3->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    muonSV_mass_cat4->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    muonSV_gen_matched_mass_cat1->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    muonSV_gen_matched_mass_cat2->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    muonSV_gen_matched_mass_cat3->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    muonSV_gen_matched_mass_cat4->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    muonSV_gen_matched_mass_cat5->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    muonSV_gen_matched_mass_cat6->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    
    muonSV_mass_min_chi2_categorised->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    muonSV_mass_min_chi2->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    nmuonSV_plot->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    nmuonSV_multivertices_plot->Scale(lumi*xs*branching_ratio/no_of_entries_original);
    */

    //TFile f(Form("/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/batch2/categorised_output_QCD_Pt-1000toInf_MuEnrichedPt5_m_%s_unscaled_checked2.root", mass.c_str()), "recreate");
    TFile f((output_name + "_m" + mass + "_ctau" + lifetime + ".root").c_str(), "recreate");
    muonSV_mass_min_chi2_categorised->Write();
    muonSV_mass_min_chi2->Write();
    nmuonSV_plot->Write();
    nmuonSV_multivertices_plot->Write();
    muonSV_mass_min_chi2_multivertices_cat->Write();
    muonSV_mass_min_chi2_singlevertex_cat->Write();
    muonSV_mass_multivertices_cat1->Write();
    muonSV_mass_multivertices_mass_window_cat1->Write();
    muonSV_mass_multivertices_cat2->Write();
    muonSV_mass_multivertices_mass_window_cat2->Write();
    muonSV_mass_multivertices_cat3->Write();
    muonSV_mass_multivertices_mass_window_cat3->Write();
    muonSV_mass_multivertices_cat4->Write();
    muonSV_mass_multivertices_mass_window_cat4->Write();
    muonSV_mass_multivertices_cat5->Write();
    muonSV_mass_multivertices_mass_window_cat5->Write();
    muonSV_mass_multivertices_cat6->Write();
    muonSV_mass_multivertices_mass_window_cat6->Write();
    muonSV_mass_multivertices_cat1_new->Write();
    muonSV_mass_multivertices_mass_window_cat1_new->Write();
    muonSV_mass_multivertices_cat2_new->Write();
    muonSV_mass_multivertices_mass_window_cat2_new->Write();  
    muonSV_mass_singlevertex_cat1->Write();
    muonSV_mass_singlevertex_mass_window_cat1->Write();
    muonSV_mass_singlevertex_cat2->Write();
    muonSV_mass_singlevertex_mass_window_cat2->Write();
    muonSV_mass_singlevertex_cat3->Write();
    muonSV_mass_singlevertex_mass_window_cat3->Write();
    muonSV_mass_singlevertex_cat4->Write();
    muonSV_mass_singlevertex_mass_window_cat4->Write();
    muonSV_mass_singlevertex_cat5->Write();
    muonSV_mass_singlevertex_mass_window_cat5->Write();
    muonSV_mass_singlevertex_cat6->Write();
    muonSV_mass_singlevertex_mass_window_cat6->Write(); 


    f.Close(); 
 
    /*
    TFile f1(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat1/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "UPDATE");
    f1.Delete("signal;1");
    f1.WriteObject(muonSV_gen_matched_mass_cat1, "signal");
    f1.Close();

    TCanvas* c1 = new TCanvas("", "", 800, 700);
    muonSV_gen_matched_mass_cat1->SetLineColor(kBlue+1);
    muonSV_gen_matched_mass_cat1->Draw("hist e1");

    c1->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat1/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));   
 
    TFile f2(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat2/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "UPDATE");
    f2.Delete("signal;1");
    f2.WriteObject(muonSV_gen_matched_mass_cat2, "signal");
    f2.Close();

    TCanvas* c2 = new TCanvas("", "", 800, 700);
    muonSV_gen_matched_mass_cat2->SetLineColor(kBlue+1);
    muonSV_gen_matched_mass_cat2->Draw("hist e1");

    c2->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat2/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str())); 

    TFile f3(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat3/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "UPDATE");
    f3.Delete("signal;1");
    f3.WriteObject(muonSV_gen_matched_mass_cat3, "signal");
    f3.Close();

    TCanvas* c3 = new TCanvas("", "", 800, 700);
    muonSV_gen_matched_mass_cat3->SetLineColor(kBlue+1);
    muonSV_gen_matched_mass_cat3->Draw("hist e1");

    c3->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat3/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));

    TFile f4(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat4/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "UPDATE");
    f4.Delete("signal;1");
    f4.WriteObject(muonSV_gen_matched_mass_cat4, "signal");
    f4.Close();

    TCanvas* c4 = new TCanvas("", "", 800, 700);
    muonSV_gen_matched_mass_cat4->SetLineColor(kBlue+1);
    muonSV_gen_matched_mass_cat4->Draw("hist e1");

    c4->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat4/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));
 
    TFile f5(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat5/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "UPDATE");
    f5.Delete("signal;1");
    f5.WriteObject(muonSV_gen_matched_mass_cat5, "signal");
    f5.Close();

    TCanvas* c5 = new TCanvas("", "", 800, 700);
    muonSV_gen_matched_mass_cat5->SetLineColor(kBlue+1);
    muonSV_gen_matched_mass_cat5->Draw("hist e1");

    c5->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat5/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));

    TFile f6(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat6/vector_m_%s/output_vector_%s_%s_1_1.root", mass.c_str(), mass.c_str(), lifetime.c_str()), "UPDATE");
    f6.Delete("signal;1");
    f6.WriteObject(muonSV_gen_matched_mass_cat6, "signal");
    f6.Close();

    TCanvas* c6 = new TCanvas("", "", 800, 700);
    muonSV_gen_matched_mass_cat6->SetLineColor(kBlue+1);
    muonSV_gen_matched_mass_cat6->Draw("hist e1");

    c6->Print(Form("/home/hep/khl216/CMSSW_10_2_13/src/statsForDS/output/muonSV/categories_gen_matched/cat6/vector_m_%s/muonSV_mass_%s_%s_1_1.pdf", mass.c_str(), mass.c_str(), lifetime.c_str()));
    */

    return 0;
 }








