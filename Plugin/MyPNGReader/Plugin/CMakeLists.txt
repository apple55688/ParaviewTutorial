# The pqReader.xml file contains xml defining readers with their file
# extensions and descriptions.  The Server Manager XML file defines the
# properties of the reader.  This example uses the already existing PNG reader
# but gives it another identity in the Server Manager.  Adding your own reader
# to ParaView would mean the SourceProxy class points to your class.
paraview_add_plugin(MyPNGReader
  REQUIRED_ON_CLIENT
  REQUIRED_ON_SERVER
  VERSION "1.0"
  SERVER_MANAGER_XML readers.xml)
