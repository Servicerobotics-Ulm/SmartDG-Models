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
#include "BWMapUpcallManager.hh"

BWMapUpcallManager::BWMapUpcallManager(
	Smart::InputSubject<DGService_DGBasicLink::DGBasicLinkObject> *subject,
	const int &prescaleFactor)
	:	Smart::IInputHandler<DGService_DGBasicLink::DGBasicLinkObject>(subject, prescaleFactor)
{  }
BWMapUpcallManager::~BWMapUpcallManager()
{  }

void BWMapUpcallManager::notify_upcalls(const DGService_DGBasicLink::DGBasicLinkObject &input)
{
	for(auto it=upcalls.begin(); it!=upcalls.end(); it++) {
		(*it)->on_BWMap(input);
	}
}

void BWMapUpcallManager::attach(BWMapUpcallInterface *upcall)
{
	upcalls.push_back(upcall);
}
void BWMapUpcallManager::detach(BWMapUpcallInterface *upcall)
{
	upcalls.remove(upcall);
}
