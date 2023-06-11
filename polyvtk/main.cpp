#include <vtkSmartPointer.h>
#include <vtkPolyDataReader.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkPolyDataWriter.h>

int main(int argc, char* argv[])
{
  // Read the VTK file
  vtkSmartPointer<vtkPolyDataReader> reader = vtkSmartPointer<vtkPolyDataReader>::New();
  reader->SetFileName("binary.vtk");
  reader->Update();

  // Get the polydata
  vtkPolyData* polydata = reader->GetOutput();

  // Get the points
  vtkPoints* points = polydata->GetPoints();

  // Modify the point coordinates
  vtkIdType numPoints = points->GetNumberOfPoints();
  for (vtkIdType i = 0; i < numPoints; ++i)
  {
    double* coordinates = points->GetPoint(i);
    // Modify the coordinates here
    coordinates[0] += 1.0;  // Modify X coordinate
    coordinates[1] += 2.0;  // Modify Y coordinate
    coordinates[2] += 3.0;  // Modify Z coordinate
  }

  // Write the modified polydata to a new VTK file
  vtkSmartPointer<vtkPolyDataWriter> writer = vtkSmartPointer<vtkPolyDataWriter>::New();
  writer->SetFileName("output.vtk");
  writer->SetInputData(polydata);
  writer->Write();

  return 0;
}
