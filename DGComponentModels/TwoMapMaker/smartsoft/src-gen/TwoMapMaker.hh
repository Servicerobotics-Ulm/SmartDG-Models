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
#ifndef _TWOMAPMAKER_HH
#define _TWOMAPMAKER_HH

#include <map>
#include <iostream>
#include "aceSmartSoft.hh"
#include "smartQueryServerTaskTrigger_T.h"
#include "TwoMapMakerCore.hh"

#include "TwoMapMakerPortFactoryInterface.hh"
#include "TwoMapMakerExtension.hh"

// forward declarations
class TwoMapMakerPortFactoryInterface;
class TwoMapMakerExtension;

// includes for PlainOpcUaTwoMapMakerExtension
// include plain OPC UA device clients
// include plain OPC UA status servers


// include communication objects
#include <DGService_DGBasicLink/DGBasicLinkObject.hh>
#include <DGService_DGBasicLink/DGBasicLinkObjectACE.hh>

// include tasks
#include "GrayImageCollector.hh"
#include "ImageCollector.hh"
#include "ImageJoiner.hh"
// include UpcallManagers
#include "GrayImage1UpcallManager.hh"
#include "GrayImage2UpcallManager.hh"
#include "Image1UpcallManager.hh"
#include "Image2UpcallManager.hh"

// include input-handler(s)
// include request-handler(s)

// include handler
#include "CompHandler.hh"


#include "SmartStateChangeHandler.hh"

#define COMP TwoMapMaker::instance()

class TwoMapMaker : public TwoMapMakerCore {
private:
	static TwoMapMaker *_twoMapMaker;
	
	// constructor
	TwoMapMaker();
	
	// copy-constructor
	TwoMapMaker(const TwoMapMaker& cc);
	
	// destructor
	~TwoMapMaker() { };
	
	// load parameter from ini file
	void loadParameter(int argc, char* argv[]);
	
	// instantiate comp-handler
	CompHandler compHandler;
	
	// helper method that maps a string-name to an according TaskTriggerSubject
	Smart::TaskTriggerSubject* getInputTaskTriggerFromString(const std::string &client);
	
	// internal map storing the different port-creation factories (that internally map to specific middleware implementations)
	std::map<std::string, TwoMapMakerPortFactoryInterface*> portFactoryRegistry;
	
	// internal map storing various extensions of this component class
	std::map<std::string, TwoMapMakerExtension*> componentExtensionRegistry;
	
public:
	
	// define tasks
	Smart::TaskTriggerSubject* grayImageCollectorTrigger;
	GrayImageCollector *grayImageCollector;
	Smart::TaskTriggerSubject* imageCollectorTrigger;
	ImageCollector *imageCollector;
	Smart::TaskTriggerSubject* imageJoinerTrigger;
	ImageJoiner *imageJoiner;
	
	// define input-ports
	// InputPort GrayImage1
	Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> *grayImage1;
	Smart::InputTaskTrigger<DGService_DGBasicLink::DGBasicLinkObject> *grayImage1InputTaskTrigger;
	GrayImage1UpcallManager *grayImage1UpcallManager;
	// InputPort GrayImage2
	Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> *grayImage2;
	Smart::InputTaskTrigger<DGService_DGBasicLink::DGBasicLinkObject> *grayImage2InputTaskTrigger;
	GrayImage2UpcallManager *grayImage2UpcallManager;
	// InputPort Image1
	Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> *image1;
	Smart::InputTaskTrigger<DGService_DGBasicLink::DGBasicLinkObject> *image1InputTaskTrigger;
	Image1UpcallManager *image1UpcallManager;
	// InputPort Image2
	Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> *image2;
	Smart::InputTaskTrigger<DGService_DGBasicLink::DGBasicLinkObject> *image2InputTaskTrigger;
	Image2UpcallManager *image2UpcallManager;
	
	// define request-ports
	
	// define input-handler
	
	// define output-ports
	Smart::IPushServerPattern<DGService_DGBasicLink::DGBasicLinkObject> *grayMap;
	Smart::IPushServerPattern<DGService_DGBasicLink::DGBasicLinkObject> *rGBMap;
	
	// define answer-ports
	
	// define request-handlers
	
	// definitions of PlainOpcUaTwoMapMakerExtension
	
	
	// define default slave ports
	SmartACE::StateSlave *stateSlave;
	SmartStateChangeHandler *stateChangeHandler;
	SmartACE::WiringSlave *wiringSlave;
	
	
	/// this method is used to register different PortFactory classes (one for each supported middleware framework)
	void addPortFactory(const std::string &name, TwoMapMakerPortFactoryInterface *portFactory);
	
	SmartACE::SmartComponent* getComponentImpl();
	
	/// this method is used to register different component-extension classes
	void addExtension(TwoMapMakerExtension *extension);
	
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
	
	Smart::StatusCode connectGrayImage1(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectGrayImage2(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectImage1(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectImage2(const std::string &serverName, const std::string &serviceName);

	// return singleton instance
	static TwoMapMaker* instance()
	{
		if(_twoMapMaker == 0) {
			_twoMapMaker = new TwoMapMaker();
		}
		return _twoMapMaker;
	}
	
	static void deleteInstance() {
		if(_twoMapMaker != 0) {
			delete _twoMapMaker;
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
		struct GrayImageCollector_struct {
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
		} grayImageCollector;
		struct ImageCollector_struct {
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
		} imageCollector;
		struct ImageJoiner_struct {
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
		} imageJoiner;
		
		//--- upcall parameter ---
		
		//--- server port parameter ---
		struct GrayMap_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} grayMap;
		struct RGBMap_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} rGBMap;
	
		//--- client port parameter ---
		struct GrayImage1_struct {
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} grayImage1;
		struct GrayImage2_struct {
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} grayImage2;
		struct Image1_struct {
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} image1;
		struct Image2_struct {
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} image2;
		
		// -- parameters for PlainOpcUaTwoMapMakerExtension
		
	} connections;
};
#endif
