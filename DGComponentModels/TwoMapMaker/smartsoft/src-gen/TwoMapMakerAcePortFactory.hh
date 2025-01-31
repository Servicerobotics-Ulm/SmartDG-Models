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

#ifndef TWOMAPMAKER_ACE_PORTFACTORY_HH_
#define TWOMAPMAKER_ACE_PORTFACTORY_HH_

// include ACE/SmartSoft component implementation
#include "TwoMapMakerImpl.hh"

// include the main component-definition class
#include "TwoMapMakerPortFactoryInterface.hh"

class TwoMapMakerAcePortFactory: public TwoMapMakerPortFactoryInterface
{
private:
	TwoMapMakerImpl *componentImpl;
public:
	TwoMapMakerAcePortFactory();
	virtual ~TwoMapMakerAcePortFactory();

	virtual void initialize(TwoMapMaker *component, int argc, char* argv[]) override;
	virtual int onStartup() override;

	virtual Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> * createGrayImage1() override;
	virtual Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> * createGrayImage2() override;
	virtual Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> * createImage1() override;
	virtual Smart::IPushClientPattern<DGService_DGBasicLink::DGBasicLinkObject> * createImage2() override;
	
	virtual Smart::IPushServerPattern<DGService_DGBasicLink::DGBasicLinkObject> * createGrayMap(const std::string &serviceName) override;
	virtual Smart::IPushServerPattern<DGService_DGBasicLink::DGBasicLinkObject> * createRGBMap(const std::string &serviceName) override;
	
	// get a pointer to the internal component implementation
	SmartACE::SmartComponent* getComponentImpl();

	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) override;
	virtual void destroy() override;
};

#endif /* TWOMAPMAKER_ACE_PORTFACTORY_HH_ */
