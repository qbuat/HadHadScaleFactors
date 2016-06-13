#include "HadHadScaleFactors/HadHadScaleFactors.h"
#include "TError.h"


float HHSF::trigger_sf(const bool& pass_1, const bool& pass_2, const float& sf_1, const float& sf_2)
{

  return pass_1 * sf_1 * pass_2 * sf_2;

}

float HHSF::tauid_sf(const long& event_number, 
		     const bool& tight_1, 
		     const bool& tight_2, 
		     const float& sf_tight_1, 
		     const float& sf_tight_2, 
		     const float& sf_med_1, 
		     const float& sf_med_2)

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
    Fatal("HHSF", "At least one tau should pass tight");

  return -1;

}
