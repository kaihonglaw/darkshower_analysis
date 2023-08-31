signal_input_dir="/vols/cms/khl216/nano_out/nanotron_v3_bdt_0p9994_fixed_with_gen_match/bparkProductionAll_V1p0/"
background_input_dir="/vols/cms/khl216/nano_out/nanotron_v3_bdt_0p95_fixed_with_gen_match/bparkProductionAll_V1p0/"
output_dir="/vols/cms/khl216/darkshower_analysis_muonSV_gen_matching/darkshower_analysis/makeclass_code/output/vector_m_20/"

for mass in 20;
do
    QCD_bin="QCD_Pt-1000toInf_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-120to170_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-120to170_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-15to20_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10  
    QCD_bin="QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-20to30_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v4_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext3-v1_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-30to50_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-50to80_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-800to1000_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext3-v2_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-80to120_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v2_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    QCD_bin="QCD_Pt-80to120_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1_MINIAODSIM_v1p0_generationSync"
    ./bin/analysis "$background_input_dir$QCD_bin" "$output_dir$QCD_bin" $mass 10
    for lifetime in 1 10 50 100 500 ;
    do
        signal="HiddenValley_vector_m_$mass""_ctau_$lifetime""_xiO_1_xiL_1_privateMC_11X_NANOAODSIM_v1p0_generationSync"
        ./bin/analysis "$signal_input_dir$signal" "$output_dir$signal" $mass $lifetime
    done
done
    
