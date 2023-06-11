#include "vtkABI.h"
#include "vtkClientServerInterpreter.h"

extern void vtkBinReader_Init(vtkClientServerInterpreter*);
extern void vtkBinReaderModule_Init(vtkClientServerInterpreter*);

extern "C" void VTK_ABI_EXPORT vtkBinReaderCS_Initialize(vtkClientServerInterpreter* csi)
{
  (void)csi;
  vtkBinReader_Init(csi);
  vtkBinReaderModule_Init(csi);
}
