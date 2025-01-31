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

#include "ZeroCameraAcePortFactory.hh"

// create a static instance of the default AcePortFactory
static ZeroCameraAcePortFactory acePortFactory;

ZeroCameraAcePortFactory::ZeroCameraAcePortFactory()
{  
	componentImpl = 0;
	ZeroCamera::instance()->addPortFactory("ACE_SmartSoft", this);
}

ZeroCameraAcePortFactory::~ZeroCameraAcePortFactory()
{  }

void ZeroCameraAcePortFactory::initialize(ZeroCamera *component, int argc, char* argv[])
{
	if(component->connections.component.defaultScheduler != "DEFAULT") {
		ACE_Sched_Params sched_params(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(component->connections.component.defaultScheduler == "FIFO") {
			sched_params.policy(ACE_SCHED_FIFO);
			sched_params.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(component->connections.component.defaultScheduler == "RR") {
			sched_params.policy(ACE_SCHED_RR);
			sched_params.priority(ACE_THR_PRI_RR_MIN);
		}
		// create new instance of the SmartSoft component with customized scheuling parameters 
		componentImpl = new ZeroCameraImpl(component->connections.component.name, argc, argv, sched_params);
	} else {
		// create new instance of the SmartSoft component
		componentImpl = new ZeroCameraImpl(component->connections.component.name, argc, argv);
	}
}

int ZeroCameraAcePortFactory::onStartup()
{
	return componentImpl->startComponentInfrastructure();
}


Smart::IPushServerPattern<DGService_DGBasicLink::DGBasicLinkObject> * ZeroCameraAcePortFactory::createGrayImage(const std::string &serviceName)
{
	return new SmartACE::PushServer<DGService_DGBasicLink::DGBasicLinkObject>(componentImpl, serviceName);
}

Smart::IPushServerPattern<DGService_DGBasicLink::DGBasicLinkObject> * ZeroCameraAcePortFactory::createRGBImage(const std::string &serviceName)
{
	return new SmartACE::PushServer<DGService_DGBasicLink::DGBasicLinkObject>(componentImpl, serviceName);
}


SmartACE::SmartComponent* ZeroCameraAcePortFactory::getComponentImpl()
{
	return componentImpl;
}

int ZeroCameraAcePortFactory::onShutdown(const std::chrono::steady_clock::duration &timeoutTime)
{
	componentImpl->stopComponentInfrastructure(timeoutTime);
	return 0;
}

void ZeroCameraAcePortFactory::destroy()
{
	// clean-up component's internally used resources (internally used communication middleware) 
	componentImpl->cleanUpComponentResources();
	delete componentImpl;
}
