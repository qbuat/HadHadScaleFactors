#ifndef HadHadScaleFactors_HadHadScaleFactors_H
#define HadHadScaleFactors_HadHadScaleFactors_H

class HHSF {

 public:
  
  HHSF() {};
  virtual ~HHSF() {};

  float trigger_sf(const bool& pass_1, const bool& pass_2, const float& sf_1, const float& sf_2);

  float tauid_sf(const long& event_number, 
		 const bool& tight_1, 
		 const bool& tight_2, 
		 const float& sf_tight_1, 
		 const float& sf_tight_2, 
		 const float& sf_med_1, 
		 const float& sf_med_2);

};


#endif
