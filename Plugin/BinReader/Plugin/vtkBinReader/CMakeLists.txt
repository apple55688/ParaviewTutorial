set(classes
  vtkBinReader)

vtk_module_add_module(vtkBinReader
    FORCE_STATIC
    CLASSES ${classes})

paraview_add_server_manager_xmls(
    XMLS  readers.xml)
