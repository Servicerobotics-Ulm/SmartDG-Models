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
#ifndef _GRAYIMAGE1_UPCALL_INTERFACE_HH
#define _GRAYIMAGE1_UPCALL_INTERFACE_HH

#include "DGService_DGBasicLink/DGBasicLinkObject.hh"

class GrayImage1UpcallInterface {
public:
	virtual ~GrayImage1UpcallInterface() {  }

	virtual void on_GrayImage1(const DGService_DGBasicLink::DGBasicLinkObject &input) = 0;
};

#endif
