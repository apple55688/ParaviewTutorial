set(sources
  BinReader.h
  BinReader.cxx
)

paraview_add_plugin(BinReaderPlugin
  REQUIRED_ON_CLIENT
  REQUIRED_ON_SERVER
  VERSION "1.0"
  MODULES vtkBinReader
  MODULE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/vtkBinReader/vtk.module"
  EXTRA_INCLUDES BinReader.h
  SOURCES ${sources}
)

install(TARGETS BinReaderPlugin
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/paraview.plugin"
  DESTINATION ${CMAKE_INSTALL_PLUGINDIR}
  )
