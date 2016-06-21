#!/usr/bin/env python

import ROOT

ROOT.gROOT.Macro('$ROOTCOREDIR/scripts/load_packages.C')
ROOT.gROOT.SetBatch(True)

# instantiate the DummyStruct() to load the functions into CINT because ...
# ROOT is stupid: https://sft.its.cern.ch/jira/browse/ROOT-7216
dummy = ROOT.HHSF.DummyStruct()

rfile = ROOT.TFile.Open("root://eosatlas.cern.ch//eos/atlas/user/c/cgrefe/xTau-NTuples/hhsm_25.v10/"
                        "group.phys-higgs.hhsm_25.mc15_13TeV.361108.PoPy8_Ztt.D3.e3601_s2576_s2132_r7267_r6282_p2524.v10_hist/"
                        "group.phys-higgs.8040291._000001.hist-output.root")

tree = rfile.Get("NOMINAL")
print tree.GetEntries()


weight_trig_str = 'HHSF::trigger_sf({0}, {1}, {2}, {3})'.format(
    'ditau_tau0_HLT_tau35_medium1_tracktwo',
    'ditau_tau1_HLT_tau25_medium1_tracktwo',
    'ditau_tau0_sf_NOMINAL_effSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM',
    'ditau_tau1_sf_NOMINAL_effSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM')

weight_id_str = 'HHSF::tauid_sf({0}, {1}, {2}, {3}, {4}, {5}, {6})'.format(
    'event_number',
    'ditau_tau0_jet_bdt_tight',
    'ditau_tau1_jet_bdt_tight',
    'ditau_tau0_sf_NOMINAL_TAU_EFF_JETIDBDTTIGHT',
    'ditau_tau1_sf_NOMINAL_TAU_EFF_JETIDBDTTIGHT',
    'ditau_tau0_sf_NOMINAL_TAU_EFF_JETIDBDTMEDIUM',
    'ditau_tau1_sf_NOMINAL_TAU_EFF_JETIDBDTMEDIUM')

tauid_sel = 'n_taus_medium == 2 && n_taus_tight > 0 && ditau_tau0_jet_bdt_medium == 1 && ditau_tau1_jet_bdt_medium == 1'


hist = ROOT.TH1F("hist", "hist", 10, 0, 100)
tree.Draw("ditau_vis_mass>>hist", "({0}) * {1} * {2}".format(tauid_sel, weight_trig_str, weight_id_str))
print hist.Integral()
