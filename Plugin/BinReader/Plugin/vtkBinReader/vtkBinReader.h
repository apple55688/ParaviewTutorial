#ifndef __vtkBinReader_h
#define __vtkBinReader_h

#include "vtkImageAlgorithm.h"

class VTK_EXPORT vtkBinReader : public vtkImageAlgorithm
{
public:
  static vtkBinReader* New();
  vtkTypeMacro(vtkBinReader, vtkImageAlgorithm);
  vtkSetStringMacro(FileName);
  vtkGetStringMacro(FileName);

protected:
  vtkBinReader();
  ~vtkBinReader();
  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*);

private:
  char* FileName;

  vtkBinReader(const vtkBinReader&) = delete;
  void operator=(const vtkBinReader&) = delete;
};


#endif