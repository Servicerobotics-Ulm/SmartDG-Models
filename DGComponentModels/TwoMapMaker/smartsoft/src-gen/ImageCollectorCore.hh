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
#ifndef _IMAGECOLLECTOR_CORE_HH
#define _IMAGECOLLECTOR_CORE_HH
	
#include "aceSmartSoft.hh"

// include upcall interface
#include "Image1UpcallInterface.hh"
#include "Image2UpcallInterface.hh"

// include communication-objects for output ports

// include all interaction-observer interfaces
#include <ImageCollectorObserverInterface.hh>


class ImageCollectorCore
:	public SmartACE::ManagedTask
,	public Smart::TaskTriggerSubject
,	public Image1UpcallInterface
,	public Image2UpcallInterface
{
private:
	bool useDefaultState; 
	bool useLogging;
	int taskLoggingId;
	unsigned int currentUpdateCount;
	
	Smart::StatusCode image1Status;
	DGService_DGBasicLink::DGBasicLinkObject image1Object;
	Smart::StatusCode image2Status;
	DGService_DGBasicLink::DGBasicLinkObject image2Object;
	
	
protected:
	virtual int execute_protected_region();
	
	virtual void updateAllCommObjects();
	
	virtual int getPreviousCommObjId();
	
	void triggerLogEntry(const int& idOffset);
	
	
	// overload and implement this method in derived classes to immediately get all incoming updates from Image1 (as soon as they arrive)
	virtual void on_Image1(const DGService_DGBasicLink::DGBasicLinkObject &input) {
		// no-op
	}
	
	// this method can be safely used from the thread in derived classes
	inline Smart::StatusCode image1GetUpdate(DGService_DGBasicLink::DGBasicLinkObject &image1Object) const
	{
		// copy local object buffer and return the last status code
		image1Object = this->image1Object;
		return image1Status;
	}
	// overload and implement this method in derived classes to immediately get all incoming updates from Image2 (as soon as they arrive)
	virtual void on_Image2(const DGService_DGBasicLink::DGBasicLinkObject &input) {
		// no-op
	}
	
	// this method can be safely used from the thread in derived classes
	inline Smart::StatusCode image2GetUpdate(DGService_DGBasicLink::DGBasicLinkObject &image2Object) const
	{
		// copy local object buffer and return the last status code
		image2Object = this->image2Object;
		return image2Status;
	}
	
	
	
/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<ImageCollectorObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(ImageCollectorObserverInterface *observer);
	void detach_interaction_observer(ImageCollectorObserverInterface *observer);

public:
	ImageCollectorCore(Smart::IComponent *comp, const bool &useDefaultState=true);
	virtual ~ImageCollectorCore();
	
	inline void setUpLogging(const int &taskNbr, const bool &useLogging=true) {
		this->taskLoggingId = taskNbr;
		this->useLogging = useLogging;
	}
	
	inline bool isLoggingActive() const {
		return useLogging;
	}
	
	inline int getLoggingID() const {
		return taskLoggingId;
	}
	
	inline int getCurrentUpdateCount() const {
		return currentUpdateCount;
	}
	
};
#endif
