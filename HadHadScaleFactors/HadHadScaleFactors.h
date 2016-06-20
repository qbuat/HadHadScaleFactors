#ifndef HadHadScaleFactors_HadHadScaleFactors_H
#define HadHadScaleFactors_HadHadScaleFactors_H


namespace HHSF {

  struct DummyStruct {};


  const float trigger_sf(bool match_1, 
			 bool match_2, 
			 float sf_1, 
			 float sf_2);

  const float tauid_sf(long event_number, 
		       bool tight_1, 
		       bool tight_2, 
		       float sf_tight_1, 
		       float sf_tight_2, 
		       float sf_med_1, 
		       float sf_med_2);
}


#endif
