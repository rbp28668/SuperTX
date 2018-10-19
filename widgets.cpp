
#include "stdafx.h"
#include "Widgets.hpp"

/************************************************************************
* Function:   CInput::PathExists
* static member which checks that if the given output is connected to 
* this input then we'll get a circular link.  These shouldn't be allowed
* as they will go into an infinite loop when trying to calculate
* the value.
* Parameters: pOutput is the output that is to be connected
* Returns:    true if a path exists, false if not
************************************************************************/
bool CInput::PathExists(const COutput* pOutput) const
{
  bool blExists = false;
  if(pOutput)  // 0 output is trivial case for recursion 
    {
    const CWidget* pParent = pOutput->Parent();
    int nInputs = pParent->InputCount();
    for(int i=0; !blExists && i<nInputs; ++i)
      {
      const CInput* pInput = &pParent->Input(i);
      if(pInput == this) // got back to this input
        blExists = true;
      else
        blExists = PathExists(pInput->Source());
      }
    }
  return blExists;
}
