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
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#ifndef DGSERVICE_DGBASICLINK_DGBASICLINKOBJECT_H_
#define DGSERVICE_DGBASICLINK_DGBASICLINKOBJECT_H_

#include "DGService_DGBasicLink/DGBasicLinkObjectCore.hh"

namespace DGService_DGBasicLink {
		
class DGBasicLinkObject : public DGBasicLinkObjectCore {
	public:
		// default constructors
		DGBasicLinkObject();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// DGBasicLinkObject(const int &data);
		
		DGBasicLinkObject(const DGBasicLinkObjectCore &dGBasicLinkObject);
		DGBasicLinkObject(const DATATYPE &dGBasicLinkObject);
		virtual ~DGBasicLinkObject();
		
		// use framework specific getter and setter methods from core (base) class
		using DGBasicLinkObjectCore::get;
		using DGBasicLinkObjectCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const DGBasicLinkObject &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace DGService_DGBasicLink */
#endif /* DGSERVICE_DGBASICLINK_DGBASICLINKOBJECT_H_ */
