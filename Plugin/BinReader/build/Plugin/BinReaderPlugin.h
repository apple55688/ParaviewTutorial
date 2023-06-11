#define _paraview_add_plugin_built_shared 1
#define _paraview_add_plugin_with_initializers 0
#define _paraview_add_plugin_with_python 0
#define _paraview_add_plugin_with_ui 0
#define _paraview_add_plugin_with_xml 1

#define PARAVIEW_BUILDING_PLUGIN
#define PARAVIEW_PLUGIN_BUILT_SHARED _paraview_add_plugin_built_shared
#include "vtkPVPlugin.h"

#if _paraview_add_plugin_with_ui
#include "vtkPVGUIPluginInterface.h"
#include <QObject>
#include <QtPlugin>
#endif

#if _paraview_add_plugin_with_xml
#include "vtkPVServerManagerPluginInterface.h"
#endif

#if _paraview_add_plugin_with_python
#include "vtkPVPythonPluginInterface.h"
#endif

#if _paraview_add_plugin_with_initializers
#include "vtkPVDynamicInitializerPluginInterface.h"
#endif

class BinReaderPlugin :
#if _paraview_add_plugin_with_ui
  public QObject,
  public vtkPVGUIPluginInterface,
#endif

  public vtkPVPlugin

#if _paraview_add_plugin_with_initializers
  , public vtkPVDynamicInitializerPluginInterface
#endif
#if _paraview_add_plugin_with_xml
  , public vtkPVServerManagerPluginInterface
#endif
#if _paraview_add_plugin_with_python
  , public vtkPVPythonPluginInterface
#endif

{
#if _paraview_add_plugin_with_ui
  Q_OBJECT
  Q_INTERFACES(vtkPVGUIPluginInterface)
  Q_PLUGIN_METADATA(IID "com.kitware/paraview/BinReaderPlugin")
#endif
public:
  BinReaderPlugin();

  /**
   * Returns the name for this plugin.
   */
  const char* GetPluginName() override
    {return "BinReader"; }

  /**
   * Returns the version for this plugin.
   */
  const char* GetPluginVersionString() override
    { return "1.0"; }

  /**
   * Returns true if this plugin is required on the server.
   */
  bool GetRequiredOnServer() override
    { return true; }

  /**
   * Returns true if this plugin is required on the client.
   */
  bool GetRequiredOnClient() override
    { return true; }

  /**
   * Returns a ';' separated list of plugin names required by this plugin.
   */
  const char* GetRequiredPlugins() override
    { return ""; }

  /**
   * Returns a description of this plugin.
   */
  const char* GetDescription() override
    { return "An example plugin that adds a reader to the ParaView GUI. It is added in the file dialog when opening files."; }

  /**
   * Returns EULA for the plugin, if any. If none, this will return nullptr.
   */
  const char* GetEULA() override;

  /**
   * Provides access to binary resources compiled into the plugin. This is
   * primarily used to compile in icons and compressed help project (qch) files
   * into plugins.
   */
  void GetBinaryResources(std::vector<std::string>& resources) override;

#if _paraview_add_plugin_with_xml
  /**
   * Obtain the server-manager configuration xmls, if any.
   */
  void GetXMLs(std::vector<std::string> &xmls) override;

  /**
   * Returns the callback function to call to initialize the interpretor for
   * the new vtk/server-manager classes added by this plugin. Returning nullptr
   * is perfectly valid.
   */
  vtkClientServerInterpreterInitializer::InterpreterInitializationCallback
    GetInitializeInterpreterCallback() override;
#endif

#if _paraview_add_plugin_with_ui
  /**
   * Returns the list of ParaView-Interfaces provided by this plugin.
   */
  QObjectList interfaces() override;
#endif

#if _paraview_add_plugin_with_python
  void GetPythonSourceList(std::vector<std::string>& modules,
    std::vector<std::string>& sources,
    std::vector<int>& package_flags) override;
#endif

#if _paraview_add_plugin_with_initializers
  void Initialize() override;
#endif
};
