//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------
#ifndef _ONEUSER_HH
#define _ONEUSER_HH

#include <map>
#include <iostream>
#include "aceSmartSoft.hh"
#include "smartQueryServerTaskTrigger_T.h"
#include "OneUserCore.hh"

#include "OneUserPortFactoryInterface.hh"
#include "OneUserExtension.hh"

// forward declarations
class OneUserPortFactoryInterface;
class OneUserExtension;

// includes for PlainOpcUaOneUserExtension
// include plain OPC UA device clients
// include plain OPC UA status servers


// include communication objects
#include <DGService_DGBasicLink/DGBasicLinkObject.hh>
#include <DGService_DGBasicLink/DGBasicLinkObjectACE.hh>

// include tasks
#include "ImageViewer.hh"
// include UpcallManagers
#include "BWMapUpcallManager.hh"
#include "MapUpcallManager.hh"

// include input-handler(s)
// include request-handler(s)

// include handler
#include "CompHandler.hh"


#include "SmartStateChangeHandler.hh"

#define COMP OneUser::instance()

class OneUser : public OneUserCore {
private:
	static OneUser *_oneUser;
	
	// constructor
	OneUser();
	
	// copy-constructor
	OneUser(const OneUser& cc);
	
	// destructor
	~OneUser() { };
	
	// load parameter from ini file
	void loadParameter(int argc, char* argv[]);
	
	// instantiate comp-handler
	CompHandler compHandler;
	
	// helper method that maps a string-name to an according TaskTriggerSubject
	Smart::TaskTriggerSubject* getInputTaskTriggerFromString(const std::string &client);
	
	// internal map storing the different port-creation factories (that internally map to specific middleware implementations)
	std::map<std::string, OneUserPortFactoryInterface*> portFactoryRegistry;
	
	// internal map storing various extensions of this component class
	std::map<std::string, OneUserExtension*> componentExtensionRegistry;
	
public:
	
	// define tasks
	Smart::TaskTriggerSubject* imageViewerTrigger;
	ImageViewer *imageViewer;
	
	// define input-ports
	// InputPort BWMap
	Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> *bWMap;
	Smart::InputTaskTrigger<DGService_DGBasicLink::DGBasicLinkObject> *bWMapInputTaskTrigger;
	BWMapUpcallManager *bWMapUpcallManager;
	// InputPort Map
	Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> *map;
	Smart::InputTaskTrigger<DGService_DGBasicLink::DGBasicLinkObject> *mapInputTaskTrigger;
	MapUpcallManager *mapUpcallManager;
	
	// define request-ports
	
	// define input-handler
	
	// define output-ports
	
	// define answer-ports
	
	// define request-handlers
	
	// definitions of PlainOpcUaOneUserExtension
	
	
	// define default slave ports
	SmartACE::StateSlave *stateSlave;
	SmartStateChangeHandler *stateChangeHandler;
	SmartACE::WiringSlave *wiringSlave;
	
	
	/// this method is used to register different PortFactory classes (one for each supported middleware framework)
	void addPortFactory(const std::string &name, OneUserPortFactoryInterface *portFactory);
	
	SmartACE::SmartComponent* getComponentImpl();
	
	/// this method is used to register different component-extension classes
	void addExtension(OneUserExtension *extension);
	
	/// this method allows to access the registered component-extensions (automatically converting to the actuall implementation type)
	template <typename T>
	T* getExtension(const std::string &name) {
		auto it = componentExtensionRegistry.find(name);
		if(it != componentExtensionRegistry.end()) {
			return dynamic_cast<T*>(it->second);
		}
		return 0;
	}
	
	/// initialize component's internal members
	void init(int argc, char *argv[]);
	
	/// execute the component's infrastructure
	void run();
	
	/// clean-up component's resources
	void fini();
	
	/// call this method to set the overall component into the Alive state (i.e. component is then ready to operate)
	void setStartupFinished();
	
	/// connect all component's client ports
	Smart::StatusCode connectAndStartAllServices();
	
	/// start all assocuated Activities
	void startAllTasks();
	
	/// start all associated timers
	void startAllTimers();
	
	Smart::StatusCode connectBWMap(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectMap(const std::string &serverName, const std::string &serviceName);

	// return singleton instance
	static OneUser* instance()
	{
		if(_oneUser == 0) {
			_oneUser = new OneUser();
		}
		return _oneUser;
	}
	
	static void deleteInstance() {
		if(_oneUser != 0) {
			delete _oneUser;
		}
	}
	
	// connections parameter
	struct connections_struct
	{
		// component struct
		struct component_struct
		{
			// the name of the component
			std::string name;
			std::string initialComponentMode;
			std::string defaultScheduler;
			bool useLogger;
		} component;
		
		//--- task parameter ---
		struct ImageViewer_struct {
			double minActFreq;
			double maxActFreq;
			std::string trigger;
			// only one of the following two params is 
			// actually used at run-time according 
			// to the system config model
			double periodicActFreq;
			// or
			std::string inPortRef;
			int prescale;
			// scheduling parameters
			std::string scheduler;
			int priority;
			int cpuAffinity;
		} imageViewer;
		
		//--- upcall parameter ---
		
		//--- server port parameter ---
	
		//--- client port parameter ---
		struct BWMap_struct {
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} bWMap;
		struct Map_struct {
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} map;
		
		// -- parameters for PlainOpcUaOneUserExtension
		
	} connections;
};
#endif
