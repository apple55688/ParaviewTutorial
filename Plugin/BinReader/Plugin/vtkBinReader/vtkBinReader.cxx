#include "vtkBinReader.h"
#include "vtkObjectFactory.h"

vtkStandardNewMacro(vtkBinReader);

vtkBinReader::vtkBinReader()
{
  this->FileName = nullptr;
}

vtkBinReader::~vtkBinReader()
{
  if (this->FileName)
  {
    delete[] this->FileName;
    this->FileName = nullptr;
  }
}

int vtkBinReader::RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*)
{
  // Open the file
  FILE* fp = fopen(this->FileName, "rb");
  if (!fp)
  {
    vtkErrorMacro(<< "Failed to open file " << this->FileName);
    return 0;
  }

  // Read the data and print it out
  char buf[1024];
  while (!feof(fp))
  {
    size_t numRead = fread(buf, 1, 1024, fp);
    if (numRead > 0)
    {
      printf("%.*s", static_cast<int>(numRead), buf);
    }
  }

  // Close the file
  fclose(fp);

  return 1;
}



