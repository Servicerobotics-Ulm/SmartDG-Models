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
#include "Image2UpcallManager.hh"

Image2UpcallManager::Image2UpcallManager(
	Smart::InputSubject<DGService_DGBasicLink::DGBasicLinkObject> *subject,
	const int &prescaleFactor)
	:	Smart::IInputHandler<DGService_DGBasicLink::DGBasicLinkObject>(subject, prescaleFactor)
{  }
Image2UpcallManager::~Image2UpcallManager()
{  }

void Image2UpcallManager::notify_upcalls(const DGService_DGBasicLink::DGBasicLinkObject &input)
{
	for(auto it=upcalls.begin(); it!=upcalls.end(); it++) {
		(*it)->on_Image2(input);
	}
}

void Image2UpcallManager::attach(Image2UpcallInterface *upcall)
{
	upcalls.push_back(upcall);
}
void Image2UpcallManager::detach(Image2UpcallInterface *upcall)
{
	upcalls.remove(upcall);
}
