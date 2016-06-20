#include "HadHadScaleFactors/HadHadScaleFactors.h"
#include "TError.h"


namespace HHSF {


  const float trigger_sf(bool match_1,  bool match_2,  float sf_1,  float sf_2)
  {
    
    return match_1 * sf_1 * match_2 * sf_2;
  
  }

  const float tauid_sf(long event_number, 
		       bool tight_1, 
		       bool tight_2, 
		       float sf_tight_1, 
		       float sf_tight_2, 
		       float sf_med_1, 
		       float sf_med_2)
    
  {
    // tight - medium
    if (tight_1 and not tight_2)
      return sf_tight_1 * sf_med_2;
    
    // medium - tight
    if (not tight_1 and tight_2)
      return sf_med_1 * sf_tight_2;
    
    // tight - tight
    if (tight_1 and tight_2) {
      if (event_number % 2 != 0) {
	return sf_tight_1 * sf_med_2;
      } else {
	return sf_med_1 * sf_tight_2;
      }
    }
    
    if (not tight_1 and not tight_2)
      return 0.;
      // Fatal("HHSF", "At least one tau should pass tight");
    
    return -1;
  }

} // end of namespace HHSF
