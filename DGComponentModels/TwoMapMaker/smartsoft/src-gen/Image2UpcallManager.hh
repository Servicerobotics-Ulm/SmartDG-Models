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
#ifndef _IMAGE2_UPCALL_MANAGER_HH
#define _IMAGE2_UPCALL_MANAGER_HH

#include <list>
#include "aceSmartSoft.hh"
#include "Image2UpcallInterface.hh"

/** Image2UpcallManager connects input-handling with Upcall propagation
 *
 * This class implements an InputHandler for the InputPort Image2 and propagates the handling 
 * of incoming data to all associated (i.e. attached) Upcalls.
 */
class Image2UpcallManager
:	public Smart::IInputHandler<DGService_DGBasicLink::DGBasicLinkObject>
{
private:
	// list of associated updalls
	std::list<Image2UpcallInterface*> upcalls;

	// call the on_Image2 of all the attached Image2UpcallInterfaces
	void notify_upcalls(const DGService_DGBasicLink::DGBasicLinkObject &input);
	
protected:
	virtual void handle_input(const DGService_DGBasicLink::DGBasicLinkObject &input) {
		// relay input-handling to all attached Image2UpcallInterfaces
		this->notify_upcalls(input);
	}
public:
	Image2UpcallManager(
		Smart::InputSubject<DGService_DGBasicLink::DGBasicLinkObject> *subject,
		const int &prescaleFactor=1
	);
	virtual ~Image2UpcallManager();
	
	void attach(Image2UpcallInterface *upcall);
	void detach(Image2UpcallInterface *upcall);
};

#endif
